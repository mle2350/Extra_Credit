#include "TicTacToe_Game.h"

TicTacToe_Game::TicTacToe_Game()
{

}

TicTacToe_Game::~TicTacToe_Game()
{
    //dtor
}

void TicTacToe_Game::playGame()
{
        using namespace std::chrono_literals;
    const unsigned char user1{'X'}, user2{'O'};
    std::array<unsigned char, 10> brands{};
    std::uint16_t option;
    std::string repeat;

    CLEAN_SCREEN
    do
    {
        std::cout << "\nChoose the game mode\n"
                  << "0. USER VS MACHINE\n"
                  << "1. USER VS USER\n"
                  << "2. MACHINE VS MACHINE\n> ";
        while(!TicTacToe::input(option) || option > 2)
            std::puts("Invalid Input.Try Again\n>>> ");
        brands.fill(0);
        CLEAN_SCREEN
        switch(option) {
        case 0:
            while (true)
            {
                TicTacToe::board(brands);
                TicTacToe::movement(brands, user1);
                CLEAN_SCREEN
                if (TicTacToe::diagonal(brands, user1)
                        || TicTacToe::horizontal(brands, user1)
                        || TicTacToe::vertical(brands, user1)) {
                    TicTacToe::board(brands);
                    std::puts("You won");
                    break;
                }

                if (TicTacToe::tie(brands)) {
                    TicTacToe::board(brands);
                    std::puts("Tie");
                    break;
                }

                TicTacToe::machine(brands, user2);
                if (TicTacToe::diagonal(brands, user2)
                        || TicTacToe::horizontal(brands, user2)
                        || TicTacToe::vertical(brands, user2)) {
                    TicTacToe::board(brands);
                    std::puts("You lost");
                    break;
                }
            } break;

        case 1:
            while (true)
            {
                TicTacToe::board(brands);
                TicTacToe::movement(brands, user1);
                CLEAN_SCREEN
                if (TicTacToe::diagonal(brands, user1)
                        || TicTacToe::horizontal(brands, user1)
                        || TicTacToe::vertical(brands, user1)) {
                    TicTacToe::board(brands);
                    std::puts("User1 wins");
                    break;
                }

                if (TicTacToe::tie(brands)) {
                    TicTacToe::board(brands);
                    std::puts("Tie");
                    break;
                }

                TicTacToe::board(brands);
                TicTacToe::movement(brands, user2);
                CLEAN_SCREEN
                if (TicTacToe::diagonal(brands, user2)
                        || TicTacToe::horizontal(brands, user2)
                        || TicTacToe::vertical(brands, user2)) {
                    TicTacToe::board(brands);
                    std::puts("User2 wins");
                    break;
                }
            } break;

        case 2:
            while (true)
            {
                CLEAN_SCREEN
                TicTacToe::machine(brands, user1);
                if (TicTacToe::diagonal(brands, user1)
                        || TicTacToe::horizontal(brands, user1)
                        || TicTacToe::vertical(brands, user1)) {
                    TicTacToe::board(brands);
                    std::puts("Machine1 wins");
                    break;
                }
                TicTacToe::board(brands);
                std::this_thread::sleep_for(1.369s);
                CLEAN_SCREEN

                if (TicTacToe::tie(brands)) {
                    TicTacToe::board(brands);
                    std::puts("Tie");
                    break;
                }

                TicTacToe::machine(brands, user2);
                if (TicTacToe::diagonal(brands, user2)
                        || TicTacToe::horizontal(brands, user2)
                        || TicTacToe::vertical(brands, user2)) {
                    TicTacToe::board(brands);
                    std::puts("Machine2 wins");
                    break;
                }
                TicTacToe::board(brands);
                std::this_thread::sleep_for(1.369s);
            } break;
          }
        std::puts("Do you want to play again? [Y/y/S/s/n/N]");
        std::cin >> repeat;
        CLEAN_SCREEN
    } while (std::tolower(repeat[0]) == 'y' || std::tolower(repeat[0]) == 's');
}
