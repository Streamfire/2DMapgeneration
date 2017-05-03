#ifndef TIMER
#define TIMER

#include <SDL.h>
#include "TSingleton.hpp"

#define g_pTimer CTimer::Get()

class CTimer : public TSingleton < CTimer >
{
private:
	float m_fElapsed;//Zeit seit letztem Frame
	float m_fCurTime;//Aktuelle Zeit
	float m_fLastTime;//Zeit beim letzten Frame

public:
	CTimer();
	void Update();
	float GetElapsed(){ return m_fElapsed; };

};


#endif