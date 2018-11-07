################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Main.cpp \
../UniqueWords1.cpp \
../UniqueWords2.cpp \
../UniqueWords3.cpp 

OBJS += \
./Main.o \
./UniqueWords1.o \
./UniqueWords2.o \
./UniqueWords3.o 

CPP_DEPS += \
./Main.d \
./UniqueWords1.d \
./UniqueWords2.d \
./UniqueWords3.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


