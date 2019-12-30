//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {

	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnLoop();

	CFPS::FPSControl.OnLoop();

	char Buffer[255];
	sprintf(Buffer, "%s %d", "Mutanoid", CFPS::FPSControl.GetFPS());
	SDL_SetWindowTitle(mWindow, Buffer);
}

//==============================================================================
