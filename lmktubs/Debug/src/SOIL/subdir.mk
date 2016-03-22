################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SOIL/SOIL.c \
../src/SOIL/image_DXT.c \
../src/SOIL/image_helper.c \
../src/SOIL/stb_image_aug.c 

OBJS += \
./src/SOIL/SOIL.o \
./src/SOIL/image_DXT.o \
./src/SOIL/image_helper.o \
./src/SOIL/stb_image_aug.o 

C_DEPS += \
./src/SOIL/SOIL.d \
./src/SOIL/image_DXT.d \
./src/SOIL/image_helper.d \
./src/SOIL/stb_image_aug.d 


# Each subdirectory must supply rules for building sources it contributes
src/SOIL/%.o: ../src/SOIL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/cpp" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/hpp" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/fmod" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/SOIL" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/SOIL/SOIL" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


