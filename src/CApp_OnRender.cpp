//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {

	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	SDL_FillRect(Surf_Display, &Rect, SDL_MapRGB(Surf_Display->format, 255,255,255));

	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnRender(Surf_Display);

	mScreenBuf = SDL_CreateTextureFromSurface(mRenderer, Surf_Display);
	if (mScreenBuf == nullptr) {
		//help! jesus take the wheel
	}

	SDL_RenderClear(mRenderer);
	SDL_RenderCopy(mRenderer, mScreenBuf, NULL, NULL);
	SDL_RenderPresent(mRenderer);

}

//==============================================================================
