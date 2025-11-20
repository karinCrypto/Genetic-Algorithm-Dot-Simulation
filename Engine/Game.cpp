// 게임 루프

#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "../GA/Population.h"
#include "../Objects/TileMap.h"

Population* population;
TileMap* tilemap;

void Game::init(const char* title, int w, int h) {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);

    running = true;

    population = new Population();
    tilemap = new TileMap("assets/maps/maze01.txt");
}

void Game::run() {
    while (running) {
        Input::handleEvents(running);
        
        population->updateAgents(tilemap);
        
        Renderer::clear(renderer);
        tilemap->render(renderer);
        population->render(renderer);
        Renderer::present(renderer);
    }
}

void Game::clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
