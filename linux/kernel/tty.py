#!/usr/bin/env python3
"""teleyping module
"""

import tkinter as tk
import json
import time
import sys


class TTY(tk.Text):
    """handles teletyping

    Args:
        tk.Text (obj): text widget
    """

    def __init__(self, wizard, master=None, **kwargs):
        """instantiation module.
        creates input offset, tty, and binds the text widget to 'enter' key

        Args:
            master: optional
            kwargs: keyworded variable length list of arguments
        """

        tk.Text.__init__(self, wizard, master, **kwargs)

        # prompt to use
        self._prompt = ('(stg) ')

        attrs = json.loads(sys.argv[1])

        try:
            self.dev_attrs = attrs['blockdevices'][0]
        except Exception:
            self.dev_attrs = {}

        # create input mark/offset
        self.mark_set('input', 'insert')
        self.mark_gravity('input', 'left')

        # self.insert('1.0', self._prompt)

        from kernel.shell import Wizard

        self.wizard = Wizard(master=self)
        self.wizard.handle_check()

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
