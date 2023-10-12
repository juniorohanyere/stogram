#!/usr/bin/env python
"""the stogram launcher module
launches the stogram window and resposible for mounting storage device (if
not mounted). Then mounts the root file system (if found). If no compatible
file system is found, attempts to install stogram on the device
"""

import tkinter as tk
from shell import Shell


launcher = tk.Tk()
launcher.title("Stogram")
launcher.config(bg="black")

tty = Shell(launcher, bg='black', fg='white', insertbackground='white', bd=0,
            highlightthickness=0)
tty.focus_set()
tty.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)

launcher.mainloop()
