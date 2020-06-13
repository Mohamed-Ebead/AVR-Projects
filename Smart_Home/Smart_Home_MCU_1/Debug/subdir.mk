################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Interrupt.c \
../ADC_Program.c \
../App.c \
../DIO_prog.c \
../EXT_INT.c \
../EXT_INT_ISR.c \
../Program.c \
../Timer0_PWM_Prog.c \
../Timer2_PWM_Prog.c \
../UART_prog.c 

OBJS += \
./ADC_Interrupt.o \
./ADC_Program.o \
./App.o \
./DIO_prog.o \
./EXT_INT.o \
./EXT_INT_ISR.o \
./Program.o \
./Timer0_PWM_Prog.o \
./Timer2_PWM_Prog.o \
./UART_prog.o 

C_DEPS += \
./ADC_Interrupt.d \
./ADC_Program.d \
./App.d \
./DIO_prog.d \
./EXT_INT.d \
./EXT_INT_ISR.d \
./Program.d \
./Timer0_PWM_Prog.d \
./Timer2_PWM_Prog.d \
./UART_prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=800000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


