#include "Game.hpp"




int CGame::Init()
{
	Event = g_pFramework->GetEvent();

	p_Tile = new CSprite;
	p_Tile->Load(P_TILESHEET, 52, 32, 32);
	p_Tile->Rescale(32, 32);

	Map = new CMap;
	Map->Init(p_Tile);
	Map->Generate();
	
	wheel = 0;
	running = true;
	return 0;
}


void CGame::Quit()
{

}

int CGame::Run()
{
while (running == true)
	{
		g_pFramework->Update();
		
		if (Event->type == SDL_QUIT || g_pFramework->KeyState(SDL_SCANCODE_ESCAPE))
			running = false;

		CameraUpdate();
		Map->ScanMouse();
		Map->Update();
		Render();
		
		g_pFramework->Flip();
		g_pFramework->Clear();
	}
return 0;
}



void CGame::Render()
{
	Map->Render();
	

}


void CGame::CameraUpdate()
{
	if (g_pFramework->MWheel() == 0)
		wheel = 0;

	if (wheel == 0)
	{
		if (g_pFramework->MWheel() >= 1)
		{
			Map->Zoom(static_cast<int>(5 * g_pTimer->GetElapsed()*200.f));
			wheel = 1;
		}
		if (g_pFramework->MWheel() <= -1)
		{
			Map->Zoom(static_cast<int>(-5 * g_pTimer->GetElapsed()*200.f));
			wheel = 1;
		}
	}

	if (g_pFramework->KeyState(SDL_SCANCODE_DOWN))
		Map->CamMove(0, static_cast<int>(g_pTimer->GetElapsed()*1000.f));

	if (g_pFramework->KeyState(SDL_SCANCODE_UP))
		Map->CamMove(0, static_cast<int>(-g_pTimer->GetElapsed()*1000.f));

	if (g_pFramework->KeyState(SDL_SCANCODE_LEFT))
		Map->CamMove(static_cast<int>(-g_pTimer->GetElapsed()*1000.f), 0);

	if (g_pFramework->KeyState(SDL_SCANCODE_RIGHT))
		Map->CamMove(static_cast<int>(g_pTimer->GetElapsed()*1000.f), 0);
}
