#include "TMS570Board.h"
#include "FlashDriver.h"

TMS570Board::TMS570Board()
{
}

TMS570Board::init()
{
    // Setup flash read mode, address wait states and data wait states
    FLASH->FRDCNTL =  0x01000000U
                    | (3U << 8U)
                    | (1U << 4U)
                    |  1U;

    // Setup flash bank power modes
    FLASH->FBFALLBACK = (SYS_SLEEP << 14U)
                       | (SYS_SLEEP << 12U)
                       | (SYS_SLEEP << 10U)
                       | (SYS_SLEEP << 8U)
                       | (SYS_ACTIVE << 6U)
                       | (SYS_ACTIVE << 4U)
                       | (SYS_ACTIVE << 2U)
                       |  SYS_ACTIVE;

}
