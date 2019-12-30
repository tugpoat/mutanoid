//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	mWindow = SDL_CreateWindow("Mutanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN );

	Surf_Display = SDL_GetWindowSurface(mWindow);

	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnLoad("res/faces/yaranaika/face.xml");

	return true;
}

//==============================================================================
