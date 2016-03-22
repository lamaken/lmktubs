################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/cpp/Avatar.cpp \
../src/cpp/Ball.cpp \
../src/cpp/BezierCurve.cpp \
../src/cpp/Cell.cpp \
../src/cpp/Circuit.cpp \
../src/cpp/Core.cpp \
../src/cpp/Fonts.cpp \
../src/cpp/GameData.cpp \
../src/cpp/GameEnded.cpp \
../src/cpp/GameScene.cpp \
../src/cpp/Hud.cpp \
../src/cpp/MenuScene.cpp \
../src/cpp/Path.cpp \
../src/cpp/PauseMessage.cpp \
../src/cpp/SceneManager.cpp \
../src/cpp/SoundManager.cpp \
../src/cpp/lmktubs.cpp 

OBJS += \
./src/cpp/Avatar.o \
./src/cpp/Ball.o \
./src/cpp/BezierCurve.o \
./src/cpp/Cell.o \
./src/cpp/Circuit.o \
./src/cpp/Core.o \
./src/cpp/Fonts.o \
./src/cpp/GameData.o \
./src/cpp/GameEnded.o \
./src/cpp/GameScene.o \
./src/cpp/Hud.o \
./src/cpp/MenuScene.o \
./src/cpp/Path.o \
./src/cpp/PauseMessage.o \
./src/cpp/SceneManager.o \
./src/cpp/SoundManager.o \
./src/cpp/lmktubs.o 

CPP_DEPS += \
./src/cpp/Avatar.d \
./src/cpp/Ball.d \
./src/cpp/BezierCurve.d \
./src/cpp/Cell.d \
./src/cpp/Circuit.d \
./src/cpp/Core.d \
./src/cpp/Fonts.d \
./src/cpp/GameData.d \
./src/cpp/GameEnded.d \
./src/cpp/GameScene.d \
./src/cpp/Hud.d \
./src/cpp/MenuScene.d \
./src/cpp/Path.d \
./src/cpp/PauseMessage.d \
./src/cpp/SceneManager.d \
./src/cpp/SoundManager.d \
./src/cpp/lmktubs.d 


# Each subdirectory must supply rules for building sources it contributes
src/cpp/%.o: ../src/cpp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/cpp" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/hpp" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/fmod" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/SOIL" -I"/home/alex/workspaces/lmktubs.com/lmktubs/src/SOIL/SOIL" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


