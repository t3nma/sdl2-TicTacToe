// Board.h
// Board class definition. Member-functions defined in Board.cpp
//
// Author: yat0 - https://github.com/yat0

#ifndef _BOARD_
#define _BOARD_

class Board
{
public:
    enum BOARD_PIECE {PIECE_EMPTY, PIECE_X, PIECE_O};

    Board();

    void render() const;
    void restart();
    bool hasWinner() const;
    bool isDraw() const;
    void place(int row, int col, bool humanPiece=true);
    bool isFieldEmpty(int row, int col) const;
    bool isFieldCross(int row, int col) const;
    bool isFieldCircle(int row, int col) const;

private:
    BOARD_PIECE m[3][3];
    int occupiedPlaces;

    // helpers
    void renderBoard() const;
    void renderPieces() const;
    bool checkRows() const;
    bool checkColumns() const;
    bool checkDiagonals() const;
};

#endif
