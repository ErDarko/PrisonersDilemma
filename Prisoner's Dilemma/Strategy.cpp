#include "Strategy.h"

enum StrategyType
{
    TIT_FOR_TAT = 1,
    TWO_TIT_FOR_TAT,
    OMEGA_TIT_FOR_TAT,
    RANDOM
};

void Strategy::player_vs_ai_strategy_choice(int strategy_choice_input, bool& ai_action, bool player_last_action, int player_points, int ai_points)
{
    switch (strategy_choice_input)
    {
    case TIT_FOR_TAT:
        tit_for_tat(ai_action, player_last_action);
        break;
    case TWO_TIT_FOR_TAT:
        two_tit_for_tat(ai_action, player_last_action, player_last_action);
        break;
    case OMEGA_TIT_FOR_TAT:
        omega_tit_for_tat(ai_action, player_last_action, 1);
        break;
    case RANDOM:
        random(ai_action);
        break;
    default:
        std::cerr << "Invalid strategy choice!" << std::endl;
        break;
    }
}

void Strategy::ai_vs_ai_strategy_choice(int strategy_choice_input_01, bool& ai_action_01, int strategy_choice_input_02, bool& ai_action_02, int ai_01_points, int ai_02_points)
{
    static bool last_action_01 = true;
    static bool last_action_02 = true;

    // Handle strategy choice for AI 01
    switch (strategy_choice_input_01)
    {
    case TIT_FOR_TAT:
        break;
    case TWO_TIT_FOR_TAT:
        two_tit_for_tat(ai_action_01, last_action_02, last_action_01);
        break;
    case OMEGA_TIT_FOR_TAT:
        omega_tit_for_tat(ai_action_01, last_action_02, 1);
        break;
    case RANDOM:
        random(ai_action_01);
        break;
    default:
        std::cerr << "Invalid strategy choice for AI 01!" << std::endl;
        break;
    }

    // Handle strategy choice for AI 02
    switch (strategy_choice_input_02)
    {
    case TIT_FOR_TAT:
        tit_for_tat(ai_action_02, last_action_01);
        break;
    case TWO_TIT_FOR_TAT:
        two_tit_for_tat(ai_action_02, last_action_01, last_action_02);
        break;
    case OMEGA_TIT_FOR_TAT:
        omega_tit_for_tat(ai_action_02, last_action_01, 1);
        break;
    case RANDOM:
        random(ai_action_02);
        break;
    default:
        std::cerr << "Invalid strategy choice for AI 02!" << std::endl;
        break;
    }

    // Update last actions
    last_action_01 = ai_action_01;
    last_action_02 = ai_action_02;
}



/************************************
*Implement your strategies down here*
************************************/



// Implement the "Tit for Tat" strategy
void Strategy::tit_for_tat(bool& ai_action, bool opponent_last_action)
{
    ai_action = opponent_last_action;
}

// Implement the "Two Tit for Tat" strategy
void Strategy::two_tit_for_tat(bool& ai_action, bool opponent_last_action, bool opponent_prev_action)
{
    ai_action = opponent_last_action;
}

// Implement the "Omega Tit for Tat" strategy
void Strategy::omega_tit_for_tat(bool& ai_action, bool opponent_last_action, int round_number)
{
    ai_action = opponent_last_action;
}

// Implement the "Random" strategy
void Strategy::random(bool& ai_action)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(0, 1);

    ai_action = dis(gen);
}



bool Strategy::get_ai_action() const
{
    return ai_action;
}