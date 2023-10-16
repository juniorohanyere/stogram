"""import tkinter as tk
from tkinter import simpledialog
import subprocess

def run_command_with_sudo(command, password):
    cmd = f"echo '{password}' | sudo -S {command}"
    subprocess.Popen(cmd, shell=True)

def get_sudo_password():
    root = tk.Tk()
    root.withdraw()  # Hide the main window

    password = simpledialog.askstring("Password", "Enter your password:", show="*")

    if password:
        command = "ls"
        run_command_with_sudo(command, password)

get_sudo_password()
"""
import tkinter as tk
import subprocess
import pyautogui

def start_terminal():
    # Simulate keyboard shortcuts to open the terminal emulator (Ctrl+Alt+T for gnome-terminal)
    pyautogui.hotkey('ctrl', 'alt', 't')

app = tk.Tk()
app.title("Background Terminal Launcher")

button = tk.Button(app, text="Start Background Terminal", command=start_terminal)
button.pack()

app.mainloop()
