#!/usr/bin/env bash
# wrapper script for installing or updating the stogram virtual machine
# run the script with sudo priviledge

BIN_PATH="/usr/bin"
SUDOERS_PATH="/etc/sudoers.d"

linux_install()
{
    mkdir -p $BIN_PATH

    # copy source file to bin path
    sudo cp ../machine/stgvm.py $BIN_PATH/stgvm

    # create the service unit
    cat << EOF > \
        $(pkg-config systemd --variable=systemdsystemunitdir)/stgvm.service
# STGVM - Stogram Virtual Machine
# service unit file for STGVM

[Unit]
Description=STGVM - Stogram Virtual Machine
After=network.service

[Service]
ExecStart=$(which sudo) $(which stgvm)
Restart=always
User=$SUDO_USER
Environment="DISPLAY=$DISPLAY"

[Install]
WantedBy=multi-user.target
EOF

    sudo systemctl daemon-reload

    # disable sudo password prompt for stgvm
    sudo echo "$SUDO_USER   ALL=NOPASSWD:$(which stgvm)" > $SUDOERS_PATH/stgvm
    sudo chmod 0440 $SUDOERS_PATH/stgvm
    sudo visudo -c

    sudo systemctl enable stgvm
    sudo systemctl start stgvm
}

linux_install
