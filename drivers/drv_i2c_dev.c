/*
 * drv_i2c.c
 *
 *  Created on: Jun 22, 2020
 *      Author: zqli
 */

#include "drv_i2c.h"

/*rt-thread i2c master communication interface APIs*/
rt_size_t cypress_master_xfer (struct rt_i2c_bus_device *bus,struct rt_i2c_msg msgs[], rt_uint32_t num);
rt_size_t cypress_Slave_xfer (struct rt_i2c_bus_device *bus,struct rt_i2c_msg msgs[], rt_uint32_t num);
rt_err_t cypress_i2c_bus_control(struct rt_i2c_bus_device *bus, rt_uint32_t cmd, rt_uint32_t arg);

/*define i2c master base and configure struct*/
cyhal_i2c_t mI2C;
cyhal_i2c_cfg_t mI2C_cfg;

/*define the rt-thread i2c interface APIs ops*/
static const struct rt_i2c_bus_device_ops cypress_i2c_ops =
{
		cypress_master_xfer,
		cypress_Slave_xfer,
		cypress_i2c_bus_control,
};

/*i2c master interrupt event handle*/
void master_event_handler(void *callback_arg, cyhal_i2c_event_t event)
{
    /* To remove unused variable warning */
    (void) callback_arg;
    /* Check master write complete event */
    if (0UL != (CYHAL_I2C_MASTER_WR_CMPLT_EVENT & event))
    {
        /* Perform the required functions */
    }
    /* Check master read complete event */
    if (0UL != (CYHAL_I2C_MASTER_RD_CMPLT_EVENT & event))
    {
        /* Perform the required functions */
    }
    /* Check for errors */
    if (0UL == (CYHAL_I2C_MASTER_ERR_EVENT & event))
    {
        /* Perform the required function */
    }
}

/*Initial the i2c master*/
cy_rslt_t cy_initial_i2c_master()
{
		/* Declare variables */
	    cy_rslt_t rslt;

	    /*configure the i2c master parameters*/
	    mI2C_cfg.is_slave = false;
	    mI2C_cfg.address = I2C_MASTER_ADDRESS;
	    mI2C_cfg.frequencyhal_hz = I2C_MASTER_FREQUENCY;

	    /* Initialize I2C master, set the SDA and SCL pins and assign a new clock */
	    rslt = cyhal_i2c_init(&mI2C, mI2C_SDA, mI2C_CLK , NULL);
	    /* Configure the I2C resource to be master */
	    rslt = cyhal_i2c_configure(&mI2C, &mI2C_cfg);

	    /*register the i2c master event callback*/
	    cyhal_i2c_register_callback(&mI2C, (cyhal_i2c_event_callback_t) master_event_handler, NULL);
	    cyhal_i2c_enable_event(&mI2C, (cyhal_i2c_event_t)   \
	                                     (CYHAL_I2C_MASTER_WR_CMPLT_EVENT \
	                                    | CYHAL_I2C_MASTER_RD_CMPLT_EVENT \
	                                    | CYHAL_I2C_MASTER_ERR_EVENT),    \
										I2C_MASTER_IRQ_PRIORITY , true);

	    return rslt;
}

rt_size_t cypress_master_xfer (struct rt_i2c_bus_device *bus,struct rt_i2c_msg msgs[], rt_uint32_t num)
{
	cy_en_scb_i2c_status_t status = CY_SCB_I2C_SUCCESS;
	static struct cypress_i2c_bus i2cbus ;

	uint16_t  dev_addr;		/*Slave address*/
	uint16_t len;			/*data length*/
	uint16_t flags;			/*I2C read or write control flags*/
	uint8_t *msgbuf;		/*transfer datas*/

	uint32_t timeout = 0;
	bool send_stop = true;

	i2cbus.msg = msgs;
	dev_addr = i2cbus.msg->addr;
	len = i2cbus.msg->len;
	flags = i2cbus.msg->flags;
	msgbuf = i2cbus.msg->buf;

	if(flags == RT_I2C_RD)	/*read from i2c slave*/
	{
	status = cyhal_i2c_master_read(&mI2C, dev_addr, (uint8_t *)msgbuf, len, timeout , send_stop);
	}
	else
	if(flags == RT_I2C_WR) /*write to i2c slave*/
	{
	status = cyhal_i2c_master_write(&mI2C, dev_addr, (uint8_t *)msgbuf, len, timeout , send_stop);
	}
	return status;
}

rt_size_t cypress_Slave_xfer (struct rt_i2c_bus_device *bus,struct rt_i2c_msg msgs[], rt_uint32_t num)
{
	return 0;
}

rt_err_t cypress_i2c_bus_control(struct rt_i2c_bus_device *bus,
                                                  rt_uint32_t cmd,
                                                  rt_uint32_t arg)
{
     return RT_ERROR;
}

/*i2c master hardware initial and register to rt-thread drive device*/
rt_err_t rt_hw_i2c_init()
{
	static struct cypress_i2c_bus pi2c;

	pi2c.parent.ops = &cypress_i2c_ops;

	/*cypress HAL APIs to initial the i2c hardware*/
	cy_initial_i2c_master();

	return rt_i2c_bus_device_register(&pi2c.parent, "i2c");

}


