#ifndef _LINUX_FUSIONX_ATTRIBUTES_H
#define _LINUX_FUSIONX_ATTRIBUTES_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>

struct fusionx_attributes {
    int fusionx_kgsl_skip_zeroing;
};

extern struct fusionx_attributes fusionx_data;

#endif /* _LINUX_FUSIONX_ATTRIBUTES_H */