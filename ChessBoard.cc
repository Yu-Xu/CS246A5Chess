#include <iostream>
#include <string>
#include "ChessBoard.h"

ChessBoard::ChessBoard(): board{}, size{8} {
  // set up the board with no pieces
  for(int i = 0; i < size; ++i) {
    std::vector<Cell> c;
    board.push_back(c);
    for(int j = 0; j < size; ++j) {
      if (i % 2 == 0) { // even row
        if (j % 2 == 0) { // even col is white
          board[i].push_back(Cell{});
          board[i][j].setCell(i, j, 1);
        } else {
          board[i].push_back(Cell{});
          board[i][j].setCell(i, j, 0);
        }
      } else { // odd row
        if (j % 2 == 0) { // even col is black
          board[i].push_back(Cell{});
          board[i][j].setCell(i, j, 0);
        } else {
          board[i].push_back(Cell{});
          board[i][j].setCell(i, j, 1);
        }
      }
    }
  }
}

ChessBoard::~ChessBoard() {
}

void ChessBoard::clearBoard() { // clear the chessboard
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      board[i][j] = Cell{};
    }
  }
}

 // add piece to the board
 // only uses for setup mode
void ChessBoard::addPiece(int r, int c, std::string type, bool colour) {
  if (board[r][c].getPiece() != nullptr) {
    board[r][c].attackPiece(type, colour);
  } else {
    board[r][c].setPiece(type, colour);
  }
}

// remove piece from the board
// only uses for setup mode
void ChessBoard::removePiece(int r, int c) {
  if (board[r][c].getPiece() != nullptr) {
    board[r][c].clearPiece();
  }
}

// when player want to leave setup mode
// check if the board is legal to start a game
bool ChessBoard::checkBoard() {
  int wKing = 0;
  int bKing = 0;
  bool bIncheck = 0;
  bool wIncheck = 0;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr) {
        std::string type = board[i][j].getPiece()->type;
        // exactlly one white King one black King in the board
        // cannot put king in check
        if (type == "K") {
          ++wKing;
          wIncheck = incheck(true, i, j);
        } else if (type == "k") {
          ++bKing;
          bIncheck = incheck(false, i, j);
        }
        if (wIncheck == true || bIncheck == true){
          std::cout << "King in Check" << std::endl;
          return false;
        }
        // no pawn in the first and end row
        if (i == 0 || i == 7) {
          if (type == "P" || type == "p") {
            std::cout << "Pawn in end or first row" << std::endl;
            return false;
          }
        }
      }
    }
  }
  if (wKing != 1 || bKing != 1) {
    std::cout << "Wrong Number Of Kings" << std::endl;
    return false;
  }
  return true;
}

std::vector<std::vector<Cell>> &ChessBoard::getBoard() {
  return board;
}


