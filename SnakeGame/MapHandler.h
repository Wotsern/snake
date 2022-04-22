#ifndef MAPHANDLER_H
#define MAPHANDLER_H

#include "CharacterObject.h"
#include "EndingScene.h"
#include "Helpers.h"
#include "RuntimeInterface.h"

class MapHandler
{
private:
	int				m_rows;								//Amount of rows on a map.
	int				m_columns;							//Amount of columns on a map.
	int				m_x;								//Used to set X pos.
	int				m_y;								//Used to set Y pos.
	int				m_mapGrid[m_mapWidth][m_mapHeight];	//2D array for columns and rows.
	int				m_currentWall;						//Used for incrementation when drawing to the console.
	int				m_mapToLoad;						//Grabs the map the player wants to load.
	CharacterObject m_wallSegments[625];				//Const int
	bool			m_wallCollided;						//Check to see if player has collided with a wall.
	
public:
	MapHandler();

	void initialise();
	
	void render(int mapNumber);
	void drawScore(int score);				//Draws the score to the screen.
	void loadMap(int mapNumber);			//Loads a map based on parameter value passed.
	void buildMap();

	void checkCollision(int xPos, int yPos, RuntimeInterface* runtimeInterface); //Checks for collision with player head and wall.

	CharacterObject getSegmentArray(int i); //Returns the wall array.

	void setMapNumber(int mapNumber); //Sets the map number.
	int getMapNumber();

};

#endif // !MAPHANDLER_H