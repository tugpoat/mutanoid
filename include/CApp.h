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

#include "CScreen.h"
#include "CFace.h"

//==============================================================================
class CApp : public CEvent {
	private:
		bool            Running;

		SDL_Window      *mWindow;
		
		CScreen*        Active_Screen;

		SDL_Surface*    Surf_Display;

		//New stuff
		SDL_Renderer*	mRenderer;

		SDL_Texture*	mScreenBuf;

		SDL_GLContext	mGLContext;


	public:
		CApp();

		int OnExecute();

	public:
		bool OnInit();

		void OnEvent(SDL_Event* Event);

			void OnKeyDown(SDL_Keycode sym, Uint16 mod);

			void OnKeyUp(SDL_Keycode sym, Uint16 mod);

			void OnExit();

		void OnLoop();

		void OnRender();

		void OnCleanup();
};

//==============================================================================

#endif
