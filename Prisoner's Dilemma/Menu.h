#pragma once
#include "Strategy.h"

class Menu
{
public:
    void display_main_menu();

    void display_player_vs_ai_menu();
    void display_rounds_menu();

    void display_ai_vs_ai_menu_01();
    void display_ai_vs_ai_menu_02();

    void display_explanation();

    int get_choice(int min, int max); // Get a validated choice from the user within the given range
    void clear_screen(); // Clear the terminal screen

    int get_game_mode_choice();
    int get_player_vs_ai_strategy_choice();
    int get_round_choice();
    int get_ai_vs_ai_strategy_choice_01();
    int get_ai_vs_ai_strategy_choice_02();
};