################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CourseGrades.cpp \
../Essay.cpp \
../FinalExam.cpp \
../GradedActivity.cpp \
../PassFailActivity.cpp \
../PassFailExam.cpp \
../spc15-11.cpp 

OBJS += \
./CourseGrades.o \
./Essay.o \
./FinalExam.o \
./GradedActivity.o \
./PassFailActivity.o \
./PassFailExam.o \
./spc15-11.o 

CPP_DEPS += \
./CourseGrades.d \
./Essay.d \
./FinalExam.d \
./GradedActivity.d \
./PassFailActivity.d \
./PassFailExam.d \
./spc15-11.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


