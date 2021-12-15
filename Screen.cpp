#include "Screen.h"
#include <string.h>

Screen:: Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){

}
bool Screen:: init(){
    if(SDL_Init(SDL_INIT_VIDEO < 0)){
        return false;
    }
    m_window = SDL_CreateWindow("Particle Effects", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    if (m_window == NULL){
        SDL_Quit();
        return false;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (m_renderer == NULL){
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    } 
    if (m_texture == NULL){
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; //32 bit integer for all systems to represent all the pixels on the screen
    memset(m_buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)); // turn screen black
    return true;
}
void Screen:: close(){
    delete [] m_buffer;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
bool Screen:: processEvents(){
    SDL_Event event;
    while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                return false;
        }
    return true;
}

void Screen::update(){
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    // Method to make the color value an RGBA value
    Uint32 color {};
    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 8;
    color += 0xFF;
    m_buffer[y * SCREEN_WIDTH + x] = color;
}