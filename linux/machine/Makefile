# makefile for building the CORE and SMachine for the Stogram Chat System

# the bin path
BPATH = /usr/local/bin

# sudoers path
SPATH = /etc/sudoers.d

# sudoers file
SFILE = $(SPATH)/smachine

SRC = smachine.py

# unit file
UFILE = $(shell pkg-config systemd --variable=systemdsystemunitdir)/smachine.service

# target file
TARGET = $(BPATH)/smachine

all: $(TARGET)


# copy source file to bin path and rename
$(TARGET): $(SRC) $(UFILE) $(SFILE)
	mkdir -p $(BPATH)
	cp $< $@
	systemctl daemon-reload
	systemctl enable smachine
	@#systemctl start smachine
	systemctl restart smachine

# create the stgvm service unit
$(UFILE): unit.sh
	./$<
	mv ./smachine.service $@

# create the sudoers file and grant necessary permissions
$(SFILE): sudoers.sh
	echo $(shell ./sudoers.sh) > $@
	chmod 0440 $@
	visudo -c

.PHONY: clean

clean:
	-systemctl stop smachine
	-systemctl disable smachine
	-rm -f $(UFILE)
	-rm -f $(SFILE)
	-rm -f $(TARGET)
