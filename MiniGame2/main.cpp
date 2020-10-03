#include <array>
#include <iostream>

#include <SDL2/SDL.h>
#include <boost/timer/timer.hpp>

#include "local_player.h"

#undef main

void show(SDL_Renderer*, SDL_Texture*);

int main(int argc, char *argv[]) {
    using namespace boost;
    timer::cpu_timer t;

    double tim = 0;
    std::array<Uint8, 4> bg_color = { 50, 50, 50, 255 };
    std::array<Uint8, 4> col1 = { 100, 200, 255, 255 };
    int quit = 0;
    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    SDL_Texture* texture = nullptr;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);


    window = SDL_CreateWindow("Test", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    render = SDL_CreateRenderer(window, -1, 0);

    Local_player square1(render, col1, 10, 10, 10, 10, 100);
    texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 480);
    if (!window) {
        goto __Destroy;
        std::cout << "´°¿Ú±¬Õ¨£¡" << std::endl;
    }
    if (!render) {
        goto __Destroy;
        std::cout << "äÖÈ¾Æ÷±¬Õ¨£¡" << std::endl;
    }
    if (!texture) {
        goto __Destroy;
        std::cout << "ÌùÍ¼±¬Õ¨£¡" << std::endl;
    }


    do {
        t.start();
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
            quit = 1;
        SDL_SetRenderTarget(render, texture);
        SDL_SetRenderDrawColor(render, bg_color[0], bg_color[1], bg_color[2], bg_color[3]);
        SDL_RenderClear(render);
        square1.move_player(tim);
        show(render, texture);
        tim = t.elapsed().wall;
        tim /= 1000000000;
    } while (quit != 1);

__Destroy:
    if (texture)
        SDL_DestroyTexture(texture);
    if (render)
        SDL_DestroyRenderer(render);
    if (window)
        SDL_DestroyWindow(window);


    SDL_Quit();
    return 0;
}


void show(SDL_Renderer* render, SDL_Texture* texture) {
    SDL_SetRenderTarget(render, nullptr);
    SDL_RenderCopy(render, texture, nullptr, nullptr);
    SDL_RenderPresent(render);
}