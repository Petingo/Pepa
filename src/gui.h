// #ifndef __GUI_PAINT_H
// #define __GUI_PAINT_H

// #include "utility/Debug.h"
// #include "DEV_Config.h"
// #include "fonts.h"

// namespace pepa{

// class Gui {
//     Gui() = default;
//     ~Gui() = default;

//     UWORD DrawString(UWORD x, UWORD y, const char * pString,
//                      sFONT* Font, UWORD colorForeground, UWORD colorBackground);
// }

// }

// void Paint_DrawString_EN(UWORD Xstart, UWORD Ystart, const char * pString,
//                          sFONT* Font, UWORD Color_Foreground, UWORD Color_Background)
// {
//     UWORD Xpoint = Xstart;
//     UWORD Ypoint = Ystart;

//     if (Xstart > Paint.Width || Ystart > Paint.Height) {
//         Debug("Paint_DrawString_EN Input exceeds the normal display range\r\n");
//         return;
//     }

//     while (* pString != '\0') {
//         //if X direction filled , reposition to(Xstart,Ypoint),Ypoint is Y direction plus the Height of the character
//         if ((Xpoint + Font->Width ) > Paint.Width ) {
//             Xpoint = Xstart;
//             Ypoint += Font->Height;
//         }

//         // If the Y direction is full, reposition to(Xstart, Ystart)
//         if ((Ypoint  + Font->Height ) > Paint.Height ) {
//             Xpoint = Xstart;
//             Ypoint = Ystart;
//         }
//         Paint_DrawChar(Xpoint, Ypoint, * pString, Font, Color_Background, Color_Foreground);

//         //The next character of the address
//         pString ++;

//         //The next word of the abscissa increases the font of the broadband
//         Xpoint += Font->Width;
//     }
// }

// #endif