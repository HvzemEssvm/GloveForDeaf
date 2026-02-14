#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=main.c DIO.c lcd1602.c INTERRUPT.c ADC.c TIMER.c test.c buzzer.c flex.c glove.c eeprom.c TWI.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/main.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/lcd1602.o ${OBJECTDIR}/INTERRUPT.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/test.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/flex.o ${OBJECTDIR}/glove.o ${OBJECTDIR}/eeprom.o ${OBJECTDIR}/TWI.o
POSSIBLE_DEPFILES=${OBJECTDIR}/main.o.d ${OBJECTDIR}/DIO.o.d ${OBJECTDIR}/lcd1602.o.d ${OBJECTDIR}/INTERRUPT.o.d ${OBJECTDIR}/ADC.o.d ${OBJECTDIR}/TIMER.o.d ${OBJECTDIR}/test.o.d ${OBJECTDIR}/buzzer.o.d ${OBJECTDIR}/flex.o.d ${OBJECTDIR}/glove.o.d ${OBJECTDIR}/eeprom.o.d ${OBJECTDIR}/TWI.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/main.o ${OBJECTDIR}/DIO.o ${OBJECTDIR}/lcd1602.o ${OBJECTDIR}/INTERRUPT.o ${OBJECTDIR}/ADC.o ${OBJECTDIR}/TIMER.o ${OBJECTDIR}/test.o ${OBJECTDIR}/buzzer.o ${OBJECTDIR}/flex.o ${OBJECTDIR}/glove.o ${OBJECTDIR}/eeprom.o ${OBJECTDIR}/TWI.o

# Source Files
SOURCEFILES=main.c DIO.c lcd1602.c INTERRUPT.c ADC.c TIMER.c test.c buzzer.c flex.c glove.c eeprom.c TWI.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=ATmega32A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/2ebed374b05daeb48edd47333d022bbba84e9a6d .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/77da3fa5f365924e56d8a0ef6a98cdacd21cdfa1 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/lcd1602.o: lcd1602.c  .generated_files/flags/default/baadeb1550a9703461400b134d1e5394dfd4bf9f .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd1602.o.d 
	@${RM} ${OBJECTDIR}/lcd1602.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/lcd1602.o.d" -MT "${OBJECTDIR}/lcd1602.o.d" -MT ${OBJECTDIR}/lcd1602.o -o ${OBJECTDIR}/lcd1602.o lcd1602.c 
	
${OBJECTDIR}/INTERRUPT.o: INTERRUPT.c  .generated_files/flags/default/4e8a23ec563b43ab137b8143eda8e14e7d591d51 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INTERRUPT.o.d 
	@${RM} ${OBJECTDIR}/INTERRUPT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/INTERRUPT.o.d" -MT "${OBJECTDIR}/INTERRUPT.o.d" -MT ${OBJECTDIR}/INTERRUPT.o -o ${OBJECTDIR}/INTERRUPT.o INTERRUPT.c 
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/186e73914a4d59539031710fb6bae79389b7fde8 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ADC.o.d" -MT "${OBJECTDIR}/ADC.o.d" -MT ${OBJECTDIR}/ADC.o -o ${OBJECTDIR}/ADC.o ADC.c 
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/28b6f22522e9a6c2b4cfb33e08731f5e02a45f17 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER.o.d" -MT "${OBJECTDIR}/TIMER.o.d" -MT ${OBJECTDIR}/TIMER.o -o ${OBJECTDIR}/TIMER.o TIMER.c 
	
${OBJECTDIR}/test.o: test.c  .generated_files/flags/default/f8034755b36d632916bd8f5a218e0e8760bd3a9d .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test.o.d 
	@${RM} ${OBJECTDIR}/test.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/test.o.d" -MT "${OBJECTDIR}/test.o.d" -MT ${OBJECTDIR}/test.o -o ${OBJECTDIR}/test.o test.c 
	
