#include "Game.h"

Game::Game() : rounds(0), total_rounds(0), points_player_01(0), points_player_02(0), action_player_01(true), action_player_02(true) {}

int Game::determine_rounds(int rounds_choice)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Determine number of rounds based on user's choice
    switch (rounds_choice)
    {
    case 1:
        return std::uniform_int_distribution<>(10, 30)(gen);
    case 2:
        return std::uniform_int_distribution<>(50, 80)(gen);
    case 3:
        return std::uniform_int_distribution<>(100, 200)(gen);
    default:
        std::cerr << "Invalid rounds_choice. Returning -1." << std::endl;
        return -1;
    }
}

bool Game::calculate_points()
{
    int current_round = total_rounds - rounds + 1;
    --rounds;

    std::cout << "\nRound " << current_round << std::endl;

    if (action_player_01 && action_player_02)
    {
        points_player_01 += 3;
        points_player_02 += 3;
    }
    else if (!action_player_01 && !action_player_02)
    {
        points_player_01 += 1;
        points_player_02 += 1;
    }
    else if (action_player_01 && !action_player_02)
    {
        points_player_02 += 5;
    }
    else if (!action_player_01 && action_player_02)
    {
        points_player_01 += 5;
    }

    std::cout << "Player 01 Points: " << points_player_01 << " | " << "Player 02 Points: " << points_player_02 << std::endl;

    // Check if the game has ended
    if (rounds == 0)
    {
        if (points_player_01 > points_player_02)
        {
            std::cout << "\n\n\nPlayer 01 Won!\n\n\n";
        }
        else if (points_player_01 == points_player_02)
        {
            std::cout << "\n\n\nDraw!\n\n\n";
        }
        else
        {
            std::cout << "\n\n\nPlayer 02 Won!\n\n\n";
        }
        // Resets points
        points_player_01 = 0;
        points_player_02 = 0;

        return false; // Indicate that the game has ended
    }

    return true; // Continue the game
}

void Game::player_vs_ai(Strategy& strategy, int strategy_choice_input)
{
    int player_choice{};
    bool player_last_action = true;
    bool ai_last_action = true;
    int round_number = 1;

    while (true)
    {
        // Determine AI's action based on the chosen strategy
        strategy.player_vs_ai_strategy_choice(strategy_choice_input, action_player_02, player_last_action, points_player_01, points_player_02);

        // Prompt the player for their choice
        do
        {
            std::cout << "Your Turn!\n1) Co-Operate or 2) Deflect?\n";
            std::cin >> player_choice;

            if (player_choice == 1)
            {
                action_player_01 = true;  // Player chooses to cooperate
            }
            else if (player_choice == 2)
            {
                action_player_01 = false; // Player chooses to deflect
            }
            else
            {
                std::cout << "Invalid Input! Try again!" << std::endl;
                continue;
            }
            menu.clear_screen(); // Clear the screen after the player's choice

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;

        } while (true);

        std::cout << "Player 02 (AI) Has Chosen... " << (action_player_02 ? "Co-Operate!" : "Deflect!") << std::endl;

        if (!calculate_points())
        {
            break; // End the game if all rounds are completed
        }

        // Update last actions
        player_last_action = action_player_01;
        ai_last_action = action_player_02;

        ++round_number;
    }
}

void Game::ai_vs_ai(Strategy& strategy, int strategy_choice_input_01, int strategy_choice_input_02)
{
    bool ai_last_action_01 = true;
    bool ai_last_action_02 = true;
    int round_number = 1;

    while (true)
    {
        // Determine actions for both AIs based on their chosen strategies
        strategy.ai_vs_ai_strategy_choice(strategy_choice_input_01, action_player_01, strategy_choice_input_02, action_player_02, points_player_01, points_player_02);

        std::cout << "Player 01 (AI) has chosen... " << (action_player_01 ? "Co-Operate!" : "Deflect!") << std::endl;
        std::cout << "Player 02 (AI) has chosen... " << (action_player_02 ? "Co-Operate!" : "Deflect!") << std::endl;

        if (!calculate_points())
        {
            break; // End the game if all rounds are completed
        }

        // Update last actions
        ai_last_action_01 = action_player_01;
        ai_last_action_02 = action_player_02;

        ++round_number;
    }
}

void Game::set_rounds(int rounds_value)
{
    rounds = rounds_value;
    total_rounds = rounds_value;
}