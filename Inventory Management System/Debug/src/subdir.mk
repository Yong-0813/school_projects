################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Inventory\ Management\ System.cpp 

CPP_DEPS += \
./src/Inventory\ Management\ System.d 

OBJS += \
./src/Inventory\ Management\ System.o 


# Each subdirectory must supply rules for building sources it contributes
src/Inventory\ Management\ System.o: ../src/Inventory\ Management\ System.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/Inventory Management System.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Inventory\ Management\ System.d ./src/Inventory\ Management\ System.o

.PHONY: clean-src

