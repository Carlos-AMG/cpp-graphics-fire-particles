#include <SDL2/SDL.h>
#include "Screen.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Swarm.h"


//color works this way: RGBA (Red, Green, Blue, Alpha)


int main(int argv, char** args){

    std::srand(time(NULL));
    Screen screen;
    if (screen.init() == false){
        std::cout << "Error initializing SDL"<< std::endl;
    }
    Swarm Zergs;

    bool quit = false; 

    while (1)
    {
        int time_ms = SDL_GetTicks();
        unsigned char green = (1 + sin(time_ms * 0.0001)) * 128; // unsigned char for it to be 1 byte and have a maximum value of 255
        unsigned char red = (1 + sin(time_ms * 0.0002)) * 128;
        unsigned char blue = (1 + sin(time_ms * 0.0003)) * 128;
        const Particle * const pParticles = Zergs.getParticles();
        for (int i = 0; i < Swarm::NPARTICLES; i++){
            Particle particle = pParticles[i];
            int x = (particle.m_xcoord + 1) * screen.SCREEN_WIDTH / 2;
            int y = (particle.m_ycoord + 1) * screen.SCREEN_HEIGHT / 2;
            screen.setPixel(x, y, red, green, blue);
            
        }

        
        
        
        screen.update();
        if (!(screen.processEvents())){
            break;
        }
    }
    screen.close();
    

    return 0;
}