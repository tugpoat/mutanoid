//=============================================================================
#ifndef _CSPRITE_H_
    #define _CSPRITE_H_

#include "CEntity.h"

//=============================================================================
class CSprite : public CEntity {
    public:
        CSprite();

		bool OnLoad(const char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();
    protected:
    	unsigned int iFrames;
    	bool bAnimating;

};

//=============================================================================

#endif


