#!/usr/bin/env python3
"""wrapper for the stogram window
jumps to the stogram bootloader=>sboot
"""

import tkinter

from boot import sboot


def main():
    """entry point
    """

    root - tk.Tk()
    root.title('Stogram')
    root.config(bg='black')

    width = root.winfo_screenwidth()
    height = root.winfo_screenheight()
    root.geometry('{}x{}'.format(width, height))

    boot = sboot.Sboot(root, bg='black', bd=0, hightlightthickness=0)
    boot.update()
    boot.label.pack_forget()
    boot.select_interface()

    root.mainloop()


if __name__ == '__main__':
    main()
