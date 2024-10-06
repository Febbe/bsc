PWD:=$(shell pwd)
TOP:=$(PWD)/../..
PREFIX?=$(TOP)/inst

.PHONY: all
all: install

.PHONY: install
install:
	cmake -B build -S . -DCMAKE_INSTALL_PREFIX=$(PREFIX)
	cmake --build build --target install
	
.PHONY: clean
clean:
	rm -rf build

.PHONY: full_clean
full_clean: clean

TAGS:	*.h *.c *.cxx
	etags *.h *.c *.cxx
