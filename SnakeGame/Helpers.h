#ifndef HELPERS_H
#define HELPERS_H

#include "AudioHandler.h"

const int m_mapHeight = 25;             //Const means values that will not be changed.
const int m_mapWidth = 25;

void drawChar(char c, int x, int y);    //Used for drawing character in set position.

void drawScore(int text, int x, int y); //Used for drawing score text in set position.

void color(int color);                  //Used for setting color.
void gotoxy(int x, int y);              //Used for positioning.

//Macro for safe delete of a pointer.

#define SAFE_DELETE(pointer)     \
if(pointer)                      \
{                                \
    delete pointer;              \
    pointer = nullptr;           \
}                                \

//Macro for playing audio.

#define PLAY_SOUND(int)          \
if(int) {                        \
        AudioHandler audio;      \
        audio.playAudio(int);    \
}                                \

#endif // !HELPERS_H
