/*code creater by :      Ahmed Maher
 *Matriculation Number : 2502300
 */

#include "inc/tm4c1294ncpdt.h"
#include <stdint.h>
#include <stdio.h>


void main(void)
{
    //int i; // => counter

    SYSCTL_RCGCGPIO_R |= 0x00001120 ;//=> initial the CLK for portF and portN (0000 0001(for N) 0001(J) 001(for F)0 0000)2

    // wait until the port is available
    while((SYSCTL_RCGCGPIO_R & 0x00001120) == 0); //

    GPIO_PORTN_DEN_R = 0x03; // => Digital enable pins(0,1) for portN --> D2 & D1.
    GPIO_PORTN_DIR_R = 0x03; // => set the direction for pins(0,1) for portN as output. --> D2 & D1.

    GPIO_PORTF_AHB_DEN_R = 0x11; // => Digital enable pins(0,4) for portF --> D3 & D4.
    GPIO_PORTF_AHB_DIR_R = 0x11; // => set the direction for pins(0,1) for portF as output. --> D2 & D1.

    GPIO_PORTJ_AHB_DEN_R = 0x03; // => Digital enable pins(0) for portF. --> SW1.
    GPIO_PORTJ_AHB_DIR_R = 0x00; // => set the direction for pins(0) for portJ as input--> SW1.


    GPIO_PORTJ_AHB_DATA_R = 0x03; //fill in the data register for PJ0(switch user) with 1.
    GPIO_PORTJ_AHB_PUR_R = 0x03;  // WUP for PJ0, PJ1 -->> US1, US2.

    int i;

    while(1)
    {
        if (GPIO_PORTJ_AHB_DATA_R == 0x02)
               {
                    GPIO_PORTN_DATA_R = 0x02;    // => D1 is on.
                    for( i = 0; i < 500000; i++); // => Delay

                    GPIO_PORTN_DATA_R ^= 0x03; // => D2 is on, D1 is off
                    for( i = 0; i < 500000; i++); // => Delay.

                    GPIO_PORTN_DATA_R ^= 0x01; // => D2 is off, D1 is off
                }
                else if (GPIO_PORTJ_AHB_DATA_R == 0x01)
                {
                    GPIO_PORTF_AHB_DATA_R = 0x10; // => D3 is on, D4 is off
                    for( i = 0; i < 500000; i++); // => Delay

                    GPIO_PORTF_AHB_DATA_R ^= 0x11; // => D4 is on, D3 is off
                    for( i = 0; i < 500000; i++); // => Delay.

                    GPIO_PORTF_AHB_DATA_R ^= 0x01; // => D4 is off, D3 is off
                }
                else if (GPIO_PORTJ_AHB_DATA_R == 0x00)
                {
                    GPIO_PORTN_DATA_R = 0x02;    // => D1 is on,D2 is off
                    GPIO_PORTF_AHB_DATA_R = 0x10; // => D3 is on, D4 is off
                    for( i = 0; i < 500000; i++); // => Delay.

                    GPIO_PORTN_DATA_R ^= 0x03; // => D2 is on, D1 is off
                    GPIO_PORTF_AHB_DATA_R ^= 0x11; // => D4 is on, D3 is off
                    for( i = 0; i < 500000; i++); // => Delay.

                    GPIO_PORTN_DATA_R ^= 0x01; // => D2 is off, D1 is off
                    GPIO_PORTF_AHB_DATA_R ^= 0x01; // => D4 is off, D3 is off

                }
    }

}
