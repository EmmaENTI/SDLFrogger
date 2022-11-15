#include "GameEngine.h"


//Constructor
GameEngine::GameEngine(int x, int y)
{
	windowHeight = y;
	windowWidth = x;
	isRunning = true;
}

//Actions

#pragma region INITIALIZATION
void GameEngine::Init()
{
	srand(time(NULL));

	InitSDL();
	InitWindowAndRenderer();

	logo.LoadTexture(renderer, "resources/logo.png");
}


//INITIALIZE SDL// -> InitSDL()
	//Ensures that SDL is working and it can run
void GameEngine::InitSDL()
{
	//Load SDL and check if it is correct
	int result = SDL_Init(SDL_INIT_VIDEO);
	//If not negative, process succeeded
	bool success = result >= 0;
	if (!success)
	{
		throw SDL_GetError(); //This will return a message of the error that occured
	}
}

//Create a window and a render ->InitWindowAndRenderer()
	//Window is the surface we render in
	//Renderer paints the surface
void GameEngine::InitWindowAndRenderer()
{
	int result = SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_SHOWN, &window, &renderer);
	bool success = result >= 0;
	if (!success)
	{
		throw SDL_GetError(); //This will return a message of the error that occured
	}

}
#pragma endregion


#pragma region RUN
void GameEngine::Run()
{
	//ESTO VA EN EL INIT
	//BEFORE THE GAME LOOP
	SM->AddScene("Splash Screen", new SplashScreenScene());
	SM->AddScene("Main Menu", new MainMenuScene());
	SM->SetScene("Splash Screen");

	//GAME LOOP
	while (isRunning)
	{
		IM->Listen(); //Singleton
		isRunning = !IM->GetQuitEvent(); //Singleton
		SM->GetCurrentScene()->Update(0.0f);
		//RENDERER
		SDL_SetRenderDrawColor(renderer, 230, 100, 100, 255);
		SDL_RenderClear(renderer);
		SM->GetCurrentScene()->Render(renderer);
		SDL_RenderPresent(renderer);
	}
}

void GameEngine::Update()
{
	// ... 
}

void GameEngine::Render()
{
	SDL_SetRenderDrawColor(renderer, rand()%256, rand() % 256, rand() % 256, 255);
	//Render the background
	SDL_RenderClear(renderer);
	//Background
	//GameObjects
	SDL_RenderCopy(renderer, logo.texture, &logo.sourceRect, &logo.destinationRect);
	//UI
	SDL_RenderPresent(renderer);
}
#pragma endregion


#pragma region QUIT
void GameEngine::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	//Destroy all renderers
	//Destroy all windows
	//Quits SDL
}
#pragma endregion