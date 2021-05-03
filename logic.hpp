#pragma once

#include <cstdint>

enum class CellState
{
    Empty,
    X,
    O
};

enum class PlayerSign
{
    X,
    O
};

constexpr size_t FIELD_WIDTH = 3;

using GameField = CellState[FIELD_WIDTH * FIELD_WIDTH];

enum class TurnOutcome
{
    CONTINUE,
    DRAW,
    X_WON,
    O_WON
};

bool is_valid_pos(size_t row, size_t col)
{
    return row < FIELD_WIDTH && col < FIELD_WIDTH;
}

CellState get_cell(GameField const &field, size_t row, size_t col)
{
    if (is_valid_pos(row, col))
    {
        return field[col * FIELD_WIDTH + row];
    }
    return CellState::Empty;
}

bool set_cell(GameField &field, size_t row, size_t col, CellState state)
{
    if (is_valid_pos(row, col) && get_cell(field, row, col) == CellState::Empty)
    {
        field[col * FIELD_WIDTH + row] = state;
        return true;
    }
    return false;
}

bool is_draw(GameField const &field)
{
    for (size_t i = 0; i < FIELD_WIDTH * FIELD_WIDTH; i++)
    {
        if (field[i] == CellState::Empty)
        {
            return false;
        }
    }
    return true;
}

CellState is_line_full(GameField const &field,
                       size_t start_x, size_t start_y,
                       short dx, short dy)
{

    size_t x = start_x, y = start_y;
    CellState first_cell = get_cell(field, x, y);
    if (first_cell == CellState::Empty)
    {
        return CellState::Empty;
    }
    while (is_valid_pos(x + dx, y + dy))
    {
        x += dx;
        y += dy;
        if (get_cell(field, x, y) != first_cell)
        {
            return CellState::Empty;
        }
    }
    return first_cell;
}

TurnOutcome check_turn_outcome(GameField const &field)
{
    // x or o wins
    // is draw
    // otherwise continue

#define CHECK_LINE(start_x, start_y, dx, dy)                                                    \
    if (CellState res = is_line_full(field, start_x, start_y, dx, dy); res != CellState::Empty) \
    {                                                                                           \
        return res == CellState::X ? TurnOutcome::X_WON : TurnOutcome::O_WON;                   \
    }

    for (size_t i = 0; i < FIELD_WIDTH; i++) {
        // check i-th row
        CHECK_LINE(0, i, 1, 0);
        // check i-th column
        CHECK_LINE(i, 0, 0, 1);
    }

    CHECK_LINE(0, 0, 1, 1);
    CHECK_LINE(2, 0, -1, 1);

#undef CHECK_LINE

    if (is_draw(field)) {
        return TurnOutcome::DRAW;
    }

    return TurnOutcome::CONTINUE;
}

CellState sign_to_cell(PlayerSign sign) {
    return sign == PlayerSign::X ? CellState::X : CellState::O;
}

PlayerSign next_player(PlayerSign current) {
    return current == PlayerSign::X ? PlayerSign::O : PlayerSign::X;
}

struct Pos
{
    size_t x, y;
};
