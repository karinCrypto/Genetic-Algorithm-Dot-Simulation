#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

// ------------ 난수 ------------
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dist(-1.0, 1.0);

// ------------ GA 파라미터 ------------
const int POP_SIZE = 200;
const int DNA_SIZE = 200;
const double MUTATION_RATE = 0.05;

// ------------ 게임 화면 ------------
const int WIDTH = 800;
const int HEIGHT = 600;

// 목표 위치
const SDL_Point TARGET = {700, 100};

// 개체(Dot) 클래스
class Dot {
public:
    double x, y;
    int step;
    bool dead = false;
    bool reached = false;
    double fitness = 0.0;

    vector<SDL_Point> dna;

    Dot() {
        x = 50;
        y = HEIGHT - 50;
        step = 0;
        dna.resize(DNA_SIZE);

        for (int i = 0; i < DNA_SIZE; i++) {
            dna[i].x = dist(gen) * 5;
            dna[i].y = dist(gen) * 5;
        }
    }

    void move() {
        if (step < DNA_SIZE && !dead && !reached) {
            x += dna[step].x;
            y += dna[step].y;
            step++;

            if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) dead = true;

            double d = hypot(x - TARGET.x, y - TARGET.y);
            if (d < 10) reached = true;
        }
    }

    void calcFitness() {
        double d = hypot(x - TARGET.x, y - TARGET.y);
        fitness = 1.0 / (d + 1.0);
        if (reached) fitness += 1.0;
    }

    Dot crossover(const Dot& other) {
        Dot child;
        uniform_int_distribution<> cut(0, DNA_SIZE - 1);
        int midpoint = cut(gen);

        for (int i = 0; i < DNA_SIZE; i++) {
            if (i < midpoint) child.dna[i] = dna[i];
            else child.dna[i] = other.dna[i];
        }
        return child;
    }

    void mutate() {
        uniform_real_distribution<> chance(0.0, 1.0);
        for (int i = 0; i < DNA_SIZE; i++) {
            if (chance(gen) < MUTATION_RATE) {
                dna[i].x = dist(gen) * 5;
                dna[i].y = dist(gen) * 5;
            }
        }
    }
};

// 개체군
class Population {
public:
    vector<Dot> dots;
    int generation = 0;

    Population() {
        dots.resize(POP_SIZE);
    }

    void update() {
        for (auto& d : dots) d.move();
    }

    void evaluate() {
        for (auto& d : dots) d.calcFitness();
    }

    Dot selectParent() {
        double total = 0;
        for (auto& d : dots) total += d.fitness;

        uniform_real_distribution<> pick(0.0, total);
        double r = pick(gen);

        double sum = 0;
        for (auto& d : dots) {
            sum += d.fitness;
            if (sum >= r) return d;
        }
        return dots.back();
    }

    void generate() {
        vector<Dot> newDots(POP_SIZE);

        for (int i = 0; i < POP_SIZE; i++) {
            Dot p1 = selectParent();
            Dot p2 = selectParent();

            Dot child = p1.crossover(p2);
            child.mutate();
            newDots[i] = child;
        }

        dots = newDots;
        generation++;
    }
};

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Genetic Algorithm - Dot Evolution",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Population pop;
    int frame = 0;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) quit = true;
        }

        // 세대 종료
        if (frame >= DNA_SIZE) {
            pop.evaluate();
            pop.generate();
            frame = 0;
        }

        pop.update();
        frame++;

        // 화면 렌더링
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // 목표점
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_Rect targetRect{ TARGET.x - 5, TARGET.y - 5, 10, 10 };
        SDL_RenderFillRect(renderer, &targetRect);

        // 개체들
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (auto& d : pop.dots) {
            SDL_Rect r{ (int)d.x, (int)d.y, 3, 3 };
            SDL_RenderFillRect(renderer, &r);
        }

        SDL_RenderPresent(renderer);

        SDL_Delay(10); // 시각화 속도
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
