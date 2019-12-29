#include "CFace.h"
CFace CFace::FaceControl;

CFace::~CFace() {
	//free this properly somehow lmao
	for (size_t i =0; i < mEntityList.size(); i++)
		delete mEntityList[i];
}

bool CFace::OnLoad(char *file) {

	//Check to make sure it's a valid screen by calling our parent function
	if (!CScreen::OnLoad(file))
		return false;


	//load in screen definition file
	pugi::xml_document doc;
	if (!doc.load_file(file)) return false;
	std::cout << "loaded face file " << file << std::endl;

	//we have established that there is a screen section present by calling the parent constructor
	pugi::xml_node face = doc.child("screen").child("face");
	if (face == 0) {
		//No face section, can't load.
		std::cout << "no face section, can't load" << std::endl;
		return false;
	}

	std::cout << "found face" << std::endl;

	mName = face.attribute("name").as_string();
	mMood = face.attribute("defaultmood").as_string();
	
	pugi::xml_node mood = face.find_child_by_attribute("mood", "name", mMood.c_str());
	pugi::xml_node base = mood.child("base");
	if (base == 0) {
		//No face section, can't load.
		std::cout << "no base section for default mood " << mMood << ", can't load" << std::endl;
		return false;
	}

	std::cout << "loading bg from " << std::string(mBasePath + "/" + mMood + "/" + base.attribute("file").as_string()) << std::endl;
	mBackground = IMG_Load(std::string(mBasePath + "/" + mMood + "/" + base.attribute("file").as_string()).c_str());

	for (pugi::xml_node sprite: mood.children("sprite")) {
		CSprite *spr = new CSprite();
		std::string spr_fpath = std::string(mBasePath + "/" + mMood + "/" + sprite.attribute("file").as_string());
		std::cout << "loading sprite from file " << spr_fpath << " w: " << sprite.attribute("width").as_int() << " h: " << sprite.attribute("height").as_int() << " framecount: " << sprite.attribute("rows").as_int() << std::endl;
		spr->OnLoad(spr_fpath.c_str(), sprite.attribute("width").as_int(), sprite.attribute("height").as_int(), sprite.attribute("rows").as_int());
		std::cout << sprite.attribute("x").as_float() << sprite.attribute("y").as_float() << std::endl;
		spr->X = sprite.attribute("x").as_float();
		spr->Y = sprite.attribute("y").as_float();
		spr->StartAnimating();
		mEntityList.push_back(spr);
	}

	return true;
}

bool CFace::SetMood(char *name) {
	return true;
}