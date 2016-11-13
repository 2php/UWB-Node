/**
  *      __            ____
  *     / /__ _  __   / __/                      __  
  *    / //_/(_)/ /_ / /  ___   ____ ___  __ __ / /_ 
  *   / ,<  / // __/_\ \ / _ \ / __// _ \/ // // __/ 
  *  /_/|_|/_/ \__//___// .__//_/   \___/\_,_/ \__/  
  *                    /_/   github.com/KitSprout    
  * 
  * @file    main.c
  * @author  KitSprout
  * @date    13-Nov-2016
  * @brief   
  * 
  */

/* Includes --------------------------------------------------------------------------------*/
#include "drivers\stm32f4_system.h"
#include "modules\serial.h"
#include "modules\imu.h"
#include "uwbNode_bsp.h"

/** @addtogroup STM32_Program
  * @{
  */

/* Private typedef -------------------------------------------------------------------------*/
/* Private define --------------------------------------------------------------------------*/
/* Private macro ---------------------------------------------------------------------------*/
/* Private variables -----------------------------------------------------------------------*/
extern IMU_DataTypeDef IMU;

/* Private function prototypes -------------------------------------------------------------*/
/* Private functions -----------------------------------------------------------------------*/

int main( void )
{
  HAL_Init();

  UWBN_GPIO_Config();
  UWBN_UART_Config(NULL);
  UWBN_IMU_Config();

  while (1) {
    LED_B_Toggle();
    delay_ms(100);
#if 0
    IMU_GetRawData(&IMU);
    printf("GX:%5.0f\tGY:%5.0f\tGZ:%5.0f\tAX:%5.0f\tAY:%5.0f\tAZ:%5.0f\tMX:%5.0f\tMY:%5.0f\tMZ:%5.0f\r\n",
      IMU.gyrRaw[0], IMU.gyrRaw[1], IMU.gyrRaw[2],
      IMU.accRaw[0], IMU.accRaw[1], IMU.accRaw[2],
      IMU.magRaw[0], IMU.magRaw[1], IMU.magRaw[2]
    );
#else
    IMU_GetScaleData(&IMU);
    printf("GX:%8.2f\tGY:%8.2f\tG8:%5.2f\tAX:%7.4f\tAY:%7.4f\tAZ:%7.4f\tMX:%6.1f\tMY:%6.1f\tMZ:%6.1f\r\n",
      IMU.gyrData[0], IMU.gyrData[1], IMU.gyrData[2],
      IMU.accData[0], IMU.accData[1], IMU.accData[2],
      IMU.magData[0], IMU.magData[1], IMU.magData[2]
    );
#endif

  }
}

/*************************************** END OF FILE ****************************************/
