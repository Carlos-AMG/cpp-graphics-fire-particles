#include <iostream>
#include <string.h>
#include <SDL2/SDL.h>

int main(int argv, char** args){
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        std::cout << "SDL Init failed" << std::endl;
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Particle Effects", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (window == NULL){
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (renderer == NULL){
        std::cout << "Could not create renderer"<<std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    } 
    if (texture == NULL){
        std::cout << "Could not create textures"<<std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Uint32  *buffer = new Uint32(SCREEN_WIDTH * SCREEN_HEIGHT); //32 bit integer for all systems to represent all the pixels on the screen
    memset(buffer, 255, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    bool quit = false; 
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = true;
            
        }
        
    }

    delete [] buffer;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}