#pragma once
#include "Scene.h"
#include <iostream>
#include "InputManager.h"
#include "SceneManager.h"

class SplashScreenScene : public Scene
{
	// Inherited via Scene
	virtual void Update(float dt) override;
	virtual void Render(SDL_Renderer*) override;
	virtual void OnEnter() override;
	virtual void OnExit() override;
};