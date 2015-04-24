obj-m := panic.o
# LINUX_SRC := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(LINUX_SRC) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) -C $(LINUX_SRC) M=$(PWD) clean
