#include "GIODriver.h"

GIODriver::GIODriver()
{

}

GIODriver::init()
{
    // bring GIO module out of reset
    gioREG->GCR0      = 1;
    gioREG->INTENACLR = 0xFF;
    gioREG->LVLCLR    = 0xFF;

}

GIODriver::setDirection(gioPORT_t *port, unsigned dir)
{
    port.DIR = dir;
}
