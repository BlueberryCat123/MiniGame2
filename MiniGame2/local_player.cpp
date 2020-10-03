#include "local_player.h"

#include <iostream>


Local_player::Local_player(SDL_Renderer* render_, std::array<Uint8, 4> color_, int x_, int y_, int w_, int h_, double speed_) :
    Pawn::Pawn(render_, color_, x_, y_, w_, h_), speed(speed_) {}


void Local_player::move_player(double tim) {
    movex = 0;
    movey = 0;
    const Uint8* state = SDL_GetKeyboardState(NULL);
    using namespace std;
    if (state[SDL_SCANCODE_UP])
        movey -= speed * tim;
    if (state[SDL_SCANCODE_DOWN])
        movey += speed * tim;
    if (state[SDL_SCANCODE_LEFT])
        movex -= speed * tim;
    if (state[SDL_SCANCODE_RIGHT])
        movex += speed * tim;

    move(movex, movey);
}