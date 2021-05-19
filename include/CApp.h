//==============================================================================
// SDL Tutorial 8
//==============================================================================
#ifndef _CAPP_H_
	#define _CAPP_H_

#include <iostream>

#include <SDL.h>
#include <SDL_mixer.h>


#include "Define.h"

#include "CFPS.h"

#include "CCamera.h"
#include "CEntity.h"
#include "CEvent.h"

#include "CScreen.h"
#include "CFace.h"

#include "CLogger.h"

extern CLogger *logger;

//FIXME: TEST CODE
extern Mix_Chunk *sample;

//==============================================================================
class CApp : public CEvent {
	private:
		bool            Running;
		CScreen*        Active_Screen;

		//SDL Gfx stuff
		SDL_Window      *mWindow;
		SDL_Surface*    Surf_Display;

		//SDL Gfx API stuff
		SDL_Renderer*	mRenderer;
		SDL_Texture*	mScreenBuf;
		SDL_GLContext	mGLContext;


		//SDL Audio stuff
		SDL_AudioDeviceID	mAudioDevId;
		SDL_AudioSpec 		mWavSpec;


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
