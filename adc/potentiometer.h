/**
  ******************************************************************************
  * @file    potentiometer.h
  * @brief   This file is the header of potentiometer.c
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32_hal.h"
#include <stdint.h>
#include <stddef.h>

#define POT_ADC_POLL_TIMEOUT 1000U /*!< Default timeout value when polling the ADC (1s) */

/**
  * @brief Enumeration defining the software error code.
  */
typedef enum
{
  POT_OK         = 0,               /*!< Success Status                                  */
  POT_ERROR      = -1               /*!< Error Status                                    */
} pot_status_t;

typedef struct
{
  uint32_t          id;       /*!< Config ID             */
  hal_adc_handle_t  *phadc;   /*!< ADC handler           */
  uint8_t           state;    /*!< Driver state 0=uninitialized, 1=initialized */
} pot_obj_t;

int32_t pot_io_init(pot_obj_t *pobj);

/*  public function  --------------------------------------------------------------------------*/
pot_status_t pot_init(pot_obj_t *pobj, uint32_t id);
pot_status_t pot_get_level(pot_obj_t *pobj, uint32_t *plevel);

#ifdef __cplusplus
}
#endif

#endif /* POTENTIOMETER_H */
