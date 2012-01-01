/** @file gio.c 
*   @brief Custom TMS570 Board GIO Driver Inmplmentation File
*   @author Morteza <ansarinia@aut.ac.ir>
*   @date November.2011
*   @version 1.0
*
*   (c) AUTSat 2011, All rights reserved.
*/

#include "gio.h"


/** @fn void gioInit(void)
*   @brief Initializes the GIO Driver (Pins A[2] and A[3] are I2C Ports for RTI support)
*/
void gioInit(void)
{
    /** bring GIO module out of reset */
    gioREG->GCR0      = 1;
    gioREG->INTENACLR = 0xFF;
    gioREG->LVLCLR    = 0xFF;              

    /** @b initalise @b Port @b A */

    /** - Port A output values */
    gioPORTA->DOUT =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port A direction */
    gioPORTA->DIR  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (1 << 2)  /* Bit 2 */
                   | (1 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port A open drain enable */
    gioPORTA->PDR  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port A pullup / pulldown selection */
    gioPORTA->PSL  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port A pullup / pulldown enable*/
    gioPORTA->PULDIS  =  0        /* Bit 0 */
                      | (0 << 1)  /* Bit 1 */
                      | (0 << 2)  /* Bit 2 */
                      | (0 << 3)  /* Bit 3 */
                      | (0 << 4)  /* Bit 4 */
                      | (0 << 5)  /* Bit 5 */
                      | (0 << 6)  /* Bit 6 */
                      | (0 << 7); /* Bit 7 */

#if 1
    /** @b initalise @b Port @b B */

    /** - Port B output values */
    gioPORTB->DOUT =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port B direction */
    gioPORTB->DIR  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port B open drain enable */
    gioPORTB->PDR  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port B pullup / pulldown selection */
    gioPORTB->PSL  =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */

    /** - Port B pullup / pulldown enable*/
    gioPORTB->PULDIS  =  0        /* Bit 0 */
                      | (0 << 1)  /* Bit 1 */
                      | (0 << 2)  /* Bit 2 */
                      | (0 << 3)  /* Bit 3 */
                      | (0 << 4)  /* Bit 4 */
                      | (0 << 5)  /* Bit 5 */
                      | (0 << 6)  /* Bit 6 */
                      | (0 << 7); /* Bit 7 */
#endif


    /** @b initalise @b interrupts */

    /** - interrupt polarity */
    gioREG->POL =  0        /* Bit 0 */
                | (0 << 1)  /* Bit 1 */
                | (0 << 2)  /* Bit 2 */
                | (0 << 3)  /* Bit 3 */
                | (0 << 4)  /* Bit 4 */
                | (0 << 5)  /* Bit 5 */
                | (0 << 6)  /* Bit 6 */
                | (0 << 7); /* Bit 7 */

    /** - interrupt level */
    gioREG->LVLSET =  0        /* Bit 0 */
                   | (0 << 1)  /* Bit 1 */
                   | (0 << 2)  /* Bit 2 */
                   | (0 << 3)  /* Bit 3 */
                   | (0 << 4)  /* Bit 4 */
                   | (0 << 5)  /* Bit 5 */
                   | (0 << 6)  /* Bit 6 */
                   | (0 << 7); /* Bit 7 */


    /** - clear all pending interrupts */
    gioREG->FLG = 0xFF;

    /** - enable interrupts */
    gioREG->INTENASET =  0        /* Bit 0 */
                      | (0 << 1)  /* Bit 1 */
                      | (0 << 2)  /* Bit 2 */
                      | (0 << 3)  /* Bit 3 */
                      | (0 << 4)  /* Bit 4 */
                      | (0 << 5)  /* Bit 5 */
                      | (0 << 6)  /* Bit 6 */
                      | (0 << 7); /* Bit 7 */
}


/** @fn void gioSetDirection(gioPORT_t *port, unsigned dir)
*   @brief Set Port Direction
*/
void gioSetDirection(gioPORT_t *port, unsigned dir)
{
    port->DIR = dir;
}


/** @fn void gioSetBit(gioPORT_t *port, unsigned bit, unsigned value)
*   @brief Write Bit
*/
void gioSetBit(gioPORT_t *port, unsigned bit, unsigned value)
{
    if (value)
    {
        port->DSET = 1 << bit;
    }
    else
    {
        port->DCLR = 1 << bit;
    }
}


/** @fn void gioSetPort(gioPORT_t *port, unsigned value)
*   @brief Write Port Value
*/
void gioSetPort(gioPORT_t *port, unsigned value)
{
    port->DOUT = value;
}


/** @fn unsigned gioGetBit(gioPORT_t *port, unsigned bit)
*   @brief Read Bit
*/
unsigned gioGetBit(gioPORT_t *port, unsigned bit)
{
    return (port->DIN >> bit) & 1U;
}


/** @fn unsigned gioGetPort(gioPORT_t *port)
*   @brief Read Port Value
*/
unsigned gioGetPort(gioPORT_t *port)
{
    return port->DIN;
}


/** @fn void gioEnableNotification(unsigned bit)
*   @brief Enable Interrupt
*   @param[in] bit interrupt pin to enable
*              - 0: LSB
*              - 7: MSB
*/
void gioEnableNotification(unsigned bit)
{
    gioREG->INTENASET = 1 << bit;
}


/** @fn void gioDisableNotification(unsigned bit)
*   @brief Disable Interrupt
*   @param[in] bit interrupt pin to enable
*              - 0: LSB
*              - 7: MSB
*/
void gioDisableNotification(unsigned bit)
{
    gioREG->INTENACLR = 1 << bit;
}


/** @fn void gioHighLevelInterrupt(void)
*   @brief GIO Interrupt Handler
*/
#if 0
    #pragma INTERRUPT(gioHighLevelInterrupt, IRQ)
#endif

void gioHighLevelInterrupt(void)
{
    int offset = gioREG->OFFSET0 - 1U;

    if (offset >= 0)
    {
        gioNotification(offset);
    }
}


/** @fn void gioLowLevelInterrupt(void)
*   @brief GIO Interrupt Handler
*/
#if 0
    #pragma INTERRUPT(gioLowLevelInterrupt, IRQ)
#endif

void gioLowLevelInterrupt(void)
{
    int offset = gioREG->OFFSET1 - 1U;

    if (offset >= 0)
    {
        gioNotification(offset);
    }
}

#endif
