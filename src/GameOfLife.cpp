/**
 * @file GameOfLife.cpp
 * @brief Implementation of the Game of Life class methods.
 * 
 * This file contains the implementation of the methods defined in the GameOfLife class,
 * which includes initializing the board, updating the board, and printing the board.
 * 
 * @author Corentin L.
 * @version 1.0
 */

#include "GameOfLife.hpp"

#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

namespace chrono = std::chrono;

GameOfLife GameOfLife::new_empty(int rows, int cols) {
    GameOfLife result{ rows, cols };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.board[i][j] = { false, false };
        }
    }
    return result;
}

GameOfLife GameOfLife::new_random(int rows, int cols) {
    GameOfLife result{ rows, cols };
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.board[i][j] = { std::rand() % 2 == 1, false };
        }
    }
    return result;
}

void GameOfLife::update() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int neighbors = countNeighbors(i, j);
            if (board[i][j].currentValue) {
                board[i][j].nextValue = (neighbors == 2 || neighbors == 3);
            } else {
                board[i][j].nextValue = (neighbors == 3);
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j].currentValue = board[i][j].nextValue;
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const GameOfLife& gol) {
    for (int i = 0; i < gol.rows; ++i) {
        for (int j = 0; j < gol.cols; ++j) {
            stream << (gol.board[i][j].currentValue ? '*' : ' ');
        }
        stream << std::endl;
    }
    return stream;
}

GameOfLife::GameOfLife(int rows, int cols) :
    rows{ rows },
    cols{ cols },
    board{ static_cast<std::vector<Cell>::size_type>(rows), std::vector<Cell>(static_cast<std::vector<Cell>::size_type>(cols)) }
{}

int GameOfLife::countNeighbors(int x, int y) const {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny].currentValue) {
                count++;
            }
        }
    }
    return count;
}

void GameOfLife::clearScreen() {
    #if defined (_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__)
        system("clear");
        // std::cout << "\033[2J\033[1;1H";
    #endif
}

void GameOfLife::startGame() {
    using namespace std::chrono_literals;
    std::srand(std::time(nullptr));
    int rows, cols;
    std::cout << "------------------------------[ Game of Life ]------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;
    std::cout << "Enter the number of columns: ";
    std::cin >> cols;
    GameOfLife gol = GameOfLife::new_random(rows, cols);
    while (true) {
        clearScreen();
        std::cout << gol;
        gol.update();
        std::this_thread::sleep_for(100ms);
    }
}