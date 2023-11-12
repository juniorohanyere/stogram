#!/usr/bin/env python3
"""handles ctypes for complex data structures or data types
"""

import ctypes


class Status(ctypes.c_int):
    """class that defines some status conditions, should be mapped with
    status_t located in indicator.h

    Args:
        ctypes.c_int (ctypes): integer content of the ctype structure
    """

    OK = 0
    FAILED = 1
    MALLOC_ERR = 2
    OFILE_ERR = 3
    PCB_FULL = 4
    FDT_FULL = 5
    INV_FD = 6


class State(ctypes.c_int):
    """class that defines some states conditions, should be mapped with
    state_t located in indicator.h

    Args:
        ctypes.c_int (ctypes): integer content of the ctype structure
    """

    RUNNING = 0     # R
    SLEEPING = 1    # S
    IDLE = 2        # I
    WAITING = 3     # D
    STOPPED = 4     # T
    TRACED = 5      # t
    ZOMBIE = 6      # Z
    DEAD = 7        # X


class FDT(ctypes.Structure):
    """data structure for File Descriptor Table (FDT)

    Args:
        ctypes.Structure (ctype): structure for the contents of the ctype
    """

    _fields_ = [
        ('fd', ctypes.c_int),
        ('modes', ctypes.c_int),
        # using c_longlong for off_t, this might pose some issues
        ('offset', ctypes.c_longlong),
        ('filename', ctypes.POINTER(ctypes.c_char_p)),
        # more fields ...
    ]


class PCB(ctypes.Structure):
    """data structure for Process Control Block (PCB)

    Args:
        ctypes.Structure (ctype): structure for the contents of the ctype
    """

    _fields_ = [
        ('children', ctypes.POINTER(ctypes.c_int)),
        ('ppid', ctypes.c_uint16),
        ('prio', ctypes.c_uint16),
        ('pc', ctypes.c_uint16),
        ('status', Status),
        ('state', State),
        ('name', ctypes.c_char_p),
        ('reg', ctypes.c_char_p),
        # ('meminfo', ctypes.POINTER(Meminfo)),
        ('fdt', ctypes.POINTER(FDT)),
        # ('tcb', ctypes.POINTER(TCB)),
    ]
