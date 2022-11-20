/*
 * fsm_traffic.c
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#include "fsm_traffic.h"

int sec1 = 0;
int sec2 = 0;

void fsm_traffic_run() {
	switch (state) {
	case 0:
		if (sec1 == (red_time - green_time)  && sec2 == 0) {
			sec2 = yellow_time;
			state = 1;
		}
		break;
	case 1:
		if (sec1 == 0 && sec2 == 0) {
			sec1 = green_time;
			sec2 = red_time;
			state = 2;
		}
	case 2:
		if (sec1 == 0 && sec2 == (red_time - green_time)) {
			sec1 = yellow_time;
			state = 3;
		}
	case 3:
		if (sec1 == 0 && sec2 == 0) {
			sec1 = red_time;
			sec2 = green_time;
			state = 0;
		}
		break;
	default:
		sec1 = red_time;
		sec2 = green_time;
		state = 0;
		break;
	}
	settraffic(state);
	display2Counter(sec1-1,sec2-1);
	if (timer3_flag == 1) {
		timer3_flag = 0;
		//TODO
		sec1--;
		sec2--;

		setTimer3(1000);
	}
}
