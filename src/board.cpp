#include "board.h"
#include <iostream>


namespace TTT 
{

    Board::Board(): _grid(_boardSize, std::vector<char>(_boardSize, ' ')) {}

    void Board::displayBoard() const 
    {
        for (size_t i = 0; i < _boardSize; i++)
        {
            std::cout << "\t\t" << _grid[i][0];

            for (size_t j = 1; j < _boardSize; j++)
                std::cout <<" | " << _grid[i][j];
            
            if(i != _boardSize - 1)
                std::cout << "\n\t\t__________\n\n";
            else std::cout << "\n";
        }
    }

    bool Board::checkWin( Coordination coord ) const
    {
        if(_grid[coord.xCoord][coord.yCoord] == ' ')
            return false;
        char playerSymbol = _grid[coord.xCoord][coord.yCoord];

        //checking for column
        for(size_t i = 0; i < _boardSize; i++)
        {
            if(_grid[coord.xCoord][i] != playerSymbol)
                break;
            else if( i == _boardSize - 1)
                return true;
        }

        //checking for row
        for(size_t i = 0; i < _boardSize; i++)
        {
            if(_grid[i][coord.yCoord] != playerSymbol)
                break;
            else if( i == _boardSize - 1)
                return true;
        }

        //checking for diagonal
        if(coord.xCoord == coord.yCoord)
        {
            for(size_t i = 0; i < _boardSize; i++)
            {
                if(_grid[i][i] != playerSymbol)
                    break;
                else if( i == _boardSize - 1)
                    return true;
            }
        }

        //checking for antidiagonal
        if(coord.xCoord + coord.yCoord == (int)_boardSize - 1)
        {
            for(size_t i = 0; i < _boardSize; i++)
            {
                if(_grid[i][(coord.xCoord + coord.yCoord) - i] != playerSymbol)
                    break;
                else if (i == _boardSize - 1)
                    return true;
            }
        }
        
        return false;
    }

    bool Board::checkDraw(int moveCount) const
    {
        if(moveCount == (int)(_boardSize * _boardSize))
            return true;
        return false;
    }

    bool Board::makeMove(Coordination coord, char playerSymbol)
    {
        if((coord.xCoord >= 0 && coord.xCoord < (int)_boardSize) 
            && (coord.yCoord >= 0 && coord.yCoord < (int)_boardSize)
            && (_grid[coord.xCoord][coord.yCoord] == ' '))   
        {
                _grid[coord.xCoord][coord.yCoord] = playerSymbol;
                return true;
        }
        return false;
    }
}