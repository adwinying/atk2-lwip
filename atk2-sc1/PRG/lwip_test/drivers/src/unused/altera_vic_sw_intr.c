/******************************************************************************
*                                                                             *
* License Agreement                                                           *
*                                                                             *
* Copyright (c) 2009 Altera Corporation, San Jose, California, USA.           *
* All rights reserved.                                                        *
*                                                                             *
* Permission is hereby granted, free of charge, to any person obtaining a     *
* copy of this software and associated documentation files (the "Software"),  *
* to deal in the Software without restriction, including without limitation   *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,    *
* and/or sell copies of the Software, and to permit persons to whom the       *
* Software is furnished to do so, subject to the following conditions:        *
*                                                                             *
* The above copyright notice and this permission notice shall be included in  *
* all copies or substantial portions of the Software.                         *
*                                                                             *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE *
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         *
* DEALINGS IN THE SOFTWARE.                                                   *
*                                                                             *
* This agreement shall be governed in all respects by the laws of the State   *
* of California and by the laws of the United States of America.              *
*                                                                             *
******************************************************************************/
#include "altera_vic_irq.h"
#include "altera_vic_regs.h"


/** @Function Description:  This function sets the software trigger for single
  *                         interrupt.
  * @API Type:              External
  * @param ic_id            The interrupt controller ID.
  * @param irq              IRQ number
  * @return                 0 if successful, else error (-1)
  */
int alt_vic_sw_interrupt_set(alt_u32 ic_id, alt_u32 irq)
{
    alt_vic_dev* pdev;

    if(ic_id >= ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS)
        return -1;

    /* Get VIC handle */
    pdev = alt_vic_dev_list[ic_id];

    if(irq < pdev->num_of_intr_ports)
    {
        IOWR_ALTERA_VIC_SW_INTERRUPT_SET(pdev->base, 1 << irq);
        return 0;
    }

    return -1;
}

/** @Function Description:  This function clears the software trigger for
  *                         single interrupt.
  * @API Type:              External
  * @param ic_id            The interrupt controller ID.
  * @param irq              IRQ number
  * @return                 0 if successful, else error (-1)
  */
int alt_vic_sw_interrupt_clear(alt_u32 ic_id, alt_u32 irq)
{
    alt_vic_dev* pdev;

    if(ic_id >= ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS)
        return -1;

    /* Get VIC handle */
    pdev = alt_vic_dev_list[ic_id];

    if(irq < pdev->num_of_intr_ports)
    {
        IOWR_ALTERA_VIC_SW_INTERRUPT_CLR(pdev->base, 1 << irq);
        return 0;
    }

    return -1;
}

/** @Function Description:  This function checks software trigger status for
  *                         single interrupt.
  * @API Type:              External
  * @param ic_id            The interrupt controller ID.
  * @param irq              IRQ number
  * @return                 zero if corresponding software trigger interrupt
  *                         is disabled and non-zero otherwise.
  */
alt_u32 alt_vic_sw_interrupt_status(alt_u32 ic_id, alt_u32 irq)
{
    alt_u32 enabled;
    alt_vic_dev* pdev;

    if(ic_id >= ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS)
        return 0;

    /* Get VIC handle */
    pdev = alt_vic_dev_list[ic_id];

    if(irq < pdev->num_of_intr_ports)
    {
        enabled = IORD_ALTERA_VIC_SW_INTERRUPT(pdev->base);
        return (enabled & (1 << irq)) ? 1 : 0;
    }

    return 0;
}

