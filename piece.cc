#include "piece.h"
#include <iostream>

Piece::Piece(std::string &t, bool &colour, int &row, int &col):
  type{t}, colour{colour}, r{row}, c{col}, check{0} {}

Piece::Piece(const Piece &rhs):
  type{rhs.type}, colour{rhs.colour}, r{rhs.r}, c{rhs.c}, check{rhs.check} {}

 /*void Piece::notify(bool player, int r, int c) {
   return;
 }*/

 bool Piece::legalMove(bool player, int row, int col) {
   return false;
 }

 std::string Piece::getType() {
   return type;
 }

 bool Piece::getColour() {
   return colour;
 }

 bool Piece::getPassant() {
   return 0;
 }

 bool Piece::getFirst() {
   return 0;
 }

 void Piece::setFirst(bool first) {
   return;
 }

 void Piece::setPassant(bool passant) {
   return;
 }

Piece::~Piece() {}

void Piece::print() {
  std::cout << this->r << " " << this->c << std::endl;
}
