#ifndef PAWN_H
#define PAWN_H

#include <array>
#include <memory>

#include <SDL2/SDL.h>

class Pawn {

private:
    SDL_Renderer* render;
    std::array<Uint8, 4> color;
    double x, y, w, h;
    SDL_Rect rect;
    void setRect();
    void drawPawn() const;


public:
    Pawn(SDL_Renderer*, std::array<Uint8, 4>, int, int, int, int);
    void move(double, double);


};
#endif // PAWN_H