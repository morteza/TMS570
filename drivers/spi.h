/** @file spi.h
*   @brief SPI Driver Definition File
*   @date 11.August.2009
*   @version 1.01.000
*   
*/

/* (c) Texas Instruments 2009-2010, All rights reserved. */


#ifndef __SPI_H__
#define __SPI_H__

#include "gio.h"


/** @enum triggerEvent
*   @brief Transfer Group Trigger Event
*/
enum triggerEvent
{
    TRG_NEVER   = 0,
    TRG_RISING  = 1,
    TRG_FALLING = 2,
    TRG_BOTH    = 3,
    TRG_HIGH    = 5,
    TRG_LOW     = 6,
    TRG_ALWAYS  = 7
};


/** @enum triggerSource
*   @brief Transfer Group Trigger Source
*/
enum triggerSource
{
    TRG_DISABLED,
    TRG_GIOA0,
    TRG_GIOA1,
    TRG_GIOA2,
    TRG_GIOA3,
    TRG_GIOA4,
    TRG_GIOA5,
    TRG_GIOA6,
    TRG_GIOA7,
    TRG_HET8,
    TRG_HET10,
    TRG_HET12,
    TRG_HET14,
    TRG_HET16,
    TRG_HET18,
    TRG_TICK
};


/** @enum chipSelect
*   @brief Transfer Group Chip Select
*/
enum chipSelect
{
    CS_NONE = 0xFF,
    CS_0    = 0xFE,
    CS_1    = 0xFD,
    CS_2    = 0xFB,
    CS_3    = 0xF7,
    CS_4    = 0xEF,
    CS_5    = 0xDF,
    CS_6    = 0xBF,
    CS_7    = 0x7F
};


/** @struct spiBase
*   @brief SPI Register Definition
*
*   This structure is used to access the SPI module egisters.
*/
/** @typedef spiBASE_t
*   @brief SPI Register Frame Type Definition
*
*   This type is used to access the SPI Registers.
*/
typedef volatile struct spiBase
{
    unsigned  GCR0;                 /**< 0x0000: Global Control 0 */
    unsigned                :  7U;  
    unsigned  ENA           :  1U;  /**< 0x0004: SPI Enable bit */
    unsigned                :  7U;
    unsigned  LB            :  1U;  /**< 0x0005: Loop back bit */
    unsigned                :  7U;
    unsigned  PD            :  1U;  /**< 0x0006: Power down bit */
    unsigned  GCR1          :  8U;  /**< 0x0007: Global Control 1 */
    unsigned                :  7U;
    unsigned  ENAHIGHZ      :  1U;  /**< 0x0008: Enable HIGHZ outputs */
    unsigned                :  7U;
    unsigned  DMAREQEN      :  1U;  /**< 0x0009: DMA Request enable */
    unsigned  INT0          : 16U;  /**< 0x000A: Interrupt Enable bits */
    unsigned  LVL;                  /**< 0x000C: Interrupt Level */
    unsigned                :  7U;
    unsigned  BUFINIT       :  1U;  /**< 0x0010: Buffer inialisation active flag */
    unsigned                :  8U;
    unsigned  FLG           : 16U;  /**< 0x0012: Interrupt flags */
    unsigned  PCFUN;                /**< 0x0014: Function Pin Enable */
    unsigned  PCDIR;                /**< 0x0018: Pin Direction */
    unsigned  PCDIN;                /**< 0x001C: Pin Input Latch */
    unsigned  PCDOUT;               /**< 0x0020: Pin Output Latch */
    unsigned  PCSET;                /**< 0x0024: Output Pin Set */
    unsigned  PCCLR;                /**< 0x0028: Output Pin Clr */
    unsigned  PCPDR;                /**< 0x002C: Open Drain Output Enable */
    unsigned  PCDIS;                /**< 0x0030: Pullup/Pulldown Disable */
    unsigned  PCPSL;                /**< 0x0034: Pullup/Pulldown Selection */
    unsigned  DAT0;                 /**< 0x0038: Transmit Data */
    unsigned  DAT1;                 /**< 0x003C: Transmit Data with Format and Chip Select */
    unsigned  BUF;                  /**< 0x0040: Receive Buffer */
    unsigned  EMU;                  /**< 0x0044: Emulation Receive Buffer */
    unsigned  DELAY;                /**< 0x0048: Delays */
    unsigned  CSDEF;                /**< 0x004C: Default Chip Select */
    unsigned  FMT0;                 /**< 0x0050: Data Format 0 */
    unsigned  FMT1;                 /**< 0x0054: Data Format 1 */
    unsigned  FMT2;                 /**< 0x0058: Data Format 2 */
    unsigned  FMT3;                 /**< 0x005C: Data Format 3 */
    unsigned  INTVECT0;             /**< 0x0060: Interrupt Vector 0 */
    unsigned  INTVECT1;             /**< 0x0064: Interrupt Vector 1 */
    unsigned  SRSEL;                /**< 0x0068: Slew Rate Select */
    unsigned  PMCTRL;               /**< 0x006C: Parrallel Mode Control */
    unsigned  RAMACCESS     : 16U;  /**< 0x0070: RX Ram Write Access Enable */
    unsigned  MIBSPIE       : 16U;  /**< 0x0072: MibSPI Enable */
    unsigned  SETINTENARDY  : 16U;  /**< 0x0074: Transfer Group Interrupt Enable Set Register */
    unsigned  SETINTENASUS  : 16U;
    unsigned  CLRINTENARDY  : 16U;  /**< 0x0078: Transfer Group Interrupt Enable Clear Register */
    unsigned  CLRINTENASUS  : 16U;
    unsigned  SETINTLVLRDY  : 16U;  /**< 0x007C: Transfer Group Interrupt Level Set Register */
    unsigned  SETINTLVLSUS  : 16U;
    unsigned  CLRINTLVLRDY  : 16U;  /**< 0x0080: Transfer Group Interrupt Level Clear Register */
    unsigned  CLRINTLVLSUS  : 16U;
    unsigned  INTFLGRDY     : 16U;  /**< 0x0084: Transfer Group Interrupt Flags */
    unsigned  INTFLGSUS     : 16U;
    unsigned                : 32U;
    unsigned                : 32U;
    unsigned  TICKCNT;              /**< 0x0090: Tick Counter */
    unsigned                :  3U;
    unsigned  TGINSERVICE   :  5U;
    unsigned                :  9U;
    unsigned  LTGPEND       :  7U;  /**< 0x0096: Transfer Group End Pointer */
    unsigned                :  8U;
    unsigned  TGCTRL[16U];          /**< 0x0098: Transfer Group Control */
    unsigned  DMACTRL[8U];
    unsigned  DMACOUNT[8U];
    unsigned  DMACNTLEN;
    unsigned                : 32U;
    unsigned                : 23U;
    unsigned  PTESTEN       :  1U;
    unsigned                :  4U;
    unsigned  EDEN          :  4U;
    unsigned  UERRSTAT;
    unsigned  UERRADDRRX;
    unsigned  UERRADDRTX;
    unsigned  RXOVRN_BUF_ADDR;
    unsigned  IOLPKTSTCR;
} spiBASE_t;


