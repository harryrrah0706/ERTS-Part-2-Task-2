################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./FreeRTOS_Source/croutine.obj" \
"./FreeRTOS_Source/event_groups.obj" \
"./FreeRTOS_Source/list.obj" \
"./FreeRTOS_Source/queue.obj" \
"./FreeRTOS_Source/stream_buffer.obj" \
"./FreeRTOS_Source/tasks.obj" \
"./FreeRTOS_Source/timers.obj" \
"./FreeRTOS_Source/portable/CCS/ARM_CM4F/port.obj" \
"./FreeRTOS_Source/portable/CCS/ARM_CM4F/portasm.obj" \
"./FreeRTOS_Source/portable/MemMang/heap_4.obj" \
"./MainProgram/main_program.obj" \
"./driverlib/cpu.obj" \
"./driverlib/cs.obj" \
"./driverlib/flash.obj" \
"./driverlib/fpu.obj" \
"./driverlib/gpio.obj" \
"./driverlib/interrupt.obj" \
"./driverlib/pcm.obj" \
"./driverlib/sysctl.obj" \
"./driverlib/timer32.obj" \
"./driverlib/uart.obj" \
"./driverlib/wdt_a.obj" \
"./inc/Clock.obj" \
"./inc/CortexM.obj" \
"./inc/SysTick.obj" \
"./inc/bumpSwitch.obj" \
"./inc/dcMotor.obj" \
"./inc/outputLED.obj" \
"./inc/songFile.obj" \
"./system/CCS/msp432_startup_ccs.obj" \
"./system/CCS/printf-stdarg.obj" \
"./system/CCS/system_msp432p401r.obj" \
"../system/CCS/msp432p401r.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include FreeRTOS_Source/subdir_vars.mk
-include FreeRTOS_Source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include FreeRTOS_Source/portable/MemMang/subdir_vars.mk
-include MainProgram/subdir_vars.mk
-include driverlib/subdir_vars.mk
-include inc/subdir_vars.mk
-include system/CCS/subdir_vars.mk
-include subdir_rules.mk
-include FreeRTOS_Source/subdir_rules.mk
-include FreeRTOS_Source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include FreeRTOS_Source/portable/MemMang/subdir_rules.mk
-include MainProgram/subdir_rules.mk
-include driverlib/subdir_rules.mk
-include inc/subdir_rules.mk
-include system/CCS/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
RTOSDemo.out \

EXE_OUTPUTS__QUOTED += \
"RTOSDemo.out" \

BIN_OUTPUTS += \
RTOSDemo.bin \

BIN_OUTPUTS__QUOTED += \
"RTOSDemo.bin" \


# All Target
all: RTOSDemo.out

# Tool invocations
RTOSDemo.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: MSP432 Linker'
	"C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me -O0 --opt_for_speed=2 -g --gcc --define=__MSP432P401R__ --define=USE_CMSIS_REGISTER_FORMAT=1 --define=TARGET_IS_MSP432P4XX --define=ccs --diag_warning=225 --diag_wrap=off --display_error_number --verbose_diagnostics --gen_func_subsections=on -z -m"RTOSDemo.map" --stack_size=800 --heap_size=0 -i"C:/TI/ccs/ccs_base/arm/include" -i"C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/lib" -i"C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="RTOSDemo_linkInfo.xml" --rom_model --unused_section_elimination=on -o "RTOSDemo.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

RTOSDemo.bin: $(EXE_OUTPUTS)
	@echo 'Building secondary target: "$@"'
	@echo 'Invoking: MSP432 Hex Utility'
	"C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armhex" --diag_wrap=off -o "RTOSDemo.bin" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building secondary target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "FreeRTOS_Source\croutine.obj" "FreeRTOS_Source\event_groups.obj" "FreeRTOS_Source\list.obj" "FreeRTOS_Source\queue.obj" "FreeRTOS_Source\stream_buffer.obj" "FreeRTOS_Source\tasks.obj" "FreeRTOS_Source\timers.obj" "FreeRTOS_Source\portable\CCS\ARM_CM4F\port.obj" "FreeRTOS_Source\portable\CCS\ARM_CM4F\portasm.obj" "FreeRTOS_Source\portable\MemMang\heap_4.obj" "MainProgram\main_program.obj" "driverlib\cpu.obj" "driverlib\cs.obj" "driverlib\flash.obj" "driverlib\fpu.obj" "driverlib\gpio.obj" "driverlib\interrupt.obj" "driverlib\pcm.obj" "driverlib\sysctl.obj" "driverlib\timer32.obj" "driverlib\uart.obj" "driverlib\wdt_a.obj" "inc\Clock.obj" "inc\CortexM.obj" "inc\SysTick.obj" "inc\bumpSwitch.obj" "inc\dcMotor.obj" "inc\outputLED.obj" "inc\songFile.obj" "system\CCS\msp432_startup_ccs.obj" "system\CCS\printf-stdarg.obj" "system\CCS\system_msp432p401r.obj" 
	-$(RM) "main.d" "FreeRTOS_Source\croutine.d" "FreeRTOS_Source\event_groups.d" "FreeRTOS_Source\list.d" "FreeRTOS_Source\queue.d" "FreeRTOS_Source\stream_buffer.d" "FreeRTOS_Source\tasks.d" "FreeRTOS_Source\timers.d" "FreeRTOS_Source\portable\CCS\ARM_CM4F\port.d" "FreeRTOS_Source\portable\MemMang\heap_4.d" "MainProgram\main_program.d" "driverlib\cpu.d" "driverlib\cs.d" "driverlib\flash.d" "driverlib\fpu.d" "driverlib\gpio.d" "driverlib\interrupt.d" "driverlib\pcm.d" "driverlib\sysctl.d" "driverlib\timer32.d" "driverlib\uart.d" "driverlib\wdt_a.d" "inc\Clock.d" "inc\CortexM.d" "inc\SysTick.d" "inc\bumpSwitch.d" "inc\dcMotor.d" "inc\outputLED.d" "inc\songFile.d" "system\CCS\msp432_startup_ccs.d" "system\CCS\printf-stdarg.d" "system\CCS\system_msp432p401r.d" 
	-$(RM) "FreeRTOS_Source\portable\CCS\ARM_CM4F\portasm.d" 
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-C:/TI/ccs/utils/tiobj2bin/tiobj2bin RTOSDemo.out RTOSDemo.bin C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armofd C:/TI/ccs/tools/compiler/ti-cgt-arm_20.2.5.LTS/bin/armhex C:/TI/ccs/utils/tiobj2bin/mkhex4bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

