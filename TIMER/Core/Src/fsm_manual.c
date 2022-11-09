/*
 * fsm_manual.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Hong Phat
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
		if(timer2_flag == 1){
			setTimer2(500);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_10);
		}
		if(isButton1Pressed() == 1){
			setTimer2(500);
			set_timer = 0;
			status = MAN_YELLOW;
		}
		if(isButton2Pressed() == 1){
			set_timer++;
		}
		if(isButton3Pressed() == 1){
			timer_red = set_timer*1000;
		}
		break;
	case MAN_YELLOW:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);
			if(timer2_flag == 1){
				setTimer2(5000);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_11);
			}
			if(isButton1Pressed() == 1){
				set_timer = 0;
				setTimer2(500);
				status = MAN_GREEN;
			}
			if(isButton2Pressed() == 1){
				set_timer++;
			}
			if(isButton3Pressed() == 1){
				timer_yellow = set_timer*1000;
			}
			break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1);
		if(timer2_flag == 1){
			setTimer2(5000);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_12);
		}
		if(isButton1Pressed() == 1){
			set_timer = 0;
			status = AUTO_RED;
			setTimer(timer_red);
		}
		if(isButton2Pressed() == 1){
			set_timer++;
		}
		if(isButton3Pressed() == 1){
			timer_green= set_timer*1000;
		}
		break;
	default:
		break;
	}
}
