/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

#ifndef SORTEDVEC_H
#define SORTEDVEC_H

#include <utility>

template <class T, std::size_t size=3>
class SortedVector{
    public:
        SortedVector(std::size_t num = 0);
        bool add(const T& value);
        const T& median() const;
        void removeLarger(const T& v);
        void print(std::ostream &os);
    private:
        T vec[size];
		std::size_t numObjects;
};

template <class T, std::size_t size>
SortedVector<T, size>::SortedVector(std::size_t num) : numObjects(num){
};

template <class T, std::size_t size>
bool SortedVector<T, size>::add(const T& value){
	using std::swap;

    if(numObjects == size){
        return false; // SortedVector �r full.
    }

	if (numObjects == 0){
		vec[numObjects] = value;
		numObjects++;
	}

	if (numObjects == 1){
		vec[numObjects] = value;
		if (vec[numObjects] < vec[0])
			swap(vec[0], vec[numObjects]);
		numObjects++;
	}

    else{

		for (std::size_t i = 0; i <= numObjects; ++i){
			
			if (i == numObjects){
				// Ojektet �r st�rre �n de i arrayen
				// och ska in sist.
				vec[numObjects] = value;
			}

            if ( value < vec[i] ){
				for (unsigned int j = numObjects; j > i; --j){
					// Flytta alla ett steg upp
                    vec[j] = vec[j-1];
                }

                vec[i] = value; // S�tt vec[i] till value
                i = (numObjects+1); // i incrementeras sedan med ett och blir st�rre �n numObjects
            }

            

        }
        
		numObjects++;

    }

	return true;
};

template <class T, std::size_t size>
const T& SortedVector<T, size>::median() const{
    // Returnera mittenelementet eller det f�rsta av de tv� i mitten om det
    // j�mnt antal.

        return vec[(numObjects/2)];
        // I det h�r fallet har jag utg�tt fr�n att det automatiskt avrundas ner
        // det skulle g� att anv�nda floor() fr�n cmath f�r att vara s�ker p� att det blir r�tt.

};

template <class T, std::size_t size>
void SortedVector<T, size>::removeLarger(const T& v){

    for(std::size_t i = (numObjects-1); i > 0; --i){
        // Loopen b�rjar p� slutet av vektorn s� det blir enkelt att r�kna ner numObjects
        if(vec[i] > v){
            vec[i] = T();
            numObjects--;
        }
    }
};

template <class T, std::size_t size>
void SortedVector<T, size>::print(std::ostream &os){

    for(std::size_t i = 0; i < numObjects; i++){
        std::cout << vec[i] << std::endl;
    }
};

#endif