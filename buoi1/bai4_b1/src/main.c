#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOA_CRH     (*(volatile uint32_t *)0x40010804)
#define GPIOA_CRL     (*(volatile uint32_t *)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)
#define GPIOA_IDR     (*(volatile uint32_t *)0x40010808)
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
	volatile int32_t count=0;
	volatile int32_t v=1;

	RCC_APB2ENR |= 0x00000004;
	GPIOA_CRL &= (~0xFFFFFFFF);
	GPIOA_CRL |= 0x00038000;
	GPIOA_ODR &=~ (0x1 << 0);
	while(1){
		
			if((GPIOA_IDR&(0x1<<3))!=0){
				delay_ms(30);
				if((GPIOA_IDR&(0x1<<3))!=0){
					GPIOA_ODR^=(0x1<<4);
				}
				while((GPIOA_IDR&(0x1<<3))!=0){

				}
			}
		

	}
}
