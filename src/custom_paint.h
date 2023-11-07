#include "GUI_Paint.h"
#include "DEV_Config.h"
#include "utility/Debug.h"

bool IsAlphabit(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


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
UWORD DrawWrappedString(UWORD x, UWORD y, const char * pString,
                       sFONT* font, UWORD colorForeground, UWORD colorBackground)
{
    UWORD xPoint = x;
    UWORD yPoint = y;

    // calculate the maximum number of characters per line
    UWORD maxCharsPerLine = Paint.Width / font->Width - 1;

    const char *currentPtr = pString;
    while (*currentPtr != '\0') {
        // neglect leading ' ' and '\n'
        while(*currentPtr == ' ' || *currentPtr == '\n'){
            currentPtr++;
        }

        char pStringLine[maxCharsPerLine + 1] = {0};

        // prograssively add words to the line until the line is full
        int lineCharCounter = 0;
        while(1){
            // Get the next word (until ' ' or '\n')
            int wordCharCounter = 0;
            char currentChar = *(currentPtr + lineCharCounter + wordCharCounter);
            while(currentChar != '\0' && currentChar != ' ' && currentChar != '\n'){
                wordCharCounter++;
                currentChar = *(currentPtr + lineCharCounter + wordCharCounter);
            }

            // Add current word to line if there's enough space
            if(lineCharCounter + wordCharCounter <= maxCharsPerLine){
                int i;
                for(i = 0; i < wordCharCounter; i++){
                    pStringLine[lineCharCounter + i] = *(currentPtr + lineCharCounter + i);
                }

                lineCharCounter += wordCharCounter;

                // Add a space after the word if there's still space
                if(lineCharCounter < maxCharsPerLine && currentChar != '\0'){
                    pStringLine[lineCharCounter] = ' ';
                    lineCharCounter++;
                }
            }
            else break;

            // if the current word is the last word of the string, break
            if(currentChar == '\0' || lineCharCounter == maxCharsPerLine) break;
        }
        
        // if there is no word added into the line, meaning we have a very long word, just fill the line with the word as far as we can
        if(lineCharCounter == 0){
            int i;
            for(i = 0; i < maxCharsPerLine && *(currentPtr + i) != '\0'; i++){
                pStringLine[i] = *(currentPtr + i);
            }
            lineCharCounter = i;
        }


        // update the current pointer
        currentPtr += lineCharCounter;

        // draw the line
        Paint_DrawString_EN(xPoint, yPoint, pStringLine, font, colorForeground, colorBackground);

        // update the y position if there's something now drawn
        if(*currentPtr){
            yPoint += font->Height;
        }

    }

    return yPoint;
}
