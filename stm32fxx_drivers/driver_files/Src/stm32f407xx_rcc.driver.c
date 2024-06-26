/*
 * stm32f407xx_rcc.driver.c
 *
 *  Created on: May 24, 2024
 *      Author: danielramirez
 */


#include "stm32f407xx_usart_driver.h"




uint16_t AHB_PreScalar[8] = {2, 4, 8, 16, 64, 128, 256, 512};
uint8_t APB_PreScalar[4] = {2, 4, 8, 16};




uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1, SystemClk;

	uint8_t clksrc, temp, ahbp, apb1p;

	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0)
	{
		SystemClk = 16000000;
	}
	else if (clksrc == 1)
	{
		SystemClk = 8000000;
	}
	else if (clksrc == 2)
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

	// for ahbp
	temp = (( RCC->CFGR >> 4) & 0xF);

	if (temp < 8)
	{
		ahbp = 1;
	}
	else
	{
		ahbp = AHB_PreScalar[temp-8];
	}

	//for apb1
	temp = (( RCC->CFGR >> 10) & 0x7);

	if (temp < 4)
	{
		apb1p = 1;
	}
	else
	{
		ahbp = APB_PreScalar[temp-4];
	}

	pclk1 = (SystemClk / ahbp) / apb1p;

	return pclk1;

}



uint32_t RCC_GetPCLK2Value(void)
{
	uint32_t pclk2, SystemClk;

	uint8_t clksrc, temp, ahbp, apb1p;

	clksrc = ((RCC->CFGR >> 2) & 0x3);

	if(clksrc == 0)
	{
		SystemClk = 16000000;
	}
	else if (clksrc == 1)
	{
		SystemClk = 8000000;
	}
	else if (clksrc == 2)
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

	// for ahbp
	temp = (( RCC->CFGR >> 4) & 0xF);

	if (temp < 8)
	{
		ahbp = 1;
	}
	else
	{
		ahbp = AHB_PreScalar[temp-8];
	}

	//for apb1
	temp = (( RCC->CFGR >> 10) & 0x7);

	if (temp < 4)
	{
		apb1p = 1;
	}
	else
	{
		ahbp = APB_PreScalar[temp-4];
	}

	pclk1 = (SystemClk / ahbp) / apb1p;

	return pclk2;

}
