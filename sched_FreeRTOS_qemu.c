/*==================================================================================================

  sched_FreeRTOS_qemu.c

  Used hardware: STM32F4-Discovery evaluation board (QEMU)

  Example of using the FreeRTOS with the ESFree scheduler on the STM32F4-Discovery board.

  ==================================================================================================
*/

#include "stm32f4_discovery.h"
#include "scheduler.h"
#include "diag/Trace.h"


TaskHandle_t xHandle1 = NULL, xHandle2 = NULL, xHandle3 = NULL;

void vPrioInfo(void *pvParam){
  trace_printf("Priorities:\n%s: %d\n", pcTaskGetName(xHandle1), uxTaskPriorityGet(xHandle1));
  trace_printf("%s: %d\n", pcTaskGetName(xHandle2), uxTaskPriorityGet(xHandle2));
  trace_printf("%s: %d\n\n", pcTaskGetName(xHandle3), uxTaskPriorityGet(xHandle3));
} // vPrioInfo

void vBlink(void *pvParam){
  trace_printf("%s\n", pcTaskGetName(NULL));
  BSP_LED_Toggle((uint32_t)pvParam);
} // vBlink


void main(void){
  vSchedulerAperiodicJobCreate(vPrioInfo,  "ApJob", NULL, pdMS_TO_TICKS(1));
  __HAL_RCC_GPIOD_CLK_ENABLE();
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);

  vSchedulerInit();

  vSchedulerPeriodicTaskCreate(vBlink, "Task1", configMINIMAL_STACK_SIZE, (void *)LED3, 1, &xHandle1, pdMS_TO_TICKS(010), pdMS_TO_TICKS(250), pdMS_TO_TICKS(001), pdMS_TO_TICKS(250));
  vSchedulerPeriodicTaskCreate(vBlink, "Task2", configMINIMAL_STACK_SIZE, (void *)LED6, 1, &xHandle2, pdMS_TO_TICKS(260), pdMS_TO_TICKS(200), pdMS_TO_TICKS(001), pdMS_TO_TICKS(200));
  vSchedulerPeriodicTaskCreate(vBlink, "Task3", configMINIMAL_STACK_SIZE, (void *)LED5, 1, &xHandle3, pdMS_TO_TICKS(135), pdMS_TO_TICKS(500), pdMS_TO_TICKS(001), pdMS_TO_TICKS(500));

  vSchedulerStart();
  while(1);
} // main
