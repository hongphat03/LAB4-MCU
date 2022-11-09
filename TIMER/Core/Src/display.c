/*
 * display.c
 *
 *  Created on: Nov 9, 2022
 *      Author: Hong Phat
 */
#include "display.h"
// Use four 7segment (led1, led2, led3, led4) to display the time of road 1 when mode is normal
// Use two 7segment (led1, led2) to display time duration value
// Use two 7segment (led3, led4) to display the mode
void display(int led){
		switch(led){
		case 1:
			switch (status){
				// when mode is normal, use led1 to display time of road 1
				case AUTO_RED:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
						display7SEG(timerred_counter/10);
					break;
				case AUTO_YELLOW:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
						display7SEG(timeryellow_counter/10);
					break;
				case AUTO_GREEN:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
						display7SEG(timergreen_counter/10);
					break;
				// when mode is modify-time, use led1 to display time duration value
				case MAN_RED:
				case MAN_GREEN:
				case MAN_YELLOW:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
						display7SEG(set_timer/10);
				default:
					break;
			}
			break;
		case 2:
			switch(status){
				// when mode is normal, use led1 to display time of road 1
				case AUTO_RED:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
						display7SEG(timerred_counter%10);
					break;
				case AUTO_YELLOW:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
						display7SEG(timeryellow_counter%10);
					break;
				case AUTO_GREEN:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
						display7SEG(timergreen_counter%10);
					break;
					// when mode is modify-time, use led2 to display time duration value
				case MAN_RED:
				case MAN_GREEN:
				case MAN_YELLOW:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
					display7SEG(set_timer%10);
				default:
					break;
			}
			break;
		case 3:
			switch(status2){
			// when mode is normal, use led3 to display time of road 1
				case AUTO_RED:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						display7SEG(timerred2_counter/10);
					break;
				case AUTO_YELLOW:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						display7SEG(timeryellow2_counter/10);
					break;
				case AUTO_GREEN:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						display7SEG(timergreen2_counter/10);
					break;
				// when mode is modify-time, use led3 to display the mode
				case MAN_RED:
				case MAN_GREEN:
				case MAN_YELLOW:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
					display7SEG(0);
				default:
					break;
			}
			break;
		case 4:
			switch(status2){
			// when mode is normal, use led4 to display time of road 1
				case AUTO_RED:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						display7SEG(timerred2_counter%10);
					break;
				case AUTO_YELLOW:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						display7SEG(timeryellow2_counter%10);
					break;
				case AUTO_GREEN:
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
						HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
						display7SEG(timergreen2_counter%10);
					break;
					// when mode is modify-time, use led4 to display the mode
				case MAN_RED:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
					display7SEG(2);
					break;
				case MAN_YELLOW:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
					display7SEG(3);
					break;
				case MAN_GREEN:
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
					HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
					display7SEG(4);
					break;
				default:
					break;
			}
			break;
			default:
				break;
		}
}