${OBJECTDIR}/buzzer.o: buzzer.c  .generated_files/flags/default/b12e3f2e0b2444d955b0892a6b1b983f0bddc694 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buzzer.o.d" -MT "${OBJECTDIR}/buzzer.o.d" -MT ${OBJECTDIR}/buzzer.o -o ${OBJECTDIR}/buzzer.o buzzer.c 
	
${OBJECTDIR}/flex.o: flex.c  .generated_files/flags/default/2d5f1ca6737d69410b2bafa917354e5073dbc3db .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flex.o.d 
	@${RM} ${OBJECTDIR}/flex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/flex.o.d" -MT "${OBJECTDIR}/flex.o.d" -MT ${OBJECTDIR}/flex.o -o ${OBJECTDIR}/flex.o flex.c 
	
${OBJECTDIR}/glove.o: glove.c  .generated_files/flags/default/56471da40b5c860a1c56a755db709a86510db398 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glove.o.d 
	@${RM} ${OBJECTDIR}/glove.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/glove.o.d" -MT "${OBJECTDIR}/glove.o.d" -MT ${OBJECTDIR}/glove.o -o ${OBJECTDIR}/glove.o glove.c 
	
${OBJECTDIR}/eeprom.o: eeprom.c  .generated_files/flags/default/553d0d26fea3c78fd37ee293f63222f7b6333a46 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/eeprom.o.d 
	@${RM} ${OBJECTDIR}/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/eeprom.o.d" -MT "${OBJECTDIR}/eeprom.o.d" -MT ${OBJECTDIR}/eeprom.o -o ${OBJECTDIR}/eeprom.o eeprom.c 
	
${OBJECTDIR}/TWI.o: TWI.c  .generated_files/flags/default/ed6232d90d715e210d61569f3145203aa9af716c .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWI.o.d 
	@${RM} ${OBJECTDIR}/TWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1 -g -DDEBUG  -gdwarf-2  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TWI.o.d" -MT "${OBJECTDIR}/TWI.o.d" -MT ${OBJECTDIR}/TWI.o -o ${OBJECTDIR}/TWI.o TWI.c 
	
else
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/bee6a997ce0bf854bf6baa39ad3400f85aaf3040 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/main.o.d" -MT "${OBJECTDIR}/main.o.d" -MT ${OBJECTDIR}/main.o -o ${OBJECTDIR}/main.o main.c 
	
${OBJECTDIR}/DIO.o: DIO.c  .generated_files/flags/default/207aec3ad688116666c22469fb0da00935bb6e84 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/DIO.o.d 
	@${RM} ${OBJECTDIR}/DIO.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/DIO.o.d" -MT "${OBJECTDIR}/DIO.o.d" -MT ${OBJECTDIR}/DIO.o -o ${OBJECTDIR}/DIO.o DIO.c 
	
${OBJECTDIR}/lcd1602.o: lcd1602.c  .generated_files/flags/default/a0f7c704488998cf1dc59ba61188a9e0eaa6d8d .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd1602.o.d 
	@${RM} ${OBJECTDIR}/lcd1602.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/lcd1602.o.d" -MT "${OBJECTDIR}/lcd1602.o.d" -MT ${OBJECTDIR}/lcd1602.o -o ${OBJECTDIR}/lcd1602.o lcd1602.c 
	
${OBJECTDIR}/INTERRUPT.o: INTERRUPT.c  .generated_files/flags/default/c853bca71e451e0cdf3f8ff457a0a0e6b066cbdf .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/INTERRUPT.o.d 
	@${RM} ${OBJECTDIR}/INTERRUPT.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/INTERRUPT.o.d" -MT "${OBJECTDIR}/INTERRUPT.o.d" -MT ${OBJECTDIR}/INTERRUPT.o -o ${OBJECTDIR}/INTERRUPT.o INTERRUPT.c 
	
${OBJECTDIR}/ADC.o: ADC.c  .generated_files/flags/default/994f70a27c4399b1bf339d001130006a46b6512e .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADC.o.d 
	@${RM} ${OBJECTDIR}/ADC.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/ADC.o.d" -MT "${OBJECTDIR}/ADC.o.d" -MT ${OBJECTDIR}/ADC.o -o ${OBJECTDIR}/ADC.o ADC.c 
	
