#ifndef SNAKETAIL_H
#define SNAKETAIL_H

#include "CharacterObject.h"
#include "RuntimeInterface.h"
#include "SnakeHead.h"

class SnakeTail {
private:
	int					m_totalSnakeSegments; 
	CharacterObject		m_segments[10000]; //Magic array that stores tail segments.
	Vector2				m_previousPositions[10000]; //Stores previous positions of head.

	int					m_currentMove;
public:
	SnakeTail();

	//void update(int xPos, int yPos);
	void update(int xPos, int yPos, RuntimeInterface* runtimeInterface);
	void render();
	void unrender();
	void setNewPosition(int xPos, int yPos); //Position handler of all tail segments.

	void checkTailCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface); //Collision checker for head against tail.

	int getTailLength();				//Getter for tail length.
	void setTailLength(int tailLength); //Setter for tail length.
};

#endif // !SNAKETAIL_H
