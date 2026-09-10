#include <stdint.h>
#define RCC_APB2ENR   (*(volatile uint32_t *)0x40021018)
#define GPIOA_CRH     (*(volatile uint32_t *)0x40010804)
#define GPIOA_CRL     (*(volatile uint32_t *)0x40010800)
#define GPIOA_ODR     (*(volatile uint32_t *)0x4001080C)
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
	GPIOA_CRL |= 0x33333333;
	while(1){
		delay_ms(1000);
		GPIOA_ODR &=~(0x0000FFFF);
		GPIOA_ODR |=(0x1<<count);
		if (count>=7){
			v=-1;
		}
		else if(count<=0){
			v=1;
		}
		count+=v;

	}
}
