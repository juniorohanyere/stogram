# makefile for building the CORE and SMachine for the Stogram Chat System

BIN_PATH=/usr/bin

SUDOERS_PATH=/etc/sudoers.d

SUDOERS=$(SUDOERS_PATH)/smachine

SRC=smachine.py

UNIT=$(shell pkg-config systemd --variable=systemdsystemunitdir)/smachine.service

TARGET=$(BIN_PATH)/smachine

all: $(TARGET)


# copy source file to bin path and rename
$(TARGET): $(SRC) $(UNIT) $(SUDOERS)
	mkdir -p $(BIN_PATH)
	cp $< $@
	systemctl daemon-reload
	systemctl enable smachine
	systemctl start smachine
	systemctl restart smachine

# create the stgvm service unit
$(UNIT): unit.sh
	./$<
	mv ./smachine.service $@

$(SUDOERS): sudoers.sh
	echo $(shell ./sudoers.sh) > $@
	chmod 0440 $@
	visudo -c

.PHONY: clean

clean:
	sudo rm $(UNIT)
	sudo rm $(SUDOERS)
	sudo rm $(TARGET)
