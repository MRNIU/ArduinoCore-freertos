
# This file is a part of MRNIU/ArduinoCore-freertos (https://github.com/MRNIU/ArduinoCore-freertos).
#
# Makefile for MRNIU/ArduinoCore-freertos.

CURR_DIR := $(shell pwd)
ROOT_DIR := $(CURR_DIR)/../..
include $(ROOT_DIR)/Makefile.env

exclude_dirs := deprecated deprecated-avr-comp
subdirs := $(shell find . -maxdepth 1 -type d)
subdirs := $(basename $(patsubst ./%, %, $(subdirs)))
subdirs := $(filter-out $(exclude_dirs), $(subdirs))
SUB_DIR := $(subdirs)

.PHONY: default
default:
	@echo Entry $(CURR_DIR)
	@$(MAKE) all
	@echo Leave $(CURR_DIR)

.PHONY: all
all: $(SUB_DIR)
	@echo Entry $(CURR_DIR)
	@for subdir in $(SUB_DIR); \
    	do $(MAKE) -C $$subdir all || exit 1; \
    done
	@$(MAKE) $(patsubst %.cpp, %.o, $(wildcard *.cpp))
	@echo Leave $(CURR_DIR)

%.o: %.cpp
	@echo Compiling C++ file $< ...
	@$(CXX) $(CXXFLAGS_ARDUINOCORE_$(MCU)) $< -o $@
	@echo Compiling Done

.PHONY: clean
clean:
	@echo Entry $(CURR_DIR)
	@echo Deleting... $<
	@echo Deleting Completed
	@echo Leave $(CURR_DIR)

.PHONY: info
info:
	@echo Current dir: $(CURR_DIR)
	@echo ARCH: $(ARCH)
	@echo CC: $(CC)
	@echo CFLAGS: $(CFLAGS)
	@echo CXX: $(CXX)
	@echo CXXFLAGS: $(CXXFLAGS)
	@echo LD: $(LD)
	@echo LDFLAGS: $(LDFLAGS)
	@echo AS: $(AS)
	@echo ASFLAGS: $(ASFLAGS)
	@echo exclude_dirs: $(exclude_dirs)
	@echo SUBDIRS: $(SUB_DIR)
