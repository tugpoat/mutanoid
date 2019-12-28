#ifndef _CSCREEN_H_
    #define _CSCREEN_H_

#include <vector>
#include <SDL.h>
#include <SDL_image.h>

#include "CEntity.h"
#include "CSprite.h"

class CScreen
{
	public:
		static CScreen			ScreenControl;
		SDL_Surface*			mBackground;
		SDL_Surface*			Surf_Display;

	private:
		unsigned int			mWidth, mHeight;
		std::vector<CEntity *>	mEntityList;

	public:
		CScreen();

	public:
		bool OnLoad(char *name);
		void OnRender(SDL_Surface* Surf_Display);
		void OnLoop();

    public:
        int getWidth() { return mWidth;};
        int getHeight() { return mHeight;};
};

#endif
