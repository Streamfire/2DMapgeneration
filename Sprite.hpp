#ifndef SPRITE
#define SPRITE

#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Framework.hpp"



class CSprite
{
public:
	CSprite::CSprite();

	void Load(std::string path);
	
	void Load(std::string path, int NumFrames, int FWidth, int FHeight);
	
	void Rescale(int h, int w);
	void SetPos(int x, int y);
	void ChangePos(int x, int y);

	void Render();
	void Render(float Phase);

	SDL_Rect* GetRect(){ return &ScaleRect; };

private:
	void SetColorKey(int r, int g, int b);


	int FrameHeight, FrameWidth, FrameNum;

	//die beiden Rects zum Rendern
	SDL_Rect ScaleRect;
	SDL_Rect ClipRect;

	SDL_Texture* t_Sprite;
	SDL_Surface* s_Temp;
	SDL_Renderer* s_Renderer;//vom Framework übernommener Zeiger

};
#endif