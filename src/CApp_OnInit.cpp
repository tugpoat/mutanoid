//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	mWindow = SDL_CreateWindow("Mutanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (mWindow == nullptr) {
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == nullptr) {
		return false;
	}

	Surf_Display = SDL_GetWindowSurface(mWindow);

	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnLoad("res/faces/miku/face.xml");

	return true;
}

//==============================================================================
