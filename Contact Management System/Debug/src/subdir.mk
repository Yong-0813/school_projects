################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Contact\ Management\ System.cpp 

CPP_DEPS += \
./src/Contact\ Management\ System.d 

OBJS += \
./src/Contact\ Management\ System.o 


# Each subdirectory must supply rules for building sources it contributes
src/Contact\ Management\ System.o: ../src/Contact\ Management\ System.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Contact Management System.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Contact\ Management\ System.d ./src/Contact\ Management\ System.o

.PHONY: clean-src

