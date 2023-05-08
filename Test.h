#pragma once
#include "World.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();

	bool IsQuit() { return m_quit; }

protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };

	class Graphics* m_graphics{ nullptr };
	class Input* m_input{ nullptr };
	class Time* m_time{ nullptr };
	World* m_world{ nullptr };

};
