#include "Vector2.h"

Vector2::Vector2() //This class is used widely throughout the entire project.
{
	m_x = 0;
	m_y = 50;
}

void Vector2::setCurrentPosX(int currentPosX)
{
	m_x = currentPosX; //Setter for X position.
}

int Vector2::getCurrentPosX()
{
	return m_x; //Getter for the X position.
}

void Vector2::setCurrentPosY(int currentPosY)
{
	m_y = currentPosY; //Setter for the Y position.
}

int Vector2::getCurrentPosY()
{
	return m_y; //Getter for the Y position.
}

void Vector2::setCurrentPosXY(int currentPosX, int currentPosY) //Setter for both X and Y position.
{
	m_x = currentPosX;
	m_y = currentPosY;
}

Vector2 Vector2::getCurrentPosXY()
{
	return Vector2(); //Getter for the current position (X and Y values returned of any instance that inherits this class).
}