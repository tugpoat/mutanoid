//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnCleanup() {
	SDL_FreeSurface(Surf_Display);
	SDL_DestroyTexture(mScreenBuf);
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	IMG_Quit();
	SDL_Quit();
}

//==============================================================================
