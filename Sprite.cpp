#include "Sprite.hpp"
CSprite::CSprite()
{
	t_Sprite = NULL;
	s_Temp = NULL;
	s_Renderer = NULL;

	s_Renderer = g_pFramework->GetScreen();
	if (s_Renderer == NULL)
	{
		printf("Fehler beim abholen des Renderers");
	}

	ScaleRect.h = 0;
	ScaleRect.w = 0;
	ScaleRect.x = 0;
	ScaleRect.y = 0;

	ClipRect.h = 0;
	ClipRect.w = 0;
	ClipRect.x = 0;
	ClipRect.y = 0;

	FrameHeight = 0;
	FrameWidth = 0;
	FrameNum = 0;

}

void CSprite::Load(std::string path)
{
	//bmp aus dem angegebenen Pfasd laden
	s_Temp = IMG_Load(path.c_str());
	if (s_Temp == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		printf("Fehler beim erstellen der Surface\n");
	}

	
	
	//aus der Surface eine textur erstellen
	t_Sprite = SDL_CreateTextureFromSurface(s_Renderer, s_Temp);
	if (t_Sprite == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		printf("Fehler beim erstellen der Textur\n");
	}


	ClipRect.h = s_Temp->h;
	ClipRect.w = s_Temp->w;
	ClipRect.x = 0;
	ClipRect.y = 0;

	ScaleRect.h = s_Temp->h;
	ScaleRect.w = s_Temp->w;
	ScaleRect.x = 0;
	ScaleRect.y = 0;
}



//animierten Sprite laden
void CSprite::Load(std::string path, int NumFrames, int FWidth, int FHeight)
{
	Load(path);

	ClipRect.w = FWidth;
	ClipRect.h = FHeight;
	FrameHeight = FHeight;
	FrameWidth = FWidth;
	FrameNum = NumFrames;
}


void CSprite::SetColorKey(int r, int g, int b)
{
	//transparente Farbe setzen
	SDL_SetColorKey(s_Temp, 1,
		SDL_MapRGB(s_Temp->format, r, g, b));
}

//Setzen von höhe und Weite des Scalerects
void CSprite::Rescale(int h, int w)
{
	if (w != 0)
		ScaleRect.w = w;

	if (h != 0)
		ScaleRect.h = h;
}

void CSprite::SetPos(int x, int y)
{
	//Position festlegen
	ScaleRect.x = x;
	ScaleRect.y = y;

}

void CSprite::ChangePos(int x, int y)
{
	//Position relativ zur momentanen ändern
	ScaleRect.x = ScaleRect.x + x;
	ScaleRect.y = ScaleRect.y + y;
}

void CSprite::Render()
{
	//Sprite in den Renderkontext des Fensters kopieren
	SDL_RenderCopy(s_Renderer, t_Sprite, &ClipRect, &ScaleRect);
}

//ausschnitt des Spritesheet rendern, der der übergebenen Animationsphase entspricht
void CSprite::Render(float Phase)
{

	//position des zu rendernden ausschnittes auf dem Spritesheet
	int col = static_cast<int>(Phase) % (s_Temp->w / FrameWidth);
	int row = static_cast<int>(Phase) / (s_Temp->w / FrameWidth);

	ClipRect.x = col*FrameWidth;
	ClipRect.y = row*FrameHeight;

	SDL_RenderCopy(s_Renderer, t_Sprite, &ClipRect, &ScaleRect);
}