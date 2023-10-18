#!/usr/bin/env bash

TARGET=stgvm.service

# create the service unit

cat << EOF > $TARGET
# STGVM - Stogram Virtual Machine
# service unit file for STGVM

[Unit]
Description=STGVM - Stogram Virtual Machine
After=network.service

[Service]
ExecStart=$(which sudo) /usr/bin/stgvm
Restart=always
User=$SUDO_USER
Environment="DISPLAY=$DISPLAY"

[Install]
WantedBy=multi-user.target
EOF
