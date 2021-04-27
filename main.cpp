#include <iostream>
#include "logic.hpp"
#include "io.hpp" //input-output

int main()
{
    //человек Х
    //комп 0
    
    // while game is not over
    // -read player input/ run ai
    // -apply ove
    // -process new game state
    // -print turn outcome
    print_greeting();

    gameFiled field {};
     
    TurnOutсome outcome {};// по умолчанию continue
    do 
    {
        auto pos = query_player_move();
        std::cout << pos.x << pos.y << "\n";
        set_cell(field, pos.x, pos.y, Cellstate::X);

    } while (outcome == TurnOutсome::CONTINUE);

    
    return 0;
}
