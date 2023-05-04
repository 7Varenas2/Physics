#include "Graphics.h"
#include "Random.h"
#include <iostream>
#include "Test.h"
#include <SDL.h>
#include <glm/glm.hpp>

int main(int argc, char* argv[]) {

	//Graphics graphics;
	//graphics.CreateWindow("Physics", 800, 600);
	//while (1)
	//{
	//	graphics.Clear();
	//	for (int i = 0; i < 200; i++)
	//	{
	//		graphics.DrawPoint({ randomf(800),randomf(600) }, { randomf(),randomf(),randomf(),randomf() });
	//		graphics.DrawCircle({ randomf(800), randomf(600) }, randomf(10), { randomf(),randomf(),randomf(),randomf() });
	//		graphics.DrawFilledCircle({ randomf(800), randomf(600) }, randomf(10), { randomf(),randomf(),randomf(),randomf() });
	//		graphics.DrawLine({ randomf(800), randomf(600) }, { randomf(800), randomf(600) }, { randomf(),randomf(),randomf(),randomf() });
	//	}
	//	graphics.Present();
	//}

	Test* test = new Test();
	test->Initialize();
	

	//// Run the main loop THIS IS FOR MANUAL EXIT
	//bool quit = false;
	//while (!quit) {
	//	SDL_Event event;
	//	while (SDL_PollEvent(&event)) {
	//		switch (event.type) {
	//		case SDL_QUIT:
	//			quit = true;
	//			break;
	//		}
	//	}
	//}

	// Clean up SDL after 5 seconds
	SDL_Delay(5000);

	return 0;
}