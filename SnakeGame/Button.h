#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

#include "Vector2.h"

class Button : public Vector2{
private:
	std::string	m_text; //Text to display.
	int			m_x;	//Where to position on X axis.
	int			m_y;	//Where to position on Y axis.

public:
	Button();

	void render();

	void setText(std::string buttonText); //Setter for the button.
	std::string getText();
};


#endif // !BUTTON_H
