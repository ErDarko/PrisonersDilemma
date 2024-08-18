#pragma once

#include <iostream>
#include <random>

class Strategy
{
public:
    // Methods to handle strategy choices for player vs AI and AI vs AI
    void player_vs_ai_strategy_choice(int strategy_choice_input, bool& ai_action, bool player_last_action, int player_points, int ai_points);
    void ai_vs_ai_strategy_choice(int strategy_choice_input_01, bool& ai_action_01, int strategy_choice_input_02, bool& ai_action_02, int ai_01_points, int ai_02_points);

    // Various strategies
    void tit_for_tat(bool& ai_action, bool opponent_last_action);
    void two_tit_for_tat(bool& ai_action, bool opponent_last_action, bool opponent_prev_action);
    void omega_tit_for_tat(bool& ai_action, bool opponent_last_action, int round_number);
    void random(bool& ai_action);

    bool get_ai_action() const;

private:
    bool ai_action;
};