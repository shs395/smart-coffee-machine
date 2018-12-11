#include <linux/fs.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/delay.h>

#define BUTTON 26
#define DEV_NAME "button_dev"
#define DEV_NUM 240

MODULE_LICENSE("GPL");
ssize_t button_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset) {
	int button_value= 0;
	printk(KERN_ALERT "READ button_dev\n");

	button_value = gpio_get_value(BUTTON);
	
	printk(KERN_ALERT "value = %d\n", button_value);
	
	if(copy_to_user(buffer, &button_value, length)) {
		printk(KERN_ALERT "ERROR to COPY TO USER\n");
	}
	return 0;
}


int button_open(struct inode *pinode, struct file *pfile) {
	printk(KERN_ALERT "OPEN button_dev\n");
	return 0;
}

int button_close (struct inode *pinode, struct file *pfile) {
	printk(KERN_ALERT "RELEASE button_dev\n");
	return 0;
}
struct file_operations fop = {
	.owner = THIS_MODULE,
	.read = button_read,
	.open = button_open,
	.release = button_close,
};

int __init button_init(void) {
	printk(KERN_ALERT "INIT button\n");
	register_chrdev(DEV_NUM, DEV_NAME, &fop);
	return 0;
}

void __exit button_exit(void){
	printk(KERN_ALERT "EXIT button\n");
	unregister_chrdev(DEV_NUM, DEV_NAME);
}

module_init(button_init);
module_exit(button_exit);
