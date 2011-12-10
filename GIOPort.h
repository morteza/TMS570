/*
 * GIOPort.h
 *
 *  Created on: Nov 20, 2011
 *      Author: Morteza
 *      Description: GIO Port Register Definition
 */

#ifndef GIOPORT_H_
#define GIOPORT_H_

class GIOPort {
public:
	GIOPort();
	virtual ~GIOPort();

protected:
	uint32_t DIR;    /**< 0x0000: Data Direction Register */
    unsigned DIN;    /**< 0x0004: Data Input Register */
    unsigned DOUT;   /**< 0x0008: Data Output Register */
    unsigned DSET;   /**< 0x000C: Data Output Set Register */
    unsigned DCLR;   /**< 0x0010: Data Output Clear Register */
    unsigned PDR;    /**< 0x0014: Open Drain Register */
    unsigned PULDIS; /**< 0x0018: Pull up Disable Register */
    unsigned PSL;    /**< 0x001C: Pull Up/Down Selection Register */

};

#endif /* GIOPORT_H_ */
