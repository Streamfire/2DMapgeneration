/*
*
*
*
*/

#include <iostream>
#include <windows.h>
#include "SDL.h"
#include "Framework.hpp"
#include "Game.hpp"
#include "Paths.hpp"


int main(int argc, char **argv)
{
	g_pFramework->Init("BeHives", 100, 100, WINDOWHEIGHT, WINDOWWIDTH, 0);
	
	CGame* Game = new CGame;
	Game->Init();



	Game->Run();
	Game->Quit();


	return 0;
}