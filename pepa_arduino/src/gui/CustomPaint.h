#ifndef CUSTOM_PAINT_H
#define CUSTOM_PAINT_H

#include "../eink/GUI_Paint.h"
#include "../eink/DEV_Config.h"
#include "../eink/Debug.h"

bool isAlphabit(char c);

/**
 * 
 * @brief: Draw a that wrap based on word, and return the y position of the last drawn line
 * 
 * @param: x, x position of the string
 * @param: y, y position of the string
 * @param: pString, the string to be drawn
 * @param: font, the font of the string
 * @param: colorForeground, the color of the string
 * @param: colorBackground, the background color of the string
 * 
 * @return: the y position of the last drawn line
 * 
 */
uint16_t drawWrappedString(uint16_t x, uint16_t y, const char * pString,
                       sFONT* font, uint16_t colorForeground, uint16_t colorBackground);

#endif