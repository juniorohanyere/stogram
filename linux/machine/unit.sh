#!/usr/bin/env bash

TARGET=smachine.service

# create the service unit

cat << EOF > $TARGET
# SMachine - Stogram Virtual Machine
# service unit file for SMachine

[Unit]
Description=SMachine - Stogram Virtual Machine
After=network.service

[Service]
ExecStart=$(which sudo) /usr/local/bin/smachine
Restart=always
User=$SUDO_USER
Environment="DISPLAY=$DISPLAY"

[Install]
WantedBy=multi-user.target
EOF
