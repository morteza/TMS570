#ifndef GIODRIVER_H
#define GIODRIVER_H

/** @struct gioBase
*   @brief GIO Base Register Definition
*
*   This structure is used to access the GIO module egisters.
*/
typedef volatile struct gioBase
{
    unsigned GCR0;      /**< 0x0000: Global Control Register */
    unsigned PWDN;      /**< 0x0004: Power Down Register */
    unsigned INTDET;    /**< 0x0008: Interrupt Detect Regsiter*/
    unsigned POL;       /**< 0x000C: Interrupt Polarity Register */
    unsigned INTENASET; /**< 0x0010: Interrupt Enable Set Register */
    unsigned INTENACLR; /**< 0x0014: Interrupt Enable Clear Register */
    unsigned LVLSET;    /**< 0x0018: Interrupt Priority Set Register */
    unsigned LVLCLR;    /**< 0x001C: Interrupt Priority Clear Register */
    unsigned FLG;       /**< 0x0020: Interrupt Flag Register */
    unsigned OFFSET0;   /**< 0x0024: Interrupt Offset A Register */
    unsigned OFFSET1;   /**< 0x0028: Interrupt Offset B Register */
} gioBASE_t;


/** @struct gioPort
*   @brief GIO Port Register Definition
*/
typedef volatile struct gioPort
{
} gioPORT_t;


/** @def gioREG
*   @brief GIO Register Frame Pointer
*
*   This pointer is used by the GIO driver to access the gio module registers.
*/
#define gioREG   ((gioBASE_t *)0xFFF7BC00U)

/** @def gioPORTA
*   @brief GIO Port (A) Register Pointer
*
*   Pointer used by the GIO driver to access PORTA
*/
#define gioPORTA ((gioPORT_t *)0xFFF7BC34U)

/** @def gioPORTB
*   @brief GIO Port (B) Register Pointer
*
*   Pointer used by the GIO driver to access PORTB
*/
#define gioPORTB ((gioPORT_t *)0xFFF7BC54U)


class GIODriver
{
public:
    GIODriver();

    void init();
    void setDirection(gioPORT_t *port, unsigned dir);
    void setBit(gioPORT_t *port, unsigned bit, unsigned value);
    void setPort(gioPORT_t *port, unsigned value);
    unsigned getBit(gioPORT_t *port, unsigned bit);
    unsigned getPort(gioPORT_t *port);
    void enableNotification(unsigned bit);
    void disableNotification(unsigned bit);
    void notification(int bit);
};

#endif // GIODRIVER_H
