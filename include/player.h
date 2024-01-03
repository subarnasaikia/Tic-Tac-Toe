#pragma once

namespace TTT 
{
    class Player
    {
        public:
            Player(char symbol);
            char getSymbol() const;
            void changeSymbol(char symbol);
        private:
            char _playerSymbol;
    };
}