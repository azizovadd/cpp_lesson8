#include <iostream>
#include <cassert>

#include "logic.hpp"
#include "io.hpp"
#include "ai.hpp"

int main() {
    // Human is always X
    // AI is always O

    // while game is not over
    //  - read player input / run AI
    //  - apply move
    //  - process new game state
    //  - print turn outcome
    print_greeting();

    //GameField field {};
    GameField field;//new
    Get_Field(&field);//new
    TurnOutcome outcome {};
    PlayerSign current_player = PlayerSign::X;
    do {
        Pos pos;
        if (current_player == PlayerSign::X) {
            pos = query_player_move(field);
        } else {
            pos = query_ai_move(field);
        }
        assert(set_cell(field, pos.x, pos.y, sign_to_cell(current_player)));

        outcome = check_turn_outcome(field);
        print_field(field);
        current_player = next_player(current_player);

    } while (outcome == TurnOutcome::CONTINUE);

    print_game_outcome(outcome);

    return 0;
}