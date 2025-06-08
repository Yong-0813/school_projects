################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Task\ Schedular.cpp 

CPP_DEPS += \
./src/Task\ Schedular.d 

OBJS += \
./src/Task\ Schedular.o 


# Each subdirectory must supply rules for building sources it contributes
src/Task\ Schedular.o: ../src/Task\ Schedular.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Task Schedular.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Task\ Schedular.d ./src/Task\ Schedular.o

.PHONY: clean-src

