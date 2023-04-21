#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

# include <iostream>
# include <thread>

#include "tictactoe.h"


class TicTacToe_Game
{
    public:
        TicTacToe_Game();
        virtual ~TicTacToe_Game();
        void playGame();

    protected:

    private:
};

#endif // TICTACTOE_GAME_H