// init the board to star a normal game
void ChessBoard::init() {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if ((i >= 0 && i <=1) || (i >= 6 && i <=7)) {
        // setup 32 pieces
        if (j == 0 || j == 7) { // set  Rooks
          if (i == 0) board[i][j].setPiece("r", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("R", 1);
        } else if (j == 1 || j == 6) { // set  knights
          if (i == 0) board[i][j].setPiece("n", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("N", 1);
        }  else if (j == 2 || j == 5) { // set  bishops
          if (i == 0) board[i][j].setPiece("b", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("B", 1);
        } else if (j == 3) { // set queens
          if (i == 0) board[i][j].setPiece("q", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("Q", 1);
        } else if (j == 4) {  // set kings
          if (i == 0) board[i][j].setPiece("k", 0);
          if (i == 1) board[i][j].setPiece("p", 0);
          if (i == 6) board[i][j].setPiece("P", 1);
          if (i == 7) board[i][j].setPiece("K", 1);
        }
      }
    }
  }
  // every piece attach other 31 pieces as Observer
  int r = 0;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if(i != j) board[r][i].getPiece()->attach(board[r][j].getPiece());
      board[r][i].getPiece()->attach(board[r + 1][j].getPiece());
      board[r][i].getPiece()->attach(board[r + 6][j].getPiece());
      board[r][i].getPiece()->attach(board[r + 7][j].getPiece());
    }
  }
  r = 1;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      board[r][j].getPiece()->attach(board[r - 1][j].getPiece());
      if(i != j) board[r][j].getPiece()->attach(board[r][j].getPiece());
      board[r][j].getPiece()->attach(board[r + 5][j].getPiece());
      board[r][j].getPiece()->attach(board[r + 6][j].getPiece());
    }
  }
  r = 6;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      board[r][j].getPiece()->attach(board[r - 6][j].getPiece());
      board[r][j].getPiece()->attach(board[r - 5][j].getPiece());
      if(i != j) board[r][j].getPiece()->attach(board[r][j].getPiece());
      board[r][j].getPiece()->attach(board[r + 1][j].getPiece());
    }
  }
  r = 7;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      board[r][j].getPiece()->attach(board[r - 7][j].getPiece());
      board[r][j].getPiece()->attach(board[r - 6][j].getPiece());
      board[r][j].getPiece()->attach(board[r - 1][j].getPiece());
      if(i != j) board[r][j].getPiece()->attach(board[r][j].getPiece());
    }
  }
}

std::pair<int, int> ChessBoard::findKing(bool colour) {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr) {
        std::string type = board[i][j].getPiece()->type;
        bool color = board[i][j].getPiece()->colour;
        if ((type == "K" || type == "k") && (color == colour)) {
          return  std::pair<int, int>(i, j);
        }
      }
    }
  }
  return  std::pair<int, int>(-1, -1);
}


// when start game in setup mode since the game doesn't init a normal board
// needs to setup Observer for all pieces in the board
void ChessBoard::setUpOb() {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr) {
        for(int m = 0; m < size; ++m) {
          for(int n = 0; n < size; ++n) {
            if (board[m][n].getPiece() != nullptr && m != i && n != j) {
              board[i][j].getPiece()->attach(board[m][n].getPiece());
            }
          }
        }
      }
    }
  }
}

// when you move a piece you need to update the Observer
void ChessBoard::updateOb(int r, int c, int row, int col) {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr && (i != row || j != col)) {
        //deattach previous piece
        board[i][j].getPiece()->deattach(board[r][c].getPiece());
        // attach new piece
        board[i][j].getPiece()->attach(board[row][col].getPiece());
        board[row][col].getPiece()->attach(board[i][j].getPiece());
      }
    }
  }
  board[row][col].getPiece()->deattach(board[r][c].getPiece());
}


// uses for checking if king is in check
// to see if a piece of one player in (r, c) can capture another piece in (row, col)
bool ChessBoard::legalMove(int r, int c, int row, int col, std::string type, bool player) {
  int hdist = col - c;
  int vdist = row - r;
  if (type == "Q" || type == "q" || type == "R" || type == "r" || type == "B" || type == "b") {
    return movePiece(r, c, row, col, type);
  } else if (type == "N" || type == "n") {
    return moveKnight(r, c, row, col);
  } else if (type == "P" || type == "p") {
    if (hdist == 1 || hdist == -1) {
      if ((vdist == -1 && player == true)||(vdist == 1 && player == false)) {
        return true;
      }
    }
  } else if (type == "K" || type == "k"){
    if ((hdist == 1 || hdist == -1 || hdist == 0)
    && (vdist == 1 || vdist == -1 || vdist == 0)) {
      return true;
    }
  }
  return false;
}

// to see if a piece at (row, col) can capture its opponent's King
bool ChessBoard::check(bool player, int row, int col, std::string type) {
  //bool opponent = !player;
  std::pair<int, int> k = findKing(player);
  bool check = false;
  if (k.first >= 0 && k.second >= 0) {
    //int r, int c, int row, int col, std::string type
    check = legalMove(row, col, k.first, k.second, type, player);
  }
  return check;
}

