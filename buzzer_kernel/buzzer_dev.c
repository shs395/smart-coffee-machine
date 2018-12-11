#include <linux/fs.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/delay.h>

#define BUZZER 19
#define DEV_NAME "buzzer_dev"
#define DEV_NUM 243

MODULE_LICENSE("GPL");

ssize_t buzzer_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	int msg;

	printk(KERN_ALERT "WRITE buzzer_dev\n");

	if(copy_from_user(&msg, buffer, length)!=0) {
		printk(KERN_ALERT "WRITE ERROR");
		return -1;
	}

	printk("%d\n", msg);
	gpio_set_value(BUZZER, msg);
	return 0;
}

int buzzer_open(struct inode *pinode, struct file *pfile) {
	printk(KERN_ALERT "OPEN buzzer_dev\n");
	return 0;
}

int buzzer_close (struct inode *pinode, struct file *pfile) {
	printk (KERN_ALERT "RELEASE buzzer_dev\n");
	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.write = buzzer_write,
	.open = buzzer_open,
	.release = buzzer_close,
};

int __init buzzer_init(void) {
	printk(KERN_ALERT "INIT buzzer\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	gpio_request(BUZZER, "BUZZER");
	gpio_direction_output(BUZZER, 1);
	return 0;
}
void __exit buzzer_exit(void) {
	printk(KERN_ALERT "EXIT buzzer\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(buzzer_init);
module_exit(buzzer_exit);

