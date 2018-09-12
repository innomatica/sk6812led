#ifndef __BOARD_H
#define __BOARD_H
/*
 * \author Sungjune Lee
 * \brief Minimal implementation of nRF24L01P communication.
 * \copyright
 *
 * nRF24L01P data transaction based on the enhanced shockbust protocol.
 *
 */
#include <stdint.h>
#include <stdbool.h>
#include "stm32l0xx_hal.h"
#include "stm32l0xx_ll_cortex.h"

// LED
#define LED_ON					(LED_GPIO_Port->BSRR = LED_Pin)
#define LED_OFF					(LED_GPIO_Port->BRR = LED_Pin)
#define LED_TOGGLE				(LED_GPIO_Port->ODR ^= LED_Pin)
// BTN
#define BTN_READ				(((BTN_GPIO_Port->IDR)&(BTN_Pin))==(BTN_Pin)?(0):(1))
// SysTick Int
#define SYSTICK_ENABLE_IT		do{LL_SYSTICK_EnableIT();}while(0)
#define SYSTICK_DISABLE_IT		do{LL_SYSTICK_DisableIT();}while(0)
// critical section
#define ENTER_CRITICAL			do{LL_SYSTICK_DisableIT();}while(0)
#define EXIT_CRITICAL			do{LL_SYSTICK_EnableIT();}while(0)

// debug
#define DEBUG_OUTPUT			(1)
#define UNIT_TEST				(0)

#if DEBUG_OUTPUT
#define DbgPrintf(x,arg...)		UART_Printf(x,##arg)
#else
#define DbgPrintf(x,arg...)		{}
#endif

/// General purpose functions
void USB_Printf(const char* format,...);
void UART_Printf(const char* format,...);
void USecDelay(unsigned usec);

#endif	// __BOARD_H
