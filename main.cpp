#include <iostream>

#include "SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include "sdl_functions.h"



int main(int argc, char* args[]) {
  SDL_Window* window = NULL;
  SDL_Renderer* g_pRenderer = 0;

  SDL_Surface* screenSurface = NULL;
  SDL_Surface* image = nullptr;
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }
  window = SDL_CreateWindow(
                "hello_sdl2",
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
                );
  if (window != NULL) {
      g_pRenderer = SDL_CreateRenderer(window, -1, 0);
  }


  SDL_SetRenderDrawColor(g_pRenderer, 0xff, 0x88, 0xff, 0xff);
  SDL_RenderPresent(g_pRenderer);

  SDL_RenderClear(g_pRenderer);
  SDL_RenderPresent(g_pRenderer);


  screenSurface = SDL_GetWindowSurface(window);
  image = loadSurface("car.bmp", screenSurface->format);
  updateSize(image, 100, 100);


  SDL_BlitSurface(image, NULL, screenSurface, NULL);
  SDL_UpdateWindowSurface(window);
//  SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0x88));
//  SDL_UpdateWindowSurface(window);
//  SDL_Delay(2000);

//    std::cin.get();
//  int running = true;
//  while(running){
//     uint32_t time = SDL_GetTicks();
//     SDL_Event event;
//     while(SDL_PollEvent(&event)){
//         if(event.type==SDL_QUIT){
//             running = false;
//             break;
//         }
//         printf("tick %d \n" , SDL_GetTicks()/100%6);
//     }

//  }
//  SDL_DestroyWindow(window);
//  SDL_Surface *surface;



    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Apply the image
        SDL_BlitSurface( image, NULL, screenSurface, NULL );

        //Update the surface
        SDL_UpdateWindowSurface( window );
        SDL_Delay(33);
        updateSize(image, std::rand()%500, std::rand()%500);
    }

  SDL_Quit();
  std::cout << "sucess";
  return 0;
}
