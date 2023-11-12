#!/usr/bin/env python3

"""module to recursively get the content of a parent directory
"""

import os
import subprocess


class Content:
    """copy the content of a given source directory to a destionation directory
    assigning decimal names to the content of the destination instead of the
    original name of the source content
    """

    def __init__(self, dst, src):
        """initialise self
        src and dst must begin with '/' and must not end with '/'

        Args:
            dst (str): destination directory/path
            src (str): source directory/path

        Return:
            return nothing
        """

        if not src.startswith("/") or not dst.startswith("/"):
            raise NameError("pathnames must begin with '/'")

        elif src.endswith("/") or dst.endswith("/"):
            raise NameError("pathnames must not end with '/'")

        self.parent = src
        self.dest = dst
        self.content = self.get_content()
        self.create_content()

    def get_content(self):
        """get the content of a given directory recursively, and organise the
        result into a dictionary

        Return:
            return the dict organisation of the content
        """

        dictionary = {}
        my_list = []

        content = subprocess.run(f'ls -R {self.parent}', shell=True, text=True,
                                 stdout=subprocess.PIPE,
                                 stderr=subprocess.PIPE)

        lines = content.stdout.split('\n')

        for line in lines:
            if line != '':
                my_list += [line]

        value = []
        for d in my_list:
            if d.startswith(self.parent):
                key = d.rstrip(':')
                # seems like strip() has some bugs:
                # key = key.lstrip(dir) or key = key.strip(dir)
                key = key.split(self.parent)[1].strip('/')
                value = []
            else:
                value += [d]

            dictionary.update([(key, value)])

        # the parent is not needed
        # dictionary.pop("")

        return dictionary

    def create_content(self, parent="", target=None, a_dict={}):
        """fill a specific direcotry with content making str representation of
        decimals as the name for the content and output an organised dictionary
        representation of the created content into a json file

        can't believe I generated this algorithm all from my head
        just whiteboarding alone!

        Return:
            return nothing
        """

        if target is None:
            target = self.dest

        for child in self.content[parent.rstrip('/')]:
            fd = 0
            key = None
            value = [None, None]
            path = parent + child + "/"

            alt_path = target + "/" + str(fd)
            while os.access(alt_path, os.F_OK) is True:
                fd += 1
                alt_path = target + "/" + str(fd)

            key = path.split('/')[-2]
            value[0] = str(fd)

            if path.rstrip('/') in self.content:
                os.mkdir(alt_path)

                value[1] = {}

                # recursion, almost missed this algorithm :)
                self.create_content(path, target=alt_path, a_dict=value[1])

            else:
                src_file = self.parent + "/" + parent + "/" + child
                subprocess.run(f'cp {src_file} {alt_path}', shell=True,
                               text=True)
                value[1] = ""

            a_dict.update([(key, value)])

        self.content.pop(parent.rstrip('/'))

        if self.content == {}:
            with open('sda.json', 'w') as file:
                file.write(str(a_dict))
