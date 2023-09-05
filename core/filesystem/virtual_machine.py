'''
    encodes and decodes filenames and directories to a numbers
    so the filenames and directories does not appear in letters

    the aim is to create obfuscation to protect important data
'''

def encode(string):
    ch = [
        "`123456789", "0-=qwertyu", "iop[]asdfg", "hjkl;'\\zxc", "vbnm,./ ~@",
        "#$%^&*()_+", "QWERTYUIOP", "{}ASDFGHJK", "L:\"|ZXCVBN",
        "M<>?\t\n\a\r\b"
    ]

    s = ""

    for c in string:
        for i in range(len(ch)):
            for j in range(len(ch[i])):
                if ch[i][j] == c:
                    s += str(i) + str(j)

    return (s)


def decode(string):
	pass
