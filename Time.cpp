#include "Time.h"

Time::Time()
{
    m_prevTime = SDL_GetPerformanceCounter();
}

void Time::Update()
{
    uint64_t m_time = SDL_GetPerformanceCounter();
    uint64_t elpasedTime = m_time - m_prevTime;
    m_prevTime = m_time;

    m_deltaTime = elpasedTime / (float)SDL_GetPerformanceFrequency();
}
