/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

#ifndef POLY_H
#define POLY_H

#include <cmath>
#include <ostream>
#include "vertex.h"

class Polygon{
	private:
		Vertex *v_list;
		std::size_t list_length;
	public:
		Polygon(Vertex* vp=nullptr, unsigned int n=0);
		Polygon(const Polygon& otherPolygon);
		~Polygon();
		void add(const Vertex& v);
		double area() const;
		int minx() const;
		int maxx() const;
		int miny() const;
		int maxy() const;
		std::size_t numVertices() const {return list_length;};
		Polygon& operator=(Polygon otherPolygon);
		friend void swap(Polygon& first, Polygon& second);
		friend std::ostream& operator<<(std::ostream& os, const Polygon& poly);
};

inline bool operator==(const Polygon& lhs, const Polygon& rhs){ return (std::fabs( lhs.area() - rhs.area() ) < 1E-3); }
inline bool operator!=(const Polygon& lhs, const Polygon& rhs){ return !operator==(lhs, rhs); }
inline bool operator<(const Polygon& lhs, const Polygon& rhs){ return ( lhs.area() < rhs.area() ); }
inline bool operator> (const Polygon& lhs, const Polygon& rhs){ return  operator< (rhs, lhs); }
inline bool operator<=(const Polygon& lhs, const Polygon& rhs){ return !operator> (lhs, rhs); }
inline bool operator>=(const Polygon& lhs, const Polygon& rhs){ return !operator< (lhs, rhs); }

#endif
