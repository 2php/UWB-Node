/**
  *      __            ____
  *     / /__ _  __   / __/                      __  
  *    / //_/(_)/ /_ / /  ___   ____ ___  __ __ / /_ 
  *   / ,<  / // __/_\ \ / _ \ / __// _ \/ // // __/ 
  *  /_/|_|/_/ \__//___// .__//_/   \___/\_,_/ \__/  
  *                    /_/   github.com/KitSprout    
  * 
  * @file    stm32f4_exti.c
  * @author  KitSprout
  * @date    19-Nov-2016
  * @brief   
  * 
  */

/* Includes --------------------------------------------------------------------------------*/
#include "stm32f4_system.h"
#include "stm32f4_exti.h"

/** @addtogroup STM32_Driver
  * @{
  */

/* Private typedef -------------------------------------------------------------------------*/
/* Private define --------------------------------------------------------------------------*/
/* Private macro ---------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------*/
ExtiHandle_st hExtix = {
  .pin          = EXTIx_PIN,
  .EvenCallback = NULL,
};

static pFunc EXTIx_Callback = NULL;

/* Private function prototypes -------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------*/

/**
  * @brief  EXTIx_Config
  * @param  None
  * @retval None
  */
void EXTIx_Config( void )
{
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Pin ******************************************************************/
  GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
  GPIO_InitStruct.Pin   = EXTIx_PIN;
  HAL_GPIO_Init(EXTIx_GPIO_PORT, &GPIO_InitStruct);

  /* EXTI IT *******************************************************************/
  HAL_NVIC_SetPriority(EXTIx_IRQ, 0x0F, 0);
  HAL_NVIC_EnableIRQ(EXTIx_IRQ);
}

/**
  * @brief  EXTI line detection callbacks.
  */
void HAL_GPIO_EXTI_Callback( uint16_t GPIO_Pin )
{
  if (GPIO_Pin == hExtix.pin) {
    hExtix.EvenCallback();
  }
}

/*************************************** END OF FILE ****************************************/
