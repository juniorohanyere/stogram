#!/usr/bin/env python3

import win32file
import win32con


def handle_event():
    """ method for listening on external storge insertion and removal on
    windows
    """

    if dbhInfo.Action == win32con.DBT_DEVICEARRIVAL:
        print("External storage device inserted:", dbhInfo.DeviceName)
        # dev = subprocess.Popen(['C:\\to bo continued...


if __name__ == '__main__':
    handle_event()
