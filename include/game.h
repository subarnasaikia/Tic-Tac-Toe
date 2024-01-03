#pragma once

#include "board.h"
#include "player.h"

namespace TTT
{
    class Game
    {
        public:
            Game();
            void run();
        private:
            Board::Coordination _coord;
            Board _board;
            Player _playerX;
            Player _playerO;
            Player *_currentPlayer;
            int _moveCount = 0;

            void _changePlayer();
            void _playerTurn();
            void _result();
            void _clearTerminal();

    };
    
}