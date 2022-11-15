#pragma once
#include "Scene.h"
#include "UIText.h"
#include "SDL_ttf.h"
#include <cassert>
#include "InputManager.h"
#include "SceneManager.h"


class MainMenuScene : public Scene
{
private:
	UIText sampleText;
	TTF_Font* font;
	float buttonAngle;
public:
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};