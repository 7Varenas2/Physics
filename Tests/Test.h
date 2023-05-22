#pragma once
#include "..\Engine\World.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();

	virtual void Render() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Update();
	virtual void PreRender();
	virtual void PostRender();


	bool IsQuit() { return m_quit; }


protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };
	float m_fixedTime{ 0 };

	class Graphics* m_graphics{ nullptr };
	class Input* m_input{ nullptr };
	class Time* m_time{ nullptr };
	World* m_world{ nullptr };

};