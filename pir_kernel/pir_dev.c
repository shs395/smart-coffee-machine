#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/spinlock.h>
#include <linux/version.h>
#include <asm/uaccess.h>

#define DEFAULT_GPIO_TRIGER 13
#define FILE_NUMBER 280
#define FILE_DEVICE "/dev/pir_sensor"

static int gpio_trigger = DEFAULT_GPIO_TRIGER;
/*module_param(gpio_trigger, int , 0644); //var name, var type, permission
static DECLARE_WAIT_QUEUE_HEAD(read_wait_queue);*/
MODULE_LICENSE("GPL"); 


//global method
static int pir_open (struct inode * pinode, struct file * pfile)
{
    printk(KERN_ALERT "%s: open.\n", THIS_MODULE->name);
    return 0;
}
static int pir_release (struct inode * pinode,  struct file * pfile)
{
    printk(KERN_ALERT "%s: release.\n", THIS_MODULE->name);
    return 0;
}
static ssize_t pir_read(struct file * pfile, char * __user buffer, size_t length, loff_t * offset)
{ //send data to user section
  int count;
  int value = 0;

  value = gpio_get_value(gpio_trigger);
  printk("%d\n", value);
  count = copy_to_user(buffer, &value, length);


  return 0;
}


static struct file_operations pir_fops = {
  .owner = THIS_MODULE,
  .open = pir_open,
  .read = pir_read,
  .release = pir_release,
};

int __init pir_init(void){
  gpio_request(gpio_trigger, THIS_MODULE->name);
  gpio_direction_input(gpio_trigger);
 

  printk(KERN_ALERT "INIT pir\n");
  register_chrdev(FILE_NUMBER ,FILE_DEVICE,&pir_fops);
  return 0;
}
void __exit pir_exit(void){
  printk(KERN_ALERT "EXIT pir\n");
  unregister_chrdev(FILE_NUMBER, FILE_DEVICE);
}

module_init(pir_init);
module_exit(pir_exit);
