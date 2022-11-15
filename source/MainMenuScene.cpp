#include "MainMenuScene.h"

void MainMenuScene::Update(float dt)
{
	//Check if the mouse is inside the render rect
	int width = 28 * sampleText.text.length();
	int height = 50;

	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMoyseY();

	int X = sampleText.position[0] - width / 2;
	int Y = sampleText.position[1] - height / 2;

	bool isInsideAABBX = mouseX > X && mouseX < X + width;
	bool isInsideAABBY = mouseY > Y && mouseY < Y + height;

	if (isInsideAABBX && isInsideAABBY)
	{
		buttonAngle += 0.1f;
		if (IM->CheckKeyState(SDLK_j, PRESSED))
		{
			SM->SetScene("Splash Screen");
		}
	}
	else
		buttonAngle = 0;
}

void MainMenuScene::Render(SDL_Renderer* renderer)
{
	//Segun el Edu no va aqui
	//Text data, width y height, color and surrf
	int width = 28 * sampleText.text.length();
	int height = 50;
	SDL_Color color = { 0, 0, 0 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, sampleText.text.c_str(), color);
	assert(surface != nullptr);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	assert(texture != nullptr);

	SDL_SetTextureAlphaMod(texture, 255); //255 -> opaque , 0 -> transparent
	//Siempre para dibujar en SDL, donde esta y cuanto mide
	SDL_Rect renderRect =
	{
		sampleText.position[0] - width/2,
		sampleText.position[1] - height/2,
		width,
		height
	};
	SDL_RenderCopyEx(renderer, texture, NULL, &renderRect, sin(buttonAngle * (3.14f * 2.0f) / 180.0f) *10, NULL, SDL_FLIP_NONE);
	//Renderer, target texture, texture part we want to draw and what size, agle, ceter of sprite, flip sprite
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void MainMenuScene::OnEnter()
{
	//Init TTF
	assert(TTF_Init() != -1);
	//Load the font
	font = TTF_OpenFont("resources/fonts/hyperspace.ttf", 28);
	assert(font != NULL);
	sampleText.text = "Hola ke ase";
	sampleText.position[0] = 250;
	sampleText.position[1] = 250;

	buttonAngle = 0;
}

void MainMenuScene::OnExit()
{

}
