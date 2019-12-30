//==============================================================================
#ifndef _CENTITY_H_
	#define _CENTITY_H_

#include <vector>

#include "CAnimation.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CSurface.h"

//==============================================================================
enum {
	ENTITY_TYPE_GENERIC = 0,
};

//==============================================================================
enum {
	ENTITY_FLAG_NONE 	= 0,

	ENTITY_FLAG_GRAVITY	= 0x00000001,
	ENTITY_FLAG_GHOST	= 0x00000002,
	ENTITY_FLAG_MAPONLY	= 0x00000004
};

//==============================================================================
class CEntity {
	public:
		static std::vector<CEntity*>    EntityList;

	protected:
		CAnimation      Anim_Control;

		SDL_Surface*    Surf_Entity;

	public:
		float	X;
		float	Y;

		int		Width;
		int		Height;

	public:
		int		Type;
		int		Flags;

	protected:
		float	SpeedX;
		float	SpeedY;

		float	AccelX;
		float	AccelY;

	public:
		float	MaxSpeedX;
		float	MaxSpeedY;

	protected:
		int		CurrentFrameCol;
		int		CurrentFrameRow;

	protected:
		int		Col_X;
		int		Col_Y;
		int		Col_Width;
		int		Col_Height;
	protected:
	 
	public:
	public:
		CEntity();

		virtual ~CEntity();

	public:
		virtual bool OnLoad(const char* File, int Width, int Height, int MaxFrames);

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

		virtual void OnAnimate();

		virtual bool OnCollision(CEntity* Entity);
	public:
		void    OnMove(float MoveX, float MoveY);

		void 	StopMove();

	public:
		bool    Collides(int oX, int oY, int oW, int oH);

	private:
		bool 	PosValid(int NewX, int NewY);

		bool 	PosValidEntity(CEntity* Entity, int NewX, int NewY);
};

//==============================================================================

#endif
