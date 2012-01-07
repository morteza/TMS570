/** @file spi.c 
*   @brief SPI Driver Inmplmentation File
*   @date 10.June.2010
*   @version 1.01.000
*
*/

/* (c) Texas Instruments 2009-2010, All rights reserved. */


#include "spi.h"


/** @fn void spiInit(void)
*   @brief Initializes the SPI Driver
*
*   This function initializes the SPI module.
*/
void spiInit(void)
{
    /** @b intalise @b SPI1 */

    /** bring SPI out of reset */
    spiREG1->GCR0 = 1U;

    /** enable SPI1 multibuffered mode and enable buffer RAM */
    spiREG1->MIBSPIE = 1U;

    /** SPI1 master mode and clock configuration */
    spiREG1->GCR1 = (1 << 1)  /* CLOKMOD */
                  | 1;  /* MASTER */

    /** SPI1 enable pin configuration */
    spiREG1->ENAHIGHZ = 0;  /* ENABLE HIGHZ */

    /** - Delays */
    spiREG1->DELAY = (0 << 24)  /* C2TDELAY */
                   | (0 << 16)  /* T2CDELAY */
                   | (0 << 8)  /* T2EDELAY */
                   | 0;  /* C2EDELAY */

    /** - Data Format 0 */
    spiREG1->FMT0 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (1 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 8;  /* data word length */

    /** - Data Format 1 */
    spiREG1->FMT1 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 2 */
    spiREG1->FMT2 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 3 */
    spiREG1->FMT3 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - wait for buffer inialisation complete before accessing MibSPI registers */
    while (spiREG1->BUFINIT) { /* wait */ } 

    /** - inialise transfer groups */
    spiREG1->TGCTRL[0] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (0 << 8);  /* start buffer */

    spiREG1->TGCTRL[1] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (120 << 8);  /* start buffer */

    spiREG1->TGCTRL[2] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0) << 8);  /* start buffer */

    spiREG1->TGCTRL[3] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0) << 8);  /* start buffer */

    spiREG1->TGCTRL[4] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0) << 8);  /* start buffer */

    spiREG1->TGCTRL[5] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0) << 8);  /* start buffer */

    spiREG1->TGCTRL[6] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0+0) << 8);  /* start buffer */

    spiREG1->TGCTRL[7] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0+0+0) << 8);  /* start buffer */

    
    spiREG1->TGCTRL[8] = 120+0+0+0+0+0+0+0 << 8;

    spiREG1->LTGPEND = 120+0+0+0+0+0+0+0-1;

    /** - initalise buffer ram */
    {   int i = 0;

        if (120 > 0)
        {
            while (i < 120-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (1 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_0;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_0;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_1;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_1;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_2;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_2;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_4;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_4;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_5;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_5;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_6;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_6;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0+0+0-1)
            {
                spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_7;  /* chip select */
            }
            spiRAM1->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_7;  /* chip select */
        }
    }

    /** - set interrupt levels */
    spiREG1->LVL = (0 << 9)  /* TXINT */
                 | (0 << 8)  /* RXINT */
                 | (0 << 6)  /* OVRNINT */
                 | (0 << 4)  /* BITERR */
                 | (0 << 3)  /* DESYNC */
                 | (0 << 2)  /* PARERR */
                 | (0 << 1) /* TIMEOUT */
                 | (0);  /* DLENERR */

    /** - clear any pending interrupts */
    spiREG1->FLG = 0xFFFFFFFFU;

    /** - enable interrupts */
    spiREG1->INT0 = (0 << 9)  /* TXINT */
                  | (0 << 8)  /* RXINT */
                  | (0 << 6)  /* OVRNINT */
                  | (0 << 4)  /* BITERR */
                  | (0 << 3)  /* DESYNC */
                  | (0 << 2)  /* PARERR */
                  | (0 << 1) /* TIMEOUT */
                  | (0);  /* DLENERR */

    /** @b initalise @b SPI1 @b Port */

    /** - SPI1 Port output values */
    spiREG1->PCDOUT =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI1 Port direction */
    spiREG1->PCDIR  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI1 Port open drain enable */
    spiREG1->PCPDR  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI1 Port pullup / pulldown selection */
    spiREG1->PCPSL  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - SPI1 Port pullup / pulldown enable*/
    spiREG1->PCDIS  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /* SPI1 set all pins to functional */
    spiREG1->PCFUN  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (1 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - Finaly start SPI1 */
    spiREG1->ENA = 1U;

    /** @b intalise @b SPI3 */

    /** bring SPI out of reset */
    spiREG3->GCR0 = 1U;

    /** enable SPI3 multibuffered mode and enable buffer RAM */
    spiREG3->MIBSPIE = 1U;

    /** SPI3 master mode and clock configuration */
    spiREG3->GCR1 = (1 << 1)  /* CLOKMOD */
                  | 1;  /* MASTER */

    /** SPI3 enable pin configuration */
    spiREG3->ENAHIGHZ = 0;  /* ENABLE HIGHZ */

    /** - Delays */
    spiREG3->DELAY = (0 << 24)  /* C2TDELAY */
                   | (0 << 16)  /* T2CDELAY */
                   | (0 << 8)  /* T2EDELAY */
                   | 0;  /* C2EDELAY */

    /** - Data Format 0 */
    spiREG3->FMT0 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (1 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 1 */
    spiREG3->FMT1 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 2 */
    spiREG3->FMT2 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 3 */
    spiREG3->FMT3 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - wait for buffer inialisation complete before accessing MibSPI registers */
    while (spiREG3->BUFINIT) { /* wait */ } 

    /** - inialise transfer groups */
    spiREG3->TGCTRL[0] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (0 << 8);  /* start buffer */

    spiREG3->TGCTRL[1] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (120 << 8);  /* start buffer */

    spiREG3->TGCTRL[2] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0) << 8);  /* start buffer */

    spiREG3->TGCTRL[3] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0) << 8);  /* start buffer */

    spiREG3->TGCTRL[4] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0) << 8);  /* start buffer */

    spiREG3->TGCTRL[5] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0) << 8);  /* start buffer */

    spiREG3->TGCTRL[6] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0+0) << 8);  /* start buffer */

    spiREG3->TGCTRL[7] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((120+0+0+0+0+0+0) << 8);  /* start buffer */

    
    spiREG3->TGCTRL[8] = 120+0+0+0+0+0+0+0 << 8;

    spiREG3->LTGPEND = 120+0+0+0+0+0+0+0-1;

    /** - initalise buffer ram */
    {   int i = 0;

        if (120 > 0)
        {
            while (i < 120-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_0;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_0;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_1;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_1;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_2;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_2;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_4;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_4;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_5;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_5;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_6;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_6;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 120+0+0+0+0+0+0+0-1)
            {
                spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_7;  /* chip select */
            }
            spiRAM3->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_7;  /* chip select */
        }
    }

    /** - set interrupt levels */
    spiREG3->LVL = (0 << 9)  /* TXINT */
                 | (0 << 8)  /* RXINT */
                 | (0 << 6)  /* OVRNINT */
                 | (0 << 4)  /* BITERR */
                 | (0 << 3)  /* DESYNC */
                 | (0 << 2)  /* PARERR */
                 | (0 << 1) /* TIMEOUT */
                 | (0);  /* DLENERR */

    /** - clear any pending interrupts */
    spiREG3->FLG = 0xFFFFFFFFU;

    /** - enable interrupts */
    spiREG3->INT0 = (0 << 9)  /* TXINT */
                  | (0 << 8)  /* RXINT */
                  | (0 << 6)  /* OVRNINT */
                  | (0 << 4)  /* BITERR */
                  | (0 << 3)  /* DESYNC */
                  | (0 << 2)  /* PARERR */
                  | (0 << 1) /* TIMEOUT */
                  | (0);  /* DLENERR */

    /** @b initalise @b SPI3 @b Port */

    /** - SPI3 Port output values */
    spiREG3->PCDOUT =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI3 Port direction */
    spiREG3->PCDIR  =  1        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI3 Port open drain enable */
    spiREG3->PCPDR  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI3 Port pullup / pulldown selection */
    spiREG3->PCPSL  =  1        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - SPI3 Port pullup / pulldown enable*/
    spiREG3->PCDIS  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /* SPI3 set all pins to functional */
    spiREG3->PCFUN  =  1        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - Finaly start SPI3 */
    spiREG3->ENA = 1U;

    /** @b intalise @b SPI5 */

    /** bring SPI out of reset */
    spiREG5->GCR0 = 1U;

    /** enable SPI5 multibuffered mode and enable buffer RAM */
    spiREG5->MIBSPIE = 1U;

    /** SPI5 master mode and clock configuration */
    spiREG5->GCR1 = (1 << 1)  /* CLOKMOD */
                  | 1;  /* MASTER */

    /** SPI5 enable pin configuration */
    spiREG5->ENAHIGHZ = 0;  /* ENABLE HIGHZ */

    /** - Delays */
    spiREG5->DELAY = (0 << 24)  /* C2TDELAY */
                   | (0 << 16)  /* T2CDELAY */
                   | (0 << 8)  /* T2EDELAY */
                   | 0;  /* C2EDELAY */

    /** - Data Format 0 */
    spiREG5->FMT0 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 1 */
    spiREG5->FMT1 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 2 */
    spiREG5->FMT2 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - Data Format 3 */
    spiREG5->FMT3 = (0 << 24)  /* wdelay */
                  | (0 << 23)  /* parity Polarity */
                  | (0 << 22)  /* parity enable */
                  | (0 << 21)  /* wait on enable */
                  | (0 << 20)  /* shift direction */
                  | (0 << 17)  /* clock polarity */
                  | (0 << 16)  /* clock phase */
                  | (99 << 8) /* baudrate prescale */
                  | 16;  /* data word length */

    /** - wait for buffer inialisation complete before accessing MibSPI registers */
    while (spiREG5->BUFINIT) { /* wait */ } 

    /** - inialise transfer groups */
    spiREG5->TGCTRL[0] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (0 << 8);  /* start buffer */

    spiREG5->TGCTRL[1] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | (8 << 8);  /* start buffer */

    spiREG5->TGCTRL[2] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0) << 8);  /* start buffer */

    spiREG5->TGCTRL[3] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0) << 8);  /* start buffer */

    spiREG5->TGCTRL[4] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0) << 8);  /* start buffer */

    spiREG5->TGCTRL[5] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0) << 8);  /* start buffer */

    spiREG5->TGCTRL[6] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0+0) << 8);  /* start buffer */

    spiREG5->TGCTRL[7] = (1 << 30)  /* oneshot */
                       | (0 << 29)  /* pcurrent reset */
                       | (TRG_ALWAYS << 20)  /* trigger event */
                       | (TRG_DISABLED << 16)  /* trigger source */
                       | ((8+0+0+0+0+0+0) << 8);  /* start buffer */

    
    spiREG5->TGCTRL[8] = 8+0+0+0+0+0+0+0 << 8;

    spiREG5->LTGPEND = 8+0+0+0+0+0+0+0-1;

    /** - initalise buffer ram */
    {   int i = 0;

        if (8 > 0)
        {
            while (i < 8-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_0;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_0;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_1;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_1;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_2;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_2;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_3;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_3;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_4;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_4;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_5;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_5;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_6;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_6;  /* chip select */
        }
        if (0 > 0)
        {
            while (i < 8+0+0+0+0+0+0+0-1)
            {
                spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                         | (1 << 12)  /* hold chip select */
                                         | (0 << 11)  /* lock transmission */
                                         | (0 << 8)  /* data format */
                                         | CS_7;  /* chip select */
            }
            spiRAM5->tx[i++].control = (4 << 13)  /* buffer mode */
                                     | (0 << 12) /* chip select hold */
                                     | (0 << 10)  /* enable WDELAY */
                                     | (0 << 8)  /* data format */
                                     | CS_7;  /* chip select */
        }
    }

    /** - set interrupt levels */
    spiREG5->LVL = (0 << 9)  /* TXINT */
                 | (0 << 8)  /* RXINT */
                 | (0 << 6)  /* OVRNINT */
                 | (0 << 4)  /* BITERR */
                 | (0 << 3)  /* DESYNC */
                 | (0 << 2)  /* PARERR */
                 | (0 << 1) /* TIMEOUT */
                 | (0);  /* DLENERR */

    /** - clear any pending interrupts */
    spiREG5->FLG = 0xFFFFFFFFU;

    /** - enable interrupts */
    spiREG5->INT0 = (0 << 9)  /* TXINT */
                  | (0 << 8)  /* RXINT */
                  | (0 << 6)  /* OVRNINT */
                  | (0 << 4)  /* BITERR */
                  | (0 << 3)  /* DESYNC */
                  | (0 << 2)  /* PARERR */
                  | (0 << 1) /* TIMEOUT */
                  | (0);  /* DLENERR */

    /** @b initalise @b SPI5 @b Port */

    /** - SPI5 Port output values */
    spiREG5->PCDOUT =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI5 Port direction */
    spiREG5->PCDIR  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI5 Port open drain enable */
    spiREG5->PCPDR  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /** - SPI5 Port pullup / pulldown selection */
    spiREG5->PCPSL  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - SPI5 Port pullup / pulldown enable*/
    spiREG5->PCDIS  =  0        /* SCS[0] */
                    | (0 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (0 << 8)  /* ENA */
                    | (0 << 9)  /* CLK */
                    | (0 << 10)  /* SIMO */
                    | (0 << 11); /* SOMI */

    /* SPI5 set all pins to functional */
    spiREG5->PCFUN  =  1        /* SCS[0] */
                    | (1 << 1)  /* SCS[1] */
                    | (0 << 2)  /* SCS[2] */
                    | (0 << 3)  /* SCS[3] */
                    | (1 << 8)  /* ENA */
                    | (1 << 9)  /* CLK */
                    | (1 << 10)  /* SIMO */
                    | (1 << 11); /* SOMI */

    /** - Finaly start SPI5 */
    spiREG5->ENA = 1U;
}


/** @fn void spiSetFunctional(spiBASE_t *spi, unsigned port)
*   @brief Change functional behavoiur of pins at runtime.
*   @param[in] spi   - Spi module base address
*   @param[in] port  - Value to write to PCFUN register
*
*   Change the value of the PCFUN register at runtime, this allows to
*   dynaimcaly change the functionality of the SPI pins between functional
*   and GIO mode.
*/
void spiSetFunctional(spiBASE_t *spi, unsigned port)
{
    spi->PCFUN = port;
}


/** @fn void spiSetData(spiBASE_t *spi, unsigned group, unsigned short data[])
*   @brief Set Buffer Data
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*   @param[in] data  - new data for transfer group
*
*   This function updates the data for the specified transfer group,
*   the length of the data must match the length of the transfer group.
*/
void spiSetData(spiBASE_t *spi, unsigned group, unsigned short data[])
{
    spiRAM_t *ram    = spi == spiREG1 ? spiRAM1 : (spi == spiREG3 ? spiRAM3 : spiRAM5);
    unsigned  start  = (spi->TGCTRL[group] >> 8) & 0xFF;
    unsigned  end    = group == 7 ? (spi->LTGPEND + 1) : (spi->TGCTRL[group+1] >> 8) & 0xFF;

    if (end < start) {end = 128;}

    while (start < end)
    {
        ram->tx[start].data = *data++;
        start++;
    }
}


/** @fn void spiGetData(spiBASE_t *spi, unsigned group, unsigned short data[])
*   @brief Retrieves Buffer Data fro receive buffer
*   @param[in]  spi   - Spi module base address
*   @param[in]  group - Transfer group (0..7)
*   @param[out] data  - pointer to data array
*
*   @return error flags from data buffer, if there was a receive error on
*           one of the buffers this will be rerflected in the return value.
*
*   This function transfers the data from the specified transfer group receve
*   buffers to the data array,  the length of the data must match the length 
*   of the transfer group.
*/
unsigned spiGetData(spiBASE_t *spi, unsigned group, unsigned short data[])
{
    spiRAM_t *ram    = spi == spiREG1 ? spiRAM1 : (spi == spiREG3 ? spiRAM3 : spiRAM5);
    unsigned  start  = (spi->TGCTRL[group] >> 8) & 0xFF;
    unsigned  end    = group == 7 ? (spi->LTGPEND + 1) : (spi->TGCTRL[group+1] >> 8) & 0xFF;
    unsigned  flags  = 0;

    if (end < start) {end = 128;}

    while (start < end)
    {
        flags  |= ram->rx[start].flags;
        *data++ = ram->rx[start].data;
        start++;
    }
    return (flags >> 8) & 0x5F;
}


/** @fn void spiTransfer(spiBASE_t *spi, unsigned group)
*   @brief Transmit Transfer Group
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   Initiates a transfer for the specified transfer group.
*/
void spiTransfer(spiBASE_t *spi, unsigned group)
{
    spi->TGCTRL[group] |= 0x80000000;
}


/** @fn int spiIsTransferComplete(spiBASE_t *spi, unsigned group)
*   @brief Check for Transfer Group Ready
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   @return 1 is transfer complete, otherwise 0.
*
*   Checks to see if the transfer for the specified transfer group
*   has finished.
*/
int spiIsTransferComplete(spiBASE_t *spi, unsigned group)
{
    return (spi->INTFLGRDY >> group) & 1;
}


/** @fn void spiEnableGroupNotification(spiBASE_t *spi, unsigned group, unsigned level)
*   @brief Enable Transfer Group interrupt
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*   @param[in] level - Interrupt level
*
*   This function enables the transfer group finished interrupt.
*/
void spiEnableGroupNotification(spiBASE_t *spi, unsigned group, unsigned level)
{
    if (level)
    {
        spi->SETINTLVLRDY = 1 << group;
    }
    else
    {
        spi->CLRINTLVLRDY = 1 << group;
    }
    spi->SETINTENARDY = 1 << group;
}


/** @fn void spiDisableGroupNotification(spiBASE_t *spi, unsigned group)
*   @brief Disable Transfer Group interrupt
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group (0..7)
*
*   This function disables the transfer group finished interrupt.
*/
void spiDisableGroupNotification(spiBASE_t *spi, unsigned group)
{
    spi->CLRINTENARDY = 1 << group;
}


/** @fn void spi1HighLevelInterrupt(void)
*   @brief Level0 Interrupt for SPI1
*/
#define IRQ __irq
#define FIQ __fiq
IRQ

void spi1HighLevelInterrupt(void)
{
    unsigned vec = spiREG1->INTVECT0;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG1->FLG & (~spiREG1->LVL & 0x035F);
        spiREG1->FLG = flags;
        spiNotification(spiREG1, flags);
    }
    else
    {
        spiGroupNotification(spiREG1, ((vec & 0x3FU) >> 1U) - 1U);
    }
}