// to see if my King at (row, col) can be checked by  all my opponent's pieces
bool ChessBoard::incheck(bool player, int row, int col) {
  bool opponent = !player;
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr) {
        bool colour = board[i][j].getPiece()->colour;
        if (colour == opponent) {
          std::string type = board[i][j].getPiece()->type;
          bool incheck = legalMove(i, j, row, col, type, opponent);
          if (incheck == true) return true; //destination will be in check
        }
      }
    }
  }
  return false;
}

// to see if a player  checkmates its opponent or not
bool ChessBoard::checkMate(bool player) {
  bool opponent = !player;
  bool checkMate = 0;
  std::pair<int, int> k = findKing(opponent);
  for (int i = -1; i <= 1; i ++) {
    for (int j = -1; j <= 1; j ++) {
      if (i != 0 && j != 0 && k.first + i >= 0 && k.second + j >= 0 && k.first + i <= 7
         && k.second + j <= 7) {
        if ((incheck(opponent, k.first + i, k.second + j) == true)
        || (board[k.first + i][k.second + j].getPiece() != nullptr
        && board[k.first + i][k.second + j].getPiece()->colour == player)) {
          checkMate =  true;
        }
        if (checkMate == false) { // opponent's king can escape in one move
          return false;
        }
      }
    }
  }
  return true;
}


//check if selected piece has a legal move based on piece move rules
//
bool ChessBoard::move(bool player, int r, int c, int row, int col, std::string type) {
  bool colour = board[r][c].getPiece()->colour;

  //check for what type of piece is being moved
  if (type == "Q" || type == "q" || type == "R" ||
    type == "r" || type == "B" || type == "b") {

      if (movePiece(r, c, row, col, type)) { // if Q R B can move to (row, col)
        if (board[row][col].getPiece() != nullptr) { //if opponent, capture

          //capture piece
          board[row][col].attackPiece(type, colour);
          updateOb(r, c, row, col); // updateObservers
          board[r][c].clearPiece();
          if (type == "R" || type == "r") {
            board[row][col].getPiece()->setFirst(0);
          }
          return true;

        } else { // move without capture
          board[row][col].setPiece(type, colour);
          updateOb(r, c, row, col);
          board[r][c].clearPiece();
          if (type == "R" || type == "r") {
            board[row][col].getPiece()->setFirst(0);
          }
          return true;
        }
      }
      return false;

  } else if (type == "N" || type == "n") { //if target is a knight

    if (moveKnight(r, c, row, col)) {
      if (board[row][col].getPiece() != nullptr) {

        board[row][col].attackPiece(type, colour);
        updateOb(r, c, row, col);
        board[r][c].clearPiece();

        return true;
      } else {

        board[row][col].setPiece(type, colour);
        updateOb(r, c, row, col);
        board[r][c].clearPiece();

        return true;
      }
    }
    return false;

  } else if (type == "P" || type == "p") {
    //if pawn moves return true otherwise return false
    return movePawn(r, c, row, col);
  } else {
    //if king moves return true otherwise return false
    return moveKing(player, r, c, row, col);
  }
}

bool ChessBoard::moveRight(int r, int c, int col) {
  for (int i = c + 1; i < col; i++) {
    if(board[r][i].getPiece() != nullptr) { // there is piece along the path, illegal
      return false;
    }
  }
  return true;
}

bool ChessBoard::moveLeft(int r, int c, int col) {
  for (int i = c + 1; i < col; i++) {
    if(board[r][i].getPiece() != nullptr) {
      return false;
    }
  }
  return true;
}

bool ChessBoard::moveUp(int r, int c, int row) {
  for (int i = r - 1; i > row ; i--) {
    if (board[i][c].getPiece() != nullptr) {
       return false;
    }
  }
  return true;
}

bool ChessBoard::moveDown(int r, int c, int row) {
  for (int i = r + 1; i < row ; i++) {
    if(board[i][c].getPiece() != nullptr) {
       return false;
     }
  }
  return true;
}

