# makefile for building the CORE and STGVM for the Stogram Chat System

BIN_PATH=/usr/bin

SUDOERS_PATH=/etc/sudoers.d

SUDOERS=$(SUDOERS_PATH)/stgvm

SRC=stgvm.py

UNIT=$(shell pkg-config systemd --variable=systemdsystemunitdir)/stgvm.service

TARGET=stgvm

all: $(TARGET)


# copy source file to bin path and rename
$(TARGET): $(SRC) $(UNIT) $(SUDOERS)
	@sudo mkdir -p $(BIN_PATH)
	@sudo cp $< $(BIN_PATH)/$@
	@sudo systemctl daemon-reload
	@sudo systemctl enable $@
	@sudo systemctl start $@
	@sudo systemctl restart $@

# create the stgvm service unit
$(UNIT): unit.sh
	@./$<
	@sudo mv ./stgvm.service $@

$(SUDOERS): sudoers.sh
	@sudo echo $(shell ./sudoers.sh) > $@
	@sudo chmod 0440 $@
	@sudo visudo -cq
