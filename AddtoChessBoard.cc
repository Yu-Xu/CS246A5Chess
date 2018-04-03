//Please add it to ChessBoard
bool ChessBoard::staleMate() {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (board[i][j].getPiece() != nullptr) {
        std::string type = board[i][j].getPiece()->type;
        bool player = board[i][j].getPiece()->colour;
        std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = computerL1(player);
        if (range.size() > 0) { // there is piece in the board still has legal move
          return false;
        }
      }
    }
  }
  return true;
}

// Computer Part

std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> ChessBoard::computerMove(bool player, std::string level) {
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> v = computerL1(player);
  if (level == "1") {
    return v;
  } else if (level == "2") {
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = computerL2(player);
    if (range.size() > 0) { // if no possible moves for level2 do level1
      return range;
    }
  } else if (level == "3") {
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = computerL3(player);
    if (range.size() > 0) {
      return range;
    }
  }
  return v;
}

// all legal moves for one piece
std::vector<std::pair<int, int>> ChessBoard::legalRange(int r, int c, std::string type, bool player) {
  if (type == "Q" || type == "q" || type == "R" || type == "r" || type == "B" || type == "b") { // 上0 下1 左2 右3 左上4 右上5 左下6 右下7
    return legal(r, c, type, player);
  } else if (type == "N" || type == "n") {
    return legalN(r, c, type, player);
  } else if (type == "K" || type == "k") {
    return legalK(r, c, type, player);
  }
  return legalP(r, c, type, player);
}

// map has a key as which piece you want to move and a value vector of moves this piece can move
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> ChessBoard::computerL1(bool player) {
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> m;
  for (int i = 0; i < size; i++)  {
    for (int j = 0; j < size; j++) {
      if (board[i][j].getPiece() != nullptr && board[i][j].getPiece()->colour == player) { // find all possible moves of all the pieces i have
        std::string type = board[i][j].getPiece()->type;
        std::vector<std::pair<int, int>> range = oneLegalMove(player, i, j, type);
        if (range.size() > 0) { // if there is move for this piece add to m
          std::pair<int, int> p = std::pair<int, int>(i , j);
          m.insert(std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>(p, range));
        }
      }
    }
  }
  return m;
}

std::map<std::pair<int, int>, std::vector<std::pair<int, int>>>ChessBoard::computerL2(bool player) {
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> captures;
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = computerL1(player); // first get all possible moves
  for (auto it : range) {
    std::vector<std::pair<int, int>> moves;
    std::pair<int, int> p = it.first;
    int l = it.second.size();
    if (l > 0) {
      for (int j = 0; j < l; j++) {
        int row = it.second[j].first;
        int col = it.second[j].second;
        int r = it.first.first;
        int c = it.first.second;
        std::string type = board[r][c].getPiece()->type;
        if (board[row][col].getPiece() != nullptr && board[row][col].getPiece()->colour != player) { // if this move has opponet piece the we prefer this move
          if (type != "K" && type != "k") moves.push_back(it.second[j]); // cannot capture a king
        }
        if (board[row][col].getPiece() == nullptr) { // if no piece there check if a piece in this cell can check a king
          board[row][col].setPiece(type, player); // since chek function will work when there is already a piece in (row, col) so i first set a piece here
          bool check = this->check(player, row, col, type);
          if (check == true) moves.push_back(it.second[j]); // if true the prefer check moves
          board[row][col].clearPiece(); // the remove it
        }
      }
    }
    if (moves.size() > 0) { // check if this piece have capturing and checking moves  if not no needs to add to m
      captures.insert(std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>(p, moves));
    }
  }
  return captures;
}

std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> ChessBoard::computerL3(bool player) {
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> m;
  std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> range = computerL1(player);
  for (auto it : range) {
    std::vector<std::pair<int, int>> moves;
    std::pair<int, int> p = it.first;
    int l = it.second.size();
    if (l > 0) {
      for (int j = 0; j < l; j++) {
        int row = it.second[j].first;
        int col = it.second[j].second;
        int r = it.first.first;
        int c = it.first.second;
        std::string type = board[r][c].getPiece()->type;
        // bool check = this->check(player, row, col, type);
        bool incheck = this->incheck(player, row, col);
        if (board[row][col].getPiece() != nullptr && board[row][col].getPiece()->colour != player) { // if this move has opponet piece the we prefer this move
          if (type != "K" && type != "k") moves.push_back(it.second[j]); // cannot capture a king
        }
        if (board[row][col].getPiece() == nullptr) { // if no piece there check if a piece in this cell can check a king
          board[row][col].setPiece(type, player); // since chek function will work when there is already a piece in (row, col) so i first set a piece here
          bool check = this->check(player, row, col, type);
          if (check == true) moves.push_back(it.second[j]); // if true the prefer check moves
          board[row][col].clearPiece(); // the remove it
        }
        if (incheck == false) {
          moves.push_back(it.second[j]);
        }
      }
    }
    if (moves.size() > 0) {
      m.insert(std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>(p, moves));
    }
  }
  return m;
}


