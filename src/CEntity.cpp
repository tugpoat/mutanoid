//==============================================================================
#include "CEntity.h"
#include <iostream>
//==============================================================================

//==============================================================================
CEntity::CEntity() {
	Surf_Entity = NULL;

	X = 0;
	Y = 0;

	Width 	= 0;
	Height 	= 0;

	MoveLeft  = false;
	MoveRight = false;

	Type = 	ENTITY_TYPE_GENERIC;

	Dead = false;
	Flags = ENTITY_FLAG_GRAVITY;

	SpeedX = 0;
	SpeedY = 0;

	AccelX = 0;
	AccelY = 0;

	MaxSpeedX = 5;
	MaxSpeedY = 10;

	CurrentFrameCol = 0;
	CurrentFrameRow = 0;

	Col_X = 0;
	Col_Y = 0;

	Col_Width  = 0;
	Col_Height = 0;
}

//------------------------------------------------------------------------------
CEntity::~CEntity() {
}

//==============================================================================
bool CEntity::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
	if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
		return false;
	}

	CSurface::Transparent(Surf_Entity, 255, 0, 255);

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

    return true;
}

//------------------------------------------------------------------------------
void CEntity::OnLoop() {

	SpeedX += AccelX * CFPS::FPSControl.GetSpeedFactor();
	SpeedY += AccelY * CFPS::FPSControl.GetSpeedFactor();

	if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
	if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
	if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
	if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

	OnAnimate();
	OnMove(SpeedX, SpeedY);
}

//------------------------------------------------------------------------------
void CEntity::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Entity == NULL || Surf_Display == NULL) return;

    CSurface::OnDraw(Surf_Display, Surf_Entity, X - CCamera::CameraControl.GetX(), Y - CCamera::CameraControl.GetY(), CurrentFrameCol * Width, (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height, Width, Height);
}

//------------------------------------------------------------------------------
void CEntity::OnCleanup() {
    if(Surf_Entity) {
        SDL_FreeSurface(Surf_Entity);
    }

    Surf_Entity = NULL;
}

//------------------------------------------------------------------------------
void CEntity::OnAnimate() {
	CurrentFrameCol = 0;
	if(MoveLeft) {
		CurrentFrameCol = 0;
	}else

	if(MoveRight) {
		CurrentFrameCol = 1;
	}

	Anim_Control.OnAnimate();
}

//------------------------------------------------------------------------------
bool CEntity::OnCollision(CEntity* Entity) {
	return false;
}

//==============================================================================
void CEntity::OnMove(float MoveX, float MoveY) {

	if(MoveX == 0 && MoveY == 0) return;

	double NewX = 0;
	double NewY = 0;

	MoveX *= CFPS::FPSControl.GetSpeedFactor();
	MoveY *= CFPS::FPSControl.GetSpeedFactor();

	if(MoveX != 0) {
		if(MoveX >= 0) 	NewX =  CFPS::FPSControl.GetSpeedFactor();
		else 			NewX = -CFPS::FPSControl.GetSpeedFactor();
	}

	if(MoveY != 0) {
		if(MoveY >= 0) 	NewY =  CFPS::FPSControl.GetSpeedFactor();
		else 			NewY = -CFPS::FPSControl.GetSpeedFactor();
	}

	while(true) {
		if(Flags & ENTITY_FLAG_GHOST) {
			PosValid((int)(X + NewX), (int)(Y + NewY)); //We don't care about collisions, but we need to send events to other entities

			X += NewX;
			Y += NewY;
		}else{
			if(PosValid((int)(X + NewX), (int)(Y))) {
				X += NewX;
			}else{
				SpeedX = 0;
			}

			if(PosValid((int)(X), (int)(Y + NewY))) {
			    Y += NewY;
			}else{
			    SpeedY = 0;
			}
		}

		MoveX += -NewX;
		MoveY += -NewY;

		if(NewX > 0 && MoveX <= 0) NewX = 0;
		if(NewX < 0 && MoveX >= 0) NewX = 0;

		if(NewY > 0 && MoveY <= 0) NewY = 0;
		if(NewY < 0 && MoveY >= 0) NewY = 0;

		if(MoveX == 0) NewX = 0;
		if(MoveY == 0) NewY = 0;

		if(MoveX == 0 && MoveY 	== 0) 	break;
		if(NewX  == 0 && NewY 	== 0) 	break;
	}
}

//------------------------------------------------------------------------------
void CEntity::StopMove() {
	if(SpeedX > 0) {
		AccelX = -1;
	}

	if(SpeedX < 0) {
		AccelX =  1;
	}

	if(SpeedX < 2.0f && SpeedX > -2.0f) {
		AccelX = 0;
		SpeedX = 0;
	}
}

//==============================================================================
bool CEntity::PosValid(int NewX, int NewY) {
	return true;
}

//------------------------------------------------------------------------------
bool CEntity::PosValidEntity(CEntity* Entity, int NewX, int NewY) {
	return true;
}