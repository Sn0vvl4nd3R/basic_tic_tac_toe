#ifndef GAME_H
#define GAME_H

#include <iostream>

#define SIZE 3

enum Player {
    NONE = '.',
    PLAYER_X = 'X',
    PLAYER_O = 'O',
};

struct cell {
    int x, y;
};

extern char field[SIZE][SIZE];

void fill_field();
void draw_field();
bool check_vertical(Player current_player);
bool check_horizontal(Player current_player);
bool check_diagonal(Player current_player);
bool check_victory(Player current_player);
bool is_draw();
bool move(Player current_player);
void game_loop();

#endif
