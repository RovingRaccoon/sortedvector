//
// vertex.cpp
//
// Author: Kristian Larsson
// Course: OOP med C++, vt12
// Uppsala Universitet
//
// IDE: Code::Blocks 10.05
// Compiler: GNU GCC
//

#include <iostream>
#include <utility>
#include "vertex.h"

Vertex::Vertex(int x, int y): pos_X(x), pos_Y(y){
	//std::cout << "New Vertex " << pos_X << "," << pos_Y << std::endl;
};

Vertex::Vertex(const Vertex& otherVertex) : pos_X(otherVertex.pos_X), pos_Y(otherVertex.pos_Y){
	//std::cout << "Copy of Vertex " << pos_X << "," << pos_Y << std::endl;
};

Vertex::~Vertex(){
	//std::cout << "Bye Vertex " << pos_X << "," << pos_Y << std::endl;
};

// Kopieringsoperatorn
Vertex& Vertex::operator=(Vertex otherVertex){

	swap(*this, otherVertex);

	return *this;
};

void swap(Vertex& first, Vertex& second){
	// by swapping the members of two classes,
	// the two classes are effectively swapped
	using std::swap;

	//std::cout << "swaping " << first.pos_X << " and " << second.pos_X << std::endl;
	//std::cout << "swaping " << first.pos_Y << " and " << second.pos_Y << std::endl;

	swap(first.pos_X, second.pos_X);
	swap(first.pos_Y, second.pos_Y);
};

std::ostream & operator<<(std::ostream& os, const Vertex& vertex){
	os << "Vertex{";

	os << "(" << vertex.pos_X << ", " << vertex.pos_Y << ") ";

	os << "}";

	return os;
};