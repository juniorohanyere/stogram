#!/usr/bin/env python3
"""sboot module, the Stogram Bootloader
loads the skerenl
"""
import sys
import subprocess
import tkinter as tk
import time
import ctypes

from kernel import shell
from kernel import my_ctypes


class Sboot(tk.Frame):
    """stogram bootloader

    Args:
        tk.Frame (frame object): base class for Sboot
    """

    def __init__(self, master=None, **kwargs):
        """initialise self

        Args:
            master (class object): placeholder (optional)
            kwargs (dict): keyworded list of arguments

        Return:
            return nothing
        """

        super().__init__(master, **kwargs)
        self.master = master
        self._flag = 0
        self.logo()
        self.focus_set()
        self.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)
        self.bind('<KeyPress>', self.key_press)

    def logo(self):
        """displays the stogram chat system logo

        Return:
            return nothing
        """

        self.label = tk.Label(self, text="Stogram", bg='black', fg='white',
                              font='Courier 50 bold')
        self.label.pack(expand=True, anchor='center')

    def test_self(self):
        """performs self test before jumping into the kernel proper
        checks for dependencies availability

        Return:
            return True on success
        """

        skernel = ctypes.CDLL('kernel/lib/libskernel.so')
        skernel.init_pcb.restype = ctypes.POINTER(my_ctypes.PCB)
        pcb = skernel.init_pcb()
        skernel.init_system(pcb)
        print(pcb[0].name.decode('utf-8'))
        print(pcb[0].prio)
        print()
        print(pcb[1].name.decode('utf-8'))
        print(pcb[1].prio)
        self.update()
        time.sleep(5)
        return True

    def select_interface(self):
        """creates an option to select interface to boot into

        Return:
            return nothing
        """

        self.frame = tk.Frame(self, bd=0, highlightthickness=0, bg='dark gray')
        self.frame.pack()

        meta = tk.Label(self.frame, text="SELECT INTERFACE", bg='black',
                        fg='dark gray', font='Courier 20 bold',
                        width=self.winfo_width())
        meta.pack(pady=2, padx=2)

        self.separator = tk.Label(self, bg='black', width=self.winfo_width())
        self.separator.pack()
        self.gui = tk.Label(self, text='Graphical User Interface (GUI)',
                            bg='dark gray', fg='black', font='Courier 15 bold',
                            width=self.winfo_width(), anchor='w',
                            justify='left')
        self.gui.pack()

        self.cli = tk.Label(self, text='Command Line Interface (CLI)',
                            bg='black', fg='dark gray', font='Courier 15 bold',
                            width=self.winfo_width(), anchor='w',
                            justify='left')
        self.cli.pack()

        self.adv = tk.Label(self, text='Advanced Options', bg='black',
                            fg='dark gray', font='Courier 15 bold',
                            width=self.winfo_width(),
                            anchor='w', justify='left')
        self.adv.pack()

    def key_press(self, event):
        """handles keypress

        Args:
            event: keypress event

        Return:
            return nothing
        """

        if event.keysym == "Return":
            if self._flag == 1:     # cli mode
                self.frame.pack_forget()
                self.separator.pack_forget()
                self.gui.pack_forget()
                self.cli.pack_forget()
                self.adv.pack_forget()

                self.logo()
                self.test_self()
                self.pack_forget()

                sh = shell.Shell(self.master, bg='black', fg='white',
                                 insertbackground='white',
                                 bd=0, highlightthickness=0)
                sh.focus_set()
                sh.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)

        elif event.keysym == "Up":
            self._flag = self._flag - 1
            if (self._flag < 0):
                self._flag = 0

        elif event.keysym == "Down":
            self._flag = self._flag + 1
            if self._flag > 2:
                self._flag = 2

        if self._flag == 0:
            self.gui.configure(bg='dark gray', fg='black')
            self.cli.configure(bg='black', fg='dark gray')
            self.adv.configure(bg='black', fg='dark gray')

        elif self._flag == 1:
            self.cli.configure(bg='dark gray', fg='black')
            self.gui.configure(bg='black', fg='dark gray')
            self.adv.configure(bg='black', fg='dark gray')

        elif self._flag == 2:
            self.adv.configure(bg='dark gray', fg='black')
            self.cli.configure(bg='black', fg='dark gray')
            self.gui.configure(bg='black', fg='dark gray')
