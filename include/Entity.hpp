#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
    Entity(){}

	Entity(Vector2f p_pos, SDL_Texture* p_tex);
	Vector2f& getPos()
	{
		return pos;
	}
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
	void Entity2(Vector2f p_pos, SDL_Texture* p_tex);
private:
	Vector2f pos;
    char pfp;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
