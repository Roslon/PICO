/** _______________________________________________________
*   File:       christmas_tree.c
*   Version:    202212111047
*   Copyright (C) 2022 Robert Roslon <robert@roslon.net>
*   Brief:      Christmas Tree
*   Licence:    Do No Harm License
*   _______________________________________________________
*/
#include <stdio.h>
#include "pico/stdlib.h"

#define LATE 1000U

static uint32_t mask_red=(1 << 15);                             // top of the tree
static uint32_t mask_green=(1 << 16) | (1 << 17);               // second level
static uint32_t mask_yellow=(1<<11) | (1<<12) | (1<<13);        // third level
static uint32_t mask_blue=(1<<6) | (1<<7) | (1<<8) | (1<<9);    // lower level
static uint32_t mask_all= (1<<6) | (1<<7) | (1<<8) | (1<<9) | (1<<11) | (1<<12) | (1<<13) | (1<<15) |(1<<16) | (1<<17);

void blinking_mask(uint32_t, uint8_t);

int main()
{    
    gpio_init_mask(mask_all);
    gpio_set_dir_out_masked(mask_all);
    
    while (1) 
    {       
        blinking_mask(mask_red,2);
        blinking_mask(mask_green,5);
        blinking_mask(mask_yellow,5);
        blinking_mask(mask_blue,5);
        sleep_ms(LATE);
        blinking_mask(mask_all,1);  
    }
    return 0;
}

void blinking_mask(uint32_t mask, uint8_t divider)
{
    gpio_set_mask(mask);
    sleep_ms(LATE/divider);
    gpio_clr_mask(mask);
    sleep_ms(LATE/divider);
}
