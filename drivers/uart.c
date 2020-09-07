#include "board.h"
#include "uart.h"
#include "cycfg_peripherals.h"
void uart0_isr_callback(void);
static int psoc6_getc(struct rt_serial_device *device_serial);
/**
 * @addtogroup
 */
/*@{*/

/* RT-Thread Device Interface */
/**
 * This function initializes uart
 */
#if 1
#ifdef RT_USING_UART0
/* UART0 device driver structure */
#define UART0_SCB_IRQ__INTC_NUMBER 46u
cy_stc_scb_uart_context_t UART0_context;
const cy_stc_sysint_t UART0_SCB_IRQ_cfg =
{
    .intrSrc = scb_7_interrupt_IRQn,
    .intrPriority = 3u,
};


struct rt_device uart0_device;

/* UART0 device driver structure */
struct uart_int_rx uart0_int_rx;
struct uart_device uart0_config =
{
	"uart0",
    UART0_HW,
    &UART0_config,
    &UART0_context,
    &UART0_SCB_IRQ_cfg,
    (IRQn_Type)UART0_SCB_IRQ__INTC_NUMBER,
    (IRQn_Type)UART0_SCB_IRQ__INTC_NUMBER,
    &uart0_int_rx,
    RT_NULL
};
/**
 * Uart common interrupt process. This need add to uart ISR.
 *
 * @param serial serial device
 */
static void uart_isr(struct rt_serial_device *device_serial)
{
    struct uart_device *uart;
    volatile uint32_t status = 0;
    RT_ASSERT(device_serial != RT_NULL);
    uart = rt_list_entry(device_serial, struct uart_device, serial);
    status = Cy_SCB_UART_GetRxFifoStatus(uart->scb_device);
    Cy_SCB_UART_ClearRxFifoStatus(uart->scb_device, CY_SCB_RX_INTR_NOT_EMPTY|CY_SCB_RX_INTR_UART_BREAK_DETECT|CY_SCB_UART_RX_TRIGGER);
    status = Cy_SCB_UART_GetRxFifoStatus(uart->scb_device);
    /* Check for receive errors */
    if (status & (CY_SCB_UART_RECEIVE_ERR_FRAME | CY_SCB_UART_RECEIVE_ERR_PARITY))
    {
        /* No need to do it for all errors. Call for UartFrameError will clear all errors */
    	Cy_SCB_UART_ClearRxFifoStatus(uart->scb_device, CY_SCB_UART_RECEIVE_ERR_FRAME | CY_SCB_UART_RECEIVE_ERR_PARITY);
        /* Re-enable FIFO after error */
    	Cy_SCB_UART_ClearRxFifo(uart->scb_device);
    }
    else
    {
    	rt_hw_serial_isr(device_serial, RT_SERIAL_EVENT_RX_IND);
    }
    //Cy_SCB_UART_ClearRxFifoStatus(&uart0_config.serial, CY_SCB_RX_INTR_NOT_EMPTY|CY_SCB_RX_INTR_UART_BREAK_DETECT|CY_SCB_UART_RX_TRIGGER);
}
/* ISR for uart interrupt */
void rt_hw_uart_isr(struct rt_serial_device *device_serial)
{

    /* enter interrupt */
    rt_interrupt_enter();

    uart_isr(&uart0_config.serial);

    /* leave interrupt */
    rt_interrupt_leave();
}




