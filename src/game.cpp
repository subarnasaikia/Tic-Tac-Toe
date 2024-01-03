#include "game.h"
#include "logo.h"
#include <iostream>
#include <cstdlib>

namespace TTT
{
    Game::Game(): _coord{0, 0}, _playerX('X'), _playerO('O'), _currentPlayer(&_playerX) {}

    void Game::run() 
    {
        _clearTerminal();
        logo();
        std::cout << "Welcome to Tic Tac Toe game..."<<std::endl;
        _board.displayBoard();

        while (!_board.checkWin(_coord) && !_board.checkDraw(_moveCount))
        {
            _playerTurn();
            _clearTerminal();
            logo();
            _board.displayBoard();
            if (!_board.checkWin(_coord) && !_board.checkDraw(_moveCount))
                _changePlayer();

        }
        _result();
    }

    void Game::_changePlayer()
    {
        if(_currentPlayer == &_playerX)
            _currentPlayer = &_playerO;
        else _currentPlayer = &_playerX;
    }

    void Game::_playerTurn()
    {
        // Board::Coordination coord;

        std::cout <<"Player " <<_currentPlayer->getSymbol() <<"'s turn."<< std::endl;
        std::cout <<"Enter the position (row column) {row(0..2) colomn(0..2)}: ";
        std::cin >> _coord.xCoord >> _coord.yCoord;

        while (!_board.makeMove(_coord, _currentPlayer->getSymbol()))
        {
            std::cout <<"Invalid Move !!!\n"
                        "You entered invalid position.\n"
                        "Enter position Again: ";
            std::cin >> _coord.xCoord >> _coord.yCoord;
        }
        _moveCount++;
    }

    void Game::_result()
    {
        if(_board.checkWin(_coord))
        {
            std::cout << "\nCongratulation Player " << _currentPlayer->getSymbol()
                        <<", You win!\n";
        }
        else 
        {
            std::cout << "\nIt's a draw!\n";
        }
    }

    void Game::_clearTerminal()
    {
        #ifdef _WIN32
            std::system("cls");  // For Windows
        #else
            std::system("clear");  // For Linux and macOS
        #endif
    }
}