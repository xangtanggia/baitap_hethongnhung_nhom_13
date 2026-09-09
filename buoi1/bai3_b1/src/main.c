#include <stdint.h>

#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOA_CRH     (*(volatile uint32_t *)0x40010804)
#define GPIOA_CRL     (*(volatile uint32_t *)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)
#define GPIOA_IDR     (*(volatile uint32_t *)0x40010808)
#define AFIO_MAPR (*(volatile uint32_t *)0x40010004)

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

	RCC_APB2ENR |= 0x00000005;
	GPIOA_CRH &= (~0xFFFFFFFF);
	GPIOA_CRH |= 0x33333333;
	GPIOA_CRL &= (~0xFFFFFFFF);
	GPIOA_CRL |= 0x88888888;
	GPIOA_ODR &=~ (0x1 << 0);
	AFIO_MAPR &= ~(7U << 24);
	AFIO_MAPR |=  (2U << 24);
	while(1){
		for(int i=0;i<8;i++){
			if((GPIOA_IDR&(0x1<<i))!=0){
				
				GPIOA_ODR|=(0x1<<(i+8));
				
			}
			else{
				GPIOA_ODR&=(~(0x1<<(i+8)));
			}
		}

	}
}
