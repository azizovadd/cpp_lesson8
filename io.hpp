#pragma once

#include <iostream>
#include "logic.hpp"

void print_greeting()
{
   std::cout << "Welcome to Tic TAc Toe game!\n";
}

//запращиваем ход игрока
struct Pos // возвращает позицию колонки и строки
{
    size_t x, y;    
}

query_player_move() // должна выдавать позицию игрока, но выдавать 2 значения нельзя, поэтому создаем структуру Pos
{
    Pos pos;
    std::cout << "Please make a move: input 2 numberd in range [1-3]\n";
    bool ok = false;

    while (!ok)
    {
        std::cout << "> ";
        std::cin >> pos.x >> pos.y;
        pos.x --;
        pos.y --;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Error: please input numbers!\n";
        }
        else if (!is_valid_pos(pos.x, pos.y))
        {
            std::cout << "Error: position is out of field bounds!\n";
        }
        else
        {
            ok = true;
        }

    //добавить проверку на ход в уже заполненную клетку
    }
    return pos;
}