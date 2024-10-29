#ifndef __ModuleUI_H__
#define __ModuleUI_H__

#include "Module.h"
#include "SDL/include/SDL.h"
#include <vector>

class Application;
class UI;
class AboutMenu;

class ModuleUI : public Module
{
public:
	ModuleUI(bool start_enabled = true);

	// Destructor
	virtual ~ModuleUI();

	bool Init();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

public:
	void MainMenu();

	bool fullscreen;
	int screenWidth;
	int screenHeight;

	bool enableAboutMenu;

	AboutMenu* aboutMenu;
private:
	std::vector<UI*> menus;

};

#endif // __ModuleWindow_H__
