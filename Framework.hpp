#ifndef FRAMEWORK
#define FRAMEWORK

#include "SDL.h"   
#include "SDL_image.h"// SDL-Header

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "TSingleton.hpp"
#include "Paths.hpp"
#include "Sprite.hpp"
#include "Timer.hpp"

#define g_pFramework CFramework::Get()

class CFramework :public TSingleton<CFramework>
{
public:
	void Init(const char *Title, int x, int y, int h, int w, bool fullscreen);
	void Update();
	void Clear();
	void Flip();




	bool KeyState(int KeyID);
	//Mausover
	bool CFramework::Mouseover(SDL_Rect Rect);
	//Linke Maustaste
	bool LMouseState(SDL_Rect Rect);
	bool LMouseState();
	//mittlere Maustaste
	bool MMouseState(SDL_Rect Rect);
	bool MMouseState();
	//rechte Maustaste
	bool RMouseState(SDL_Rect Rect);
	bool RMouseState();
	//Mausrad//positiv für hoch, negativ für runter
	int MWheel();


	bool CheckCollision(SDL_Rect A, SDL_Rect B);//Abfrage "überlappen 2 Rects?"
	int getRand(int min, int max);


	void Quit();
	SDL_Renderer* GetScreen(){ return Screen; };
	SDL_Event* GetEvent(){ return Event; };


private:

	int mouse_x, mouse_y;
	int wheel;
	

	SDL_Window* window;//Fensterhandle
	SDL_Renderer* Screen;//FensterFläche

	SDL_Event* Event;//Events, abfrage was mit dem Fenster passiert; e.g. X-Klick als SDL_QUIT
	const Uint8* Keystate;//Tastaturarray

	SDL_Texture* t_Background;
	
};





#endif