// Used for find all possible coordinate for B Q R can reach
std::vector<std::pair<int, int>> ChessBoard::legal(int r, int c, std::string type, bool player) {
  std::vector<std::pair<int, int>> v;
  if (type == "Q" || type == "q" || type == "R" || type == "r") {
    if (r > 0) { // up
      int i = r - 1;  // starts at the cell up this piece
      while (i >= 0) {  // track along until the boundary of the board
        if (board[i][c].getPiece() != nullptr) { // if along the path there is a piece in one cell
          if (board[i][c].getPiece()->colour != player) { // if the piece belongs to my opponet push to v
            v.push_back(std::pair<int, int>(i, c));
          }
          break; // cannot jump a piece
        }
        v.push_back(std::pair<int, int>(i, c));
        i--;
      }
    }
    if (r < 7) { //down
      int i = r + 1;
      while (i <= 7) {
        if (board[i][c].getPiece() != nullptr) {
          if (board[i][c].getPiece()->colour == player) {
            v.push_back(std::pair<int, int>(i, c));
          }
          break;
        }
        v.push_back(std::pair<int, int>(i, c));
        i++;
      }
    }
    if (c > 0) { //left
      int i = c - 1;
      while (i >= 0) {
        if (board[r][i].getPiece() != nullptr) {
          if (board[r][i].getPiece()->colour == player) {
            v.push_back(std::pair<int, int>(r, i));
          }
          break;
        }
        v.push_back(std::pair<int, int>(r, i));
        i--;
      }
    }
    if (c < 7) { // right
      int i = c + 1;
      while (i <= 7) {
        if (board[r][i].getPiece() != nullptr) {
          if (board[r][i].getPiece()->colour == player) {
            v.push_back(std::pair<int, int>(r, i));
          }
          break;
        }
        v.push_back(std::pair<int, int>(r, i));
        i++;
      }
    }
  }
  if (type == "Q" || type == "q" || type == "B" || type == "b") {
    int index = 4;
    if (type == "B" || type == "b") index = 0;
    if (r > 0 && c > 0) {  // up left
      int i = r - 1;
      int j = c - 1;
      while (i >= 0 && j >= 0) {
        if (board[i][j].getPiece() != nullptr) {
          if (board[i][j].getPiece()->colour != player) {
            v.push_back(std::pair<int, int>(i, j));
          }
          break;
        }
        v.at(index) = std::pair<int, int>(i, j);
        i--;
        j--;
      }
    }
    ++index;
     if (r > 0 && c < 7) {  // up right
      int i = r - 1;
      int j = c + 1;
      while (i >= 0 && j <= 7) {
        if (board[i][j].getPiece() != nullptr) {
          if (board[i][j].getPiece()->colour != player) {
            v.push_back(std::pair<int, int>(i, j));
          }
          break;
        }
        v.at(index) = std::pair<int, int>(i, j);
        i--;
        j++;
      }
    }
    ++index;
     if (r < 7 && c > 0) {  // down left
      int i = r + 1;
      int j = c - 1;
      while (i <= 7 && j >= 0) {
        if (board[i][j].getPiece() != nullptr) {
          if (board[i][j].getPiece()->colour != player) {
            v.push_back(std::pair<int, int>(i, j));
          }
          break;
        }
        v.at(index) = std::pair<int, int>(i, j);
        i++;
        j--;
      }
    }
    ++index;
     if (r < 7 && c < 7) {  // down right
      int i = r + 1;
      int j = c + 1;
      while (i <= 7 && j <= 7) {
        if (board[i][j].getPiece() != nullptr) {
          if (board[i][j].getPiece()->colour != player) {
            v.push_back(std::pair<int, int>(i, j));
          }
          break;
        }
        v.at(index) = std::pair<int, int>(i, j);
        i++;
        j++;
      }
    }
  }
  return v;
}

