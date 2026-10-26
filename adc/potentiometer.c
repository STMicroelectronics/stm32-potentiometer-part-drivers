/**
  ******************************************************************************
  * @file    potentiometer.c
  * @brief   This file provides a set of functions to interface with the potentiometer
  *          device.
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

/* Includes ------------------------------------------------------------------*/
#include "potentiometer.h"

/**
  * @brief  Initializes the Potentiometer component.
  * @param  pobj   : Potentiometer object
  * @param  id     : ID of the configuration to apply
  * @retval error status (@ref POT_OK or @ref POT_ERROR)
  */
pot_status_t pot_init(pot_obj_t *pobj, uint32_t id)
{
  pobj->id = id;
  if (pobj->state != 1U)
  {
    if (pot_io_init(pobj) != 0)
    {
      return POT_ERROR;
    }
    if (HAL_ADC_Calibrate(pobj->phadc) != HAL_OK)
    {
      return POT_ERROR;
    }
    pobj->state = 1U;
  }
  return POT_OK;
}

/**
  * @brief initialize the IO layer. This specific implementation does nothing.
  * @param  pobj   : Potentiometer object
  * @note This function must be overridden (using codegen or otherwise) with a proper implementation.
  * @retval -1 (always fails)
  */
__WEAK int32_t pot_io_init(pot_obj_t *pobj)
{
  (void)(pobj);
  return -1;
}

/**
  * @brief  Get Potentiometer level.
  * @param  pobj   : Potentiometer object
  * @param  plevel : Pointer to the potentiometer level (0..100%).
  * @retval error status (@ref POT_OK or @ref POT_ERROR)
  */
pot_status_t pot_get_level(pot_obj_t *pobj, uint32_t *plevel)
{
  /* Variable for the ADC conversion data (a count on the ADC scale) */
  pot_status_t potStatus = POT_ERROR;
  int32_t AdcRawData;
  hal_adc_config_t Config;
  uint32_t AdcFullScale;

  if (HAL_ADC_REG_StartConv(pobj->phadc) == HAL_OK)
  {
    if (HAL_ADC_REG_PollForConv(pobj->phadc, POT_ADC_POLL_TIMEOUT) == HAL_OK)
    {
      /* Retrieve the ADC full Scale */
      HAL_ADC_GetConfig(pobj->phadc, &Config);
      AdcFullScale = HAL_ADC_DIGITAL_SCALE(Config.resolution);

      if (AdcFullScale != 0U)
      {
        /* Retrieve the ADC conversion data */
        AdcRawData = HAL_ADC_REG_ReadConversionData(pobj->phadc);

        *plevel = ((uint32_t)AdcRawData * 100U) / AdcFullScale;

        potStatus = POT_OK;
      }
    }
  }

  return potStatus;
}

