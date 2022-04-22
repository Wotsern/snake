#ifndef SURVIVALMODE_H
#define SURVIVALMODE_H

#include "CharacterObject.h"
#include "RuntimeInterface.h"

class SurvivalMode : public CharacterObject{
private:
	int				m_randNum;				//Used for creating holes in the wall.
	int				m_x;					//Set the X pos of the first wall segment.
	int				m_y;					//Set the Y pos of the first wall segment.
	CharacterObject m_wallSegments[90];		//Create array of character objects used to generate the wall.
	bool			m_generateWall;			//Check to see if wall should be generated or not.

public:
	SurvivalMode();

	void update();
	void checkCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface); //Collision checker.
	void render(); //Render wall.
	void unrender(); //Unrender wall.

	void generateNewWall(); //Generates a new wall when called.
	void resetWallPosition(); //Resets the wall position.
	void generateRandomNum(); //Generate new random number for hole in the wall.
};

#endif //!SURVIVALMODE_H
