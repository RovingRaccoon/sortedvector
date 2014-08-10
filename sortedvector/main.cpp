#include <iostream>

#include "vertex.h"
#include "polygon.h"
#include "sortedvector.h"

int main(){
    mysvector::SortedVector<Polygon, 10> polygons;
	mysvector::SortedVector<int, 6> ints;

    ints.add( 3 );
    ints.add( 1 );
    ints.add( 6 );

    Vertex varr[10];
    varr[0] = Vertex(0, 0);
    varr[1] = Vertex(10, 0);
    varr[2] = Vertex(5, 2);
    varr[3] = Vertex(5, 5);

    polygons.add(Polygon( varr, 4) );

	std::cout << (Polygon(varr, 4)).area() << "\n";

    varr[0] = Vertex(0, 0);
    varr[1] = Vertex(25, 8);
    varr[2] = Vertex(10, 23);

    polygons.add( Polygon( varr, 3) );

	std::cout << (Polygon(varr, 3)).area() << "\n";

    varr[0] = Vertex(0,0);
    varr[1] = Vertex(5,0);
    varr[2] = Vertex(5,3);
    varr[3] = Vertex(4,8);
    varr[4] = Vertex(2,10);

    polygons.add( Polygon( varr, 5) );

	std::cout << (Polygon(varr, 5)).area() << "\n";

    polygons.print(std::cout);

    ints.print(std::cout);
	
    std::cout << "MEDIAN: " << ints.median() << "\n";
    std::cout << "MEDIAN: " << polygons.median() << "\n";

    ints.add( 4); // 1 3 4 6
    ints.add( 2); // 1 2 3 4 6
    ints.add( 5); // 1 2 3 4 5 6
    ints.removeLarger( 3 ); // 1 2 3

	std::cout << "MEDIAN: " << ints.median() << "\n";

	ints.clear();
	ints.print(std::cout);

    return 0;
}
