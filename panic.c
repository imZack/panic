#ifdef __KERNEL__

#include <linux/module.h>
#include <linux/kernel.h>

static int __init panic_init(void)
{
	panic("Kernel Panic :)");
	return 0;
}

static void __exit panic_exit(void)
{
}

module_init(panic_init);
module_exit(panic_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("YuLun Shih");
MODULE_DESCRIPTION("A module for kernel panic!");
#endif