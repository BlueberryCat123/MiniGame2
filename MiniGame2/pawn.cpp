#include "pawn.h"

Pawn::Pawn(SDL_Renderer* render_, std::array<Uint8, 4> color_, int x_, int y_, int w_, int h_) :render(render_), color(color_), x(x_), y(y_), w(w_), h(h_) {}

void Pawn::drawPawn() const {
    SDL_SetRenderDrawColor(render, color[0], color[1], color[2], color[3]);
    SDL_RenderDrawRect(render, &rect);
    SDL_RenderFillRect(render, &rect);
}

void Pawn::setRect() {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
}

void Pawn::move(double mx, double my) {
    x += mx;
    y += my;
    setRect();
    drawPawn();
}