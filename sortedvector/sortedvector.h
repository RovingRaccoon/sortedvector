/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

#ifndef SORTEDVEC_H
#define SORTEDVEC_H

#include <utility>

template <class T, std::size_t msize = 3, class Allocator = std::allocator<T> >
class SortedVector{

    public:
        SortedVector(std::size_t num = 0);
        const T& median() const;
        void removeLarger(const T& v);
        void print(std::ostream &os);
		// Element access
		//T& at(size_type pos);
		//T& operator[](size_type pos);
		// Iterators
		//iterator begin();
		//const_iterator begin();
		//const_iterator cbegin();
		//iterator end();
		//const_iterator end();
		//const_iterator cend();
		//reverse_iterator rbegin();
		//reverse_const_iterator rbegin();
		//reverse_const_iterator crbegin();
		//reverse_iterator end();
		//reverse_const_iterator end();
		//reverse_const_iterator cend();
		// Capacity
		bool empty() const _NOEXCEPT;
		std::size_t size() const _NOEXCEPT;
		std::size_t max_size() const _NOEXCEPT;
		void reserve(std::size_t new_cap);
		std::size_t capacity() const _NOEXCEPT;
		void shrink_to_fit();
		// Modifiers
		void clear() _NOEXCEPT;
		bool add(const T& value);
		//iterator erase(iterator pos);
		//iterator erase(const_iterator pos);
		//iterator erase(iterator first, iterator last);
		//iterator erase(const_iterator first, const_iterator last);
		//void resize();
		//void swap();

    private:
        T vec[msize];
		std::size_t numObjects;
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
SortedVector<T, msize, Allocator>::SortedVector(std::size_t num) : numObjects(num){
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
bool SortedVector<T, msize, Allocator>::add(const T& value){
	using std::swap;

    if(numObjects == msize){
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

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
const T& SortedVector<T, msize, Allocator>::median() const{
    // Returnera mittenelementet eller det första av de två i mitten om det
    // jämnt antal.

        return vec[(numObjects/2)];
        // I det här fallet har jag utgått från att det automatiskt avrundas ner
        // det skulle gå att använda floor() från cmath för att vara säker på att det blir rätt.

};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
void SortedVector<T, msize, Allocator>::removeLarger(const T& v){

    for(std::size_t i = (numObjects-1); i > 0; --i){
        // Loopen börjar på slutet av vektorn så det blir enkelt att räkna ner numObjects
        if(vec[i] > v){
            vec[i] = T();
            numObjects--;
        }
    }
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
void SortedVector<T, msize, Allocator>::print(std::ostream &os){

    for(std::size_t i = 0; i < numObjects; i++){
        std::cout << vec[i] << std::endl;
    }
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
bool SortedVector<T, msize, Allocator>::empty() const _NOEXCEPT{
	// return (begin() == end());
	return (numObjects == 0);
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
std::size_t SortedVector<T, msize, Allocator>::size() const _NOEXCEPT{
	//return std::distance(begin(), end());
	return numObjects;
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
std::size_t SortedVector<T, msize, Allocator>::max_size() const _NOEXCEPT{
	// return  std::numeric_limits<size_type>::max()
	return msize;
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
void SortedVector<T, msize, Allocator>::reserve(std::size_t new_cap){
	// To be implemented
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
std::size_t SortedVector<T, msize, Allocator>::capacity() const _NOEXCEPT{
	// To be implemented
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
void SortedVector<T, msize, Allocator>::shrink_to_fit(){
	// To be implemented
};

template <class T, std::size_t msize, class Allocator = std::allocator<T> >
void SortedVector<T, msize, Allocator>::clear() _NOEXCEPT{
	// To be implemented
};
#endif