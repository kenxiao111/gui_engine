/*
 * drv_i2c.h
 *
 *  Created on: Jun 22, 2020
 *      Author: zqli
 */

#ifndef DRIVERS_DRV_I2C_H_
#define DRIVERS_DRV_I2C_H_

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>
#include "cyhal.h"

/*Define I2C Master Pins */
#define mI2C_SDA (P9_1)
#define mI2C_CLK (P9_0)

/*Define I2C Master interrupt priority*/
#define I2C_MASTER_IRQ_PRIORITY	7u

/*Define I2C Master default address and communication frequency*/
#define I2C_MASTER_ADDRESS  0x00
#define I2C_MASTER_FREQUENCY 100000

struct cypress_i2c_bus
{
    struct rt_i2c_bus_device parent;
    struct rt_i2c_msg *msg;
};

rt_err_t rt_hw_i2c_init(void);


#endif /* DRIVERS_DRV_I2C_H_ */
