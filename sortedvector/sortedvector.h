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
        return false; // SortedVector är full.
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
				// Ojektet är större än de i arrayen
				// och ska in sist.
				vec[numObjects] = value;
			}

            if ( value < vec[i] ){
				for (unsigned int j = numObjects; j > i; --j){
					// Flytta alla ett steg upp
                    vec[j] = vec[j-1];
                }

                vec[i] = value; // Sätt vec[i] till value
                i = (numObjects+1); // i incrementeras sedan med ett och blir större än numObjects
            }

            

        }
        
		numObjects++;

    }

	return true;
};

template <class T, std::size_t size>
const T& SortedVector<T, size>::median() const{
    // Returnera mittenelementet eller det första av de två i mitten om det
    // jämnt antal.

        return vec[(numObjects/2)];
        // I det här fallet har jag utgått från att det automatiskt avrundas ner
        // det skulle gå att använda floor() från cmath för att vara säker på att det blir rätt.

};

template <class T, std::size_t size>
void SortedVector<T, size>::removeLarger(const T& v){

    for(std::size_t i = (numObjects-1); i > 0; --i){
        // Loopen börjar på slutet av vektorn så det blir enkelt att räkna ner numObjects
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