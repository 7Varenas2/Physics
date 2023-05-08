#include "Graphics.h"
#include "Random.h"
#include "Test.h"
#include "ParticleTest.h"
#include <iostream>
#include <SDL.h>
#include <glm/glm.hpp>

int main(int argc, char* argv[]) 
{
	Test* test = new ParticleTest();
	test->Initialize();
	while (!test->IsQuit()) { test->Run(); }
	delete test;

	return 0;
}