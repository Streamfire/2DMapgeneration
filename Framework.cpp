#include "Framework.hpp"

void CFramework::Init(const char *Title, int x, int y, int h, int w, bool fullscreen)
{	
	SDL_ShowCursor(0);
	window = NULL;

	//SDL Inittialisieren
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Fehler beim initialisieren der SDL\n");
		printf(SDL_GetError());
	}
	//SDL Image initialisieren
	if (IMG_Init(IMG_INIT_JPG || IMG_INIT_PNG || IMG_INIT_TIF || IMG_INIT_WEBP ) < 0)
	{
		printf("Fehler beim initialisieren der SDL_image\n");
		printf(SDL_GetError());
	}

	//Fenster erzeugen
	if (fullscreen == false)
	{
		window = SDL_CreateWindow(Title, x, y,
			w, h,
			SDL_WINDOW_SHOWN);
	}
	else {
		window = SDL_CreateWindow(Title, x, y,
			w, h,
			SDL_WINDOW_SHOWN || SDL_WINDOW_FULLSCREEN);
	}
	if (window == NULL)
	{
		printf("Fehler beim erstellen des Fensters\n");
		printf(SDL_GetError());
	}

	//RenderContext für das Window erstellen
	Screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (Screen == NULL)
	{
		printf("Fehler beim erstellen des Renderers\n");
		printf(SDL_GetError());
	}


	
	//Sprite für den Background laden
	SDL_Surface* s_Temp;
	s_Temp = SDL_LoadBMP(P_FRAMEBACKGROUND);
	if (s_Temp == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		printf("Fehler beim erstellen der Surface für den Framebackground\n");
	}

	//aus der Surface eine textur erstellen
	t_Background = SDL_CreateTextureFromSurface(Screen, s_Temp);
	if (t_Background == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
		printf("Fehler beim erstellen der Textur fürs Backgroundimage\n");
	}



	Clear();
	srand(static_cast<int>(time(NULL)));

	

	Event = new SDL_Event();
}

void CFramework::Clear()
{
	SDL_RenderClear(Screen);
	SDL_RenderCopy(Screen, t_Background, NULL, NULL);
}

void CFramework::Flip()
{
	SDL_RenderPresent(Screen);
}

void CFramework::Update()
{
	SDL_PumpEvents();
	SDL_PollEvent(Event);

	//tastaturstatus
	Keystate = SDL_GetKeyboardState(NULL);
	
	//Mausstatus
	SDL_GetMouseState(&mouse_x, &mouse_y);
	
	wheel = 0;
	if (Event->type==SDL_MOUSEWHEEL)
	wheel = Event->wheel.y;
	
	
	g_pTimer->Update();
}
//Cleanup
void CFramework::Quit()
{
	printf("Starte Framework::Quit\n");
	IMG_Quit();
	SDL_DestroyRenderer(Screen);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}
//Frameworkfunktionen
//möglicherweise mal in eine enigne Klasse auslagern

//Prüfen ob [Taste] gedrückt ist
bool  CFramework::KeyState(int KeyID)
{

	if (Keystate[KeyID])
	{
		return true;
	}
	else  return false;
}


bool CFramework::LMouseState(SDL_Rect Rect)
{

	if (
		Rect.y	< (mouse_y) &&//obere Kante Rect über unterer Kante B
		(Rect.y + Rect.h) >	mouse_y		&&//untere Kante Rect unter der oberen Kante B
		Rect.x	< (mouse_x) &&//linke Seite Rect links der rechten Seite B
		(Rect.x + Rect.w) >	mouse_x)	  //rechte Kante A rechts der linken Kante B
	{
		 if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
		{
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool CFramework::LMouseState()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		return true;
	}
	else{
		return false;
	}
}

bool CFramework::Mouseover(SDL_Rect Rect)
{
	if (
		Rect.y	< (mouse_y) &&//obere Kante Rect über unterer Kante B
		(Rect.y + Rect.h) >	mouse_y		&&//untere Kante Rect unter der oberen Kante B
		Rect.x < (mouse_x) &&//linke Seite Rect links der rechten Seite B
		(Rect.x + Rect.w) > mouse_x)	  //rechte Kante A rechts der linken Kante B
	{
		return true;

	}
	else
		return false;

}



bool CFramework::MMouseState(SDL_Rect Rect)
{

	if (
		Rect.y	< (mouse_y) &&//obere Kante Rect über unterer Kante B
		(Rect.y + Rect.h) >	mouse_y		&&//untere Kante Rect unter der oberen Kante B
		Rect.x	< (mouse_x) &&//linke Seite Rect links der rechten Seite B
		(Rect.x + Rect.w) >	mouse_x)	  //rechte Kante A rechts der linken Kante B
	{
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
		{
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool CFramework::MMouseState()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
	{
		return true;
	}
	else{
		return false;
	}
}

bool CFramework::RMouseState(SDL_Rect Rect)
{

	if (
		Rect.y	< (mouse_y) &&//obere Kante Rect über unterer Kante B
		(Rect.y + Rect.h) >	mouse_y		&&//untere Kante Rect unter der oberen Kante B
		Rect.x	< (mouse_x) &&//linke Seite Rect links der rechten Seite B
		(Rect.x + Rect.w) >	mouse_x)	  //rechte Kante A rechts der linken Kante B
	{
		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
		{
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool CFramework::RMouseState()
{
	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
	{
		return true;
	}
	else{
		return false;
	}
}

int CFramework::MWheel()
{
	if (Event->type == SDL_MOUSEWHEEL)
		return Event->wheel.y;
	else return 0;
	
	
}

//liefert einen zufälligen int Wert zwischen min und max(eingeschlossen min und max)
int CFramework::getRand(int min, int max)
{
	return (rand() % (max-min+1) + (min));

}

//gibt true zurück wenn die zwei übergebenen Rects sich überlappen
bool CFramework::CheckCollision(SDL_Rect A, SDL_Rect B)
{

	if (
		A.y	< (B.y + B.h) &&//obere Kante A über unterer Kante B
		(A.y + A.h) >	B.y		&&//untere Kante A unter der oberen Kante B
		A.x	< (B.x + B.w) &&//linke Seite A links der rechten Seite B
		(A.x + A.w) >	B.x)	  //rechte Kante A rechts der linken Kante B
	{
		//Kollision
		return true;
	}
	else
	{
		//keine Kollision
		return false;
	}

}
