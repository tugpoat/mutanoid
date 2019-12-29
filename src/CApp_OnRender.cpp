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

	CFace::FaceControl.OnRender(Surf_Display);
/*
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
*/
	//SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	///SDL_RenderPresent(mRenderer);
    SDL_UpdateWindowSurface(mWindow);
}

//==============================================================================
