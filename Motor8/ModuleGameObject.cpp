#include "Globals.h"
#include "Application.h"
#include "ModuleGameObject.h"
#include "ModuleComponent.h"

ModuleGameObject::ModuleGameObject(bool start_enabled) : Module(start_enabled)
{
	name = "GameObject";
}

// Destructor
ModuleGameObject::~ModuleGameObject()
{

}

// Called before render is available
bool ModuleGameObject::Init()
{
	bool ret = true;

	return true;
}

bool ModuleGameObject::Update(float dt)
{
	return true;
}

// Called before quitting
bool ModuleGameObject::CleanUp()
{
	return true;
}
