#include "GameObject.h"

void GameObject::LoadTexture(SDL_Renderer* renderer, std::string path)
{
	SDL_Surface* surface = IMG_Load(path.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

	SDL_FreeSurface(surface);


	destinationRect.w = sourceRect.w;
	destinationRect.h = sourceRect.h;
}

void GameObject::SetPosition(int x, int y)
{
	destinationRect.x = x;
	destinationRect.y = y;

}
