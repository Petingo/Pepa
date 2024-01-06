#ifndef CUSTOM_PAINT_H
#define CUSTOM_PAINT_H

#include "lib/GUI_Paint.h"
#include "lib/DEV_Config.h"
#include "lib/Debug.h"

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
UWORD drawWrappedString(UWORD x, UWORD y, const char * pString,
                       sFONT* font, UWORD colorForeground, UWORD colorBackground);

#endif