#include "player.h"

namespace TTT 
{
    Player::Player(char symbol): _playerSymbol(symbol){}

    char Player::getSymbol() const
    {
        return _playerSymbol;
    }

    void Player::changeSymbol(char symbol)
    {
        _playerSymbol = symbol;
    }
}