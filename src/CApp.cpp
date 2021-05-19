//==============================================================================
#include "CApp.h"

CLogger *logger;

//FIXME: TEST CODE
Mix_Chunk *sample;

//==============================================================================
CApp::CApp() {
    Surf_Display = NULL;

    Running = true;
}

//------------------------------------------------------------------------------
int CApp::OnExecute() {
    if(OnInit() == false) {
        std::cout << "Init failed" << std::endl;
        return -1;
    }

    SDL_Event Event;

    while(Running) {
        //TODO: Poll MQTT
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
        SDL_Delay(20); // Let's not murder the CPU
    }

    OnCleanup();

    return 0;
}

//==============================================================================
int main(int argc, char* argv[]) {
    CApp theApp;
    logger = new CLogger;
    int ret = theApp.OnExecute();
    delete logger;
    return ret;
}

//==============================================================================
