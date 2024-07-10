/**
 * @file GameOfLife.hpp
 * @brief Definition of the Game of Life class and associated structures.
 * 
 * This file contains the definition of the Game of Life class and the Cell structure,
 * as well as the declarations of the methods used to run the simulation.
 * 
 * @author Corentin L.
 * @version 1.0
 */

#pragma once

#include <iostream>
#include <vector>

/**
 * @brief Structure representing a single cell in the Game of Life.
 *
 * This structure contains the current and next values of the cell.
 */
struct Cell {
    bool currentValue; // The current state of the cell.
    bool nextValue; // The next state of the cell.
};

/**
 * @brief Class representing the Game of Life.
 *
 * This class provides methods to initialize, update, and display the game board.
 */
class GameOfLife {
    
public:
    /**
     * @brief Create a new empty Game of Life board.
     *
     * @param rows Number of rows in the board.
     * @param cols Number of columns in the board.
     * @return GameOfLife A GameOfLife object with all cells initialized to dead.
     */
    static GameOfLife new_empty(int rows, int cols);

    /**
     * @brief Create a new random Game of Life board.
     *
     * @param rows Number of rows in the board.
     * @param cols Number of columns in the board.
     * @return GameOfLife A GameOfLife object with cells initialized randomly.
     */
    static GameOfLife new_random(int rows, int cols);

    /**
     * @brief Start the Game of Life simulation.
     *
     * This function initializes the game board and starts the game loop.
     */
    static void startGame();

    /**
     * @brief Update the board to the next generation.
     *
     * This function calculates the next state of each cell based on its neighbors.
     */
    void update();

    /**
     * @brief Output stream operator for printing the game board.
     *
     * @param stream The output stream.
     * @param gol The GameOfLife object to print.
     * @return std::ostream& The output stream.
     */
    friend std::ostream& operator<<(std::ostream& stream, const GameOfLife& gol);

private:
    /**
     * @brief Construct a new Game of Life object.
     *
     * @param rows Number of rows in the board.
     * @param cols Number of columns in the board.
     */
    GameOfLife(int rows, int cols);

    /**
     * @brief Count the living neighbors of a cell.
     *
     * @param x The row index of the cell.
     * @param y The column index of the cell.
     * @return int The number of living neighbors.
     */
    int countNeighbors(int x, int y) const;

    /**
     * @brief Clear the console screen.
     *
     * This function clears the console screen for both Windows and Unix-like systems.
     */
    static void clearScreen();

    int rows; // Number of rows in the board.
    int cols; // Number of columns in the board.
    std::vector<std::vector<Cell>> board; // The game board.
};