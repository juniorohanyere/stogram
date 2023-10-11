#!/usr/bin/env python
"""launches the stogram window and resposible for mounting storage device (if
not mounted). Then mounts the root file system (if found). If no compatible
file system is found, attempts to install stogram on the device
"""

import tkinter as tk


class TTY(tk.Text):
    """handles teletyping

    Args:
        tk.Text (obj): text widget
    """

    def __init__(self, master=None, **kwargs):
        """instantiation module.
        creates input offset, tty, and binds the text widget to 'enter' key

        Args:
            master: optional
            kwargs: keyworded variable length list of arguments
        """

        tk.Text.__init__(self, master, **kwargs)
        self.insert('1.0', '(slauncher) ') # first prompt

        # create input mark/offset
        self.mark_set('input', 'insert')
        self.mark_gravity('input', 'left')

        # create proxy/tty
        self._orig = self._w + "_orig"
        self.tk.call("rename", self._w, self._orig)
        self.tk.createcommand(self._w, self._tty)

        # binding the widget to 'enter' key
        self.bind("<Return>", self.enter)


    def _tty(self, *args):
        """private module.
        creates the tty

        Args:
            args: non-keyworded variable length list of arguments
        """

        largs = list(args)

        if args[0] == 'insert':
            if self.compare('insert', '<', 'input'):
                # move insertion cursor to the editable part
                self.mark_set('insert', 'end')

        elif args[0] == "delete":
            if self.compare(largs[1], '<', 'input'):
                if len(largs) == 2:
                    return # don't delete anything
                largs[1] = 'input'  # move deletion, start at 'input'

        result = self.tk.call((self._orig,) + tuple(largs))

        return result

    def enter(self, event):
        """
        handles the enter key event

        Args:
            event (key event): the enter key event
        """

        command = self.get('input', 'end')

        # display result and next prompt
        self.scroll_to_bottom()
        self.insert('end', '\n' + command + '(slauncher) ')

        # move input mark
        self.mark_set('input', 'insert')
        return "break" # don't execute class method that inserts a newline

    def scroll_to_bottom(self):
        """scrolls the text widget to the bottom
        """

        lines = self.index("end-1c").split('.')[0]
        self.yview_scroll(lines, "units")

win = tk.Tk()
win.title("Stogram")
win.config(bg="black")

tty = TTY(win, bg='black', fg='white', insertbackground='white', bd=0, highlightthickness=0)
tty.focus_set()
tty.pack(pady=4, padx=4, fill=tk.BOTH, expand=True)

win.mainloop()
