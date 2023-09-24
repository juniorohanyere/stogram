'''
    encodes and decodes filenames and directories to hexadecimals, and vise
    versa, so the filenames and directories does not appear in letters

    the aim is to create obfuscation to protect important data
'''


def encode(string):
    '''
        encodes an input string into hexadecimals

        Args:
            string (str): the input string

        Return: returns the hexadecimal representation of the input string
    '''

    hex_value = ''.join([f'{ord(ch):02x}' for ch in string])

    return (hex_value)


def decode(hex_value):
    '''
        decodes an hexadecimal value into original string

        Args:
            hex_value (str): the hexadecimal value

        Return: returns the string representation of the hexadecimal
    '''

    string = ''.join([chr(int(hex_value[i: i + 2], 16))
                     for i in range(0, len(hex_value), 2)])

    return (string)
