//==============================================================================
// SDL Tutorial 8
//==============================================================================
#ifndef _CAPP_H_
	#define _CAPP_H_

#include <SDL.h>

#include "Define.h"

#include "CFPS.h"

#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"
#include "CSurface.h"


#include "CScreen.h"
#include "CFace.h"

//==============================================================================
class CApp : public CEvent {
	private:
		bool            Running;

		SDL_Window      *mWindow;
		
		CScreen*        Active_Screen;

		SDL_Surface*    Surf_Display;


	public:
		CApp();

		int OnExecute();

	public:
		bool OnInit();

		void OnEvent(SDL_Event* Event);

			void OnKeyDown(SDL_Keysym sym, SDL_Keymod mod);

			void OnKeyUp(SDL_Keysym sym, SDL_Keymod mod);

			void OnExit();

		void OnLoop();

		void OnRender();

		void OnCleanup();
};

//==============================================================================

#endif
