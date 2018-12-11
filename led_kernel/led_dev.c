#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/fs.h>

#define GPIO_LED 6
#define DEV_NAME "led_dev"
#define DEV_NUM 290

MODULE_LICENSE("GPL");

int led_open(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "OPEN led_dev\n");
	gpio_request(GPIO_LED, "GPIO_LED");
	gpio_direction_output(GPIO_LED, 1);
	return 0;
}

int led_close(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "RELEASE led_dev\n");
	gpio_direction_output(GPIO_LED,0);
	return 0;
}

struct file_operations fop = {
	.owner = THIS_MODULE,
	.open = led_open,
	.release = led_close,
};

int __init led_init(void){
	printk(KERN_ALERT "INIT led\n");
	register_chrdev(DEV_NUM,DEV_NAME, &fop);
	return 0;
}

void __exit led_exit(void){
	printk(KERN_ALERT "EXIT led\n");
	unregister_chrdev(DEV_NUM,DEV_NAME);
}

module_init(led_init);
module_exit(led_exit);

