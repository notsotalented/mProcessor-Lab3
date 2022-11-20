/*
 * button.h
 *
 *  Created on: Nov 12, 2022
 *      Author: ASUS
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "global.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button1_pressed_flag;
extern int button2_pressed_flag;
extern int button3_pressed_flag;


void getKeyInput();

#endif /* INC_BUTTON_H_ */
