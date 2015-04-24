# panic!
:collision: A module for kernel panic!

This module is for who want's to test their watchdog's loyalty.

## Get a watchdog

The instruction is based on Debian distribution.

	// Install watchdog
	root@home:# apt-get install watchdog

	// Modify watchdog condig
	root@home:# vim /etc/watchdog

Here, we uncomment `watchdog-device = /dev/watchdog` and default value is exactly our hardware watchdog device `/dev/watchdog`. Then add a line `watchdog-timeout = 5`(if you don't add this line the default value is depends on your HW watchdog's setting). OK, now we have setup a loyalty watchdog for us. Let's try something *dangerous* :smiling_imp:.

## Build panic module

	// Get this repo
	git clone https://github.com/imZack/panic
	// Here we cross compile module to our target, an arm embedded device
	ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi- LINUX_SRC=/src/linux-3.8.13 make
	// Tada~ you will get your panic.o now

## Test

	root@Moxa:~# insmod /home/panic.ko
	Kernel panic - not syncing: Kernel Panic :)

## Alternative (Linux Magic System Request Key Hacks)

Your kernel must compile with `CONFIG_MAGIC_SYSRQ`.

	// Enable sysrq
	root@home:# echo 1 > /proc/sys/kernel/sysrq
	// Send magic key to trigger system crash
	root@home:# echo "c" > /proc/sysrq-trigger

> 'c' - Will perform a system crash by a NULL pointer dereference. A crashdump will be taken if configured.
More magic keys on [Linux Magic System Request Key Hacks](https://www.kernel.org/doc/Documentation/sysrq.txt)

## References

- [watchdog.conf](http://linux.die.net/man/5/watchdog.conf)
- [Forcing a Linux kernel panic](http://borgstrom.ca/2012/10/17/forcing-a-linux-kernel-panic.html)
- [Linux Magic System Request Key Hacks](https://www.kernel.org/doc/Documentation/sysrq.txt)

# License

GPL v2