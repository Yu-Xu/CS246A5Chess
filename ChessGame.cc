#include "ChessGame.h"

ChessGame::ChessGame(): theBoard{ChessBoard{}}, p1{true}, p2{false} {
}

ChessGame::~ChessGame() {}

std::pair<int, int> ChessGame::getLocation(std::string location) {
  char row = location[1];
  char col = location[0];
  int r;
  int c;
  r = 8 - (row - '0');
  c = col - 'a';
  return std::pair<int, int>(r, c);
}

void ChessGame::startGame(std::string player1, std::string player2) {
  theBoard.init();
  int len = 8;
  this->p1.setPlayer(player1);
  this->p2.setPlayer(player2);
  if (player1 != "human") {
    char c = player1[8];
    if (c == '1') {
      this->p1.setLevel(1);
    } else if (c == '2') {
      this->p1.setLevel(2);
    } else if (c == '3') {
      this->p1.setLevel(3);
    } else if (c == '4') {
      this->p1.setLevel(4);
    }
  }
  if (player2 != "human") {
    char c = player2[8];
    if (c == '1') {
      this->p2.setLevel(1);
    } else if (c == '2') {
      this->p2.setLevel(2);
    } else if (c == '3') {
      this->p2.setLevel(3);
    } else if (c == '4') {
      this->p2.setLevel(4);
    }
  }
  // player owns 16 pieces
  p1.getRooks().push_back(std::pair<int,int>(7, 0));
  p1.getRooks().push_back(std::pair<int,int>(7, 7));
  p1.getKnights().push_back(std::pair<int,int>(7, 1));
  p1.getKnights().push_back(std::pair<int,int>(7, 6));
  p1.getBishops().push_back(std::pair<int,int>(7, 2));
  p1.getBishops().push_back(std::pair<int,int>(7, 5));
  p1.getQueen().push_back(std::pair<int,int>(7, 3));
  p1.getKing().push_back(std::pair<int,int>(7, 4));
  for (int i = 0; i < len; i++) {
    p1.getPawns().push_back(std::pair<int,int>(6, i));
  }
  p2.getRooks().push_back(std::pair<int,int>(0, 1));
  p2.getRooks().push_back(std::pair<int,int>(0, 7));
  p2.getKnights().push_back(std::pair<int,int>(0, 1));
  p2.getKnights().push_back(std::pair<int,int>(0, 6));
  p2.getBishops().push_back(std::pair<int,int>(0, 2));
  p2.getBishops().push_back(std::pair<int,int>(0, 5));
  p2.getQueen().push_back(std::pair<int,int>(0, 3));
  p2.getKing().push_back(std::pair<int,int>(0, 4));
  for (int i = 0; i < len; i++) {
    p2.getPawns().push_back(std::pair<int,int>(1, i));
  }
}

// add pieces to player when setup
void ChessGame::add(bool player, std::string type, int row, int col) {
  std::pair<int, int> k = std::pair<int, int>(row, col);
  Player &p = player ? p1: p2;//player 1
  if (type == "P" || type == "p") {
    p.getPawns().push_back(k);
  } else if (type == "B" || type == "b") {
    p.getBishops().push_back(k);
  } else if (type == "N" || type == "n") {
    p.getKnights().push_back(k);
  } else if (type == "R" || type == "r") {
    p.getRooks().push_back(k);
  } else if (type == "Q" || type == "q") {
    p.getQueen().push_back(k);
  } else if (type == "K" || type == "k") {
    p.getKing().push_back(k);
  }
}

void ChessGame::remove(bool player, std::string type, int r, int c) {
  // remove pieces from player when setup
  Player &p = player ? p1: p2;
  if (type == "P" || type == "p") {
    int len = p.getPawns().size();
    for (int i = 0; i < len; i++) {
      if (p.getPawns()[i].first == r && p.getPawns()[i].second == c){
        p.getPawns().erase(p.getPawns().begin() + i);
      }
    }
  } else if (type == "B" || type == "b") {
    int len = p.getBishops().size();
    for (int i = 0; i < len; i++) {
      if (p.getBishops()[i].first == r && p.getBishops()[i].second == c){
        p.getBishops().erase(p.getBishops().begin() + i);
      }
    }
  } else if (type == "N" || type == "n") {
    int len = p.getKnights().size();
    for (int i = 0; i < len; i++) {
      if (p.getKnights()[i].first == r && p.getKnights()[i].second == c){
        p.getKnights().erase(p.getKnights().begin() + i);
      }
    }
  } else if (type == "R" || type == "r") {
    int len = p.getRooks().size();
    for (int i = 0; i < len; i++) {
      if (p.getRooks()[i].first == r && p.getRooks()[i].second == c){
        p.getRooks().erase(p.getRooks().begin() + i);
      }
    }
  } else if (type == "Q" || type == "q") {
    int len = p.getQueen().size();
    for (int i = 0; i < len; i++) {
      if (p.getQueen()[i].first == r && p.getQueen()[i].second == c){
        p.getQueen().erase(p.getQueen().begin() + i);
      }
    }
  } else if (type == "K" || type == "k") {
    int len = p.getKing().size();
    for (int i = 0; i < len; i++) {
      if (p.getKing()[i].first == r && p.getKing()[i].second == c){
        p.getKing().erase(p.getKing().begin() + i);
      }
    }
  }
}