static rt_err_t psoc6_configure(struct rt_serial_device *device_serial, struct serial_configure *cfg)
{
    struct uart_device *uart;
    RT_ASSERT(device_serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);

    uart = rt_list_entry(device_serial, struct uart_device, serial);
    /* Start UART operation. */
    if(Cy_SCB_UART_Init(uart->scb_device, uart->uart_config, uart->uart_context) != CY_SCB_UART_SUCCESS)
    {
        rt_assert_handler("UART0 init", __FUNCTION__, __LINE__);
    }
    Cy_SCB_UART_Enable(uart->scb_device);
    /* Unmasking only the RX fifo not empty interrupt bit */
    uart->scb_device->INTR_RX_MASK = SCB_INTR_RX_MASK_NOT_EMPTY_Msk;
    /* Interrupt Settings for UART */
    Cy_SysInt_Init(uart->uart_int, uart0_isr_callback);
    /* Enable the interrupt */
    NVIC_EnableIRQ(uart->uart_int->intrSrc);
    return RT_EOK;
}
static rt_err_t psoc6_control(struct rt_serial_device *device_serial, int cmd, void *arg)
{
    struct uart_device *uart;

    RT_ASSERT(device_serial != RT_NULL);
    uart = rt_list_entry(device_serial, struct uart_device, serial);

    switch (cmd)
    {
    /* disable interrupt */
    case RT_DEVICE_CTRL_CLR_INT:
        /* disable rx irq */
    	UART_DISABLE_IRQ(uart->rx_irq);
        break;
    /* enable interrupt */
    case RT_DEVICE_CTRL_SET_INT:
        /* enable rx irq */
        UART_ENABLE_IRQ(uart->rx_irq);
        /* enable interrupt */
        break;
    }

    return RT_EOK;
}

static int psoc6_putc(struct rt_serial_device *device_serial, char c)
{
	struct uart_device *uart;
	volatile uint32_t status = 0;
	RT_ASSERT(device_serial != RT_NULL);
	uart = rt_list_entry(device_serial, struct uart_device, serial);
	status = Cy_SCB_UART_GetTxFifoStatus(uart->scb_device);
    /*
     * to be polite with serial console add a line feed
     * to the carriage return character
     */

//	if (status & CY_SCB_TX_INTR_OVERFLOW | CY_SCB_TX_INTR_UNDERFLOW)
//	{
//		Cy_SCB_UART_ClearTxFifoStatus(uart->scb_device, CY_SCB_TX_INTR_OVERFLOW | CY_SCB_TX_INTR_UNDERFLOW);
//		/* Re-enable FIFO after error */
//		Cy_SCB_UART_ClearTxFifo(uart->scb_device);
//	}
//	else
	{
		while(0 == Cy_SCB_UART_Put(uart->scb_device, (c & 0x1FF)));
	}
    Cy_SCB_UART_ClearTxFifoStatus(uart->scb_device, CY_SCB_UART_TX_NOT_FULL| CY_SCB_TX_INTR_OVERFLOW | CY_SCB_TX_INTR_UNDERFLOW);
    return 1;
}

static int psoc6_getc(struct rt_serial_device *device_serial)
{
	int ch, val;
	struct uart_device *uart;
	RT_ASSERT(device_serial != RT_NULL);
	uart = rt_list_entry(device_serial, struct uart_device, serial);
    ch = -1;
	/* polling mode */
    val = Cy_SCB_UART_GetNumInRxFifo(uart->scb_device);
    if (0UL != val)
		ch = Cy_SCB_UART_Get(uart->scb_device);
	Cy_SCB_UART_ClearRxFifoStatus(uart->scb_device, CY_SCB_RX_INTR_NOT_EMPTY|CY_SCB_RX_INTR_UART_BREAK_DETECT|CY_SCB_UART_RX_TRIGGER);
    return ch;
}

static const struct rt_uart_ops psoc6_uart_ops =
{
    .configure = psoc6_configure,
    .control = psoc6_control,
    .putc = psoc6_putc,
    .getc = psoc6_getc,
    .dma_transmit = RT_NULL
};
#endif //0
/* UART0 Interrupt Hanlder */
void uart0_isr_callback(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    rt_hw_uart_isr(&uart0_device);
    /* leave interrupt */
    rt_interrupt_leave();
}
#endif


void rt_hw_uart_init(void)
{
	struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;


	uart0_config.serial.ops    = &psoc6_uart_ops;
	uart0_config.serial.config = config;

    /* register UART0 device */
	rt_hw_serial_register(&uart0_config.serial, \
    					uart0_config.name, \
						RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_INT_TX, \
						NULL);
                          //RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX | RT_DEVICE_FLAG_STREAM,


}

/*@}*/
