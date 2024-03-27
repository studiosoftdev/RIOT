/*
 * Copyright (C) 2023 Otto-von-Guericke-Universität Magdeburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include "board.h"
#include "periph/i2c.h"
#include "vcnl40x0.h"
//#include "xtimer.h"


int main(void)
{
    //blink if read bytes non-zero
    vcnl40x0_params_t initParams = {1, 0, 0, 0, 0, 0};
    vcnl40x0_t dev = {initParams};

    uint8_t status = vcnl40x0_init(&dev, &initParams);
    if(status == 0){
        printf("Successfully initalised vcnl40x0 !");
        gpio_init(26, GPIO_OUT);
        for(int j = 0; j < 1000; j++){
            for(long unsigned int i = 0; i < 100 * MHZ(1); i++){
                    __asm("");
            }
            gpio_set(26);
            for(long unsigned int i = 0; i < 100 * MHZ(1); i++){
                    __asm("");
            }
            gpio_clear(26);
        }
        /* send something out gpio pins ? to read value ?
        while(1){
            gpio_set(26);
            for(long unsigned int i = 0; i < 10*KHZ(1); i++){
                cycle++;
            }
            gpio_clear(26);
            for(long unsigned int i = 0; i < 10*KHZ(1); i++){
                cycle--;
            }
            gpio_set(26);
        }*/
        

    }
}
