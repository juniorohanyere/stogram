#!/usr/bin/env python3
"""sboot module, the Stogram Bootloader
"""

import tkinter as tk
from kernel.environment import shell
import time

class Sboot(tk.Frame):
    def __init__(self, master=None, **kwargs):
        super().__init__(master, **kwargs)
        self.focus_set()
        self.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)
        self.logo()

    def logo(self):
        return True

    def test(self):
        # self.after(5000, self.logo)
        self.update()
        time.sleep(5)
        return True


def main():
    root = tk.Tk()
    root.title('Stogram')
    root.config(bg='black')

    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    root.geometry('{}x{}'.format(str(width), str(height)))

    boot = Sboot(root, bg='black', bd=0, highlightthickness=0)
    boot.test()

    if boot.test() == True:
        boot.pack_forget()

        sh = shell.Shell(root, bg='black', fg='white', insertbackground='white',
                   bd=0, highlightthickness=0)
        sh.focus_set()
        sh.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)

    root.mainloop()


if __name__ == '__main__':
    main()
