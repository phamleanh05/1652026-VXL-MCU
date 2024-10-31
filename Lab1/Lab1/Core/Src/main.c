/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RED 0
#define YELLOW 1
#define GREEN 2

#define RED_DURATION 9
#define YELLOW_DURATION 2
#define GREEN_DURATION 7
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/

void display7SEG(int number);
void display7SEG_2(int number);
void setTrafficLight1(int state);
void setTrafficLight2(int state);
void updateTrafficLights(int counter1, int state1, int state2, int counter2);

void display7SEG(int number) {
    if (number < 0 || number > 9) return;

    switch (number)
        {
        case 0:
            HAL_GPIO_WritePin(GPIOB, G_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | E_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | E_7SEG_Pin | D_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | C_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin | E_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOB, B_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOB, F_7SEG_Pin | G_7SEG_Pin | E_7SEG_Pin | D_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | C_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | E_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOB, E_7SEG_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin | B_7SEG_Pin | C_7SEG_Pin | D_7SEG_Pin | F_7SEG_Pin | G_7SEG_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
        }
}

void display7SEG_2(int number) {
    if (number < 0 || number > 9) return;

    switch (number)
            {
            case 0:
                HAL_GPIO_WritePin(GPIOB, G1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin | F1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 1:
                HAL_GPIO_WritePin(GPIOB, B1_7SEG_Pin | C1_7SEG_Pin, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_SET);
                break;
            case 2:
                HAL_GPIO_WritePin(GPIOB, C1_7SEG_Pin | F1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 3:
                HAL_GPIO_WritePin(GPIOB, E1_7SEG_Pin | F1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 4:
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, B1_7SEG_Pin | C1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 5:
                HAL_GPIO_WritePin(GPIOB, B1_7SEG_Pin | E1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 6:
                HAL_GPIO_WritePin(GPIOB, B1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 7:
                HAL_GPIO_WritePin(GPIOB, D1_7SEG_Pin | E1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | C1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 8:
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | E1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            case 9:
                HAL_GPIO_WritePin(GPIOB, E1_7SEG_Pin, GPIO_PIN_SET);
                HAL_GPIO_WritePin(GPIOB, A1_7SEG_Pin | B1_7SEG_Pin | C1_7SEG_Pin | D1_7SEG_Pin | F1_7SEG_Pin | G1_7SEG_Pin, GPIO_PIN_RESET);
                break;
            default:
                break;
            }
}

void setTrafficLight1(int state) {
    switch (state) {
        case RED:
            HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin | LED_GREEN_Pin, GPIO_PIN_SET);
            break;
        case YELLOW:
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | LED_GREEN_Pin, GPIO_PIN_SET);
            break;
        case GREEN:
            HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | LED_YELLOW_Pin, GPIO_PIN_SET);
            break;
    }
}

void setTrafficLight2(int state) {
    switch (state) {
        case RED:
            HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_GREEN_2_Pin, GPIO_PIN_SET);
            break;
        case YELLOW:
            HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_GREEN_2_Pin, GPIO_PIN_SET);
            break;
        case GREEN:
            HAL_GPIO_WritePin(GPIOA, LED_GREEN_2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_YELLOW_2_Pin, GPIO_PIN_SET);
            break;
    }
}

void updateTrafficLights(int counter1, int state1, int counter2, int state2) {
    // Update Traffic Light 1
    if (state1 == RED && state2 == GREEN) {
        if (counter1 >= RED_DURATION) {
            setTrafficLight1(RED);
        }
        display7SEG(counter1);
    } else if (state1 == GREEN && state2 == RED) {
        if (counter1 >= GREEN_DURATION) {
            setTrafficLight1(GREEN);
        }
        display7SEG(counter1);
    } else if (state1 == YELLOW && state2 == RED) {
        if (counter1 >= YELLOW_DURATION) {
            setTrafficLight1(YELLOW);
        }
        display7SEG(counter1);
        display7SEG_2(counter2);
    }

    // Update Traffic Light 2 (Opposite of Traffic Light 1)
    if (state2 == RED && state1 == GREEN) {
        if (counter2 >= RED_DURATION) {
            setTrafficLight2(RED);
        }
        display7SEG_2(counter2);
    } else if (state2 == GREEN && state1 == RED) {
        if (counter2 >= GREEN_DURATION) {
            setTrafficLight2(GREEN);
        }
        display7SEG_2(counter2);
    } else if (state2 == YELLOW && state1 == RED) {
        if (counter2 >= YELLOW_DURATION) {
            setTrafficLight2(YELLOW);
        }
        display7SEG_2(counter2);
        display7SEG(counter1);
    }
}

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int counter1 = RED_DURATION;
  int state1 = RED;
  int counter2 = GREEN_DURATION;
  int state2 = GREEN;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Update both traffic lights
	  updateTrafficLights(counter1, state1, counter2, state2);

	  // Decrease counters
	  counter1--;
	  counter2--;

	  // Check for state transitions for both lights
	  if (counter1 == 0) {
		  if (state1 == RED) {
			  state1 = GREEN;
			  counter1 = GREEN_DURATION;
		  } else if (state1 == GREEN) {
			  state1 = YELLOW;
			  counter1 = YELLOW_DURATION;
		  } else if (state1 == YELLOW) {
			  state1 = RED;
			  counter1 = RED_DURATION;
		  }
	  }

	  if (counter2 == 0) {
		  if (state2 == GREEN) {
			  state2 = YELLOW;
			  counter2 = YELLOW_DURATION;
		  } else if (state2 == YELLOW) {
			  state2 = RED;
			  counter2 = RED_DURATION;
		  } else if (state2 == RED) {
			  state2 = GREEN;
			  counter2 = GREEN_DURATION;
		  }
	  }

	  // Delay for 1 second between updates
	  HAL_Delay(500);
  /* USER CODE END 3 */
  }
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_GREEN_2_Pin
                          |LED_YELLOW_2_Pin|LED_RED_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, A_7SEG_Pin|B_7SEG_Pin|C_7SEG_Pin|D1_7SEG_Pin
                          |E1_7SEG_Pin|F1_7SEG_Pin|G1_7SEG_Pin|D_7SEG_Pin
                          |E_7SEG_Pin|F_7SEG_Pin|G_7SEG_Pin|A1_7SEG_Pin
                          |B1_7SEG_Pin|C1_7SEG_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin LED_GREEN_2_Pin
                           LED_YELLOW_2_Pin LED_RED_2_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|LED_GREEN_2_Pin
                          |LED_YELLOW_2_Pin|LED_RED_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : A_7SEG_Pin B_7SEG_Pin C_7SEG_Pin D1_7SEG_Pin
                           E1_7SEG_Pin F1_7SEG_Pin G1_7SEG_Pin D_7SEG_Pin
                           E_7SEG_Pin F_7SEG_Pin G_7SEG_Pin A1_7SEG_Pin
                           B1_7SEG_Pin C1_7SEG_Pin */
  GPIO_InitStruct.Pin = A_7SEG_Pin|B_7SEG_Pin|C_7SEG_Pin|D1_7SEG_Pin
                          |E1_7SEG_Pin|F1_7SEG_Pin|G1_7SEG_Pin|D_7SEG_Pin
                          |E_7SEG_Pin|F_7SEG_Pin|G_7SEG_Pin|A1_7SEG_Pin
                          |B1_7SEG_Pin|C1_7SEG_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

#ifdef  USE_FULL_ASSERT
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/