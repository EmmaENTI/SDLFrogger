#pragma once
#include <SDL.h>
#include <random>
#include "GameObject.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "SplashScreenScene.h"
#include "MainMenuScene.h"

class GameEngine
{
private:
	//------ EXECUTION CONTROL
	bool isRunning;
	//------ SDL
	int windowWidth;
	int windowHeight;

	SDL_Window* window;
	SDL_Renderer* renderer;

	void InitSDL();
	void InitWindowAndRenderer();
	//------ UPDATE
	void Update();
	//------ RENDER
	void Render();
	//------ IMAGES
	GameObject logo;

public:
	GameEngine(int x, int y);

	void Init();
	void Run();
	void Quit();
};

