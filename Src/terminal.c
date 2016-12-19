/**
  ******************************************************************************
  * File Name          : terminal.c
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "usart.h"
#include <string.h>
#include "terminal.h"

cache_queue cache;
cache_queue cache1_terminal;
//uint8_t aRxBuffer;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
//#if 0
//		HAL_UART_Transmit(&huart2,&aRxBuffer,1,0);
//#else
//		cache.w_tmp = cache.index_w+1;
//		if(cache.w_tmp>=sizeof(cache.buf)) cache.w_tmp=0;
//		cache.buf[cache.w_tmp] = aRxBuffer;
//		if(cache.w_tmp != cache.index_r) cache.index_w=cache.w_tmp;
//#endif
//		HAL_UART_Receive_IT(&huart2,&aRxBuffer,1);
		__HAL_UART_ENABLE_IT(UartHandle, UART_IT_RXNE);
}
 
void terminal2_data_process(uint8_t data)
{
	//if(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_RXNE) == RESET)
	{
			//HAL_UART_Transmit(&huart2,&data,1,0);
			//aRxBuffer = data;
			//data = huart2.Instance->RDR & 0xFF;
			//flag = 1;
#if 0
			cache.w_tmp = cache.index_w+1;
			if(cache.w_tmp>=sizeof(cache.buf)) cache.w_tmp=0;
			cache.buf[cache.w_tmp] = data;
			if(cache.w_tmp != cache.index_r) cache.index_w=cache.w_tmp;
#else
			macro_queue_write(data,cache);
#endif
			//HAL_GPIO_TogglePin(GPIOA, SYS_LED_Pin|SIG_LED_Pin);
	}
}

void terminal1_data_process(uint8_t data)
{
		macro_queue_write(data,cache1_terminal);
}

uint8_t rx_data=0;
int fputc(int c, FILE *f) // printf
{
//	uint8_t data=c;
//	HAL_UART_Transmit(&huart1,&data,1,100);
//	return c;
#if 1
	uint8_t data=c;
	HAL_UART_Transmit(&huart2,&data,1,1);
#else
	rx_data=c;
	HAL_UART_Transmit_DMA(&huart2, &rx_data, 1);
#endif
	return c;
}
/* USER CODE END 0 */
//void uart_put_string(char *str)
//{
//	HAL_UART_Transmit(&huart2,(uint8_t *)str, strlen(str),50);
//	//__HAL_UART_ENABLE_IT(&huart2,UART_IT_RXNE);
//	//HAL_UART_Receive_IT(&huart2,&aRxBuffer,1);
//}

