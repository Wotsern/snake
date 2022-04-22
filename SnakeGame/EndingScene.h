#ifndef ENDINGSCENE_H
#define ENDINGSCENE_H

#include "Button.h"
#include "Cursor.h"
#include "RuntimeInterface.h"

class EndingScene {
private:
	Cursor		m_cursor;  //Create instance of cursor.
	Button		m_button;  //Create instance of button.
public:
	EndingScene();

	void update(RuntimeInterface* runtimeInterface);
	void loadGameOverScene();
};

#endif //!ENDINGSCENE_H
