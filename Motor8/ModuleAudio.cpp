#include "Globals.h"
#include "Application.h"
#include "ModuleAudio.h"

//#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio(bool start_enabled) : Module(start_enabled)
{
	name = "Audio";
}

// Destructor
ModuleAudio::~ModuleAudio()
{}

// Called before render is available
bool ModuleAudio::Init()
{
	LOG_COMMENT("Loading Audio Mixer");
	bool ret = true;

	return ret;
}

// Called before quitting
bool ModuleAudio::CleanUp()
{
	LOG_COMMENT("Freeing sound FX, closing Mixer and Audio subsystem");

	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}

// Play a music file
bool ModuleAudio::PlayMusic(const char* path, float fade_time)
{
	bool ret = true;

	LOG_COMMENT("Successfully playing %s", path);
	return ret;
}

// Load WAV
unsigned int ModuleAudio::LoadFx(const char* path)
{
	unsigned int ret = 0;

	return ret;
}

// Play WAV
bool ModuleAudio::PlayFx(unsigned int id, int repeat)
{
	bool ret = false;

	return ret;
}