void ChessGame::updatePlayer(bool player, int r, int c, int row, int col, std::string t1, std::string t2) {
  bool opponent = !player;
  if (t2 != "") { // the player move with capture, needs to remove previous piece in (row, col)
    this->remove(player,t1, r, c); // removes my previous location of the piece
    this->remove(opponent, t2, row, col); // removes opponent's piece at  destination
    this->add(player, t1, row, col);
  } else {
    if (t1 == "P" || t1 == "p") {
      int hdist = col - c;
      if (hdist == 1 ) {
        if (opponent == true) {
          this->remove(opponent, "P", r, c + 1);
        } else {
          this->remove(opponent, "p", r, c + 1);
        }
      } else {
        if (opponent == true) {
          this->remove(opponent, "P", r, c - 1);
        } else {
          this->remove(opponent, "p", r, c - 1);
        }
      }
    }
    this->remove(player, t1, r, c);
    this->add(player, t1, row, col);
  }
}

void ChessGame::setUpOb() {
  theBoard.setUpOb();
}

// setup mode
bool ChessGame::setUp(std::string command, std::string coordinate, std::string t) {
  std::pair<int, int> c = getLocation(coordinate);
  bool result = true;
  bool colour = true;
  if(t != "") {
    char type = t[0];
    if (type >= 'a' && type <= 'z') {
      colour = false;
    }
  }
  if (command == "+") {
    if (theBoard.getBoard()[c.first][c.second].getPiece() != nullptr) {
      bool player = theBoard.getBoard()[c.first][c.second].getPiece()->colour;
      std::string t1 = theBoard.getBoard()[c.first][c.second].getPiece()->type;
      this->remove(player, t1, c.first, c.second);
    }
    theBoard.addPiece(c.first, c.second, t, colour);
    this->add(colour, t, c.first, c.second);
  } else if (command == "-") {
    this->remove(colour, t, c.first, c.second);
    theBoard.removePiece(c.first, c.second);
  } else if (command == "done") {
    this->setUpOb();
    result = theBoard.checkBoard();
  }
  return result;
}

bool ChessGame::checkMate(bool player) {
  return theBoard.checkMate(player);
}

//check again if in check

bool ChessGame::move(bool player, int r, int c, int row, int col) {
  std::string t1 = theBoard.getBoard()[r][c].getPiece()->type;
  std::string t2 = "";
  if (theBoard.getBoard()[row][col].getPiece() != nullptr) {
    std::string t2 = theBoard.getBoard()[row][col].getPiece()->type;
  }

  bool check = theBoard.check(player, row, col, t1);

  if (check ==  true) {
    if (player == 1) {
      std::cout << "Black is in check" << std::endl;
    } else {
      std::cout << "White is in check" << std::endl;
    }
  }

  bool result = theBoard.move(player, r, c, row, col);

  if (result == true) {
    if (check) {
      check = theBoard.check(player, row, col, t1);
      if (check) {
        return false;
      }
    }
    bool opponent = !player;

    this->updatePlayer(player, r, c, row, col, t1, t2);
    // when opponet moves
    // change all your pawns passant to false;
    if (p1.getColour() == opponent) {
      int len = p1.getPawns().size();
      for (int i = 0; i < len; i++) {
        std::pair<int, int> pawn = p1.getPawns()[i];
        theBoard.getBoard()[pawn.first][pawn.second].getPiece()->setPassant(0);
      }
    } else {
      int len = p2.getPawns().size();
      for (int i = 0; i < len; i++) {
        std::pair<int, int> pawn = p2.getPawns()[i];
        theBoard.getBoard()[pawn.first][pawn.second].getPiece()->setPassant(0);
      }
    }
  }
  return result;
}

std::ostream &operator<<(std::ostream &out, const ChessGame &g) {
  out << g.theBoard;
  return out;
}
