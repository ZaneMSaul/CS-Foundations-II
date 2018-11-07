################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Actor.cpp \
../ActorInventory.cpp \
../Film.cpp \
../FilmCatalog.cpp \
../Main.cpp \
../Utils.cpp 

OBJS += \
./Actor.o \
./ActorInventory.o \
./Film.o \
./FilmCatalog.o \
./Main.o \
./Utils.o 

CPP_DEPS += \
./Actor.d \
./ActorInventory.d \
./Film.d \
./FilmCatalog.d \
./Main.d \
./Utils.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


