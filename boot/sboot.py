#!/usr/bin/env python3
"""sboot module, the Stogram Bootloader
loads the skerenl
"""

import tkinter as tk
from kernel.environment import shell
import time

class Sboot(tk.Frame):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        self.master = master
        self._flag = 0
        self.logo()
        self.focus_set()
        self.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)
        self.bind('<KeyPress>', self.key_press)

    def logo(self):
        self.label = tk.Label(self, text="Stogram", bg='black', fg='white',
                              font='Courier 50 bold')
        self.label.pack(expand=True, anchor='center')

    def self_test(self):
        # self.after(5000, self.logo)
        self.update()
        time.sleep(5)
        return True

    def select_interface(self):
        self.frame = tk.Frame(self, bd=0, highlightthickness=0, bg='dark gray')
        self.frame.pack()

        meta = tk.Label(self.frame, text="SELECT MODE", bg='black',
                        fg='dark gray', font='Courier 20 bold',
                        width=self.winfo_width())
        meta.pack(pady=2, padx=2)

        self.separator = tk.Label(self, bg='black', width=self.winfo_width())
        self.separator.pack()
        self.gui = tk.Label(self, text='Graphical User Interface (GUI)',
                       bg='dark gray', fg='black', font='Courier 15 bold',
                       width=self.winfo_width(), anchor='w', justify='left')
        self.gui.pack()

        self.cli = tk.Label(self, text='Command Line Interface (CLI)',
                       bg='black', fg='dark gray', font='Courier 15 bold',
                       width=self.winfo_width(), anchor='w', justify='left')
        self.cli.pack()

        self.adv = tk.Label(self, text='Advanced Options', bg='black',
                            fg='dark gray', font='Courier 15 bold',
                            width=self.winfo_width(),
                            anchor='w', justify='left')
        self.adv.pack()

    def key_press(self, event):
        if event.keysym == "Return":
            self.frame.pack_forget()
            self.separator.pack_forget()
            self.gui.pack_forget()
            self.cli.pack_forget()
            self.adv.pack_forget()

            if self._flag == 0:
                self.logo()
                self.self_test()
                self.pack_forget()

                sh = shell.Shell(self.master, bg='black', fg='white', insertbackground='white',
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


def main():
    root = tk.Tk()
    root.title('Stogram')
    root.config(bg='black')

    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    root.geometry('{}x{}'.format(str(width), str(height)))

    boot = Sboot(root, bg='black', bd=0, highlightthickness=0)
    boot.update()
    boot.label.pack_forget()
    boot.select_interface()

    root.mainloop()


if __name__ == '__main__':
    main()
