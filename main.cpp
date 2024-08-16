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
    bool result;

    for (int i = 0; i != 3; i++){
        if (field[i] == field[i + 3] == field[i + 6] == current_player){
            result = true;
            break;
        } else {
            result = false;
        }
    }

    return result;
}

bool check_horizontal(char current_player){
    bool result;

    for (int i = 0; i < 9; i = i + 3){
        if (field[i] == field[i + 1] == field[i + 2] == current_player){
            result = true;
            break;
        } else {
            result = false;
        }
    }

    return result;
}

bool check_diagonal(char current_player){
    bool result;

    if (field[0] == field[4] == field[8] == current_player)
        result = true;
    else if (field[2] == field[4] == field[6] == current_player)
        result = true;
    else
        result = false;

    return result;
}

bool check_victory(char current_player){
    bool vertical = check_vertical(current_player);
    bool horizontal = check_horizontal(current_player);
    bool diagonal = check_diagonal(current_player);

    if (vertical || horizontal || diagonal)
        return true;
    else
        return false;
}

bool move(char current_player){
    int cell;

    while (true){
        std::cout << current_player << " : " << "Enter your cell --> ";
        std::cin >> cell;

        if (check_victory(current_player)){
            std::cout << current_player << " have won!" << std::endl;
            return true;
        } else if (field[cell - 1] == 'O' || field[cell - 1] == 'X')
            std::cout << "You cannot do that! This cell is occupied already!" << std::endl;
        else if (cell > 9)
            std::cout << "You cannot select a cell which is beyond the field!" << std::endl;
        else {
            field[cell - 1] = current_player;
            draw_field();
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







