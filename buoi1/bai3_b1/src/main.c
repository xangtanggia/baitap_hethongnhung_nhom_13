#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOA_CRH     (*(volatile uint32_t *)0x40010804)
#define GPIOA_CRL     (*(volatile uint32_t *)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)
#define GPIOA_IDR     (*(volatile uint32_t *)0x40010808)
#define GPIOB_CRH     (*(volatile uint32_t *)0x40010C04)
#define GPIOB_ODR     (*(volatile uint32_t *)0x40010C0C)
//code nay thay 3 chan pa13,pa14,pa15 bang pb13,pb14,pb15; ly do: bi trung day noi st-link
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
	RCC_APB2ENR |= 0x0000000C;
	GPIOA_CRH &= (~0x000FFFFF);
	GPIOA_CRH |= 0x00033333;
	GPIOA_CRL &= (~0xFFFFFFFF);
	GPIOA_CRL |= 0x88888888;
	GPIOB_CRH &= (~0xFFF00000);
	GPIOB_CRH |= 0x33300000;
	GPIOA_ODR |= (0xFF);
	while(1){
        uint8_t x = ~(GPIOA_IDR & 0xFF);

        GPIOA_ODR = (GPIOA_ODR & 0xE0FF) | ((x & 0x1F) << 8);
        GPIOB_ODR = (GPIOB_ODR & 0x1FFF) | ((x & 0xE0) << 8);

	}
}
