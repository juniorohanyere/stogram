#!/usr/bin/env python3

import os
import subprocess
import platform
import signal

def handle_linux_event():
    import pyudev

    context = pyudev.Context()
    monitor = pyudev.Monitor.from_netlink(context)
    monitor.filter_by(subsystem='block', device_type=None)

    for dev in iter(monitor.poll, None):
        # handle the insertion of the external storage device
        if dev.action == 'add':
            hm_dir = os.path.expanduser("~")    # home directory
            media_dir = hm_dir + "/.media/"     # media directory

            dev_name = dev.device_node
            password = "maduabuchi"   # set this to your device password for testing

            # mount point
            mnt_point = media_dir + "stogram"	# ~/.media/stogram

            subprocess.Popen(['mkdir', '-p', mnt_point])

            subprocess.run(f'echo "{password}" | sudo -S mount \
                            {dev_name} {mnt_point}', shell=True,
                           text=True, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)

            device = subprocess.Popen([f'{mnt_point}/slauncher.py', dev_name])

        # handle the removal of the external storage device
        if dev.action == 'remove':
            subprocess.run(f'echo "{password}" | sudo -S umount {dev_name}',
                           shell=True, text=True, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)

            device.send_signal(signal.SIGTERM)

def handle_windows_event():
    import win32file
    import win32con

    if dbhInfo.Action == win32con.DBT_DEVICEARRIVAL:
        print("External storage device inserted:", dbhInfo.DeviceName)
        #dev = subprocess.Popen(['C:\\

system = platform.system()

if system == "Linux":
    handle_linux_event()

elif system == "Windows":
    handle_windows_event()

elif system == "Darwin":
    handle_darwin_event()
