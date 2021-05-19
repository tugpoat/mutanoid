//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {

	if (!CFace::FaceControl.isTalking() && Mix_Playing(-1) != 0)
	{
		CFace::FaceControl.StartTalking();
	}
	else if (CFace::FaceControl.isTalking() && Mix_Playing(-1) == 0)
		CFace::FaceControl.StopTalking();

	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnLoop();

	CFPS::FPSControl.OnLoop();

	char Buffer[255];
	sprintf(Buffer, "%s %d", "Mutanoid", CFPS::FPSControl.GetFPS());
	SDL_SetWindowTitle(mWindow, Buffer);
}

//==============================================================================
