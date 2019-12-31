//==============================================================================
// Surface functions
//==============================================================================
#ifndef _CSURFACE_H_
    #define _CSURFACE_H_

#include <SDL.h>
#include <SDL_image.h>

//==============================================================================
class CSurface {
	public:
		CSurface();

	public:
		static SDL_Surface* OnLoad(const char* File);

		static bool OnDraw(SDL_Renderer* renderer, SDL_Texture* Surf_Src, int X, int Y);
		static bool OnDraw(SDL_Renderer *renderer, SDL_Texture* Surf_Src, int X, int Y, int W, int H);

		static bool OnDraw(SDL_Renderer* renderer, SDL_Texture* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

		static bool Transparent(SDL_Texture* Surf_Dest, int R, int G, int B);
};

//==============================================================================

#endif