/** @fn void spi1LowLevelInterrupt(void)
*   @brief Level1 Interrupt for SPI1
*/
IRQ

void spi1LowLevelInterrupt(void)
{
    unsigned vec = spiREG1->INTVECT1;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG1->FLG & (spiREG1->LVL & 0x035F);
        spiREG1->FLG = flags;
        spiNotification(spiREG1, flags);
    }
    else
    {
        spiGroupNotification(spiREG1, ((vec & 0x3FU) >> 1U) - 1U);
    }
}


/** @fn void spi3HighInterruptLevel(void)
*   @brief Level0 Interrupt for SPI3
*/
IRQ

void spi3HighInterruptLevel(void)
{
    unsigned vec = spiREG3->INTVECT0;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG3->FLG & (~spiREG3->LVL & 0x035F);
        spiREG3->FLG = flags;
        spiNotification(spiREG3, flags);
    }
    else
    {
        spiGroupNotification(spiREG3, ((vec & 0x3FU) >> 1U) - 1U);
    }
}


/** @fn void spi3LowLevelInterrupt(void)
*   @brief Level1 Interrupt for SPI3
*/
IRQ

void spi3LowLevelInterrupt(void)
{
    unsigned vec = spiREG3->INTVECT1;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG3->FLG & (spiREG3->LVL & 0x035F);
        spiREG3->FLG = flags;
        spiNotification(spiREG3, flags);
    }
    else
    {
        spiGroupNotification(spiREG3, ((vec & 0x3FU) >> 1U) - 1U);
    }
}


/** @fn void spi5HighLevelInterrupt(void)
*   @brief Level0 Interrupt for SPI5
*/
IRQ

void spi5HighLevelInterrupt(void)
{
    unsigned vec = spiREG5->INTVECT0;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG5->FLG & (~spiREG5->LVL & 0x035F);
        spiREG5->FLG = flags;
        spiNotification(spiREG5, flags);
    }
    else
    {
        spiGroupNotification(spiREG5, ((vec & 0x3FU) >> 1U) - 1U);
    }
}


/** @fn void spi5LowLevelInterrupt(void)
*   @brief Level1 Interrupt for SPI5
*/
IRQ

void spi5LowLevelInterrupt(void)
{
    unsigned vec = spiREG5->INTVECT1;

    if (vec > 0x100001U)
    {
        unsigned flags = spiREG5->FLG & (~spiREG5->LVL & 0x035F);
        spiREG5->FLG = flags;
        spiNotification(spiREG5, flags);
    }
    else
    {
        spiGroupNotification(spiREG5, ((vec & 0x3FU) >> 1U) - 1U);
    }
}

