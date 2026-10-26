# __Potentiometer Part Drivers__

![tag](https://img.shields.io/badge/tag-2.0.0-brightgreen.svg)
[![release note](https://img.shields.io/badge/release_note-view_html-gold.svg)](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/stm32-potentiometer-part-drivers/blob/main/Release_Notes.html)

## Overview

The Potentiometer part drivers provides APIs to drive the Potentiometer through ADC.


## Description

### Peripherals initialization:
   Part Potentiometer assumes that the initialization of all needed peripherals (ADC,GPIO) is done by the main application. The GPIO peripheral is usually initialized by the auto generated code produced by the Cube tool, otherwise it up to the user to correctly initialize the GPIO peripheral.

## How to use it?

To use the Potentiometer part APIs, the application should define the Potentiometer object and assign ADC HW resources to it..

```
typedef struct
{
  pot_io_t         pio;      /*!< IO Context  */
  uint8_t          state;    /*!< Driver state                 */
} pot_obj_t;
```

The application should configure the following: here is an example for ADC:
```
pot_obj_t PotObj;
  (...)
  /* Initialize the Potentiometer */
  printf("potentiometer_init() ");
  if (pot_init(&PotObj, MX_POTENTIOMETER_0) != POT_OK)
  {
    printf("ERROR\n");
  }
  printf("PASSED\n");
```
The link to the pio structure is done in pot_init() which should be the first API to call. Once this is successfully done, all operations can be called.