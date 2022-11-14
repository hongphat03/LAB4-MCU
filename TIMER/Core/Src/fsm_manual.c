/*
 * fsm_MODIFYual.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Hong Phat
 */

#include "fsm_manual.h"

void fsm_modify_run(){
	switch(status){
	case MODIFY_RED:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
		if(timer2_flag == 1){
			// blinky led every second
			setTimer2(500);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_10);
		}
		if(isButton1Pressed() == 1){
			// if button is pressed, mode is changed to mode 3 ( modify time for yellow led)
			setTimer2(500);
			set_timer = 1;
			// reset value of time duration
			status = MODIFY_YELLOW;
			status2 = MODIFY_YELLOW;
		}
		if(isButton2Pressed() == 1){
			// if button2 is pressed, value of timer duration increase one second
			set_timer++;
			if(set_timer > 99) set_timer = 1;
		}
		if(isButton3Pressed() == 1){
			// if button3 is pressed, set the value
			timer_red = set_timer*1000;
		}
		break;
	case MODIFY_YELLOW:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
			if(timer2_flag == 1){
				// blinky led every second
				setTimer2(500);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_11);
			}
			if(isButton1Pressed() == 1){
				// if button is pressed, mode is changed to mode 4 ( modify time for green led)
				set_timer = 1;
				// reset value of time duration
				setTimer2(500);
				status = MODIFY_GREEN;
				status2 = MODIFY_GREEN;
			}
			if(isButton2Pressed() == 1){
				// if button2 is pressed, value of timer duration increase one second
				set_timer++;
				if(set_timer > 99) set_timer = 1;
			}
			if(isButton3Pressed() == 1){
				// if button3 is pressed, set the value
				timer_yellow = set_timer*1000;
			}
			break;
	case MODIFY_GREEN:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
		if(timer2_flag == 1){
			// blinky led every second
			setTimer2(500);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_12);
		}
		if(isButton1Pressed() == 1){
			// if button is pressed, mode is changed to mode 1 ( normal mode )
			set_timer = 1;
			status = INIT;
			status2 = INIT;
		}
		if(isButton2Pressed() == 1){
			// if button2 is pressed, value of timer duration increase one second
			set_timer++;
			if(set_timer > 99) set_timer = 1;
		}
		if(isButton3Pressed() == 1){
			// if button3 is pressed, set the value
			timer_green= set_timer*1000;
		}
		break;
	default:
		break;
	}
}
