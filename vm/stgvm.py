#!/usr/bin/env python3
"""the stogram virtual machine module
"""

import os
import subprocess
import platform
import signal
import json


def device_info(data=None):
    """reads device info from the data parameter, and converts it into a
    dictionary as the info is in a string format
    """

    info = {}   # initialize with empty dictionary
    strip_info = data.strip('"\n')  # strip off the trailing (") and newline
    split_info = strip_info.split('" ')     # strip (" ) first

    for data in split_info:
        ldata = data.split('="', 1)     # split once
        if len(ldata) < 2:  # the info has some exceptions
            if ldata[0].endswith('='):
                key = ldata[0].strip('=')
            elif ldata[0].startswith(' '):
                value = ldata[0]
                info.update([(key, value)])
        else:
            key = ldata[0]
            value = ldata[1]
            info.update([(key, value)])

    # return the resulting dictionary
    return (info)


def handle_linux_event():
    """method for listening on external storage insertion and removal on linux
    """

    import pyudev

    context = pyudev.Context()
    monitor = pyudev.Monitor.from_netlink(context)
    monitor.filter_by(subsystem='block', device_type=None)

    user = os.environ.get("SUDO_USER", None)

    hm_dir = os.path.expanduser(f"~{user}")    # home directory
    media_dir = hm_dir + "/.media/"     # media directory

    # once underlying OS boots up, delete any empty that was impossible to
    # delete due to some failures or errors (device or resource in use)
    try:
        os.rmdir('{media_dir}/*')
    except FileNotFoundError:
        pass

    for dev in iter(monitor.poll, None):
        # handle the insertion of the external storage device
        if dev.action == 'add':
            dev_name = dev.device_node

            get_vol_id = subprocess.run(f'sudo lsblk -nop UUID {dev_name}',
                                        shell=True, text=True,
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)
            vol_id = get_vol_id.stdout

            # ~/.media/<volume id>
            mnt_point = media_dir + vol_id     # mount point

            subprocess.Popen(['mkdir', '-p', mnt_point])

            subprocess.run(f'sudo mount {dev_name} {mnt_point}', shell=True,
                           text=True, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)

            info = subprocess.run(f'sudo lsblk -npOP {dev_name}', shell=True,
                                  text=True, stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE)

            dev_info = device_info(info.stdout)

            dev_attrs = json.dumps(dev_info)

            device = subprocess.Popen([f'{mnt_point}/slauncher.py', dev_attrs],
                                      user=user)

        # handle the removal of the external storage device
        if dev.action == 'remove':
            # clean up

            try:
                device.send_signal(signal.SIGTERM)
                subprocess.run(f'sudo umount {dev_name}', shell=True,
                               text=True, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)
            except UnboundLocalError:
                pass

            try:
                os.rmdir('{media_dir}/*')
            except FileNotFoundError:
                pass


def handle_windows_event():
    """ method for listening on external storge insertion and removal on
    windows
    """

    import win32file
    import win32con

    if dbhInfo.Action == win32con.DBT_DEVICEARRIVAL:
        print("External storage device inserted:", dbhInfo.DeviceName)
        # dev = subprocess.Popen(['C:\\


system = platform.system()

if system == "Linux":
    handle_linux_event()

elif system == "Windows":
    handle_windows_event()

elif system == "Darwin":
    handle_darwin_event()
