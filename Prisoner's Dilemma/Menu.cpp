#include "Menu.h"
#include <iostream>
#include <limits>

void Menu::display_main_menu()
{
    std::cout
        << "Welcome to the Prisoner's Dilemma!\n"
        << "----------------------------------\n"
        << "1) Human VS Machine\n"
        << "2) Machine VS Machine\n"
        << "3) Explanation\n"
        << "4) Exit\n";
}

void Menu::display_player_vs_ai_menu()
{
    std::cout
        << "HUMAN VS MACHINE!\n"
        << "------------------\n"
        << "Choose your Enemy!\n"
        << "1) Tit For Tat\n"
        << "2) Two Tit for Tat\n"
        << "3) Omega Tit for Tat\n"
        << "4) Random\n";
}

void Menu::display_rounds_menu()
{
    std::cout
        << "Rounds!\n"
        << "-------------------\n"
        << "Choose your rounds!\n"
        << "1) Between 10 - 30\n"
        << "2) Between 50 - 80\n"
        << "3) Between 100 - 200\n";
}

void Menu::display_ai_vs_ai_menu_01()
{
    std::cout
        << "MACHINE VS MACHINE!\n"
        << "--------------------------\n"
        << "Choose your first machine!\n"
        << "1) Tit For Tat\n"
        << "2) Two Tit for Tat\n"
        << "3) Omega Tit for Tat\n"
        << "4) Random\n";
}

void Menu::display_ai_vs_ai_menu_02()
{
    std::cout
        << "MACHINE VS MACHINE!\n"
        << "---------------------------\n"
        << "Choose your second machine!\n"
        << "1) Tit For Tat\n"
        << "2) Two Tit for Tat\n"
        << "3) Omega Tit for Tat\n"
        << "4) Random\n";
}

void Menu::display_explanation()
{
    std::cout
        << "Prisoner's Dilemma Explanation:\n"
        << "-------------------------------------------------------------------------------\n"
        << "The Prisoner's Dilemma is a standard example of a game analyzed in game theory.\n"
        << "Both players can either cooperate with each other or betray (deflect).\n"
        << "The outcome depends on the simultaneous choices made by both players.\n";
}

int Menu::get_choice(int min, int max)
{
    int choice;
    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail() || choice < min || choice > max)
        {
            std::cerr << "Invalid Input! Try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return choice;
}

int Menu::get_game_mode_choice()
{
    display_main_menu();
    return get_choice(1, 4);
}

int Menu::get_player_vs_ai_strategy_choice()
{
    display_player_vs_ai_menu();
    return get_choice(1, 4);
}

int Menu::get_round_choice()
{
    display_rounds_menu();
    return get_choice(1, 3);
}

int Menu::get_ai_vs_ai_strategy_choice_01()
{
    display_ai_vs_ai_menu_01();
    return get_choice(1, 4);
}

int Menu::get_ai_vs_ai_strategy_choice_02()
{
    display_ai_vs_ai_menu_02();
    return get_choice(1, 4);
}

void Menu::clear_screen()
{
#ifdef _WIN32
    system("cls");  // Clear console on Windows
#else
    system("clear");  // Clear console on Unix/Linux/Mac
#endif
}