${OBJECTDIR}/TIMER.o: TIMER.c  .generated_files/flags/default/c3f0d2e6c9cbd3133a6c1df2137473d040049b0a .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TIMER.o.d 
	@${RM} ${OBJECTDIR}/TIMER.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TIMER.o.d" -MT "${OBJECTDIR}/TIMER.o.d" -MT ${OBJECTDIR}/TIMER.o -o ${OBJECTDIR}/TIMER.o TIMER.c 
	
${OBJECTDIR}/test.o: test.c  .generated_files/flags/default/f1bd7a0ed46277d92e3c81647a9405371e5d261c .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/test.o.d 
	@${RM} ${OBJECTDIR}/test.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/test.o.d" -MT "${OBJECTDIR}/test.o.d" -MT ${OBJECTDIR}/test.o -o ${OBJECTDIR}/test.o test.c 
	
${OBJECTDIR}/buzzer.o: buzzer.c  .generated_files/flags/default/fe49b714dbe5aec010853e9bc570da75d607664f .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/buzzer.o.d 
	@${RM} ${OBJECTDIR}/buzzer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/buzzer.o.d" -MT "${OBJECTDIR}/buzzer.o.d" -MT ${OBJECTDIR}/buzzer.o -o ${OBJECTDIR}/buzzer.o buzzer.c 
	
${OBJECTDIR}/flex.o: flex.c  .generated_files/flags/default/8c85ea72b4b7f4df6a963deb191875b19b8104d8 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/flex.o.d 
	@${RM} ${OBJECTDIR}/flex.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/flex.o.d" -MT "${OBJECTDIR}/flex.o.d" -MT ${OBJECTDIR}/flex.o -o ${OBJECTDIR}/flex.o flex.c 
	
${OBJECTDIR}/glove.o: glove.c  .generated_files/flags/default/1314089259d93655fc0ab805dc7013cc407fe484 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/glove.o.d 
	@${RM} ${OBJECTDIR}/glove.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/glove.o.d" -MT "${OBJECTDIR}/glove.o.d" -MT ${OBJECTDIR}/glove.o -o ${OBJECTDIR}/glove.o glove.c 
	
${OBJECTDIR}/eeprom.o: eeprom.c  .generated_files/flags/default/282760287132807d05240642ff402468d1ff9714 .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/eeprom.o.d 
	@${RM} ${OBJECTDIR}/eeprom.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/eeprom.o.d" -MT "${OBJECTDIR}/eeprom.o.d" -MT ${OBJECTDIR}/eeprom.o -o ${OBJECTDIR}/eeprom.o eeprom.c 
	
${OBJECTDIR}/TWI.o: TWI.c  .generated_files/flags/default/f1a6751a8736c254bd110987afc3d604973df1ab .generated_files/flags/default/ea5822228fc57a71500df969f49d3d0bb3234ff4
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/TWI.o.d 
	@${RM} ${OBJECTDIR}/TWI.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -x c -D__$(MP_PROCESSOR_OPTION)__    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -DXPRJ_default=$(CND_CONF)  $(COMPARISON_BUILD)  -gdwarf-3     -MD -MP -MF "${OBJECTDIR}/TWI.o.d" -MT "${OBJECTDIR}/TWI.o.d" -MT ${OBJECTDIR}/TWI.o -o ${OBJECTDIR}/TWI.o TWI.c 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1     -gdwarf-2 -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group  -Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1    -Wl,--gc-sections -O1 -ffunction-sections -fdata-sections -fshort-enums -fno-common -funsigned-char -funsigned-bitfields -Wall -gdwarf-3     $(COMPARISON_BUILD) -Wl,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -o dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  -o dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -Wl,--start-group  -Wl,-lm -Wl,--end-group 
	${MP_CC_DIR}\\avr-objcopy -O ihex "dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}" "dist/${CND_CONF}/${IMAGE_TYPE}/GloveForDeaf.X.${IMAGE_TYPE}.hex"
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
