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
	@mkdir -p $(BIN_PATH)
	@cp $< $(BIN_PATH)/$@
	@systemctl daemon-reload
	@systemctl enable $@
	@systemctl start $@
	@systemctl restart $@

# create the stgvm service unit
$(UNIT): unit.sh
	@./$<
	@mv ./stgvm.service $@

$(SUDOERS): sudoers.sh
	@echo $(shell ./sudoers.sh) > $@
	@chmod 0440 $@
	@visudo -cq
