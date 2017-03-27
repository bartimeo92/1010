################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/TADjuego.cpp \
../src/TADpieza.cpp \
../src/TADtablero.cpp \
../src/entorno.cpp \
../src/uex1010base2.cpp 

OBJS += \
./src/TADjuego.o \
./src/TADpieza.o \
./src/TADtablero.o \
./src/entorno.o \
./src/uex1010base2.o 

CPP_DEPS += \
./src/TADjuego.d \
./src/TADpieza.d \
./src/TADtablero.d \
./src/entorno.d \
./src/uex1010base2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


