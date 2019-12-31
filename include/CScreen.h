#ifndef _CSCREEN_H_
	#define _CSCREEN_H_

//STL
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

//platform includes
#include <libgen.h>

//SDL
#include <SDL.h>
#include <SDL_image.h>
#include <pugixml.hpp>

//Project includes
#include "CEntity.h"

class CScreen
{
	public:
		static CScreen			ScreenControl;
		SDL_Surface*			mBackground;
		SDL_Surface*			Surf_Display;

		SDL_Texture*			mBackgroundTex;

	protected:
		std::string				mBasePath, mName;
		unsigned int			mWidth, mHeight;
		std::vector<CEntity *>	mEntityList;

	public:
		virtual bool OnLoad(char *file);
		void OnRender(SDL_Renderer*);
		void OnLoop();

		virtual ~CScreen();

	public:
		int getWidth() { return mWidth;};
		int getHeight() { return mHeight;};
};

#endif
