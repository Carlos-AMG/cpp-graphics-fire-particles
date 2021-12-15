#include <SDL2/SDL.h>
#include "Screen.h"

//color works this way: RGBA (Red, Green, Blue, Alpha)


int main(int argv, char** args){


    Screen screen;
    if (screen.init() == false){
        std::cout << "Error initializing SDL"<< std::endl;
    }

    bool quit = false; 
    

    while (1)
    {
        


        screen.setPixel(400, 300, 255,255,255);
        screen.update();
        if (!(screen.processEvents())){
            break;
        }
    }
    screen.close();
    

    return 0;
}