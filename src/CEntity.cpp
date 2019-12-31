//==============================================================================
#include "CEntity.h"

//==============================================================================

//==============================================================================
CEntity::CEntity() {
	Surf_Entity = NULL;
	mEntityTex = NULL;

	X = 0;
	Y = 0;

	Width 	= 0;
	Height 	= 0;

	Type = 	ENTITY_TYPE_GENERIC;

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
	SDL_FreeSurface(Surf_Entity);
	SDL_DestroyTexture(mEntityTex);
}

//==============================================================================
bool CEntity::OnLoad(const char* File, int Width, int Height, int MaxFrames) {
	if((Surf_Entity = CSurface::OnLoad(File)) == NULL) {
		return false;
	}

	this->Width = Width;
	this->Height = Height;

	Anim_Control.MaxFrames = MaxFrames;

	return true;
}

//------------------------------------------------------------------------------
void CEntity::OnLoop() {

	if (AccelX != 0)
		SpeedX += AccelX * CFPS::FPSControl.GetSpeedFactor();
	if (AccelY != 0)
		SpeedY += AccelY * CFPS::FPSControl.GetSpeedFactor();

	if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
	if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
	if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
	if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

	OnAnimate();
	OnMove(SpeedX, SpeedY);
}

//------------------------------------------------------------------------------
void CEntity::OnRender(SDL_Renderer* renderer) {
	if(Surf_Entity == NULL) return;
	if (mEntityTex == NULL)
		mEntityTex = SDL_CreateTextureFromSurface(renderer, Surf_Entity);
	else
		SDL_UpdateTexture(mEntityTex, NULL, Surf_Entity->pixels, Width * sizeof(Uint32));
	
	SDL_Rect DestR;

	DestR.x = X - CCamera::CameraControl.GetX();
	DestR.y = Y - CCamera::CameraControl.GetY();
	DestR.w = Width;
	DestR.h = Height;

	SDL_Rect SrcR;

	SrcR.x = CurrentFrameCol * Width;
	SrcR.y = (CurrentFrameRow + Anim_Control.GetCurrentFrame()) * Height;
	SrcR.w = Width;
	SrcR.h = Height;

	SDL_RenderCopy(renderer, mEntityTex, &SrcR, &DestR);
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