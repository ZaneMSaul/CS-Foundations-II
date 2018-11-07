################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Dog.cpp \
../Main.cpp \
../Mammal.cpp \
../StudentScores.cpp 

OBJS += \
./Dog.o \
./Main.o \
./Mammal.o \
./StudentScores.o 

CPP_DEPS += \
./Dog.d \
./Main.d \
./Mammal.d \
./StudentScores.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


