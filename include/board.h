#pragma once

#include<vector>
#include <cstddef>

namespace TTT {
    class Board
    {
        public:

            //strcuture to main the user provide coordination (xCoord, yCoord)
            struct Coordination {
                int xCoord;
                int yCoord;
            };

            // Constructor to initialize the board
            Board();

            //Methods for checking win/draw
            bool checkWin( Coordination coord ) const;
            bool checkDraw( int moveCount) const;

            //Method to display the board
            void displayBoard() const;

            //method to make move and update the board
            bool makeMove( Coordination coord, char playerSymbol);

        private:
            //seting board size as 3 for tic tac toe (3*3)
            const size_t _boardSize = 3;

            // ' ' for empty 'X' , 'O' as respectively
            std::vector<std::vector<char>> _grid; 
    };
    
}