// this method moves three type piece, queen, bishop, Rook
bool ChessBoard::movePiece(int r, int c, int row, int col, std::string type) {
  if (board[r][c].getPiece()->legalMove(row, col)) { // the destination follows the rule
    // see if there is any piece along the path
    //std::string type = board[r][c].getPiece()->type;
    int hdist = col - c;
    int vdist = row - r;
    if (row == r && (type == "Q" || type == "q" || type == "R" || type == "r")) {
      if (hdist > 0) { // moves right
        return this->moveRight(r, c, col);
      } else { // moves left
        return this->moveLeft(r, c, col);
      }
    } else if (col == c && (type == "Q" || type == "q" || type == "R" || type == "r")) {
      if (vdist > 0) { // moves down
        return this->moveDown(r, c, row);
      } else { // moves up
        return this->moveUp(r, c, row);
      }
    } else { // moves diagonal direction
      if (type == "Q" || type == "q" || type == "B" || type == "b") {
        if (vdist < 0 && hdist > 0) {
          for (int i = r - 1, j = c + 1; i > row && j < col; i--, j++) {
            if(board[i][j].getPiece() != nullptr) return false;
          }
          return true;
        } else if (vdist < 0 && hdist < 0) {
          for (int i = r - 1, j = c - 1; i > row && j > col; i--, j--) {
            if(board[i][j].getPiece() != nullptr) return false;
          }
          return true;
        } else if (vdist > 0 && hdist > 0) {
          for (int i = r + 1, j = c + 1; i < row && j < col; i++, j++) {
            if(board[i][j].getPiece() != nullptr) return false;
          }
          return true;
        } else {
          for (int i = r + 1, j = c - 1; i < row && j > col; i++, j--) {
            if(board[i][j].getPiece() != nullptr) {
              return false;
            }
          }
          return true;
        }
      }
    }
  }
  return false;
}

bool ChessBoard::moveKnight(int r, int c, int row, int col) {
  // since knight can jump through the pieces
  // no need to check along the path
  return board[r][c].getPiece()->legalMove(row, col); // check if the destination is legal
}

bool ChessBoard::movePawn(int r, int c, int row, int col) {
  int hdist = col - c;
  int vdist;
  if (r > row) {
    vdist = r - row;
  } else {
    vdist = row - r;
  }
  if (board[r][c].getPiece()->legalMove(row, col)) {
    std::string type = board[r][c].getPiece()->type;
    bool colour = board[r][c].getPiece()->colour;
    if ((hdist == 1 || hdist == -1) && vdist == 1) { //capture
      if (board[row][col].getPiece() != nullptr
      && colour != board[row][col].getPiece()->colour) { // normal capture
        if (board[row][col].getPiece()->type != "k" && board[row][col].getPiece()->type != "K") {
          board[row][col].attackPiece(type, colour);
          updateOb(r, c, row, col);
          board[r][c].clearPiece();
        }
        return true;
      } else if (board[r][col].getPiece() != nullptr
        && board[row][col].getPiece() == nullptr
        && colour != board[r][col].getPiece()->colour) { // en passant
        int passant = board[r][col].getPiece()->getPassant();
        if (passant == 1) { // the opponent pawn is a passant
          board[row][col].attackPiece(type, colour);
          updateOb(r, c, row, col);
          board[r][c].clearPiece();
          // also remove the passant from the Observers
          for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
              if (board[i][j].getPiece() != nullptr) {
                board[i][j].getPiece()->deattach(board[r][col].getPiece());
              }
            }
          }
          board[r][col].clearPiece();
          return true;
        }
      }
    }
    // move without capture
    int first = board[r][c].getPiece()->getFirst();
    if (first == true) { // first move
      if (hdist == 0) {
        if ((vdist == 2 || vdist ==  1) && board[row][col].getPiece() == nullptr) {
          // move 1 or 2 step forward and no piece at destination
          board[row][col].setPiece(type, colour);
          updateOb(r, c, row, col);
          board[r][c].clearPiece();
          board[row][col].getPiece()->setFirst(0); // first move has been done
          if (vdist == 2) {
            board[row][col].getPiece()->setPassant(1); // pawn is now a passant
          }
          return true;
        }
      }
    } else {
      if (hdist == 0) {
        if (vdist == 1 && board[row][col].getPiece() == nullptr) {
          // move 1 step forward and no piece at destination
          board[row][col].setPiece(type, colour);
          updateOb(r, c, row, col);
          board[r][c].clearPiece();
          return true;
        }
      }
    }
  }
  return false;
}

