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

    def key_press(self, event):
        """
        handles the enter key event

        Args:
            event (key event): the enter key event
        """

        if (event.keysym == "Return"):
            line = self.get('input', 'end')
            args = line.split()

            self.insert('end', '\n')

            # scroll to bottom before calling update
            self.scroll_to_bottom()

            # call update to reflect changes immediately
            self.update()

            if len(args) == 0:
                line = ''

            elif len(args) == 1:
                if args[0] == "clear":
                    self.clear_screen()

                    return "break"  # remove newline

                elif args[0] == "list":
                    listd = subprocess.run("sudo lshw -class disk", shell=True,
                                           text=True, stdout=subprocess.PIPE,
                                           stderr=subprocess.PIPE)
                    line = listd.stdout
                    result = line.split("\n")

                    # print result bit by bit
                    for i in range(len(result)):
                        self.scroll_to_bottom()
                        if i == 0:
                            self.insert('end', result[i])
                        else:
                            self.insert('end', '\n' + result[i])
                    line = ''

                else:
                    line = "invalid instruction: type help for more info\n"

            else:
                line = "invalid instruction: type help for more info\n"

            # display result and next prompt
            self.scroll_to_bottom()
            self.insert('end', line + self._prompt)

            # move input mark
            self.mark_set('input', 'insert')

            return "break"  # don't execute class method that inserts a newline

    def control_key(self, event):
        """handles key combination with the ctrl key (CTRL + [Regular Key])
        """

        if event.keysym == "d" and int(self.index("insert").split('.')[1]) == \
                len(self._prompt):  # don't exit if not beginning of prompt
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
