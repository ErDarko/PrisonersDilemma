#pragma once

#include "Strategy.h"
#include "Menu.h"
#include <iostream>
#include <random>

class Game
{
public:
    Game();

    int determine_rounds(int rounds_choice);
    bool calculate_points();
    void player_vs_ai(Strategy& strategy, int strategy_choice_input);
    void ai_vs_ai(Strategy& strategy, int strategy_choice_input_01, int strategy_choice_input_02);
    void set_rounds(int rounds_value);

private:
    Menu menu;
    int rounds;
    int total_rounds;
    int points_player_01;
    int points_player_02;
    bool action_player_01;
    bool action_player_02;
};