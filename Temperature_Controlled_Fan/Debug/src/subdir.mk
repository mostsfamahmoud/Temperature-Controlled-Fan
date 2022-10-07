################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Fan_Controller.c \
../src/adc.c \
../src/dc_motor.c \
../src/gpio.c \
../src/lcd.c \
../src/lm35_sensor.c \
../src/pwm.c 

OBJS += \
./src/Fan_Controller.o \
./src/adc.o \
./src/dc_motor.o \
./src/gpio.o \
./src/lcd.o \
./src/lm35_sensor.o \
./src/pwm.o 

C_DEPS += \
./src/Fan_Controller.d \
./src/adc.d \
./src/dc_motor.d \
./src/gpio.d \
./src/lcd.d \
./src/lm35_sensor.d \
./src/pwm.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


