#include "Engine/Game.h"

int main(int argc, char* argv[]) {
    Game game;
    game.init("GA Evolution Engine", 800, 600);
    game.run();
    game.clean();
    return 0;
}
