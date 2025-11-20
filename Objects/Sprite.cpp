// 스프라이트 이미지 로딩

#include "Sprite.h"

Sprite::Sprite(const char* path) {
    SDL_Surface* surf = IMG_Load(path);
    texture = SDL_CreateTextureFromSurface(Renderer::renderer, surf);
    SDL_FreeSurface(surf);
}

void Sprite::draw(SDL_Renderer* renderer, int x, int y) {
    SDL_Rect dst{ x, y, 16, 16 };
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}
