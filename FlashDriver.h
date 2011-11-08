#ifndef FLASHDRIVER_H
#define FLASHDRIVER_H

/* Alias names for flash bank power modes
*  This enumeration is used to provide alias names for the flash bank power modes:
*     - sleep
*     - standby
*     - active
*/

enum FlashPowerModes
{
    SYS_SLEEP   = 0U, // Alias for flash bank power mode sleep
    SYS_STANDBY = 1U, // Alias for flash bank power mode standby
    SYS_ACTIVE  = 3U  // Alias for flash bank power mode active
};


/* FlashW Register (Big Endian)
*/
struct FlashRegister
{
    unsigned               : 16U; /* 0x0000 */
    unsigned FRDCNTL       : 16U; /* 0x0000 */
    unsigned               : 16U; /* 0x0004 */
    unsigned FSPRD         : 16U; /* 0x0004 */
    unsigned               : 16U; /* 0x0008 */
    unsigned FEDACCTRL1    : 16U; /* 0x0008 */
    unsigned               : 16U; /* 0x000C */
    unsigned FEDACCTRL2    : 16U; /* 0x000C */
    unsigned               : 16U; /* 0x0010 */
    unsigned FEDACCNT      : 16U; /* 0x0010 */
    unsigned FCERADDR;            /* 0x0014 */
    unsigned               : 16U; /* 0x0018 */
    unsigned FCERRPOSITION : 16U; /* 0x0018 */
    unsigned               : 16U; /* 0x001C */
    unsigned FEDACSTATUS   : 16U; /* 0x001C */
    unsigned FUERRADDR;           /* 0x0020 */
    unsigned FEDACSDIS;           /* 0x0024 */
    unsigned : 32U;               /* 0x0028 */
    unsigned : 32U;               /* 0x002C */
    unsigned               : 16U; /* 0x0030 */
    unsigned FBPROT        : 16U; /* 0x0030 */
    unsigned               : 16U; /* 0x0034 */
    unsigned FBSE          : 16U; /* 0x0034 */
    unsigned               : 16U; /* 0x0038 */
    unsigned FBBUSY        : 16U; /* 0x0038 */
    unsigned               :  8U; /* 0x003C */
    unsigned OTPPROTDIS    :  8U; /* 0x003C */
    unsigned BAGP          :  8U; /* 0x003C */
    unsigned VREADST       :  8U; /* 0x003C */
    unsigned               : 16U; /* 0x0040 */
    unsigned FBFALLBACK    : 16U; /* 0x0040 */
    unsigned               : 16U; /* 0x0044 */
    unsigned FBPRDY        : 16U; /* 0x0044 */
    unsigned               :  6U; /* 0x0048 */
    unsigned PSLEEP        : 10U; /* 0x0048 */
    unsigned               : 15U; /* 0x0048 */
    unsigned PUMPPWR       :  1U; /* 0x0048 */
    unsigned               : 16U; /* 0x004C */
    unsigned FPAC2         : 16U; /* 0x004C */
    unsigned               : 16U; /* 0x0050 */
    unsigned FMAC          : 16U; /* 0x0050 */
    unsigned               : 16U; /* 0x0054 */
    unsigned FMSTAT        : 16U; /* 0x0054 */
    unsigned FEMUDMSW;            /* 0x0058 */
    unsigned FEMUDLSW;            /* 0x005C */
    unsigned               : 16U; /* 0x0060 */
    unsigned FEMUECC       : 16U; /* 0x0060 */
    unsigned               : 16U; /* 0x0064 */
    unsigned FLOCK         : 16U; /* 0x0064 */
    unsigned FENUADDR;            /* 0x0068 */
    unsigned FDIAGCTRL;           /* 0x006C */
    unsigned FRAWDATAH;           /* 0x0070 */
    unsigned FRAWDATAL;           /* 0x0074 */
    unsigned FRAWECC;             /* 0x0078 */
    unsigned FPRIMADDTAG;         /* 0x007C */
    unsigned               : 16U; /* 0x0080 */
    unsigned FVREADCT      : 16U; /* 0x0080 */
    unsigned FVHVCT1;             /* 0x0084 */
    unsigned               : 16U; /* 0x0088 */
    unsigned FVHVCT2       : 16U; /* 0x0088 */
    unsigned               : 16U; /* 0x008C */
    unsigned FVNVCT        : 16U; /* 0x008C */
    unsigned               : 16U; /* 0x0090 */
    unsigned FVPPCT        : 16U; /* 0x0090 */
    unsigned               : 16U; /* 0x0094 */
    unsigned FVWLCT        : 16U; /* 0x0094 */
    unsigned : 32U;               /* 0x0098 */
    unsigned : 32U;               /* 0x009C */
    unsigned FBSTROBES;           /* 0x0100 */
    unsigned               : 16U; /* 0x0104 */
    unsigned FPSTROBES     : 16U; /* 0x0104 */
    unsigned               : 16U; /* 0x0108 */
    unsigned FBMODE        : 16U; /* 0x0108 */
    unsigned               : 16U; /* 0x010C */
    unsigned FTCR          : 16U; /* 0x010C */
    unsigned FADDR;               /* 0x0110 */
    unsigned               : 16U; /* 0x0114 */
    unsigned FWRITE        : 16U; /* 0x0114 */
    unsigned               : 16U; /* 0x0118 */
    unsigned FCBIT_SEL     : 16U; /* 0x0118 */
    unsigned               : 16U; /* 0x011C */
    unsigned FTCTRL        : 16U; /* 0x011C */
    unsigned FWPWRITE0;           /* 0x0120 */
    unsigned FWPWRITE1;           /* 0x0124 */
    unsigned FWPWRITE2;           /* 0x0128 */
    unsigned FWPWRITE3;           /* 0x012C */
    unsigned FWPWRITE4;           /* 0x0130 */
};

/* Flash Wrapper Register Frame Pointer
*  This pointer is used by the system driver to access the flash wrapper registers.
*/

#define FLASH ((volatile struct FlashRegister *)(0xFFF87000U))


#endif // FLASHDRIVER_H
