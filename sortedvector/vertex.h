/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

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
		int getX() const {return pos_X;};
		int getY() const {return pos_Y;};
		Vertex& operator=(Vertex otherVertex);
		friend void swap(Vertex& first, Vertex& second);
		friend std::ostream & operator<<(std::ostream& os, const Vertex& vertex);
};



#endif
