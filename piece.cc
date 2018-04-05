#include "piece.h"
#include <iostream>

Piece::Piece(): subject{std::make_shared<ChessBoard>()}, colour{0}, location{std::pair<int,int>{-1, -1}}, empty{1} {
	std::cout << "ARE WE HERE" << std::endl;
}

Piece::Piece(std::shared_ptr<ChessBoard> subject, bool colour, int row, int col, bool empty): subject{subject}, colour{colour}, location{std::pair<int,int>{row,col}}, empty{empty} {}

Piece::~Piece() {}

bool Piece::isEmpty() const
{
	return this->empty;
}

bool Piece::getColour() const
{
	return this->colour;
}

std::pair<int,int> Piece::getLocation() const
{
	return this->location;
}
ChessBoard * Piece::getSubject() const
{
	return this->subject.get();
}