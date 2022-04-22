#ifndef CHARACTEROBJECT_H
#define CHARACTEROBJECT_H

#include "Vector2.h"

class CharacterObject : public Vector2
{
private:
	char m_char;

public:
	CharacterObject(); //Constructor
	~CharacterObject();

	CharacterObject(char c);
	CharacterObject(char c, int x, int y);

	char getCharacter(); //Getter used to get the current set character attached to 'CharacterObject'.
	void setCharacter(char c); //Used to set the character of the snake.
};


#endif // #define CHARACTEROBJECT_H
