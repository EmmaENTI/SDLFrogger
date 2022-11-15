#include "SplashScreenScene.h"

void SplashScreenScene::Update(float dt)
{
	if (IM->CheckKeyState(SDLK_SPACE, PRESSED))
		SM->SetScene("Main Menu");
}

void SplashScreenScene::Render(SDL_Renderer* rederer)
{

}

void SplashScreenScene::OnEnter()
{
	std::cout << "Entering Splash Screen" << std::endl;
}

void SplashScreenScene::OnExit()
{
	std::cout << "Exiting Splash Screen" << std::endl;
}


//Time manager, tutorial de lazyfu?