std::vector<std::pair<int, int>> ChessBoard::legalN(int r, int c, std::string type, bool player) {
  std::vector<std::pair<int, int>> v;
  int r1 = r + 2;
  int r2 = r - 2;
  int r3 = r + 1;
  int r4 = r - 1;
  int c1 = c + 2;
  int c2 = c - 2;
  int c3 = c + 1;
  int c4 = c - 1;
  // push all the possible coordinates to v;
  if (r1 <= 7 && c3 <= 7) {
    v.push_back(std::pair<int, int>(r1, c3));
  }
  if (r1 <= 7 && c4 >= 0) {
    v.push_back(std::pair<int, int>(r1, c4));
  }
  if (r2 >= 0 && c3 <= 7) {
    v.push_back(std::pair<int, int>(r2, c3));
  }
  if (r2 >= 0 && c4 >= 0) {
    v.push_back(std::pair<int, int>(r2, c4));
  }
  if (r3 <= 7 && c1 <= 7) {
    v.push_back(std::pair<int, int>(r3, c1));
  }
  if (r3 <= 7 && c2 >= 0) {
    v.push_back(std::pair<int, int>(r3, c2));
  }
  if (r4 >= 0 && c1 <= 7) {
    v.push_back(std::pair<int, int>(r4, c1));
  }
  if (r4 >= 0 && c2 >= 0) {
    v.push_back(std::pair<int, int>(r4, c2));
  }
  return v;
}

std::vector<std::pair<int, int>> ChessBoard::legalK(int r, int c, std::string type, bool player) {
  std::vector<std::pair<int, int>> v;
  int r1 = r + 1;
  int r2 = r - 1;
  int c1 = c + 1;
  int c2 = c - 1;
  if (r1 <= 7 && c1 <= 7) {
    if (incheck(player, r1, c1) == false) { // cannot move to a place will make the king in check
      v.push_back(std::pair<int, int>(r1, c1));
    }
  }
  if (r1 <= 7 && c2 >= 0) {
    if (incheck(player, r1, c2) == false) {
      v.push_back(std::pair<int, int>(r1, c2));
    }
  }
  if (r2 >= 0 && c1 <= 7) {
    if (incheck(player, r2, c1) == false) {
      v.push_back(std::pair<int, int>(r2, c1));
    }
  }
  if (r2 >= 0 && c2 >= 0) {
    if (incheck(player, r2, c2) == false) {
      v.push_back(std::pair<int, int>(r2, c2));
    }
  }
  if (r1 <= 7) {
    if (incheck(player, r1, c) == false) {
      v.push_back(std::pair<int, int>(r1, c));
    }
  }
  if (c1 <= 7) {
    if (incheck(player, r, c1) == false) {
      v.push_back(std::pair<int, int>(r, c1));
    }
  }
  if (r2 >= 0) {
    if (incheck(player, r2, c) == false) {
      v.push_back(std::pair<int, int>(r2, c));
    }
  }
  if (c2 >= 0) {
    if (incheck(player, r, c2) == false) {
      v.push_back(std::pair<int, int>(r, c2));
    }
  }
  return v;
}

std::vector<std::pair<int, int>> ChessBoard::legalP(int r, int c, std::string type, bool player) {
  std::vector<std::pair<int, int>> v;
  if (board[r][c].getPiece()->getFirst() == true) {
    if (player == true) { // if the player is white pawn can only move forward so r will decrease and cannot go out of bound
      if (r - 1 >= 0 && board[r - 1][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r - 1, c)); // regular move forward cannot capture piece
      if (c - 1 >= 0 && board[r - 1][c - 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r - 1, c - 1));
      if (c + 1 <= 7 && board[r - 1][c + 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r - 1, c + 1));
      if (r - 2 >= 0 && board[r - 2][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r - 2, c));
    } else {
      if (r + 1 <= 7 &&board[r + 1][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r + 1, c));
      if (c - 1 >= 0 && board[r - 1][c - 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r + 1, c - 1));
      if (c + 1 <= 7 && board[r - 1][c + 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r + 1, c + 1));
      if (r + 2 <= 7 &&board[r + 2][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r + 2, c));
    }
  } else {
    if (player == true) {
      if (r - 1 >= 0 && board[r - 1][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r - 1, c));
      if (c - 1 >= 0 && board[r - 1][c - 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r - 1, c - 1));
      if (c + 1 <= 7 && board[r - 1][c + 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r - 1, c + 1));
    } else {
      if (r + 1 <= 7 &&board[r + 1][c].getPiece() == nullptr) v.push_back(std::pair<int, int>(r + 1, c));
      if (c - 1 >= 0 && board[r - 1][c - 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r + 1, c - 1));
      if (c + 1 <= 7 && board[r - 1][c + 1].getPiece() != nullptr) v.push_back(std::pair<int, int>(r + 1, c + 1));
    }
  }
  return v;
}
