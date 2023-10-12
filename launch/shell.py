#!/usr/bin/env python
"""shell module
"""

from tty import TTY


class Shell(TTY):
    def enter(self, event):
        """
        handles the enter key event

        Args:
            event (key event): the enter key event
        """

        if (event.keysym == "Return"):
            command = self.get('input', 'end')

            # display result and next prompt
            self.scroll_to_bottom()
            self.insert('end', '\n' + command + '(slauncher) ')

            # move input mark
            self.mark_set('input', 'insert')
            return "break"  # don't execute class method that inserts a newline

    def scroll_to_bottom(self):
        """scrolls the text widget to the bottom
        """

        lines = self.index("end-1c").split('.')[0]
        self.yview_scroll(lines, "units")
