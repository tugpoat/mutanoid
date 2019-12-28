#include "CSprite.h"

CSprite::CSprite() {

}

//=============================================================================
bool CSprite::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }
    bAnimating = true;
    return true;
}

//-----------------------------------------------------------------------------
void CSprite::OnLoop() {
	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CSprite::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CSprite::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CSprite::OnAnimate() {
	if(bAnimating)
		CEntity::OnAnimate();
}
