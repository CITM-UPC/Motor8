#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "ModuleUI.h"
ModuleSceneIntro::ModuleSceneIntro(bool start_enabled) : Module(start_enabled)
{
	name = "scene";
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG_COMMENT("Loading Intro assets");
	bool ret = true;

	/*App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));*/

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG_COMMENT("Unloading Intro scene");

	for (int n = 0; n < primitives.size(); n++)
	{
		delete primitives[n];
	}
	primitives.clear();

	return true;
}

// Update
bool ModuleSceneIntro::Update(float dt)
{
	NormalPlane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	
	if (App->ui->testCube)
	{
		Cube c(0.5, 0.5, 0.5);

		//SpherePrimitive s(1, 12, 24);
	}

	for (uint n = 0; n < primitives.size(); n++)
	{
		primitives[n]->Update();
	}

	for (uint j = 0; j < game_objects.size(); j++)
	{
		game_objects.at(j)->Render();
	}

	return true;
}

bool ModuleSceneIntro::PostUpdate()
{
	for (uint n = 0; n < primitives.size(); n++)
	{
		primitives[n]->Render();
	}

	for (uint i = 0; i < game_objects.size(); i++)
	{
		if (game_objects[i]->IsActive())
		{
			game_objects[i]->Update();
		}
	}
	
	return true;
}

ModuleGameObject* ModuleSceneIntro::CreateEmptyGameObject(const char* name, ModuleGameObject* parent)
{
	std::string gameObjName = name;

	if (parent == nullptr)
	{
		std::string gameObjName = name;

		if (!game_objects.empty())
		{
			gameObjName += std::to_string(game_objects.size());
		}
		ModuleGameObject* gameObject = new ModuleGameObject(game_objects.size(), gameObjName, true, false);

		game_objects.push_back(gameObject);
		return gameObject;
	}

	if (parent != nullptr)
	{
		ModuleGameObject* gameObject = new ModuleGameObject(parent->childs.size(), name, true, false);
		parent->childs.push_back(gameObject);
		return gameObject;

	}
}