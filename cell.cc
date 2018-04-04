#include "cell.h"
//#include "info.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include <string>

Cell::Cell(): r{0}, c{0}, colour{0},
  p{nullptr} {}

Cell::~Cell() {}

void Cell::setCell(int r,int c,bool colour) {
  this->r = r;
  this->c = c;
  this->colour = colour;
}

std::shared_ptr<Piece> Cell::getPiece() {
  return p;
}

bool Cell::getColour() {
  return colour;
}

void Cell::clearPiece() {
  p.reset();
}

void Cell::setPiece(std::string s, bool colour) {
  if(p != nullptr) {
    return;
  }
  if (s == "q" || s == "Q") {
    std::shared_ptr<Piece> np{new Queen{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "k" || s == "K") {
    std::shared_ptr<Piece> np{new King{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "n" || s == "N") {
    std::shared_ptr<Piece> np{new Knight{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "r" || s == "R") {
    std::shared_ptr<Piece> np{new Rook{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "b" || s == "B") {
    std::shared_ptr<Piece> np{new Bishop{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "P" || s == "p") {
    std::shared_ptr<Piece> np{new Pawn{s, colour, r, c}};
    std::swap(p, np);
  }
}

void Cell::attackPiece(std::string s, bool colour) {
  p = nullptr;
  if (s == "q" || s == "Q") {
    std::shared_ptr<Piece> np{new Queen{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "k" || s == "K") {
    std::shared_ptr<Piece> np{new King{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "n" || s == "N") {
    std::shared_ptr<Piece> np{new Knight{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "r" || s == "R") {
    std::shared_ptr<Piece> np{new Rook{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "b" || s == "B") {
    std::shared_ptr<Piece> np{new Bishop{s, colour, r, c}};
    std::swap(p, np);
  } else if (s == "P" || s == "p") {
    std::shared_ptr<Piece> np{new Pawn{s, colour, r, c}};
    std::swap(p, np);
  }
}

std::ostream &operator<<(std::ostream &out, const Cell &c) {
  if (c.p != nullptr) {
    out << c.p->type;
  } else {
    if (c.colour == 1) {
      out << " ";
    } else {
      out << "_";
    }
  }
  return out;
}
