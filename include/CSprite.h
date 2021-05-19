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
		void OnRender(SDL_Renderer* renderer);
		void OnCleanup();
		void OnAnimate();

		void SetFrameDelay(unsigned int);
		void SetLoopDelay(unsigned int);
		bool isVisible();
		void SetVisible(bool);
		void SetOscillate(bool);

		bool isAnimating();
		void StartAnimating();
		void StopAnimating();
	protected:
		unsigned int iFrames;

		bool bAnimating;
		bool bVisible;

};

//=============================================================================

#endif


