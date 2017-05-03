#include <SDL.h>
#include "Framework.hpp"
#include "Sprite.hpp"
#include "Paths.hpp"
#include "Map.hpp"
#include "Button.hpp"
#include "Timer.hpp"



class CGame
{
public:
	int Init();
	int Run();
	void Quit();
	
	
	
private:
	bool running;
	
	void Camera();
	void Render();

	bool wheel;

	CMap* Map;

	CSprite* p_Tile;
	SDL_Event* Event;

};