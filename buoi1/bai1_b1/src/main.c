#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOC_CRH     (*(volatile uint32_t *)0x40011004)
#define GPIOC_ODR     (*(volatile uint32_t *)0x4001100C)
void delay_ms(uint32_t t)
{
    volatile unsigned long l=0;
    for (volatile uint32_t i = 0; i < t; i++)
    {
        for(l=0; l<800;l++)
        {}
    }
}
int main(void)
{

    RCC_APB2ENR |= (0x1 << 4);


    GPIOC_CRH &= ~(0x00F00000);
    GPIOC_CRH |=  (0x00300000);

    while (1)
    {
        GPIOC_ODR &= ~(0x1 << 13);
	delay_ms(3000);
	GPIOC_ODR |= (0x1 << 13);
	delay_ms(3000);

       
    }
}
