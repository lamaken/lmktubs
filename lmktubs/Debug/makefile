################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/cpp/subdir.mk
-include src/SOIL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lmktubs

dependents:
	-cd /home/alex/workspaces/lmktubs.com/lmktubs/Debug && $(MAKE) all

# Tool invocations
lmktubs: $(OBJS) $(USER_OBJS) /home/alex/workspaces/lmktubs.com/lmktubs/Debug/lmktubs
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L"/home/alex/workspaces/lmktubs.com/lmktubs/lib/fmod" -L"/home/alex/workspaces/lmktubs.com/lmktubs/lib/SOIL" -L"/home/alex/workspaces/lmktubs.com/lmktubs/Debug" -o "lmktubs" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) lmktubs
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
/home/alex/workspaces/lmktubs.com/lmktubs/Debug/lmktubs:

-include ../makefile.targets
