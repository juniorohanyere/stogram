# Process Control Block

The process control block is responsible for creating and assigning process identities to system calls
Also handles threading and memory information for a particular process

# Thread Control Block

The thread control block is responsible for creating and handling threading for processes.

# File Descriptor Table

The file descriptor table contains a data structure of open file descriptors, also handles the closing of these file descriptors
`stdin` is designed to have its file descriptor as `0`.
`stdout` is designed to have its file descriptor as `1`.
`stderr` is designed to have its file descriptor as `2`.

Other file descriptor values will be assigned to filenames, according to the available allocatable file descriptor.
The file descriptor table is an array of the file descriptor data structure. Therefore, each open file descriptor is designed as follows:

fd => the file descriptor, this is an integer value.
filename => this is the name of the file occupying the available file descriptor
offset => used to set offset where read/write operations will start from within a file or open file descriptor
flag => this describes the read-write mode of a file

>> Here are some possible components of the file descriptor table in the context of Stogram:

**Standard I/O Channels:**

File descriptors 0 (stdin), 1 (stdout), and 2 (stderr) are often reserved for the standard input, standard output, and standard error streams, respectively. These are also related to Stogram's functionality.

**Network Sockets:**

Stogram uses network sockets to communicate with other users or servers. Entries in the file descriptor table could represent open network sockets for sending and receiving messages.

**File Descriptors for Storage:**

Since Stogram supports file transfers or attachments, it may have file descriptors representing open files for reading or writing data.

**IPC Mechanisms:**

Inter-process communication (IPC) mechanisms, such as pipes or message queues, may also be present in the file descriptor table to facilitate communication between different parts of the application or between different processes.

**User Interface Components:**

Since Stogram has a graphical user interface (GUI), there might be file descriptors for GUI components like windows, buttons, or other UI elements.

**Database Connections:**

Stogram interacts with a database, file descriptors might be used to manage connections to the database server.

**Other Resources:**

Depending on the yet-to-be-identified application's architecture (components), there could be entries for other I/O resources like timers, event handlers, or device-specific file descriptors.

**Custom Channels:**

Stogram may define custom channels or communication mechanisms that require file descriptors to manage. For example, if it uses a custom messaging protocol or a unique IPC mechanism, it would have corresponding entries in the file descriptor table.
