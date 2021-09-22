#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <string>
#include "../include/RenderWindow.hpp"
#include "../include/Entity.hpp"

#define HEIGHT  32
#define WIDTH   64

using namespace std;

int main(int argc, char* args[])
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

	RenderWindow window("GAME v1.0", 1280, 720);

	SDL_Texture* grassTexture = window.loadTexture("src/gfx/dirt_grass_00.bmp");
	SDL_Texture* dirtTexture = window.loadTexture("src/gfx/dirt_00.bmp");
	SDL_Texture* skyTexture = window.loadTexture("src/gfx/sky_00.bmp");

    Entity entities[HEIGHT][WIDTH];
    Entity cameraGuy = Entity(Vector2f(0, 0), NULL);
    //std::vector<Entity> entitiees = {Entity(Vector2f(0, 0), grassTexture),
    //                      			 Entity(Vector2f(33, 0), grassTexture),
    //                      			 Entity(Vector2f(33, 33), grassTexture),
    //                      			 Entity(Vector2f(33, 66), grassTexture)};

	bool gameRunning = true;

	SDL_Event event;

	while (gameRunning)
	{
		// Get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();


        cameraGuy.pos.y++;
        cameraGuy.pos.x
        ++;


        string FileName = "map00";
        char buf[1000];
        FILE *Myfile;
        FileName = "src/worlds/" + FileName + ".txt";

        char FileNameDraft[FileName.size()+1];
        strcpy(FileNameDraft, FileName.c_str());
        Myfile = fopen(FileNameDraft, "r");

        int i=0;
        while (fgets(buf,1000, Myfile)!=NULL)
        {
            for(int j=0 ; j<WIDTH ; j++)
            {

                if(buf[j]=='x'){
                    entities[i][j].Entity2(Vector2f(32 * j, 32 * i), grassTexture);
                }else if(buf[j]=='g'){
                    entities[i][j].Entity2(Vector2f(32 * j, 32 * i), dirtTexture);
                }else{
                    entities[i][j].Entity2(Vector2f(32 * j, 32 * i), skyTexture);
                }
            }
            std::cout << endl;
            i++;
        }

        fclose(Myfile);

        //window.render(entities[21][33]);
        for(int i=0 ; i<HEIGHT ; i++){
            for(int j=0 ; j<WIDTH ; j++){
    			window.render(entities[i][j], cameraGuy);
            }
        }


		window.display();

	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