void ChessBoard::undo(int r, int c, int row, int col,
   std::string mover, bool moverC, const bool destC = false, const std::string dest = "") {
     if (dest == "") {
       board[r][c].setPiece(mover, moverC);
       updateOb(r, c, row, col);
       board[row][col].clearPiece();
     } else {
       board[r][c].setPiece(mover, moverC);
       updateOb(r, c, row, col);
       board[row][col].clearPiece();

       board[row][col].setPiece(dest, destC);
       updateOb(r, c, row, col);
     }
}

std::pair<int, int> ChessBoard::findRook(bool colour, int row, int col, int h, int v) {
  for(int i = 0; i < size; ++i) {
    for(int j = 0; j < size; ++j) {
      if (board[i][j].getPiece() != nullptr) {
        std::string type = board[i][j].getPiece()->type;
        bool color = board[i][j].getPiece()->colour;
        if ((type == "R" || type == "r") && (color == colour)) {
          int hdist = j - col;
          int vdist = i - row;
          if (h == 0) {
            if ((v > 0 && vdist > 0) || (v < 0 && vdist < 0)) {
              return  std::pair<int, int>(i, j);
            }
          } else if (v == 0) {
            if ((h > 0 && hdist > 0) || (h < 0 && hdist < 0)) {
              return  std::pair<int, int>(i, j);
            }
          } else {
            if (((v > 0 && vdist > 0) || (v < 0 && vdist < 0))
          && ((h > 0 && hdist > 0) || (h < 0 && hdist < 0))) {
              return  std::pair<int, int>(i, j);
            }
          }
        }
      }
    }
  }
  return  std::pair<int, int>(-1, -1);
}

