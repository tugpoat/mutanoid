//==============================================================================
#include "CApp.h"

//==============================================================================
bool CApp::OnInit() {
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		logger->err(std::string("Failed to init SDL: ") + SDL_GetError());
		return false;
	}

	IMG_Init(IMG_INIT_PNG);
	mWindow = SDL_CreateWindow("Mutanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WWIDTH, WHEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if (mWindow == nullptr) {
		logger->err(std::string("Failed to init window: ") + SDL_GetError());
		return false;
	}

	SDL_SetWindowFullscreen(mWindow, SDL_WINDOW_FULLSCREEN);

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == nullptr) {
		logger->err(std::string("Failed to init renderer: ") + SDL_GetError());
		return false;
	}

	Surf_Display = SDL_GetWindowSurface(mWindow);
	
	mScreenBuf = SDL_CreateTexture(mRenderer,
							SDL_PIXELFORMAT_ARGB8888,
							SDL_TEXTUREACCESS_STREAMING,
							WWIDTH, WHEIGHT);

	if (mScreenBuf == nullptr) {
		//help! jesus take the wheel
		std::cout << "Failed to init screen buffer: " << SDL_GetError() << std::endl;
		return false; 
	}

	// Set up the audio stream
   	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512) < 0) {
   		logger->err(std::string("Failed to init SDL Mixer: ") + SDL_GetError());
   	}

	if (Mix_AllocateChannels(1) < 1)
		logger->err(std::string("Mixer err " )+ Mix_GetError());



	//TODO: Screen Manager to control which screen/face is active/displayed
	CFace::FaceControl.OnLoad("res/faces/miku/face.xml");

	//FIXME: TEST CODE
	sample = Mix_LoadWAV("fmjskull.wav");

	if (Mix_PlayChannel(-1, sample, 0) < 0)
		logger->err(std::string("Mixer err " )+ Mix_GetError());

	return true;
}

//==============================================================================
