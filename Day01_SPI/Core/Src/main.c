/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MAX7219.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
uint8_t disp1[38][8] = {
    {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, // 0
    {0x10, 0x18, 0x14, 0x10, 0x10, 0x10, 0x10, 0x10}, // 1
    {0x7E, 0x2, 0x2, 0x7E, 0x40, 0x40, 0x40, 0x7E},   // 2
    {0x3E, 0x2, 0x2, 0x3E, 0x2, 0x2, 0x3E, 0x0},      // 3
    {0x8, 0x18, 0x28, 0x48, 0xFE, 0x8, 0x8, 0x8},     // 4
    {0x3C, 0x20, 0x20, 0x3C, 0x4, 0x4, 0x3C, 0x0},    // 5
    {0x3C, 0x20, 0x20, 0x3C, 0x24, 0x24, 0x3C, 0x0},  // 6
    {0x3E, 0x22, 0x4, 0x8, 0x8, 0x8, 0x8, 0x8},       // 7
    {0x0, 0x3E, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x3E},  // 8
    {0x3E, 0x22, 0x22, 0x3E, 0x2, 0x2, 0x2, 0x3E},    // 9
    {0x8, 0x14, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x22},  // A
    {0x3C, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x3C, 0x0},  // B
    {0x3C, 0x40, 0x40, 0x40, 0x40, 0x40, 0x3C, 0x0},  // C
    {0x7C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x7C, 0x0},  // D
    {0x7C, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x40, 0x7C}, // E
    {0x7C, 0x40, 0x40, 0x7C, 0x40, 0x40, 0x40, 0x40}, // F
    {0x3C, 0x40, 0x40, 0x40, 0x40, 0x44, 0x44, 0x3C}, // G
    {0x44, 0x44, 0x44, 0x7C, 0x44, 0x44, 0x44, 0x44}, // H
    {0x7C, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x7C}, // I
    {0x3C, 0x8, 0x8, 0x8, 0x8, 0x8, 0x48, 0x30},      // J
    {0x0, 0x24, 0x28, 0x30, 0x20, 0x30, 0x28, 0x24},  // K
    {0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C}, // L
    {0x81, 0xC3, 0xA5, 0x99, 0x81, 0x81, 0x81, 0x81}, // M
    {0x0, 0x42, 0x62, 0x52, 0x4A, 0x46, 0x42, 0x0},   // N
    {0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C}, // O
    {0x3C, 0x22, 0x22, 0x22, 0x3C, 0x20, 0x20, 0x20}, // P
    {0x1C, 0x22, 0x22, 0x22, 0x22, 0x26, 0x22, 0x1D}, // Q
    {0x3C, 0x22, 0x22, 0x22, 0x3C, 0x24, 0x22, 0x21}, // R
    {0x0, 0x1E, 0x20, 0x20, 0x3E, 0x2, 0x2, 0x3C},    // S
    {0x0, 0x3E, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8},        // T
    {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x22, 0x1C}, // U
    {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x24, 0x18}, // V
    {0x0, 0x49, 0x49, 0x49, 0x49, 0x2A, 0x1C, 0x0},   // W
    {0x0, 0x41, 0x22, 0x14, 0x8, 0x14, 0x22, 0x41},   // X
    {0x41, 0x22, 0x14, 0x8, 0x8, 0x8, 0x8, 0x8},      // Y
    {0x0, 0x7F, 0x2, 0x4, 0x8, 0x10, 0x20, 0x7F},     // Z
    {0x8, 0x7F, 0x49, 0x49, 0x7F, 0x8, 0x8, 0x8},     // �?
    {0xFE, 0xBA, 0x92, 0xBA, 0x92, 0x9A, 0xBA, 0xFE}, // �?
};

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
// #define ONE_SCREEN 0        // 单独一个MAX7219点阵屏
// #define TWO_SCREEN 1        // 不同CS的两个点阵屏
#define tWO_SERIES_SCREEN 2 // 串联的2个点阵屏
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  uint8_t i, j;

#ifdef ONE_SCREEN
  Init_MAX7219(GPIO_PIN_3);
#endif

#ifdef TWO_SCREEN
  Init_MAX7219(GPIO_PIN_3);
  Init_MAX7219(GPIO_PIN_4);
#endif

#ifdef tWO_SERIES_SCREEN
  Init_MAX7219(GPIO_PIN_4);
  Init_MAX7219(GPIO_PIN_4);
#endif

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

#ifdef ONE_SCREEN
  /**
   * @brief 使用1个8*8 MAX7219 点阵屏
   * SPI1_SCK     PA5
   * SPI1_MOSI    PA7
   * CS           PA4
   */
  for (j = 0; j < 38; j++)
    {
      for (i = 1; i < 9; i++)
        MX7219_Write(GPIO_PIN_4,i, disp1[j][i - 1]);
      HAL_Delay(1000);
    }
#endif

#ifdef TWO_SCREEN
  /**
   * @brief 使用2个点阵屏，不同的片选CS信号
   * SPI1_SCK     PA5
   * SPI1_MOSI    PA7
   * CS1          PA4
   * CS2          PA3
   */
  for (j = 0; j < 38; j++)
    {
      //在屏1上显示
      for (i = 1; i < 9; i++)
        MX7219_Write(GPIO_PIN_4,i, disp1[j][i - 1]);
      //在屏2上显示
      for (i = 1; i < 9; i++)
        MX7219_Write(GPIO_PIN_3,i, disp1[j][i - 1]);
      HAL_Delay(1000);
    }
#endif
#ifdef tWO_SERIES_SCREEN
   for (j = 0; j < 38; j++)
    {
      //在屏1上显示
      for (i = 1; i < 9; i++){
        MX7219_Write(GPIO_PIN_4,i, disp1[j][i - 1]);
        MX7219_Write(GPIO_PIN_4,i, disp1[j][i - 1]);
      }
      HAL_Delay(1000);
    }
#endif
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
