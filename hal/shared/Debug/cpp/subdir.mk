################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/AnalogInput.cpp \
../cpp/AnalogOutput.cpp \
../cpp/DigitalInput.cpp \
../cpp/DigitalOutput.cpp \
../cpp/Pwm.cpp \
../cpp/portexception.cpp 

OBJS += \
./cpp/AnalogInput.o \
./cpp/AnalogOutput.o \
./cpp/DigitalInput.o \
./cpp/DigitalOutput.o \
./cpp/Pwm.o \
./cpp/portexception.o 

CPP_DEPS += \
./cpp/AnalogInput.d \
./cpp/AnalogOutput.d \
./cpp/DigitalInput.d \
./cpp/DigitalOutput.d \
./cpp/Pwm.d \
./cpp/portexception.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/%.o: ../cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -fPIC -I"/root/git/flashlib-hal/FlashLib/hal/HAL/include" -I/usr/lib/jvm/java-8-oracle/include/linux -I/usr/lib/jvm/java-8-oracle/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


