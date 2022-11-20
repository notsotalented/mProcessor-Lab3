/*
 * button.c
 *
 *  Created on: Nov 12, 2022
 *      Author: ASUS
 */

#include "button.h"

int button1_pressed_flag = 0;
int button2_pressed_flag = 0;
int button3_pressed_flag = 0;

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimerForKeyPress = 300;

int stop_hold = 0;

//This func do work when pressed
void subKeyProcess(int i) {
	switch (i) {
	case 0:
		if (button1_pressed_flag == 1) button1_pressed_flag = 0;
		//TODO
		mode++;
		setTimer1(500);
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);

		setTimer2(250);
		setTimer3(500);

		if (mode > 3) {
			mode = 0;
			state = -1;
		}

		if (mode != 0) {
			  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET); //SEG0
			  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);	//SEG1
		}

		switch (mode) {
		case 0:
			temp = red_time;
			break;
		case 1:
			temp = red_time;
			break;
		case 2:
			temp = yellow_time;
			break;
		case 3:
			temp = green_time;
			break;
		}

		break;
	case 1:
		if (button2_pressed_flag == 1) button2_pressed_flag = 0;
		//TODO
		temp++;
		if (temp > 99) temp = 1;

		break;
	case 2:
		if (button3_pressed_flag == 1) button3_pressed_flag = 0;
		//TODO
		switch (mode) {
		case 0:
			break;
		case 1:
			red_time = temp;
			break;
		case 2:
			yellow_time = temp;
			break;
		case 3:
			green_time = temp;
			break;
		}
		break;
	}
}

//This func do work when hold
void holdKeyProcess(int i) {
	if (button1_pressed_flag == 1) {
		button1_pressed_flag = 0;
	}
	//TODO
}

void getKeyInput(){
	for (int i = 0; i < 3; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];

		if (i == 0) {
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
		}
		else if (i == 1) {
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
		}
		else {
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);
		}

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
				  //TODO
				  subKeyProcess(i);
				  stop_hold = i;
				  //TimerForKeyPress = 300;
				}

				//Delay
				TimerForKeyPress = 300;
			}
			else {
				TimerForKeyPress--;
				if (TimerForKeyPress == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						  //TODO
						holdKeyProcess(stop_hold);
					}
					//Second delay
					TimerForKeyPress = 100;
				}
			}
		}
	}
}
