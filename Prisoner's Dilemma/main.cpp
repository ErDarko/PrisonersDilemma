#include <iostream>
#include "Game.h"
#include "Strategy.h"
#include "Menu.h"

enum GameMode
{
    HUMAN_VS_MACHINE = 1,
    MACHINE_VS_MACHINE,
    EXPLANATION,
    EXIT
};

int main()
{
    Strategy strategy;
    Menu menu;
    Game game;

    while (true)
    {
        int gamemode_choice_input = menu.get_game_mode_choice();
        menu.clear_screen();

        if (gamemode_choice_input == HUMAN_VS_MACHINE)
        {
            int strategy_choice_input = menu.get_player_vs_ai_strategy_choice();
            menu.clear_screen();
            int rounds_choice = menu.get_round_choice();
            int rounds = game.determine_rounds(rounds_choice);
            game.set_rounds(rounds);
            game.player_vs_ai(strategy, strategy_choice_input);
        }
        else if (gamemode_choice_input == MACHINE_VS_MACHINE)
        {
            int ai_vs_ai_strategy_choice_input_01 = menu.get_ai_vs_ai_strategy_choice_01();
            menu.clear_screen();
            int ai_vs_ai_strategy_choice_input_02 = menu.get_ai_vs_ai_strategy_choice_02();
            menu.clear_screen();
            int rounds_choice = menu.get_round_choice();
            int rounds = game.determine_rounds(rounds_choice);
            game.set_rounds(rounds);
            game.ai_vs_ai(strategy, ai_vs_ai_strategy_choice_input_01, ai_vs_ai_strategy_choice_input_02);
        }
        else if (gamemode_choice_input == EXPLANATION)
        {
            menu.clear_screen();
            menu.display_explanation();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Press Enter to return to the main menu...";
            std::cin.get();
            menu.clear_screen();
        }
        else if (gamemode_choice_input == EXIT)
        {
            std::cout << "Thanks for passing by!" << std::endl;
            break;
        }
    }

    return 0;
}