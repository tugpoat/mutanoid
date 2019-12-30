//=============================================================================
#ifndef _CFACE_H_
	#define _CFACE_H_


#include <string>
#include "CScreen.h"
#include "CSprite.h"

//=============================================================================
class CFace : public CScreen {
	public:
		static CFace FaceControl;
		enum {
			MOOD_NORMAL = 0,
			MOOD_ANGRY = 1,
			MOOD_COLD = 2,
			MOOD_DRUNK = 3,
			MOOD_HOT = 4,
			MOOD_PARTY = 5,
			MOOD_SLEEP = 6,
			MOOD_SURPRISED = 7
		};
	protected:
		std::string  mMood;

	public:
		~CFace();
		bool OnLoad(char *file);
		//void OnRender(SDL_Surface* Surf_Display);
		bool SetMood(char *newMood);

	private:
};

//=============================================================================

#endif


