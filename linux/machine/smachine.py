#!/usr/bin/env python3
"""the stogram virtual machine module
"""

import os
import pyudev
import subprocess
import signal
import json


def handle_event():
    """method for listening on external storage insertion and removal on linux
    """

    context = pyudev.Context()
    monitor = pyudev.Monitor.from_netlink(context)
    monitor.filter_by(subsystem='block', device_type=None)

    user = os.environ.get("SUDO_USER", None)

    hm_dir = os.path.expanduser(f"~{user}")    # home directory
    media_dir = hm_dir + "/.stogram/"     # media directory

    # once underlying OS boots up, delete any empty that was impossible to
    # delete due to some failures or errors (device or resource in use)
    try:
        os.rmdir('{media_dir}/*')
    except (FileNotFoundError, UnboundLocalError, OSError):
        pass

    for dev in iter(monitor.poll, None):
        # handle the insertion of the external storage device
        if dev.action == 'add':
            dev_name = dev.device_node

            get_vol_id = subprocess.run(f'sudo lsblk -npo UUID {dev_name}',
                                        shell=True, text=True,
                                        stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)
            vol_id = get_vol_id.stdout.strip('\n')

            # ~/.media/<volume id>
            mnt_point = media_dir + vol_id     # mount point

            subprocess.Popen(['mkdir', '-p', mnt_point])

            subprocess.run(f'sudo mount {dev_name} {mnt_point}', shell=True,
                           text=True, stdout=subprocess.PIPE,
                           stderr=subprocess.PIPE)

            info = subprocess.run(f'sudo lsblk -npJO {dev_name}', shell=True,
                                  text=True, stdout=subprocess.PIPE,
                                  stderr=subprocess.PIPE)

            dev_info = info.stdout

            # dev_attrs = json.dumps(dev_info)

            device = subprocess.Popen([f'{mnt_point}/stogram.py', dev_info],
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
                os.rmdir(f'{mnt_point}')
            except (FileNotFoundError, UnboundLocalError, OSError):
                pass


if __name__ == '__main__':
    handle_event()
