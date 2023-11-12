#!/usr/bin/env python3
"""unittest for the shell module
"""

import pycodestyle
import unittest
from core.linux.kernel import shell


class TestShell(unittest.TestCase):
    """unittest for the Shell class
    """

    @classmethod
    def setUp(self):
        """set up for classes
        """

        # self.sh = shell.Shell()

    def test_pycodestyle_compliance(self):
        """checking pycodestyle compliance
        """

        for path in ['core/linux/kernel/shell.py',
                     'core/linux/kernel/tests/test_shell.py']:
            with self.subTest(path=path):
                errors = pycodestyle.Checker(path).check_all()
                self.assertEqual(errors, 0)

    def test_doc_module(self):
        """checking module documentation
        """

        doc = shell.__doc__
        self.assertIsNotNone(doc, "'shell' module needs a docstring")

    def test_doc_class(self):
        """checking class documentation
        """

        doc = shell.Shell.__doc__
        self.assertIsNotNone(doc, "'Shell' class needs a docstring")

    def test_doc_methods(self):
        """checking methods documentation
        """

        methods_to_check = [
            'key_press',
            'control_key',
            'scroll_to_bottom',
            'clear_screen'
        ]
        for method_name in methods_to_check:
            method = getattr(shell.Shell, method_name)
            doc = method.__doc__
            self.assertIsNotNone(doc,
                                 f"'{method_name}' method needs a docstring")
            self.assertTrue(len(doc) > 1,
                            f"'{method_name}' method needs a docstring")


if __name__ == "__main__":
    unittest.main()
