/**
 * @file main.cpp
 * @brief Entry point for the Game of Life simulation.
 * 
 * This file contains the main function which starts the Game of Life.
 * 
 * @author Corentin L.
 * @version 1.0
 */

#include "GameOfLife.hpp"

/**
 * @brief Main function to start the Game of Life.
 *
 * This function calls the static startGame method of the GameOfLife class
 * to begin the simulation.
 *
 * @return int Returns 0 upon successful completion.
 */
int main() {
    GameOfLife::startGame();
    return 0;
}