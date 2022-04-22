#include "CharacterObject.h"
#include "Settings.h"

CharacterObject::CharacterObject()
{
	m_char = c_defaultCharacter; //Set the value of m_char to the default character from 'Settings.h'.
}

CharacterObject::~CharacterObject()
{
	
}

CharacterObject::CharacterObject(char c)
{
	m_char = c;
}

CharacterObject::CharacterObject(char c, int x, int y) //Function used for setting character at set X and Y position.
{
	m_char = c;
	setCurrentPosXY(x, y);
}

char CharacterObject::getCharacter() 
{
	return m_char; //Getter for grabbing the set character.
}

void CharacterObject::setCharacter(char c)
{
	m_char = c; //Setter for CharacterObject class.
}
