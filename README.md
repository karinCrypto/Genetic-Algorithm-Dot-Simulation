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

# SDL2 Genetic Algorithm Dot Simulation

This project is a visual simulation demonstrating a **Genetic Algorithm (GA)** implemented in **C++ and SDL2**.  
A population of small agents ("dots") evolves over time to reach a target location by adjusting their movement vectors through:

- DNA encoding  
- Fitness evaluation  
- Roulette-wheel selection  
- Crossover  
- Mutation  

Over successive generations, the population gradually improves its ability to navigate toward the target.

---

## Build Instructions

### Linux / macOS
```bash
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



---

# ✔ LICENSE (ALPHA License)

```text
ALPHA LICENSE

Copyright (c) 2025 Karin

Permission is hereby granted to any individual or organization to use,
copy, modify, and distribute this software and its documentation,
subject to the following conditions:

1. The software may not be sold as-is without substantial modification
   or integration into a larger project.

2. Any distribution must retain this license text in full.

3. Derivative works must provide attribution to the original author, Karin.

4. The software is provided "AS IS", without warranty of any kind.
   The author is not liable for any damages or losses resulting from
   the use of this software.

This license aims to encourage learning, experimentation, and creative
development while protecting the original author's rights.

