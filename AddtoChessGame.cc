#include "ChessGame.h"

ChessGame::ChessGame(Xwindow &xw): theBoard{ChessBoard{}}, gd{new GraphicsDisplay{xw}}, p1{nullptr}, p2{nullptr} {
}

ChessGame::~ChessGame() {
  delete p1;
  delete p2;
  delete gd;
}


void ChessGame::setPlayer(std::string player1, std::string player2) {
  if (player1 != "human") {
    delete p1;
    p1 = new Computer{true, player1};
    char c = player1[8];
    if (c == '1') {
      this->p1->setLevel("1");
    } else if (c == '2') {
      this->p1->setLevel("2");
    } else if (c == '3') {
      this->p1->setLevel("3");
    } else if (c == '4') {
      this->p1->setLevel("4");
    }
  } else {
    p1 = new Human{true, player1};
  }
  if (player2 != "human") {
    p2 = new Computer{false, player2};
    char c = player2[8];
    if (c == '1') {
      this->p2->setLevel("1");
    } else if (c == '2') {
      this->p2->setLevel("2");
    } else if (c == '3') {
      this->p2->setLevel("3");
    } else if (c == '4') {
      this->p2->setLevel("4");
    }
  } else {
    p2 = new Human{false, player1};
  }
}

void ChessGame::startGame() {
  theBoard.init();
  int len = 8;
  p1->getRooks().push_back(std::pair<int,int>(7, 0));
  p1->getRooks().push_back(std::pair<int,int>(7, 7));
  p1->getKnights().push_back(std::pair<int,int>(7, 1));
  p1->getKnights().push_back(std::pair<int,int>(7, 6));
  p1->getBishops().push_back(std::pair<int,int>(7, 2));
  p1->getBishops().push_back(std::pair<int,int>(7, 5));
  p1->getQueen().push_back(std::pair<int,int>(7, 3));
  p1->getKing().push_back(std::pair<int,int>(7, 4));
  // GraphicsDisplay
  gd->setPiece(-1, -1, 7, 0, "R", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 7, "R", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 1, "N", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 6, "N", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 2, "B", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 5, "B", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 3, "Q", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 7, 4, "K", false, std::pair<int, int> (-1, -1));

  gd->setPiece(-1, -1, 0, 0, "r", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 7, "r", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 1, "n", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 6, "n", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 2, "b", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 5, "b", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 3, "q", false, std::pair<int, int> (-1, -1));
  gd->setPiece(-1, -1, 0, 4, "k", false, std::pair<int, int> (-1, -1));
  for (int i = 0; i < len; i++) {
    p1->getPawns().push_back(std::pair<int,int>(6, i));
    gd->setPiece(-1, -1, 6, i, "P", false, std::pair<int, int> (-1, -1));
    gd->setPiece(-1, -1, 1, i, "p", false, std::pair<int, int> (-1, -1));
  }
  p2->getRooks().push_back(std::pair<int,int>(0, 1));
  p2->getRooks().push_back(std::pair<int,int>(0, 7));
  p2->getKnights().push_back(std::pair<int,int>(0, 1));
  p2->getKnights().push_back(std::pair<int,int>(0, 6));
  p2->getBishops().push_back(std::pair<int,int>(0, 2));
  p2->getBishops().push_back(std::pair<int,int>(0, 5));
  p2->getQueen().push_back(std::pair<int,int>(0, 3));
  p2->getKing().push_back(std::pair<int,int>(0, 4));
  for (int i = 0; i < len; i++) {
    p2->getPawns().push_back(std::pair<int,int>(1, i));
  }
}

//when ending a game reset all player and board
void ChessGame::endGame(Xwindow &xw) {
  delete p1;
  delete p2;
  delete gd;
  p1 = nullptr;
  p2 = nullptr;
  gd = new GraphicsDisplay{xw};
  theBoard.clearBoard();
}


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
    theBoard.addPiece(c.first, c.second, t, colour);
    int col = c.second + 1;
    // update GraphicsDisplay
    gd->setPiece(-1, -1, c.first, col, t, false, std::pair<int, int>(-1, -1));
  } else if (command == "-") {
    theBoard.removePiece(c.first, c.second);
    int col = c.second + 1;
    // update GraphicsDisplay
    gd->setPiece(c.first, col, -1, -1, t, false, std::pair<int, int>(-1, -1));
  } else if (command == "done") {
    result = theBoard.checkBoard();
  }
  return result;
}

