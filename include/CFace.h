//=============================================================================
#ifndef _CFACE_H_
	#define _CFACE_H_


#include <string>
#include "CScreen.h"
#include "CSprite.h"
#include "CLogger.h"

extern CLogger *logger;

//=============================================================================
class CFace : public CScreen {
	public:
		static CFace FaceControl;
		//TODO maybe define these in XML?
		enum {
			MOOD_NEUTRAL = 0,
			MOOD_HAPPY = 1,
			MOOD_ANGRY = 2,
			MOOD_COLD = 3,
			MOOD_DRUNK = 4,
			MOOD_HOT = 5,
			MOOD_PARTY = 6,
			MOOD_SLEEP = 7,
			MOOD_SURPRISED = 8,
			MOOD_SAD = 9,
			MOOD_POUT = 10
		};
	protected:
		std::string mMood;

	public:
		~CFace();
		bool OnLoad(const char *file);
		//void OnRender(SDL_Surface* Surf_Display);
		bool SetMood(char *newMood);
		bool isTalking();
		void StartTalking();
		void StopTalking(); 

	private:
		CSprite *mMouth;
};

//=============================================================================

#endif


