#ifndef LOCAL_PLAYER_H
#define LOCAL_PLAYER_H
#include "pawn.h"

#include <SDL2/SDL.h>

class Local_player : protected Pawn
{
public:
    Local_player(SDL_Renderer*, std::array<Uint8, 4>, int, int, int, int, double);
    void move_player(double);
private:
    double movex = 0, movey = 0;
    double speed;
};

#endif // LOCAL_PLAYER_H