bool ChessBoard::kingRight(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = c; i < k.second; i++) {
    if (i <= col && i > c) {
      // no cell in which will make King in check
      // no cell along is occupied by other piece
      // from the start to destination
      if(incheck(player, r, i) == true || board[r][i].getPiece() != nullptr) {
        return false;
      }
    }
    // no cell is occupied by other pieces from the destination to the Rook
    if(i!= c && board[r][i].getPiece() != nullptr) {
      return false;
    }
  }
  // do castling
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row][col - 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row, col - 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingLeft(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = c; i > k.second; i--) {
    if (i >= col && i < c) {
      if(incheck(player, r, i) == true || board[r][i].getPiece() != nullptr) {
        return false;
      }
    }
    if (i != c && board[r][i].getPiece() != nullptr) {
      return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row][col + 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row, col + 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingDown(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r; i <= k.first; i++) {
    if (i <= row && i > r) {
      if(incheck(player, i, c) == true || board[i][c].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && board[i][c].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row - 1][col].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row - 1, col);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingUp(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r; i >= k.first; i--) {
    if (i >= row && i < r) {
      if(incheck(player, i, c) == true || board[i][c].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && board[i][c].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row + 1][col].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row + 1, col);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingRightDown(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r, j = c; i <= k.first &&  j <= k.second; i++, j++) {
    if (i <= row && j <= col && i > r && j > c) {
      if(incheck(player, i, j) == true || board[i][j].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && j != c && board[i][j].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row - 1][col - 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row - 1, col - 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingLeftDown(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r, j = c; i <= k.first &&  j >= k.second; i++, j--) { // moves left down
    if (i <= row && j >= col && i > r && j < c) {
      if(incheck(player, i, j) == true || board[i][j].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && j != c && board[i][j].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row - 1][col + 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row - 1, col + 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingRightUp(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r, j = c; i >= row &&  j <= col; i--, j++) { // moves up right
    if (i >= row && j <= col && i < r && j > c) {
      if(incheck(player, i, j) == true || board[i][j].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && j != c && board[i][j].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row + 1][col - 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row + 1, col - 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::kingLeftUp(int r, int c, int row, int col, std::pair<int, int> k, bool player) {
  std::string type = board[r][c].getPiece()->type;
  bool colour = board[r][c].getPiece()->colour;
  for (int i = r, j = c; i >= row &&  j >= col; i--, j--) {
    if (i >= row && j >= col && i < r && j < c) {
      if(incheck(player, i, j) == true || board[i][j].getPiece() != nullptr) {
        return false;
      }
    }
    if(i != r && j != c && board[i][j].getPiece() != nullptr) {
        return false;
    }
  }
  std::string rtype = board[k.first][k.second].getPiece()->type;
  bool rcolour = board[k.first][k.second].getPiece()->colour;
  board[row + 1][col + 1].setPiece(rtype, rcolour);
  updateOb(k.first, k.second, row + 1, col + 1);
  board[row][col].setPiece(type, colour);
  board[k.first][k.second].clearPiece();
  updateOb(r, c, row, col);
  board[r][c].clearPiece();
  return true;
}

bool ChessBoard::moveKing(bool player, int r, int c, int row, int col) {
  if (board[r][c].getPiece()->legalMove(row, col)) {
    std::string type = board[r][c].getPiece()->type;
    bool colour = board[r][c].getPiece()->colour;
    int hdist = col - c;
    int vdist = row - r;
    if (((vdist == 0)&&(hdist == 2 || hdist == -2)) ||
      ((hdist == 0)&&(vdist == 2 || vdist == -2)) ||
      ((hdist == -2 || hdist == 2)&&(vdist == 2 || vdist == -2))) { // castling
        std::pair<int, int> k = findRook(player, row, col, hdist, vdist);
         if (k.first >= 0) { // king moves towards a Rook
          if (board[r][c].getPiece()->getFirst() == true
          && board[k.first][k.second].getPiece()->getFirst() == true) { // king and Rook didnt move before
            // eight directions castling
            if (vdist == 0 && hdist == 2) { // moves right
              return kingRight(r, c,row, col, k, player);
            } else if (vdist == 0 && hdist == -2) { // moves left
              return kingLeft(r, c,row, col, k, player);
            } else if (hdist == 0 && vdist == 2) { // moves down
              return kingDown(r, c,row, col, k, player);
            } else if (hdist == 0 && vdist == -2) { // moves up
              return kingDown(r, c, row, col, k, player);
            } else if (hdist == 2 && vdist == 2) { // moves right and down
              return kingRightDown(r, c, row, col, k, player);
            } else if (hdist == 2 && vdist == -2) {
              return kingLeftDown(r, c, row, col, k, player);
            } else if (hdist == -2 && vdist == 2) {
              return kingRightUp(r, c, row, col, k, player);
            } else if (hdist == -2 && vdist == -2) {
              return kingLeftUp(r, c, row, col, k, player);
            }
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    // normal move
    bool incheck = this->incheck(player, row, col);
    if (incheck ==  true) { // illegal move king will be in check
      return false;
    } else { // destination will not make king in check
      if (board[row][col].getPiece() == nullptr) {
        board[row][col].setPiece(type, colour);
        updateOb(r, c, row, col);
        board[r][c].clearPiece();
        if (board[row][col].getPiece()->getFirst() == true) {
          board[row][col].getPiece()->setFirst(0);
        }
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &out, const ChessBoard &b) {
  for(int i = 0; i <= b.size; ++i) {
    if (i < b.size) {
      out << 8 - i << " ";
      for(int j = 0; j < b.size; ++j) {
        out << b.board[i][j];
      }
      out << std::endl;
    } else {
      out << "  abcdefgh" << std::endl;
    }
  }
  return out;
}
