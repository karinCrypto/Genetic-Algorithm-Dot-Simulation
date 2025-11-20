# Genetic Algorithm Dot Simulation (SDL2)

This repository contains a visual simulation of a **Genetic Algorithm (GA)** where multiple agents ("dots") evolve over time to reach a target location.  
The simulation is implemented in **C++ with SDL2**, and each dot uses:

- DNA (movement vectors)
- Fitness evaluation
- Selection (roulette-wheel)
- Crossover
- Mutation

As generations progress, the population gradually learns how to reach the target more efficiently.

---

## Features

### ✔ Visualized Genetic Algorithm  
Each dot moves according to its DNA, and the entire population evolves in real time.

### ✔ SDL2 Rendering  
A simple 2D visualization shows:
- White dots  
- Random movement in early generations  
- Converging behavior in later generations  
- Red target box (goal)

### ✔ Full GA Pipeline  
- DNA encoding (movement vectors)  
- Fitness scoring based on proximity to target  
- Roulette-wheel parent selection  
- Crossover between parents  
- Mutation with adjustable rate  
- Generation updates

---

## Demo (Concept)

The dots start at the bottom-left and attempt to reach the red target at the top-right.  
Early generations move randomly, but over time the movement vectors evolve and dots begin approaching the target.

---

## Requirements

### 1. Compiler  
- g++ (MinGW / GCC / Clang / MSVC)

### 2. SDL2  
Install SDL2:

#### Linux (Ubuntu)
```bash
sudo apt install libsdl2-dev

#### Build Instructions
Linux / macOS
g++ src/main.cpp -o ga-sim -lSDL2 -std=c++17
./ga-sim
Windows (MinGW)
g++ src/main.cpp -o ga-sim -lmingw32 -lSDL2main -lSDL2 -std=gnu++17
ga-sim.exe

Windows (Visual Studio Developer Command Prompt)
cl src\main.cpp /EHsc /I include /link SDL2.lib SDL2main.lib

# How It Works
DNA

Each agent has a fixed-size array of movement vectors.

Movement

Each frame, a dot reads one vector from its DNA and moves accordingly.

Fitness
Fitness is calculated as:

1 / (distance_to_target + 1)
+ bonus if reached
Selection

Roulette-wheel selection chooses parents proportionally to their fitness.

Crossover

A random midpoint splits the DNA between two parents.

Mutation

Random chance to modify genes.



# Project Structure
SDL2-GA-Dots/
│
├─ src/
│   └─ main.cpp
│
├─ include/
├─ lib/
├─ assets/
│
├─ .gitignore
├─ LICENSE
└─ README.md



# Future Extensions

Obstacles & maps

Neural networks + GA

Maze-solving GA

Evolution visual UI

Rust / WebAssembly port


# License
MIT License © 2025 Karin

