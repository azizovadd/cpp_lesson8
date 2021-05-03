#pragma once

#include <random>

#include "logic.hpp"

size_t get_empty_cells(size_t* free_cells, GameField const &field) 
{
    size_t *last_element = free_cells;
    size_t free_cells_num = 0;
    for (size_t i = 0; i < FIELD_WIDTH * FIELD_WIDTH; i++)
    {
        if (field[i] == CellState::Empty)
        {
            *last_element = i;
            last_element++;
            free_cells_num++;
        }
    }
    return free_cells_num;
}

Pos get_random_empty_cell(GameField const &field)
{
    size_t free_cells[FIELD_WIDTH * FIELD_WIDTH]{};
    size_t free_cells_num = get_empty_cells(free_cells, field);
    std::mt19937 algorithm;
    std::uniform_int_distribution<> dist(0, free_cells_num - 1);
    auto random_idx = dist(algorithm);
    size_t target_idx = free_cells[random_idx];

    return Pos{target_idx % FIELD_WIDTH, target_idx / FIELD_WIDTH};
}

Pos make_predictive_move(GameField const &field) 
{
    GameField test_field;
    std::copy_n(field, FIELD_WIDTH * FIELD_WIDTH, test_field);

    size_t free_cells[FIELD_WIDTH * FIELD_WIDTH]{};
    size_t free_cells_num = get_empty_cells(free_cells, field);

    for (size_t i = 0; i < free_cells_num; i++) 
    {
        size_t free_cell_idx = free_cells[i];
        test_field[free_cell_idx] = CellState::O;
        if(check_turn_outcome(test_field) == TurnOutcome::O_WON) 
        {
            return Pos{free_cell_idx % FIELD_WIDTH, free_cell_idx / FIELD_WIDTH};
        }
        test_field[free_cell_idx] = CellState::X;
        if(check_turn_outcome(test_field) == TurnOutcome::X_WON) 
        {
            return Pos{free_cell_idx % FIELD_WIDTH, free_cell_idx / FIELD_WIDTH};
        }
        test_field[free_cell_idx] = CellState::Empty;
    }
    return get_random_empty_cell(field);
}

Pos query_ai_move(GameField const &field)
{
    // for every free cell
    //  - if we win by choosing this cell - do it!
    //  - if we prevent player of winning by choosing this cell - do it!
    //  - otherwise, pick random 

    return make_predictive_move(field);
}