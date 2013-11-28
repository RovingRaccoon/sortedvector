/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

#include <iostream>
#include <utility>
#include "polygon.h"

Polygon::Polygon(Vertex* vp, unsigned int n): list_length(n){
	
	std::cout << "Polygon " << list_length << "\n";

	v_list = new Vertex[list_length];

    for(unsigned int i = 0; i < list_length; ++i)
        v_list[i] = *(vp+i);

};

// Kopierings konstruktor
Polygon::Polygon(const Polygon& otherPolygon) : list_length(otherPolygon.list_length){
	
	std::cout << "Copy of Polygon " << list_length << "\n";

    if(list_length > 0){
        v_list = new Vertex[list_length];

        for(unsigned int i = 0; i < list_length; i++){

            v_list[i] = otherPolygon.v_list[i];

        }
    }
    else
        v_list = nullptr;
};

Polygon::~Polygon(){
    delete[] v_list;
};

void Polygon::add(const Vertex& v){
	using std::swap;

    Vertex* v_temp = v_list;

    v_list = new Vertex[list_length+1];

	for (unsigned int i = 0; i < (list_length - 1); ++i){
		//std::cout << "Swapping v_temp: " << v_temp[i] << " and v_list: " << v_list[i] << std::endl;
		swap(v_list[i], v_temp[i]);
    }

	list_length++;

    v_list[list_length-1] = v;

    delete[] v_temp;

};

double Polygon::area() const{
	// Arean beräknas som
	// halva summan av xi(yi+1-yi-1) för i mellan 0 och n.

	double a = 0;

	// Hantering av den första punkten.
	a = ( v_list[0].getX() * ( (v_list[1].getY()) - (v_list[list_length-1].getY()) ) );

    // Punkterna mellan första och sista.
	for(unsigned int i = 1; i < (list_length-1); ++i){
		a += ( v_list[i].getX() * ( (v_list[i+1].getY() ) - (v_list[i-1].getY()) ) );
	}

    // Hantering av den sista punkten.
	a += ( v_list[list_length-1].getX() * ( (v_list[0].getY() ) - (v_list[list_length-2].getY()) ) );

    // Returnera det absoluta värdet av arean.
	return fabs(a/2);
};

// Ett antal likartade funktioner för att ta fram min- och max-värden på X och Y.
int Polygon::minx() const{
	int temp = 0;

	for(unsigned int i = 0; i < list_length; ++i){
		if(i == 0 || (v_list[i].getX() < temp))
            temp = v_list[i].getX();
	}

	return temp;
};

int Polygon::maxx() const{
	int temp = 0;

	for(unsigned int i = 0; i < list_length; i++){
		if(i == 0 || (v_list[i].getX() > temp))
            temp = v_list[i].getX();
	}

	return temp;
};

int Polygon::miny() const{
	int temp = 0;

	for(unsigned int i = 0; i < list_length; i++){
		if(i == 0 || (v_list[i].getY() < temp))
            temp = v_list[i].getY();
	}

	return temp;
};

int Polygon::maxy() const{
	int temp = 0;

	for(unsigned int i = 0; i < list_length; i++){
		if(i == 0 || (v_list[i].getY() > temp))
            temp = v_list[i].getY();
	}

	return temp;
};

// Kopieringsoperatorn
Polygon& Polygon::operator=(Polygon otherPolygon){

	swap(*this, otherPolygon);

    return *this;
};

void swap(Polygon& first, Polygon& second){
	// by swapping the members of two classes,
	// the two classes are effectively swapped
	using std::swap;

	Vertex* temp = first.v_list;
	first.v_list = second.v_list;
	second.v_list = temp;

	//swap(first.v_list, second.v_list);

	swap(first.list_length, second.list_length);

};

// Operatorn för utströmmar
std::ostream & operator<<( std::ostream& os, const Polygon& poly){

    os << "{";

    for(unsigned int i = 0; i < poly.list_length; i++){
        os << "(" << poly.v_list[i].getX() << ", " << poly.v_list[i].getY() << ") ";
    };

    os << "}";

    return os;
};