// 장애물 맵(미로) 로딩
#include "TileMap.h"
#include <fstream>

TileMap::TileMap(const char* path) {
    load(path);
}

void TileMap::load(const char* path) {
    std::ifstream file(path);
    char c;
    while (file.get(c)) {
        if (c == '0') map.push_back(0);      // floor
        else if (c == '1') map.push_back(1); // wall
    }
}

void TileMap::render(SDL_Renderer* r) {
    for (int i = 0; i < map.size(); i++) {
        SDL_Rect rect{ (i % width) * 16, (i / width) * 16, 16, 16 };

        if (map[i] == 1)
            SDL_SetRenderDrawColor(r, 100, 100, 100, 255);
        else
            SDL_SetRenderDrawColor(r, 30, 30, 30, 255);

        SDL_RenderFillRect(r, &rect);
    }
}

bool TileMap::isWall(double x, double y) {
    int tx = x / 16;
    int ty = y / 16;
    return map[ty * width + tx] == 1;
}
