#include "CSprite.h"

//=============================================================================
bool CSprite::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    bAnimating = false;
    bVisible = false;

    return true;
}

void CSprite::SetFrameDelay(unsigned int newRate) {
	Anim_Control.SetFrameRate(newRate);
}

bool CSprite::isVisible() {
	return bVisible;
}

void CSprite::SetVisible(bool new_bVisible) {
	bVisible = new_bVisible;
}

void CSprite::StartAnimating() {
	bAnimating = true;
}

void CSprite::StopAnimating() {
	bAnimating = false;
}
//-----------------------------------------------------------------------------
void CSprite::OnLoop() {
	CEntity::OnLoop();
}

//-----------------------------------------------------------------------------
void CSprite::OnRender(SDL_Surface* Surf_Display) {
	if (bVisible)
		CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CSprite::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CSprite::OnAnimate() {
	if(bAnimating) {
		CEntity::OnAnimate();
	}
}
