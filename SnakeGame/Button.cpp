#include "Button.h"
#include "Helpers.h"

Button::Button()
{
	m_text = "";
}

void Button::render()
{
	gotoxy(getCurrentPosX(), getCurrentPosY()); //Allows for the button to be positioned because of the 'gotoxy' function in the 'Helpers.h'.
	std::cout << m_text; //Display text at location set above.
}

void Button::setText(std::string buttonText)
{
	m_text = buttonText; //Setter for the text.
}

std::string Button::getText()
{
	return std::string(m_text); //Getter for text to display.
}
