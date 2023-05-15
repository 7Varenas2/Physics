#pragma once
#include <SDL.h>

class Time
{
public:
	Time();

	void Update();
	float TimeDelta() const { return m_deltaTime; }

	// Getter/Setter fixed delta time
	void SetFixedDeltaTime(float fixedDeltaTime) { m_fixedDeltaTime = fixedDeltaTime; }
	float GetFixedDeltaTime() const { return m_fixedDeltaTime; }

private:
	uint64_t m_prevTime{ 0 };
	float m_deltaTime{ 0 };
	float m_fixedDeltaTime{ 0 }; // Step is 60 fps,fixed time step will be 0.016 (1/60)
	float m_fps{ 0 }; // Store the fps


};