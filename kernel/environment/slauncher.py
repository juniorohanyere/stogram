#!/usr/bin/env python3
"""the stogram launcher module
launches the stogram window and resposible for mounting storage device (if
not mounted). Then mounts the root file system (if found). If no compatible
file system is found, attempts to install stogram on the device
"""

import tkinter as tk
from shell import Shell


"""
def handle_exit_signal(signum, frame):
    print("Received exit signal. Performing cleanup...")
    # Add any cleanup actions here, such as closing windows or releasing resources
    root.destroy()  # Close the tkinter window
    exit(0)
"""

def main():
    launcher = tk.Tk()
    launcher.title("Stogram")
    launcher.config(bg="black")

    sh = Shell(launcher, bg='black', fg='white', insertbackground='white', bd=0,
                highlightthickness=0)
    sh.focus_set()
    sh.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)

    launcher.mainloop()

if __name__ == "__main__":
    main()
