################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ESFree/scheduler.c 

OBJS += \
./ESFree/scheduler.o 

C_DEPS += \
./ESFree/scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
ESFree/%.o: ../ESFree/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -DSTM32F407xx -DUSE_HAL_DRIVER -DDEBUG -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\Libraries\CMSIS\Core\Include" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\Libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\Libraries\STM32F4xx_HAL_Driver\Inc" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\FreeRTOS\Source\include" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\FreeRTOS\Source\portable\GCC\ARM_CM3" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\ESFree" -I"C:\Users\Lucas Aulas\eclipse-workspace\grr\sched_FreeRTOS_qemu\system\inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


