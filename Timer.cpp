#include "Timer.hpp"

CTimer::CTimer()
{
	m_fElapsed = 0.0f;
	m_fCurTime = SDL_GetTicks() / 1000.0f;
	m_fLastTime = 0.0f;

}


//Timer updaten
void CTimer::Update()
{
	m_fCurTime = SDL_GetTicks() / 1000.0f;

	m_fElapsed = m_fCurTime - m_fLastTime;//Zeit seit letzem frame

	m_fLastTime = m_fCurTime;

}