bool ChessGame::staleMate() {
  return theBoard.staleMate();
}

bool ChessGame::Promotion(bool player, int r, int c, int row, std::string t) {
  std::string type = theBoard.getBoard()[r][c].getPiece()->type;
  if (t == "K" || t == "k" || t == "P" || t == "p") {
    return false;
  }
  if (type != "P" && type != "p") return false;
  if (row != 0 && row != 7) return false;
  return true;
}

bool ChessGame::move(bool player, int r, int c, int row, int col, std::string promt) {
  if (r < 0 || r > 7 || c < 0 || c > 7 || row < 0 || row > 7 || col < 0 || col > 7) {
    return false;
  }
  if (theBoard.getBoard()[r][c].getPiece() == nullptr || (row == r && col == c)) {
    return false;
  }
  if (theBoard.getBoard()[r][c].getPiece()->colour != player) {
    return false;
  }
  if (promt != "") {
    if (this->Promotion(player, r, c, row, promt) == false) {
      return false;
    }
  }
  std::string t1 = theBoard.getBoard()[r][c].getPiece()->type;
  std::string t2 = "";
  if (theBoard.getBoard()[row][col].getPiece() != nullptr) {
    t2 = theBoard.getBoard()[row][col].getPiece()->type;
  }
  bool result = theBoard.move(player, r, c, row, col);
  if (result == true) {
    bool check = theBoard.check(player, row, col, t1);
    bool opponent = !player;
    if (check ==  true) {
      if (player == 1) {
        std::cout << "Black is in check" << std::endl;
      } else {
        std::cout << "White is in check" << std::endl;
      }
    }
    this->updatePlayer(player, r, c, row, col, t1, t2);
    if (p1->getColour() == opponent) {
      int len = p1->getPawns().size();
      for (int i = 0; i < len; i++) {
        std::pair<int, int> pawn = p1->getPawns()[i];
        theBoard.getBoard()[pawn.first][pawn.second].getPiece()->setPassant(0);
      }
    } else {
      int len = p2->getPawns().size();
      for (int i = 0; i < len; i++) {
        std::pair<int, int> pawn = p2->getPawns()[i];
        theBoard.getBoard()[pawn.first][pawn.second].getPiece()->setPassant(0);
      }
    }
    if (promt != "") {
      theBoard.getBoard()[row][col].clearPiece();
      theBoard.getBoard()[row][col].setPiece(promt, player);
    }
    updateBoard(r, c, row, col, t2, player);
  }
  return result;
}


// computerMove
void ChessGame::computerMove(bool player) {
  Player *p = player ? p1: p2;
  std::string level = p->getLevel();
  // all the moves you can choose
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = theBoard.computerMove(player, level);
  int size = range.size();
  int times = 64;
  while (times >= 0) {
    srand (clock());
    int i = rand() % size; // randomly pick one
    int count = 0;
    for (auto it : range) {
      int rangeSize = it.second.size();
      if (count == i && rangeSize >= 0) {
        srand (clock());
        int j = rand() % rangeSize;
        int r = it.first.first;
        int c = it.first.second;
        int row = it.second[j].first;
        int col = it.second[j].second;
        if (this->move(player, r, c, row, col, "") == true) { // do move
          return;
        } else { // if false erease this move just for safe
          it.second.erase(it.second.begin() + j);
          continue;
        }
      }
      if (rangeSize <= 0) {
        break;
      }
      ++count;
    }
    --times;
  }
}

// update the GraphicsDisplay of the board
void ChessGame::updateBoard(int r, int c, int row, int col, std::string t2, bool player) {
  int hdist = col - c;
  int vdist = row - r;
  bool passant = false;
  std::string type = theBoard.getBoard()[row][col].getPiece()->type;
  std::pair<int, int> rook = std::pair<int, int>(-1, -1);
  if (t2 == "") {
    if (type == "P" || type == "p") {
      if (hdist != 0) {
        passant = true;
      }
    }
    if (type == "K" || type == "k") {
      if (hdist == 2 || hdist == -2 || vdist == 2 || vdist == -2) {
        rook = theBoard.findRook(player, row, col, hdist, vdist);
      }
    }
  }
  int nc = c + 1;
  int ncol = col + 1;
  gd->setPiece(r, nc, row, ncol, type, passant, rook);
}

std::ostream &operator<<(std::ostream &out, ChessGame &g) {
  out << g.theBoard;
  out << *g.gd;
  return out;
}