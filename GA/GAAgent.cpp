//GA/Agent.cpp

#include "Agent.h"
#include "../Objects/Sprite.h"

Agent::Agent() : sprite("assets/sprites/agent.png") {
    reset();
}

void Agent::reset() {
    x = 50;
    y = 550;
    step = 0;
    reached = false;
}

void Agent::update(TileMap* map) {
    if (step >= dna.genes.size()) return;

    x += dna.genes[step].x;
    y += dna.genes[step].y;
    step++;

    if (map->isWall(x, y))
        dead = true;

    if (hypot(target.x - x, target.y - y) < 10)
        reached = true;
}

void Agent::render(SDL_Renderer* renderer) {
    sprite.draw(renderer, (int)x, (int)y);
}
