import win32file
import win32con
import subprocess

# Function to handle device events
def handle_device_event(dbhInfo):
    if dbhInfo.Action == win32con.DBT_DEVICEARRIVAL:
        print("Device inserted:", dbhInfo.DeviceName)
        # Run the Tkinter script using subprocess
        subprocess.Popen(['python', 'path_to_tkinter_script.py'])

# Create a handle for device notifications
hDevNotify = win32file.FindFirstChangeNotification(
    "C:\\",
    0,
    win32con.FILE_NOTIFY_CHANGE_NAME
)

while True:
    result = win32file.WaitForSingleObject(hDevNotify, win32con.INFINITE)
    if result == win32con.WAIT_OBJECT_0:
        handle_device_event(win32file.DeviceBroadcastHeader())
        win32file.FindNextChangeNotification(hDevNotify)
