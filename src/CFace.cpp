//==============================================================================
#include "CFace.h"

//==============================================================================
CFace CFace::FaceControl;

//==============================================================================

CFace::~CFace() {
	//free this properly somehow lmao
	for (size_t i =0; i < mEntityList.size(); i++)
		delete mEntityList[i];
}

//==============================================================================
// READY? SPAGHETTI!
bool CFace::OnLoad(const char *file) {
	// Check to make sure it's a valid screen by calling our parent function
	if (!CScreen::OnLoad(file))
		return false;

	// Load in screen/face definition file
	pugi::xml_document doc;
	if (!doc.load_file(file)) return false;

	logger->log(std::string("loaded face file ") + file);
	//std::cout << "loaded face file " << file << std::endl;

	// We have established that there is a screen section present by calling the parent constructor.
	// Instead, check to make sure that there is a valid face section to work with.
	pugi::xml_node face = doc.child("screen").child("face");
	if (face == 0) {
		//No face section, can't load.
		std::cout << "no face section, can't load" << std::endl;
		return false;
	}

	mName = face.attribute("name").as_string();
	mMood = face.attribute("defaultmood").as_string();
	
	pugi::xml_node mood = face.find_child_by_attribute("mood", "name", mMood.c_str());
	pugi::xml_node base = mood.child("base");

	if (base == 0) {
		logger->err(std::string("no base section for default mood " + mMood + ", can't load"));
		return false;
	}

	logger->log(std::string("loading bg from " + mBasePath + "/" + mMood + "/" + base.attribute("file").as_string()));

	mBackground = IMG_Load(std::string(mBasePath + "/" + mMood + "/" + base.attribute("file").as_string()).c_str());

	// Read all sprites in default mood
	for (pugi::xml_node sprite: mood.children("sprite")) {
		CSprite *spr = new CSprite();

		logger->log(std::string(sprite.attribute("name").as_string()));

		std::string spr_fpath = std::string(mBasePath + "/" + mMood + "/" + sprite.attribute("file").as_string());
		logger->log(std::string("loading sprite from file " + spr_fpath
			+ " w: " + sprite.attribute("width").as_string()
			+ " h: " + sprite.attribute("height").as_string()
			+ " framecount: " + sprite.attribute("rows").as_string()));


		
		spr->OnLoad(
			spr_fpath.c_str(),
			sprite.attribute("width").as_int(),
			sprite.attribute("height").as_int(),
			sprite.attribute("rows").as_int()
		);
		
		spr->X = sprite.attribute("x").as_float();
		spr->Y = sprite.attribute("y").as_float();

		spr->SetVisible(sprite.attribute("visible").as_bool());
		spr->SetFrameDelay(sprite.attribute("framedelay").as_int());

		if (sprite.attribute("oscillate").as_bool())
			spr->SetOscillate(true);

		if (sprite.attribute("loopdelay").as_int() > 0)
			spr->SetLoopDelay(sprite.attribute("loopdelay").as_int());

		if (sprite.attribute("animating").as_bool())
			spr->StartAnimating();

		mEntityList.push_back(spr);

		// Stupid simple hook so we can directly manipulate the mouth sprite.
		// This should be made more flexible later.
		if (std::string(sprite.attribute("name").as_string()) == "mouth") {
			mMouth = spr;
		}
	}

	return true;
}

//------------------------------------------------------------------------------
bool CFace::SetMood(char *name) {
	//load mood from file
	return true;
}

bool CFace::isTalking() {
	return mMouth->isAnimating();
}

void CFace::StartTalking() {
	mMouth->StartAnimating();
}

void CFace::StopTalking() {
	mMouth->StopAnimating();
}