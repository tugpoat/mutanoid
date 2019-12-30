//=============================================================================
#ifndef _CSPRITE_H_
	#define _CSPRITE_H_
#include <iostream>
#include "CEntity.h"

//=============================================================================
class CSprite : public CEntity {
	public:
		CSprite() : CEntity::CEntity() {};

		bool OnLoad(const char* File, int Width, int Height, int MaxFrames);

		void OnLoop();
		void OnRender(SDL_Surface* Surf_Display);
		void OnCleanup();
		void OnAnimate();

		void SetFrameDelay(unsigned int);
		bool isVisible();
		void SetVisible(bool);
		void StartAnimating();
		void StopAnimating();
	protected:
		unsigned int iFrames;
		bool bAnimating;
		bool bVisible;

};

//=============================================================================

#endif


