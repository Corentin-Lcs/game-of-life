<h1 align="center">Game Of Life</h1>

The "Game Of Life" GitHub project is an implementation of Conway's Game of Life using C++. This project simulates the evolution of cellular automata based on a set of simple rules, creating complex and interesting patterns over time.

<p align="center">
  <img src="https://github.com/Corentin-Lcs/game-of-life/blob/main/Game_Of_Life.png" alt="Game_Of_Life.png"/>
</p>

## Description

The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It is a zero-player game, meaning its evolution is determined by its initial state, requiring no further input from human players. The game takes place on an infinite two-dimensional grid of square cells, where each cell is either alive or dead. Every cell interacts with its eight neighbors, which are the cells horizontally, vertically, or diagonally adjacent.

> To better understand these concepts and explore the many families of structures, clear and precise explanations are available by following this [link](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life).

## Game Rules

The following rules govern the evolution of the grid from one generation to the next:

- Any live cell with fewer than two live neighbors dies, as if by `underpopulation`.
- Any live cell with two or three live neighbors continues to the `next generation`.
- Any live cell with more than three live neighbors dies, as if by `overpopulation`.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by `reproduction`.

These simple rules lead to diverse patterns and behaviors, such as still lifes, oscillators, and spaceships. The Game of Life has been extensively studied and finds applications in various fields including computer science, physics, and biology.

## Usage

To compile the `*.cpp` files from the command prompt, run the following command :

```
g++ [source_code_name].cpp -o [executable_name]
g++ *.cpp -o prog
```

> For more details about the concept of compilation and compilers, here are some useful links:
>
> Link 1 : <https://perso.univ-lyon1.fr/jean-claude.iehl/Public/educ/gcc.html> [FR]
> 
> Link 2 : <https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html> [EN]
>          
> Link 3 : <https://www.cyberciti.biz/faq/compiling-c-program-and-creating-executable-file/> [EN]
>
> Link 4 : <https://medium.com/@laura.derohan/compiling-c-files-with-gcc-step-by-step-8e78318052> [EN]
> 
> Link 5 : <https://gcc.gnu.org> [EN]

To launch the program from the command prompt, type the following command with the correct syntax :

```
prog.exe
```

## Project's Structure

```
game-of-life/
├─ README.md
├─ LICENSE
├─ Game_Of_Life.png
└─ src/
   ├─ main.cpp
   ├─ prog.exe
   ├─ GameOfLife.cpp
   └─ GameOfLife.hpp
```

## Meta

Created by [@Corentin-Lcs](https://github.com/Corentin-Lcs). Feel free to contact me !

Distributed under the GNU GPLv3 license. See [LICENSE](https://github.com/Corentin-Lcs/game-of-life/blob/main/LICENSE) for more information.
