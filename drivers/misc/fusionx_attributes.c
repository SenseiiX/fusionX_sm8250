#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/fusionx_attributes.h>

struct fusionx_attributes fusionx_data = {
    .kgsl_skip_zeroing = 0,
};

#define FUSIONX_ATTR_RW(name) \
static ssize_t name##_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf) \
{ \
    return sprintf(buf, "%d\n", fusionx_data.name); \
} \
static ssize_t name##_store(struct kobject *kobj, struct kobj_attribute *attr, const char *buf, size_t count) \
{ \
    int val; \
    if (kstrtoint(buf, 10, &val)) \
        return -EINVAL; \
    fusionx_data.name = val; \
    return count; \
} \
static struct kobj_attribute name##_attr = __ATTR(name, 0644, name##_show, name##_store);

FUSIONX_ATTR_RW(kgsl_skip_zeroing);

static struct attribute *fusionx_attrs[] = {
    &kgsl_skip_zeroing_attr.attr,
    NULL
};

static struct attribute_group fusionx_attr_group = {
    .attrs = fusionx_attrs,
};

static struct kobject *fusionx_kobj;

static int __init fusionx_attributes_init(void) {
    int retval;

    fusionx_kobj = kobject_create_and_add("fusionx_attributes", kernel_kobj);
    if (!fusionx_kobj)
        return -ENOMEM;

    retval = sysfs_create_group(fusionx_kobj, &fusionx_attr_group);
    if (retval)
        kobject_put(fusionx_kobj);

    return retval;
}

static void __exit fusionx_attributes_exit(void) {
    kobject_put(fusionx_kobj);
}

module_init(fusionx_attributes_init);
module_exit(fusionx_attributes_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kvsnr113 <kvsnrprojkt113@gmail.com>");
MODULE_DESCRIPTION("FUSIONX kgsl skip zeroing attribute module");