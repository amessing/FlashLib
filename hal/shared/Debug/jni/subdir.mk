################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../jni/edu_flash3388_flashlib_hal_ANALOGJNI.cpp \
../jni/edu_flash3388_flashlib_hal_DIOJNI.cpp \
../jni/edu_flash3388_flashlib_hal_HAL.cpp \
../jni/edu_flash3388_flashlib_hal_PWMJNI.cpp 

OBJS += \
./jni/edu_flash3388_flashlib_hal_ANALOGJNI.o \
./jni/edu_flash3388_flashlib_hal_DIOJNI.o \
./jni/edu_flash3388_flashlib_hal_HAL.o \
./jni/edu_flash3388_flashlib_hal_PWMJNI.o 

CPP_DEPS += \
./jni/edu_flash3388_flashlib_hal_ANALOGJNI.d \
./jni/edu_flash3388_flashlib_hal_DIOJNI.d \
./jni/edu_flash3388_flashlib_hal_HAL.d \
./jni/edu_flash3388_flashlib_hal_PWMJNI.d 


# Each subdirectory must supply rules for building sources it contributes
jni/%.o: ../jni/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -fPIC -I"/root/git/flashlib-hal/FlashLib/hal/HAL/include" -I/usr/lib/jvm/java-8-oracle/include/linux -I/usr/lib/jvm/java-8-oracle/include/ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


