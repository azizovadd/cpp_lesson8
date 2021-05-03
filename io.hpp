#pragma once

#include <iostream>

#include "logic.hpp"

void print_greeting()
{
    std::cout << "Welcome to Tic Tac Toe game!\n";
}

Pos query_player_move(GameField const& field)
{
    Pos pos;
    std::cout << "Please make a move: input two number in range [1-3]\n";
    bool ok = false;

    while (!ok)
    {
        std::cout << "> ";
        std::cin >> pos.x >> pos.y;
        pos.x--;
        pos.y--;
        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
            std::cout << "Error: please input numbers!\n";
        }
        else if (!is_valid_pos(pos.x, pos.y))
        {
            std::cout << "Error: position is out of field bounds!\n";
        }
         else if (get_cell(field, pos.x, pos.y) != CellState::Empty)
        {
            std::cout << "Error: this cell is not empty!\n";
        }
        else
        {
            ok = true;
        }
    }
    return pos;
}

void print_cell(CellState cell)
{
    switch (cell)
    {
    case CellState::Empty:
        std::cout << " ";
        break;

    case CellState::X:
        std::cout << "X";
        break;

    case CellState::O:
        std::cout << "O";
        break;
    }
}

void print_field(GameField const &field)
{
    std::cout << "-------------\n";
    for (size_t col = 0; col < FIELD_WIDTH; col++)
    {
        std::cout << "| ";
        for (size_t row = 0; row < FIELD_WIDTH; row++)
        {
            print_cell(get_cell(field, row, col));
            std::cout << " | ";
        }
            std::cout << "\n-------------\n";
    }
    std::cout << "\n";
}

void print_game_outcome(TurnOutcome outcome) {
    switch (outcome)
    {
    case TurnOutcome::DRAW:
        std::cout << "It's a draw!\n";
        break;
    
    case TurnOutcome::X_WON:
        std::cout << "You won! Congrats!\n";
        break;

    case TurnOutcome::O_WON:
        std::cout << "You lost. Good luck next time.\n";
        break;

    default:
        break;
    }
}