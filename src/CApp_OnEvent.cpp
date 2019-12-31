//==============================================================================
#include "CApp.h"

//TODO: Do things with this.
//Make it subscribe to MQTT Events and etc

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
	CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDL_Keycode sym, Uint16 mod){
	switch(sym) {
		case SDLK_LEFT: {
			break;
		}

		case SDLK_RIGHT: {
			break;
		}
		case SDLK_SPACE: {
			break;
		}
		case SDLK_ESCAPE: {
			OnExit();
			break;
		}
		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnKeyUp(SDL_Keycode sym, Uint16 mod){
	switch(sym) {
		case SDLK_LEFT: {
			break;
		}

		case SDLK_RIGHT: {
			break;
		}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
