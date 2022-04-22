#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "CharacterObject.h"

class SnakeHead : public CharacterObject {
private:
	char	m_c; //Set characted.
	int		m_x; //Set X pos.
	int		m_y; //Set Y pos.

	char	m_currentKey; //Used for movement.
public:
	SnakeHead();

	void update();
	void render();
	void unrender();
	void inputManager();	//Function that handles player input.
	void playerMovement();	//Function that handles player movement.
};

#endif // !SNAKEHEAD_H
