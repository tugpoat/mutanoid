//=============================================================================
#ifndef _CFACE_H_
    #define _CFACE_H_

#include "CScreen.h"

//=============================================================================
class CFace : public CScreen {
    public:
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

        bool OnLoad(char *name);
        void OnRender(SDL_Surface* Surf_Display);
        void OnLoop();
        bool SetMood(unsigned int newMood);
};

//=============================================================================

#endif


