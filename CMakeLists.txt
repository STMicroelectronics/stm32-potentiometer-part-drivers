# origin-pack: STMicroelectronics::potentiometer_part_drivers@2.0.0
# file-format: 1.0.0
project(STMicroelectronics_potentiometer_part_drivers_2_0_0)
cmake_minimum_required(VERSION 3.30)
add_library(STMicroelectronics_potentiometer_part_drivers_2_0_0 INTERFACE)

# List of all CMSIS properties that influence conditions for this package


# Device specific defined symbols








# Enable all components in this package
if(CMSIS_ENTIRE_STMicroelectronics_potentiometer_part_drivers_2_0_0)
  list(APPEND CMSIS_COMPONENTS_LIST "Cvendor:STMicroelectronics#Cclass:Board Part#Cgroup:Potentiometer#Csub:ADC#Cversion:1.0.0")
endif()

# All conditions used by this package

# condition: STMicroelectronics.potentiometer_part_drivers.2.0.0:HAL ADC
# description: STMicroelectronics ADC HAL Driver
set(STMicroelectronics.potentiometer_part_drivers.2.0.0_HAL_ADC "$<NOT:$<STREQUAL:$<FILTER:${CMSIS_COMPONENTS_LIST},INCLUDE,.*Cclass:Device#.*Cgroup:STM32 HAL#.*Csub:ADC(#.*|$)>,>>")
message(DEBUG "CMSIS condition STMicroelectronics.potentiometer_part_drivers.2.0.0_HAL_ADC enabled")


# condition: STMicroelectronics.potentiometer_part_drivers.2.0.0:POTENTIOMETER ADC CFG Condition
# description: 
set(STMicroelectronics.potentiometer_part_drivers.2.0.0_POTENTIOMETER_ADC_CFG_Condition "1")
message(DEBUG "CMSIS condition STMicroelectronics.potentiometer_part_drivers.2.0.0_POTENTIOMETER_ADC_CFG_Condition enabled")

# Files and components in this package
if("Cvendor:STMicroelectronics#Cclass:Board Part#Cgroup:Potentiometer#Csub:ADC#Cversion:1.0.0" IN_LIST CMSIS_COMPONENTS_LIST)  # Driver for Potentiometer
  message(DEBUG "Using component Board_Part_Potentiometer_ADC_1_0_0")
  target_compile_definitions(STMicroelectronics_potentiometer_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.potentiometer_part_drivers.2.0.0_HAL_ADC}:-DCMSIS_USE_Board_Part_Potentiometer_ADC_1_0_0=1>")
  target_include_directories(STMicroelectronics_potentiometer_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.potentiometer_part_drivers.2.0.0_HAL_ADC}:${CMAKE_CURRENT_LIST_DIR}/adc>")
  target_sources(STMicroelectronics_potentiometer_part_drivers_2_0_0 INTERFACE "$<${STMicroelectronics.potentiometer_part_drivers.2.0.0_HAL_ADC}:${CMAKE_CURRENT_LIST_DIR}/adc/potentiometer.c>")
endif()

