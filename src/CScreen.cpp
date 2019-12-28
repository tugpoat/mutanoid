#include "CScreen.h"
#include <iostream>
#include <sstream>

CScreen CScreen::ScreenControl;
std::vector<CEntity*> 	CEntity::EntityList;

CScreen::CScreen() {

}

bool CScreen::OnLoad(char *file) {
	//load in screen definition file

	mBackground = IMG_Load("res/test.png");

	//populate background/entities/sprites/etc
	CSprite *spr = new CSprite();
	spr->OnLoad("res/yoshi.png",64, 64, 8);
	mEntityList.push_back(spr);

	CSprite *spr2 = new CSprite();
	spr2->OnLoad("res/yoshi.png", 64, 64, 8);
	spr2->X = 420;
	spr2->Y = 420;
	mEntityList.push_back(spr2);
	return true;
}

void CScreen::OnLoop() {
	for(unsigned int i = 0;i < mEntityList.size();i++) {
        if(!mEntityList[i]) continue;

        mEntityList[i]->OnLoop();
    }
}

void CScreen::OnRender(SDL_Surface* Surf_Display) {
	CSurface::OnDraw(Surf_Display, mBackground, 0, 0, Surf_Display->w, Surf_Display->h);
	for(unsigned int i = 0;i < mEntityList.size();i++) {
        if(!mEntityList[i]) continue;

        mEntityList[i]->OnRender(Surf_Display);
    }
}