#include "game_of_life.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

game_of_life::game_of_life() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = random_value();
        }
    }
}

bool game_of_life::random_value() {
    return rand() % 2 == 0;
}

bool game_of_life::cell_taken(int i, int j) {
    return i >= 0 && i < ROWS&& j >= 0 && j < COLS&& _generation[i][j];
}

void game_of_life::next_generation() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int ni = i - 1; ni <= i + 1; ni++) {
                for (int nj = j - 1; nj <= j + 1; nj++) {
                    if (ni == i && nj == j) {
                        continue;
                    }
                    if (cell_taken(ni, nj)) {
                        neighbors++;
                    }
                }
            }
            if (_generation[i][j]) {
                if (neighbors == 2 || neighbors == 3) {
                    _next_generation[i][j] = true;
                }
                else {
                    _next_generation[i][j] = false;
                }
            }
            else {
                if (neighbors == 3) {
                    _next_generation[i][j] = true;
                }
                else {
                    _next_generation[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            _generation[i][j] = _next_generation[i][j];
        }
    }
}

void game_of_life::draw() {
    system("cls");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (_generation[i][j]) {
                cout << "O";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}

