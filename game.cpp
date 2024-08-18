#include "game.h"
#include <limits>

char field[SIZE][SIZE];

void fill_field(){
    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
            field[x][y] = NONE;
}

void draw_field(){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            std::cout << static_cast<char>(field[i][j]);
            if (j < SIZE - 1) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "-----------" << std::endl;
    }
}

bool check_vertical(Player current_player){
    for (int y = 0; y < SIZE; y++){
        if (field[y][0] == current_player && field[y][1] == current_player && field[y][2] == current_player)
            return true;
    }
    return false;
}

bool check_horizontal(Player current_player){
    for (int x = 0; x < SIZE; x ++){
        if (field[0][x] == current_player && field[1][x] == current_player && field[2][x] == current_player)
            return true;
    }
    return false;
}

bool check_diagonal(Player current_player){
    if ((field[0][0] == current_player && field[1][1] == current_player && field[2][2] == current_player) ||
        (field[2][0] == current_player && field[1][1] == current_player && field[0][2] == current_player))
        return true;
    return false;
}

bool check_victory(Player current_player){
    return check_vertical(current_player) || check_horizontal(current_player) || check_diagonal(current_player);
}

bool is_draw(){
    for (int x = 0; x < SIZE; x++){
        for (int y = 0; y < SIZE; y++){
            if (field[x][y] == NONE)
                return false;
        }
    }
    return true;
}

bool move(Player current_player){
    cell input;

    while (true){
        std::cout <<static_cast<char>(current_player) << " : " << "Enter your coordinates --> ";
        std::cin >> input.x >> input.y;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter numbers between 1 and 3." << std::endl;
            continue;
        }

        if (input.x > SIZE || input.x <= 0 || input.y > SIZE || input.y <= 0){
            std::cout << "You cannot select a cell which is beyond the field!" << std::endl;
            continue;
        } else if (field[input.x - 1][input.y - 1] != NONE){
            std::cout << "You cannot do that! This cell is occupied already!" << std::endl;
        } else {
            field[input.x - 1][input.y - 1] = current_player;
            draw_field();

            if (check_victory(current_player)){
                std::cout << std::endl << static_cast<char>(current_player) << " has won!" << std::endl;
                return true;
            }
            return false;
        }
    }
}

void game_loop(){
    Player current_player = PLAYER_X;
    fill_field();

    while (true){
        if (move(current_player))
            break;
        if (is_draw()){
            std::cout << "It's a draw!" << std::endl;
            break;
        }
        std::cout << std::endl;
        current_player = (current_player == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }
}
