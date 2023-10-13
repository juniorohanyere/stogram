#!/usr/bin/env python3
"""shell module
"""

import sys
import subprocess
from tty import TTY


class Shell(TTY):
    """interactive shell for navigating the slauncher

    Args:
        TTY (tty): teletyping class
    """

    _prompt = '(slauncher) '

    def key_press(self, event):
        """
        handles the enter key event

        Args:
            event (key event): the enter key event
        """

        if (event.keysym == "Return"):
            line = self.get('input', 'end')
            # self.insert('end', '\nDEBUG')
            args = line.split()

            if len(args) == 1:
                if args[0] == "clear":
                    self.clear_screen()
                    return "break"  # remove newline
                elif args[0] == "list":
                    ld = subprocess.run("sudo lshw -class disk", shell=True,
                                        text=True, stdout=subprocess.PIPE,
                                        stderr=subprocess.PIPE)
                    line = ld.stdout
                    a = line.split("\n")
                    # print result bit by bit
                    for b in a:
                        self.scroll_to_bottom()
                        self.insert('end', '\n' + b)
                    line = ''
            # display result and next prompt
            self.scroll_to_bottom()
            if line == '':
                self.insert('end', self._prompt)
            else:
                self.insert('end', '\n' + line + self._prompt)

            # move input mark
            self.mark_set('input', 'insert')
            return "break"  # don't execute class method that inserts a newline

    def control_key(self, event):
        """handles key combination with the ctrl key (CTRL + [Regular Key])
        """
        if event.keysym == "d" and int(self.index("insert").split('.')[1]) == \
                len(self._prompt):
            sys.exit()

    def scroll_to_bottom(self):
        """scrolls the text widget to the bottom
        """

        line = self.index("end").split('.')[0]
        self.yview_scroll(line, "units")

    def clear_screen(self):
        """clears the screen from top to bottom
        """

        self.mark_set("input", "1.0")
        self.delete("1.0", "end")
        self.insert('1.0', self._prompt)
        self.mark_set("input", "insert")
