//==============================================================================
#include "CScreen.h"

//=============================================================================
CScreen CScreen::ScreenControl;

//=============================================================================
CScreen::~CScreen() {
	SDL_DestroyTexture(mBackgroundTex);
	SDL_FreeSurface(mBackground);
}

//=============================================================================
bool CScreen::OnLoad(const char *file) {
	//glibc implementation of dirname() modifies the passed argument. we need to create a new buffer to avoid a segfault.
	char *tpath = strdup(file);
	mBasePath = std::string(dirname(tpath));
	free(tpath); //clean up

	//load in screen definition file
	pugi::xml_document doc;

	if (!doc.load_file(file)) return false;

	pugi::xml_node screen = doc.child("screen");

	if (screen == 0) {
		//No screen definition found, abort
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------
void CScreen::OnLoop() {
	for(unsigned int i = 0;i < mEntityList.size();i++) {
		if(!mEntityList[i]) continue;

		mEntityList[i]->OnLoop();
	}
}

//------------------------------------------------------------------------------
void CScreen::OnRender(SDL_Renderer* renderer) {
	if (mBackgroundTex == nullptr)
		mBackgroundTex = SDL_CreateTextureFromSurface(renderer, mBackground);

	SDL_RenderCopy(renderer, mBackgroundTex, NULL, NULL);
	for(unsigned int i = 0;i < mEntityList.size();i++) {
		if(!mEntityList[i]) continue;

		mEntityList[i]->OnRender(renderer);
	}
}

//=============================================================================
