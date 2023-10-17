#!/usr/bin/env python3

import os
import subprocess
import platform
import signal
import json


def device_info(data=None):
    # Split the data by spaces and then by "=" to extract key-value pairs
    pairs = [pair.split('=') if '=' in pair else (pair, None)
             for pair in data.split()]

    # Create a dictionary from the key-value pairs
    info = {key: value.strip('"') if value is not None else None for key,
            value in pairs}

    # return the resulting dictionary
    return (info)


def handle_linux_event():
    import pyudev

    context = pyudev.Context()
    monitor = pyudev.Monitor.from_netlink(context)
    monitor.filter_by(subsystem='block', device_type=None)

    for dev in iter(monitor.poll, None):
        # handle the insertion of the external storage device
        if dev.action == 'add':
            user = os.environ.get("SUDO_USER", None)

            hm_dir = os.path.expanduser(f"~{user}")    # home directory
            media_dir = hm_dir + "/.media/"     # media directory

            dev_name = dev.device_node

            info = subprocess.run(f'sudo lsblk -npOP {dev_name}',
                                  shell=True, text=True,
                                  stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE)

            dev_info = device_info(info.stdout)

            dev_attrs = json.dumps(dev_info)

            # ~/.media/<volume id>
            mnt_point = media_dir + dev_info["UUID"]     # mount point

            subprocess.Popen(['mkdir', '-p', mnt_point])

            subprocess.run(f'sudo mount {dev_name} {mnt_point}', shell=True,
                           text=True, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)
            device = subprocess.Popen([f'{mnt_point}/slauncher.py', dev_attrs],
                                      user=user)

        # handle the removal of the external storage device
        if dev.action == 'remove':
            # clean up
            device.send_signal(signal.SIGTERM)
            subprocess.run(f'sudo umount {dev_name}', shell=True, text=True,
                           stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            subprocess.Popen(['sudo', 'rmdir', f'{media_dir}/*'])


def handle_windows_event():
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
