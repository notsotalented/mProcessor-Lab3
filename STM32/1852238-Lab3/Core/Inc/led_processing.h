/*
 * led_processing.h
 *
 *  Created on: Nov 13, 2022
 *      Author: ASUS
 */

#ifndef INC_LED_PROCESSING_H_
#define INC_LED_PROCESSING_H_

#include "main.h"
#include "software_timer.h"

void display7SEG();

void settraffic();

void display2Counter(int sec1, int sec2);

void SecLED();

#endif /* INC_LED_PROCESSING_H_ */
