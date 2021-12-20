#include "Screen.h"
#include <string.h>

Screen:: Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_bufferSecondary(NULL){

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
    m_bufferSecondary = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    memset(m_buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32)); // clear the buffer
    memset(m_bufferSecondary, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
    return true;
}
void Screen:: close(){
    delete [] m_buffer;
    delete [] m_bufferSecondary;
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
    if (x < 0 or x >= SCREEN_WIDTH or y < 0 or y >= SCREEN_HEIGHT){
        return;
    }
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

void Screen::boxBlur(){
    Uint32 *temp = m_buffer;
    m_buffer = m_bufferSecondary;
    m_bufferSecondary = temp;
    for(int y = 0; y < SCREEN_HEIGHT; y++){
        for (int x = 0; x < SCREEN_WIDTH; x++){
            int redTotal = 0;
            int greenTotal = 0;
            int blueTotal = 0;

            for (int row = -1; row <= 1; row++){
                for (int col = -1; col <= 1; col++){
                    int currentXpos = x + col;
                    int currentYpos = y + row;

                    if (currentXpos >= 0 and currentXpos < SCREEN_WIDTH and currentYpos >= 0 and currentYpos < SCREEN_HEIGHT){
                        Uint32 colour = m_bufferSecondary[currentYpos * SCREEN_WIDTH + currentXpos];
                        Uint8 red = colour >> 24;
                        Uint8 green = colour >> 16;
                        Uint8 blue = colour >> 8;
                        redTotal += red;
                        greenTotal += green;
                        blueTotal += blue;
                    }
                }
            }
            Uint8 red = redTotal/9;
            Uint8 green = greenTotal/9;
            Uint8 blue = blueTotal/9;
            setPixel(x, y, red, green, blue); 
        }
    }
}