#pragma once

#include <cstdint>

enum class Cellstate //состояние клетки поля
{
    Empty, X, O
};

enum class PlayerSign //знак игрока
{
    X, O
};

constexpr size_t field_width = 3; //размер ширины поля

using gameFiled = Cellstate[field_width * field_width]; //массив поля

enum class TurnOutсome //результат хода
{
    CONTINUE, draw, X_win, O_win
};
// пользователь будет вводить 2 числа, определяя клетку поля, нужна проверка

bool is_valid_pos(size_t row, size_t col) // проверка валидности ввода данных поля
{
    return row < field_width && col < field_width;
}

Cellstate get_cell(gameFiled const& field, size_t row, size_t col)
{
    if (is_valid_pos(row, col))
    {
        return field[col*field_width+row];
    }
    return Cellstate::Empty;
}

//возвращаем, удачно ли прошла Запись в клетку
bool set_cell(gameFiled& field, size_t row, size_t col, Cellstate state)
{
    if (is_valid_pos(row, col) && (get_cell(field, row, col) == Cellstate::Empty))
    {
        field[col*field_width + row] = state;
        return true;
    }
    return false;
}

bool is_draw(gameFiled const& field)
{
    for(size_t i = 0; i < field_width * field_width; i ++)
    {
        if(filed[i] == Cellstate::Empty)
        {
            return false;
        }
    }
    return true;
}

ce

TurnOutcome check_turn_outcome(gameFiled const& field)
{
    // is draw
    // x or o wins
    // continue
}