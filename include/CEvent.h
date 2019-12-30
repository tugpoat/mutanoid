//==============================================================================
#ifndef _CEVENT_H_
	#define _CEVENT_H_

#include <SDL.h>

//==============================================================================
class CEvent {
	public:
		CEvent();

		virtual ~CEvent();

		virtual void OnEvent(SDL_Event* Event);

		virtual void OnInputFocus();

		virtual void OnInputBlur();

		virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod1);

		virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod);

		virtual void OnMinimize();

		virtual void OnRestore();

		virtual void OnResize(int w,int h);

		virtual void OnExpose();

		virtual void OnExit();

		virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

//==============================================================================

#endif
