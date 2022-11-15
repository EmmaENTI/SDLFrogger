#pragma once
#include <SDL.h>
#include <string>
#include <SDL_image.h>

class GameObject
{
private:

public:
	GameObject() = default;
	void LoadTexture(SDL_Renderer* renderer, std::string path);
	void SetPosition(int x, int y);
	//Hauria de ser privat
	SDL_Texture* texture;
	SDL_Rect destinationRect;
	SDL_Rect sourceRect;
};

