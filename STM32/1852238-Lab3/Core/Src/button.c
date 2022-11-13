/*
 * button.c
 *
 *  Created on: Nov 12, 2022
 *      Author: ASUS
 */

#include "button.h"

int button_pressed_flag = 0;

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;

int KeyReg3 = NORMAL_STATE;

int TimerForKeyPress = 300;



//This func do work
void subKeyProcess() {
	HAL_GPIO_TogglePin(LED_TEST_GPIO_Port, LED_TEST_Pin);
	if (button_pressed_flag == 1) {
		button_pressed_flag = 0;
	}
}

void holdKeyProcess() {
	if (button_pressed_flag == 1) {
		button_pressed_flag = 0;
	}
}

void getKeyInput(){
		KeyReg0 = KeyReg1;
		KeyReg1 = KeyReg2;

		KeyReg2 = HAL_GPIO_ReadPin(BUTTON_GPIO_Port, BUTTON_Pin);

		if ((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)) {
			if (KeyReg3 != KeyReg2) {
				KeyReg3 = KeyReg2;
				if (KeyReg2 == PRESSED_STATE) {
				  //TODO
				  subKeyProcess();
				  //TimerForKeyPress = 300;
				}
				//9s delay, or is it?

				//300 doesn't yeild the result of 3s delay on my machine. However 900 does.
				TimerForKeyPress = 300;
			}
			else {
				TimerForKeyPress--;
				if (TimerForKeyPress == 0) {
					if (KeyReg2 == PRESSED_STATE) {
						  //TODO
						holdKeyProcess();
					}
					//Second delay
					TimerForKeyPress = 20;
				}
			}
		}
}

