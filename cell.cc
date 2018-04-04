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
  p{std::make_unique<Piece>(nullptr)} {}

Cell::~Cell() {}

void Cell::setCell(int r,int c,bool colour) {
  this->r = r;
  this->c = c;
  this->colour = colour;
}

Piece* Cell::getPiece() {
  return p.get();
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
    p = make_unique<Queen>(s, colour, r, c);
  } else if (s == "k" || s == "K") {
    p = make_unique<King>(s, colour, r, c);
  } else if (s == "n" || s == "N") {
    p = make_unique<Knight>(s, colour, r, c);
  } else if (s == "r" || s == "R") {
    p = make_unique<Rook>(s, colour, r, c);
  } else if (s == "b" || s == "B") {
    p = make_unique<Bishop>(s, colour, r, c);
  } else if (s == "P" || s == "p") {
    p = make_unique<Pawn>(s, colour, r, c);
  }
}

void Cell::attackPiece(std::string s, bool colour) {
  if (s == "q" || s == "Q") {
    p = make_unique<Queen>(s, colour, r, c);
  } else if (s == "k" || s == "K") {
    p = make_unique<King>(s, colour, r, c);
  } else if (s == "n" || s == "N") {
    p = make_unique<Knight>(s, colour, r, c);
  } else if (s == "r" || s == "R") {
    p = make_unique<Rook>(s, colour, r, c);
  } else if (s == "b" || s == "B") {
    p = make_unique<Bishop>(s, colour, r, c);
  } else {
    p = make_unique<Pawn>(s, colour, r, c);
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
