#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2 //Class used widely throughout the game.
{
private:
	int m_x;	//Used for X positioning.
	int m_y;	//Used for Y positioning.

public:
	Vector2();

	void setCurrentPosX(int currentPosX);	//Set current X pos.
	int getCurrentPosX();					//Get current X pos.

	void setCurrentPosY(int currentPosY);	//Set current Y pos.
	int getCurrentPosY();					//Get current Y pos.

	void setCurrentPosXY(int currentPosX, int currentPosY); //Set current XY pos.
	Vector2 getCurrentPosXY();								//Get current XY pos.
};

#endif