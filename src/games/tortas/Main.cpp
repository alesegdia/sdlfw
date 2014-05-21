#include <stdlib.h>
#include <SDL2/SDL.h>

#include <iostream>

#include "tortasapp.h"

int main (int argc, char** argv)
{
	TortasApp app;

	switch(app.Exec(argc,argv))
	{
		case -1: printf("Couldn't init SDL.\n"); break;
		case -2: printf("Couldn't create screen.\n");
		case 0: printf("Clean exit.");
	}
	fflush(stdout);

	return EXIT_SUCCESS;
}
