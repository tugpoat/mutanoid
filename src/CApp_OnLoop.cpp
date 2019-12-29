//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnLoop() {
    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(unsigned int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();
    }

    CFace::FaceControl.OnLoop();

    CFPS::FPSControl.OnLoop();

    char Buffer[255];
    sprintf(Buffer, "%s %d", "Mutanoid", CFPS::FPSControl.GetFPS());
    SDL_SetWindowTitle(mWindow, Buffer);
}

//==============================================================================
