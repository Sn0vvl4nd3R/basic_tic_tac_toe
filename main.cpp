#include <iostream>

char field[9];

void game_loop();

int main(void){

    //int game_mode;

    //std::cout << "Choose the game mode (0 - two-player mode; 1 - single-player) --> ";
    //std::cin >> game_mode;
    
    game_loop();

    return 0;
}

void fill_field(){
    for (int i = 0; i < 9; i++)
        field[i] = '_';
}

void draw_field(){
    std::cout << field[0] << " | " << field[1] << " | " << field[2] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << field[3] << " | " << field[4] << " | " << field[5] << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << field[6] << " | " << field[7] << " | " << field[8] << std::endl;
}

bool check_vertical(char current_player){
    for (int i = 0; i != 3; i++){
        if (field[i] == current_player && field[i + 3] == current_player && field[i + 6] == current_player)
            return true;
    }

    return false;
}

bool check_horizontal(char current_player){
    for (int i = 0; i < 9; i = i + 3){
        if (field[i] == current_player && field[i + 1] == current_player && field[i + 2] == current_player)
            return true;
    }

    return false;
}

bool check_diagonal(char current_player){
    if ((field[0] == current_player && field[4] == current_player && field[8] == current_player) ||
    (field[2] == current_player && field[4] == current_player && field[6] == current_player))
        return true;

    return false;
}

bool check_victory(char current_player){
    return check_vertical(current_player) || check_horizontal(current_player) || check_diagonal(current_player);
}

bool move(char current_player){
    int cell;

    while (true){
        std::cout << current_player << " : " << "Enter your cell --> ";
        std::cin >> cell;

        if (cell > 9 || cell < 1){
            std::cout << "You cannot select a cell which is beyond the field!" << std::endl;
        } else if (field[cell -1] == 'O' || field[cell - 1] == 'X'){
            std::cout << "You cannot do that! This cell is occupied already!" << std::endl;
        } else {
            field[cell - 1] = current_player;
            draw_field();

            if (check_victory(current_player)){
                std::cout << current_player << " has won!" << std::endl;
                return true;
            }

            return false;
        }
    }
}

void game_loop(){
    fill_field();

    while (true){
        if (move('X'))
            break;
        else if (move('O'))
            break;
    }
}
