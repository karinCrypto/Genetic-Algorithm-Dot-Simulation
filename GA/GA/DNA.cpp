// 움직임 벡터 또는 NeuralNet weight를 담는 DNA 구조

#include "DNA.h"
#include <random>

static std::mt19937 gen(std::random_device{}());

DNA::DNA(int size) : genes(size) {
    mutateAll();
}

void DNA::mutateAll() {
    std::uniform_real_distribution<> dist(-1.0, 1.0);
    for (auto& g : genes)
        g = dist(gen);
}

DNA DNA::crossover(const DNA& other) {
    DNA child(genes.size());
    int midpoint = rand() % genes.size();

    for (int i = 0; i < genes.size(); i++)
        child.genes[i] = (i < midpoint) ? genes[i] : other.genes[i];

    return child;
}

void DNA::mutate(double rate) {
    std::uniform_real_distribution<> chance(0.0, 1.0);
    std::uniform_real_distribution<> dist(-1.0, 1.0);

    for (auto& g : genes) {
        if (chance(gen) < rate)
            g = dist(gen);
    }
}