/** @def spiREG1
*   @brief SPI1 Register Frame Pointer
*
*   This pointer is used by the SPI driver to access the spi module registers.
*/
#define spiREG1 ((spiBASE_t *)0xFFF7F400U)


/** @def spiPORT1
*   @brief SPI1 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of SPI1
*   (use the GIO drivers to access the port pins).
*/
#define spiPORT1 ((gioPORT_t *)0xFFF7F418U)


/** @def spiREG3
*   @brief SPI3 Register Frame Pointer
*
*   This pointer is used by the SPI driver to access the spi module registers.
*/
#define spiREG3 ((spiBASE_t *)0xFFF7F800U)


/** @def spiPORT3
*   @brief SPI3 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of SPI3
*   (use the GIO drivers to access the port pins).
*/
#define spiPORT3 ((gioPORT_t *)0xFFF7F818U)


/** @def spiREG5
*   @brief SPI5 Register Frame Pointer
*
*   This pointer is used by the SPI driver to access the spi module registers.
*/
#define spiREG5 ((spiBASE_t *)0xFFF7FC00U)


/** @def spiPORT5
*   @brief SPI5 GIO Port Register Pointer
*
*   Pointer used by the GIO driver to access I/O PORT of SPI5
*   (use the GIO drivers to access the port pins).
*/
#define spiPORT5 ((gioPORT_t *)0xFFF7FC18U)


/** @struct spiRamBase
*   @brief SPI Buffer RAM Definition
*
*   This structure is used to access the SPI buffer memory.
*/
/** @typedef spiRAM_t
*   @brief SPI RAM Type Definition
*
*   This type is used to access the SPI RAM.
*/
typedef volatile struct spiRamBase
{
    struct 
    {
        unsigned short control;  /**< tx buffer control */
        unsigned short data;     /**< tx buffer data */
    } tx[128];
    struct
    {
        unsigned short flags;    /**< rx buffer flags */
        unsigned short data;     /**< rx buffer data */
    } rx[128];
} spiRAM_t;


/** @def spiRAM1
*   @brief SPI1 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM1 ((spiRAM_t *)0xFF0E0000U)


/** @def spiRAM3
*   @brief SPI3 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM3 ((spiRAM_t *)0xFF0C0000U)


/** @def spiRAM5
*   @brief SPI5 Buffer RAM Pointer
*
*   This pointer is used by the SPI driver to access the spi buffer memory.
*/
#define spiRAM5 ((spiRAM_t *)0xFF0A0000U)


/* SPI Interface Functions */
void spiInit(void);
void spiSetFunctional(spiBASE_t *spi, unsigned port);
void spiSetData(spiBASE_t *spi, unsigned group, unsigned short data[]);
unsigned spiGetData(spiBASE_t *spi, unsigned group, unsigned short data[]);
void spiTransfer(spiBASE_t *spi, unsigned group);
int  spiIsTransferComplete(spiBASE_t *spi, unsigned group);
void spiEnableGroupNotification(spiBASE_t *spi, unsigned group, unsigned level);
void spiDisableGroupNotification(spiBASE_t *spi, unsigned group);


/** @fn void spiNotification(spiBASE_t *spi, unsigned flags)
*   @brief Error interrupt callback
*   @param[in] spi   - Spi module base address
*   @param[in] flags - Copy of error interrupt flags
*
* This is a error callback that is provided by the application and is call apon
* an error interrupt.  The paramer passed to the callback is a copy of the error
* interrupt flag register.
*/
void spiNotification(spiBASE_t *spi, unsigned flags);


/** @fn void spiGroupNotification(spiBASE_t *spi, unsigned group)
*   @brief Transfer complete notification callback
*   @param[in] spi   - Spi module base address
*   @param[in] group - Transfer group
*
* This is a callback function provided by the application.  It is call when
* a transfer is complete.  The paramter is the transfer group that triggered
* the interrupt.
*/
void spiGroupNotification(spiBASE_t *spi, unsigned group);

#endif
