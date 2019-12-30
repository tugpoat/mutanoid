//==============================================================================
#include "CEvent.h"

//==============================================================================
CEvent::CEvent() {
}

//------------------------------------------------------------------------------
CEvent::~CEvent() {
	//Do nothing
}

//==============================================================================
void CEvent::OnEvent(SDL_Event* Event) {
	switch(Event->type) {

		case SDL_KEYDOWN: {
			OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod);
			break;
		}

		case SDL_KEYUP: {
			OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod);
			break;
		}


		case SDL_QUIT: {
			OnExit();
			break;
		}

		case SDL_SYSWMEVENT: {
			//Ignore
			break;
		}

		default: {
			OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
			break;
		}
	}
}

//------------------------------------------------------------------------------
void CEvent::OnInputFocus() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnInputBlur() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnKeyDown(SDL_Keycode sym, Uint16 mod) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnKeyUp(SDL_Keycode sym, Uint16 mod) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnMinimize() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnRestore() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnResize(int w,int h) {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnExpose() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnExit() {
	//Pure virtual, do nothing
}

//------------------------------------------------------------------------------
void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
	//Pure virtual, do nothing
}

//==============================================================================
