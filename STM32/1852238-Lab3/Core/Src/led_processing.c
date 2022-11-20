/*
 * led_processing.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#include "led_processing.h"

int led7SEG[7] = {0,0,0,0,0,0,0};
int ledtraffic0[3] = {0,0,0};
int ledtraffic1[3] = {0,0,0};

//Write the output of 7SEG & choose which 7SEG
void write7SEG(int led7SEG[7], int sw) {
	switch (sw) {
	case 0:
		HAL_GPIO_WritePin(LED7_SEG0S_GPIO_Port, LED7_SEG0S_Pin, led7SEG[0]);
		HAL_GPIO_WritePin(LED7_SEG1S_GPIO_Port, LED7_SEG1S_Pin, led7SEG[1]);
		HAL_GPIO_WritePin(LED7_SEG2S_GPIO_Port, LED7_SEG2S_Pin, led7SEG[2]);
		HAL_GPIO_WritePin(LED7_SEG3S_GPIO_Port, LED7_SEG3S_Pin, led7SEG[3]);
		HAL_GPIO_WritePin(LED7_SEG4S_GPIO_Port, LED7_SEG4S_Pin, led7SEG[4]);
		HAL_GPIO_WritePin(LED7_SEG5S_GPIO_Port, LED7_SEG5S_Pin, led7SEG[5]);
		HAL_GPIO_WritePin(LED7_SEG6S_GPIO_Port, LED7_SEG6S_Pin, led7SEG[6]);
		break;
	case 1:
		HAL_GPIO_WritePin(LED7_SEG0_GPIO_Port, LED7_SEG0_Pin, led7SEG[0]);
		HAL_GPIO_WritePin(LED7_SEG1_GPIO_Port, LED7_SEG1_Pin, led7SEG[1]);
		HAL_GPIO_WritePin(LED7_SEG2_GPIO_Port, LED7_SEG2_Pin, led7SEG[2]);
		HAL_GPIO_WritePin(LED7_SEG3_GPIO_Port, LED7_SEG3_Pin, led7SEG[3]);
		HAL_GPIO_WritePin(LED7_SEG4_GPIO_Port, LED7_SEG4_Pin, led7SEG[4]);
		HAL_GPIO_WritePin(LED7_SEG5_GPIO_Port, LED7_SEG5_Pin, led7SEG[5]);
		HAL_GPIO_WritePin(LED7_SEG6_GPIO_Port, LED7_SEG6_Pin, led7SEG[6]);
		break;
	default:
		break;
	}
}

//Set the value to (which) 7SEG
void set7SEG(int number, int sw) {
	switch(number) {
	case 0: {
		int led7SEG[7] = {0,0,0,0,0,0,1};
		write7SEG(led7SEG, sw);
		break;
	}
	case 1: {
		int led7SEG[7] = {1,0,0,1,1,1,1};
		write7SEG(led7SEG, sw);
		break;
	}
	case 2: {
		int led7SEG[7] = {0,0,1,0,0,1,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 3: {
		int led7SEG[7] = {0,0,0,0,1,1,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 4: {
		int led7SEG[7] = {1,0,0,1,1,0,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 5: {
		int led7SEG[7] = {0,1,0,0,1,0,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 6: {
		int led7SEG[7] = {0,1,0,0,0,0,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 7: {
		int led7SEG[7] = {0,0,0,1,1,1,1};
		write7SEG(led7SEG, sw);
		break;
	}
	case 8: {
		int led7SEG[7] = {0,0,0,0,0,0,0};
		write7SEG(led7SEG, sw);
		break;
	}
	case 9: {
		int led7SEG[7] = {0,0,0,0,1,0,0};
		write7SEG(led7SEG, sw);
		break;
	}
	default: {
		int led7SEG[7] = {0,0,0,0,0,0,1};
		write7SEG(led7SEG, sw);
		break;
	}
	}
}

//Write the output of traffic lights
void writetraffic(int ledtraffic0[3], int ledtraffic1[3]) {
	HAL_GPIO_WritePin(RED_0_GPIO_Port, RED_0_Pin, ledtraffic0[0]);
	HAL_GPIO_WritePin(YELLOW_0_GPIO_Port, YELLOW_0_Pin, ledtraffic0[1]);
	HAL_GPIO_WritePin(GREEN_0_GPIO_Port, GREEN_0_Pin, ledtraffic0[2]);

	HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, ledtraffic1[0]);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, ledtraffic1[1]);
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, ledtraffic1[2]);
}

//Set the value to the traffic
void settraffic(int number) {
	int ledtraffic0[3] = {1,1,1};
	int ledtraffic1[3] = {1,1,1};
	switch(number) {
	case 0: //R-G
		ledtraffic0[0] = 0; ledtraffic0[1] = 1; //R1-ON + Y1-OFF
		ledtraffic1[2] = 0; ledtraffic1[0] = 1; //G2-ON + R2-OFF
		break;
	case 1: //R-Y
		ledtraffic0[0] = 0; ledtraffic0[1] = 1; //R1-ON + Y1-OFF
		ledtraffic1[1] = 0; ledtraffic1[2] = 1; //Y2-ON + G2-OFF
		break;
	case 2: //G-R
		ledtraffic0[2] = 0; ledtraffic0[0] = 1; //G1-ON + R1-OFF
		ledtraffic1[0] = 0; ledtraffic1[1] = 1; //R2-ON + Y2-OFF
		break;
	case 3: //Y-R
		ledtraffic0[1] = 0; ledtraffic0[2] = 1; //Y1-ON + G1-OFF
		ledtraffic1[0] = 0; ledtraffic1[1] = 1; //R2-ON + Y2-OFF
		break;
	default:
		ledtraffic0[0] = 1; ledtraffic0[0] = 1; //ALL OFF
		ledtraffic0[1] = 1; ledtraffic0[1] = 1;
		ledtraffic0[2] = 1; ledtraffic0[2] = 1;
		break;
	}
	writetraffic(ledtraffic0, ledtraffic1);
}


//Driver function for display7SEG
void display7SEG(int number) {
	if (number >= 10) {
		set7SEG(number/10, 0);
		set7SEG(number%10, 1);
	}
	else {
		set7SEG(0,0);
		set7SEG(number%10,1);
	}
}

void display2Counter(int sec1, int sec2) {
	if (timer4_flag == 1) {
		timer4_flag = 0;
		if (HAL_GPIO_ReadPin(EN0_GPIO_Port, EN0_Pin) == 0) {
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			display7SEG(sec2);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		}
		else {
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			display7SEG(sec1);
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		}
		setTimer4(125);
	}
}

void SecLED() {
	if (HAL_GPIO_ReadPin(LED_RED_GPIO_Port, LED_RED_Pin) == 0) {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	}
	else {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	}
}
