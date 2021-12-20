#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <SDL2/SDL.h>

class Screen{
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *m_texture;
    Uint32  *m_buffer;
public:
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;
    Screen();
    bool init();
    void close();
    bool processEvents();
    void update();
    void setPixel(int, int, Uint8, Uint8, Uint8);
    void clear();
};

#endif