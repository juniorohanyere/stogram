# Stogram Chat Application

> A console based chat operating system (OS) that manages chats virtually and provides common chat features and services for users via the command-line interface (CLI).

> A robust, terminal-based OS where almost all, if not all :), common features of a chat application are utilized on, and operated from, the CLI.

Stogram is a versatile and innovative command-line chat application designed to offer users a unique virtual environment with its own decimal-based machine language. This powerful system enables seamless communication, custom program creation, and efficient chat system management within the comfort of your terminal.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
	- [Prerequisites](#prerequisites)
	- [Installation](#installation)
- [Usage](#usage)
	- [Starting Stogram](#starting-stogram)
	- [User Authentication](#user-authentication)
	- [File System](#file-system)
	- [Custom Programs](#custom-programs)
	- [Chats and Messaging](#chats-and-messaging)
	- [Customizations](#customizations)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Features

- **Robust Virtual Environment**: Stogram offers a fully functional virtual environment with its own unique file system and command-line shell for chats.

- **User Authentication**: Securely log in with your username and password to access your personalized virtual space.

- **Decimal-Based File System**: Navigate and manage directories and files using a decimal-based file system, providing an additional layer of security and organization.

- **Custom Programs**: Create and execute custom programs using Stogram's built-in decimal-based machine language. Edit and save your programs using a user-friendly text editor. (How do you feel about this feature!)

- **Chat and Messaging**: Seamlessly interact with other users within Stogram's chat environment. Send and receive messages encoded in the decimal system, fostering collaboration and communication.

- **User-Friendly Interface**: Enjoy an intuitive ncurses-based interface that ensures a comfortable and efficient user experience.

- **Data Security**: Stogram prioritizes data security, ensuring your information is safe and protected.

- **Error Handling**: Robust error handling mechanisms guarantee smooth operation even in unexpected scenarios.

## Getting Started

### Prerequisites

Before getting started, ensure you have the following prerequisites:

- **C Compiler**: Stogram is written in C and requires a compatible compiler (GCC).

- **ncurses Library**: The application relies on the ncurses library for its user interface. Make sure it's installed on your system.

### Installation

- Clone the Stogram repository to your local machine:

	```bash
	git clone https://github.com/juniorohanyere/stogram.git
	```
	```bash
	cd stogram
	make
	```
# Usage

### Starting Stogram

	```bash
	make run
	```
- Upon launching Stogram, you'll be prompted to log in. Enter your registered `username` and `password` to access your personalized environment.

### User Authentication

- 

### Virtual File System

- Utilize decimal-based commands to navigate, organize, and manage your chats and messages in form of a virtual file system.
- While directories and files are stored using decimal encoding, they appear with their regular names within Stogram.

- **File System Structure**

> NOTE: This is just a prototype of how the file system will organised, hence, anything might change

	```
	│
	├── bin				# default/global system programs
	│   └── ...
	├── etc				# configuration files
	│   └── ...
	├── home
	│   ├── user1			# user 1
	│   │   ├── Chats		# user-specific chats
	│   │   │   ├── groups		# group chats
	│   │   │   ├── private		# private one-on-one chats
	│   │   │   └── ...
	│   │   ├── Communities		# user-specific communities
	│   │   │   ├── community1
	│   │   │   ├── community2
	│   │   │   └── ...
	│   │   ├── Documents
	│   │   ├── Downloads
	│   │   ├── Friends		# user-specific friend list
	│   │   ├── Notifications	# user-specific notifications
	│   │   ├── Programs
	│   │   ├── Trends		# user-specific trends
	│   │   │   ├── trend1
	│   │   │   ├── trend2
	│   │   │   └── ...
	│   │   ├── Vidoes
	│   │   └── ...
	│   ├── user2			# user 2
	│   │   └── ...
	│   └── ...
	├── root			# root user
	├── tmp				# temporary files
	├── usr				# custom user-written/user-specific programs
	│   ├── bin
	│   │   └── ...
	│   └── ...
	├── var				# variable data
	│   └── logs			# log files
	└── ...
	```

### Custom Programs

- Unleash your creativity by creating custom programs using Stogram's decimal-based machine language and some other preinstalled high level languages.
- Edit and save your programs effortlessly within Stogram's integrated text editor(s).
- Execute your programs within the virtual environment.

### Chats and Messaging

- Collaborate seamlessly with other users within Stogram's immersive chat environment.
- Engage in conversations and exchange messages encoded in the decimal system.
- Foster teamwork and communication within your customized virtual space.
- Be up to date on trending information.
- Join groups of community that suits your personality

### Customizations

- Provides customization for system `layouts` and `appearance`.


# Contributing

- We welcome contributions to Stogram! To contribute, please follow the [Contribution Guidelines](#) for a smooth and collaborative experience.

# License

- This project is licensed under the [GPL-v3 License](LICENSE).

# Acknowledgments

- I extend my appreciation to the open-source community and all contributors especially thos who have contributed, and those who are still contributing to the possibility of this project. Thank you for your support!

> Experience the future of command-line chat applications with Stogram!
> You're really gonna enjoy this
