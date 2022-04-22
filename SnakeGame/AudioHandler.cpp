#include <Windows.h>
#include <tchar.h>

#include "AudioHandler.h"


AudioHandler::AudioHandler()
{
}

void AudioHandler::playAudio(int clip)
{
	switch (clip) { //Clip to play.
	case 1:
		PlaySound(_T("gameOver.wav"), NULL, SND_ASYNC); //Play audio clip.
		break;
	case 2:
		PlaySound(_T("enterKey.wav"), NULL, SND_ASYNC);
		break;
	case 3:
		PlaySound(_T("foodCollect.wav"), NULL, SND_ASYNC);
		break;
	case 4:
		PlaySound(_T("clickSound.wav"), NULL, SND_ASYNC);
		break;
	}
}
