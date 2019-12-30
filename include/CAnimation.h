//==============================================================================
// Animation Class
//==============================================================================
#ifndef _CANIMATION_H_
	#define _CANIMATION_H_

#include <SDL.h>

//==============================================================================
class CAnimation {
	private:
		int	    CurrentFrame;
		int     FrameInc;


	private:
		int     FrameRate; //Milliseconds

		long    OldTime;

	public:
		int	    MaxFrames;

		bool	Oscillate;

		unsigned int iLoopDelay;

	public:
		CAnimation();

		void OnAnimate();

	public:
		void SetFrameRate(int Rate);

		void SetLoopDelay(unsigned int Delay);

		void SetCurrentFrame(int Frame);

		int GetCurrentFrame();
};

//==============================================================================

#endif
