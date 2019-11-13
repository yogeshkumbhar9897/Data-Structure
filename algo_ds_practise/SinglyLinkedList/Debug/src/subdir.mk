################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/list.cpp \
../src/list1.cpp \
../src/main.cpp \
../src/node.cpp 

OBJS += \
./src/list.o \
./src/list1.o \
./src/main.o \
./src/node.o 

CPP_DEPS += \
./src/list.d \
./src/list1.d \
./src/main.d \
./src/node.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


