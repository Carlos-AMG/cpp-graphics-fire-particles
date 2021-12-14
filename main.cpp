#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

int main(int argv, char** args){

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;


    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        cout << "SDL Init failed" << endl;
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == NULL){
        SDL_Quit();
        return 2;
    }

    while (true)
    {
        //update
    }
    


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}