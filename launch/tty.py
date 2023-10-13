#!/usr/bin/env python3
"""teleyping module
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
        self.insert('1.0', '(slauncher) ')  # first prompt

        # create input mark/offset
        self.mark_set('input', 'insert')
        self.mark_gravity('input', 'left')

        # create proxy/tty
        self._orig = self._w + "_orig"
        self.tk.call("rename", self._w, self._orig)
        self.tk.createcommand(self._w, self._tty)

        # binding the widget to specific keys
        self.bind("<KeyPress>", self.key_press)
        self.bind("<Control-KeyPress>", self.control_key)

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
                    return  # don't delete anything
                largs[1] = 'input'  # move deletion, start at 'input'

        result = self.tk.call((self._orig,) + tuple(largs))

        return result
