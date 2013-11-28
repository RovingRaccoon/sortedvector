//
// vertex.h
//
// Author: Kristian Larsson
// Course: OOP med C++, vt12
// Uppsala Universitet
//
// IDE: Code::Blocks 10.05
// Compiler: GNU GCC
//

#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
	private:
		int pos_X;
		int pos_Y;
	public:
		Vertex(int x=0, int y=0);
		Vertex(const Vertex& otherVertex);
		~Vertex();
		inline int getX() const {return pos_X;};
		inline int getY() const {return pos_Y;};
		Vertex& operator=(Vertex otherVertex);
		friend void swap(Vertex& first, Vertex& second);
		friend std::ostream & operator<<(std::ostream& os, const Vertex& vertex);

		
};

#endif
