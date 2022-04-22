#ifndef RUNTIMEINTERFACE_H
#define RUNTIMEINTERFACE_H

#include "Vector2.h"

class RuntimeInterface : public Vector2 {
private:
	int		m_playerScore;  //Used to keep track of player score.
	int		m_x;			//Used for X pos.
	int		m_y;			//Used for Y pos.

public:
	RuntimeInterface();

	void update();

	void setCurrentScore(int currentScore); //Setter for current score.
	int getCurrentScore();					//Getter for current score.
};

#endif // !RUNTIMEINTERFACE_H
