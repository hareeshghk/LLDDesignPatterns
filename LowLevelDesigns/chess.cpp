#include <vector>
#include <string>

using namespace std;

class Chess {
    Board board;
    Player players[2]; // or a vector;
    Player currentTurn;
    Status gamestatus;
    vector<Move> listOfMoves;
    
    void MovePiece(CellPosition start, CellPosition end, Piece piece);
    void endGame();
    void changeTurn();
};

enum Status {
    ACTIVE, PAUSED, FOREFEIGHT, WHITE_WIN, BLACK_WIN
};

enum Colour {
    BLACK, WHITE
};

class Board {
    vector<vector<Cell>> board;

    void ResetBoard();
    void updateBoard(Move move);
};

class Player {
    Account account;
    Colour colour;
    vector<Piece> pieces;
    Time timeLeft;
};

class Time {
    int minutes;
    int seconds;
};

class Account {
    string username;
    string password;
    string name; // add any more details about player account;
};

class Cell {
    Colour colour;
    Piece *piece;
    CellPosition position;
};

class CellPosition {
    char ch;
    int x;
};

class Move {
    Player player;
    Piece piece;
    Piece killedPiece;
    CellPosition startPosition;
    CellPosition endPosition;
};

class Piece {
    Colour color;

    virtual bool validate(CellPosition start, CellPosition end);
    virtual bool movePiece(CellPosition start, CellPosition end);
    vector<CellPosition> validPositions(CellPosition current);
};

class Knight:public Piece {
    bool validate(CellPosition start, CellPosition end) override;
};

// similar for king, rook, bishop, pawn;

