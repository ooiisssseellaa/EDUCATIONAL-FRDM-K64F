/*
 * SSD_1327ZB.h
 *
 *  Created on: 01 mar 2019
 *      Author: Alessio
 */

#ifndef SSD_1327ZB_OLED_H_
#define SSD_1327ZB_OLED_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK64F12.h"
#include "core_cm4.h"

#include "time.h"

// OLED 128 x 128 Driver SSD1327ZB
#define SSD1327ZB_CMD_SETCOLUMNADDR              	0x15
#define SSD1327ZB_CMD_SETROWADDR                 	0x75
#define SSD1327ZB_CMD_SETCONTRAST                	0x81
#define SSD1327ZB_CMD_SEGMENTREMAP               	0xA0
#define SSD1327ZB_CMD_STARTLINE                  	0xA1
#define SSD1327ZB_CMD_DISPLAYNORMAL              	0xA4
#define SSD1327ZB_CMD_DISPLAYALLON               	0xA5
#define SSD1327ZB_CMD_DISPLAYALLOFF              	0xA6
#define SSD1327ZB_CMD_DISPLAYINVERSE             	0xA7
#define SSD1327ZB_CMD_DISPLAYOFF                 	0xAE
#define SSD1327ZB_CMD_DISPLAYON                  	0xAF
#define SSD1327ZB_REMAP_COLUMN                   	0x01
#define SSD1327ZB_REMAP_NIBBLE                   	0x02
#define SSD1327ZB_REMAP_ADDR_INCREMENT           	0x04
#define SSD1327ZB_REMAP_COM                      	0x10
#define SSD1327ZB_REMAP_ODDEVEN_COM              	0x40

#define SSD1327ZB_bufferLenght						(128*64)

void SSD1327ZB_init(void);

void SSD1327ZB_sendCommand (uint8_t value);
void SSD1327ZB_sendData(uint8_t value);

// FOLLOWING NEW FUNCTION TO DRAWING: IMPROVED VELOCITY FOR ANIMATION.

void SSD1327ZB_setBuffer(uint8_t xPos, uint8_t yPos, uint8_t greyScale);
void SSD1327ZB_setAreaOnScreen (uint8_t xStart,  uint8_t xStop, uint8_t yStart,  uint8_t yStop);
void SSD1327ZB_drawPartialScreen(uint8_t xStart,  uint8_t xStop, uint8_t yStart,  uint8_t yStop);
void SSD1327ZB_drawFullScreen();

// FOLLOWING HOLD FUNCTION TO DRAWING...

void SSD1327ZB_drawPixel (uint8_t xPos, uint8_t yPos);
void SSD1327ZB_drawPicture(uint8_t bitmap[SSD1327ZB_bufferLenght]);
void SSD1327ZB_clearAllPixel (void);
void SSD1327ZB_flush (void);

#endif /* SSD_1327ZB_OLED_H_ */
