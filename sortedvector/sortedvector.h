/*
vertex.h

Author: Kristian Larsson
IDE: Visual Studio Express 2013

*/

#ifndef SORTEDVEC_H
#define SORTEDVEC_H

#include <initializer_list>
#include <iterator>
#include <cmath>
#include <utility>

namespace mysvector{

template <class T, std::size_t mSize = 3>//, class Allocator = std::allocator<T> >
class SortedVector{

    public:
		//using value_type =											T;
		//using reference =											value_type&;
		//using const_reference =										const value_type&;
		typedef T                                                   value_type;
		typedef value_type&                                         reference;
		typedef const value_type&                                   const_reference;
		typedef T*													iterator;
		typedef const T*											const_iterator;
		//using size_type =											std::size_t;
		typedef std::size_t											size_type;
		//using difference_type =										std::ptrdiff_t;
		typedef std::ptrdiff_t										difference_type;
		//using allocator_type =										Allocator;
		//typedef Allocator                                           allocator_type;
		//using pointer =												typename allocator_traits<Allocator>::pointer;
		typedef T*													pointer;
		//using const_pointer =										typename allocator_traits<Allocator>::const_pointer;
		typedef const T*											const_pointer;
		//typedef typename std::reverse_iterator<iterator>                     reverse_iterator;
		//typedef typename const std::reverse_iterator<iterator>               const_reverse_iterator;

		//explicit SortedVector(const allocator_type& alloc = allocator_type());
		explicit SortedVector(size_type n=0);

		SortedVector(size_type n, const value_type& val/*,
			const allocator_type& alloc = allocator_type()*/);
		template <class InputIterator>
		SortedVector(InputIterator first, InputIterator last/*,
			const allocator_type& alloc = allocator_type()*/);
		SortedVector(const SortedVector& x);
		//SortedVector(const SortedVector& x, const allocator_type& alloc);
		SortedVector(SortedVector&& x);
		//SortedVector(SortedVector&& x, const allocator_type& alloc);
		SortedVector(std::initializer_list<value_type> il/*,
			const allocator_type& alloc = allocator_type()*/);

        const T& median() const;
        void print(std::ostream &os);
		//SortedVector& operator=( const SortedVector& other );
		//SortedVector& operator=(SortedVector&& other);
		//SortedVector& operator=(std::initializer_list<T> ilist);
		//void assign(size_type count, const T& value);
		//template< class InputIt >
		//void assign(InputIt first, InputIt last);
		//void assign(std::initializer_list<T> ilist);
		//allocator_type get_allocator() const;
		
		// Element access
		//reference at(size_type pos);
		//reference operator[](size_type pos);
		//reference front();
		//constexpr const_reference front() const;
		//reference back();
		//constexpr const_reference back() const;
		//T* data();
		//const T* data() const;
		
		// Iterators
		//iterator begin() _NOEXCEPT;
		//const_iterator begin() const _NOEXCEPT;
		//const_iterator cbegin() _NOEXCEPT;
		//iterator end() _NOEXCEPT;
		//const_iterator end() const _NOEXCEPT;
		//const_iterator cend() _NOEXCEPT;
		//reverse_iterator rbegin() _NOEXCEPT;
		//reverse_const_iterator rbegin() const _NOEXCEPT;
		//reverse_const_iterator crbegin() _NOEXCEPT;
		//reverse_iterator end() _NOEXCEPT;
		//reverse_const_iterator end() const _NOEXCEPT;
		//reverse_const_iterator cend() _NOEXCEPT;
		
		// Capacity
		bool empty() const _NOEXCEPT;
		size_type size() const _NOEXCEPT;
		size_type max_size() const _NOEXCEPT;
		void reserve(size_type new_cap);
		size_type capacity() const _NOEXCEPT;
		void shrink_to_fit();
		
		// Modifiers
		void clear() _NOEXCEPT;
		bool add(const T& value);
		void removeLarger(const T& v);
		//iterator erase(iterator pos);
		//iterator erase(const_iterator pos);
		//iterator erase(iterator first, iterator last);
		//iterator erase(const_iterator first, const_iterator last);
		//void resize();
		//void swap();

    private:
        T vec[mSize];
		size_type numObjects;
};

/*template <class T, std::size_t mSize>//, class Allocator >
SortedVector<T, mSize, Allocator>::SortedVector(const allocator_type& alloc){
};*/

template <class T, std::size_t mSize>//, class Allocator >
SortedVector<T, mSize>/*, Allocator>*/::SortedVector(std::size_t n) : numObjects(n){
};

template <class T, std::size_t mSize>//, class Allocator >
bool SortedVector<T, mSize>/*, Allocator>*/::add(const T& value){
	using std::swap;

    if( size() < max_size() ){

		if ( empty() ){
			vec[numObjects] = value;
			//numObjects++;
		}

		if ( size() == 1 ){
			vec[size()] = value;
			if ( vec[size()] < vec[0] )
				swap(vec[0], vec[size()]);
			//numObjects++;
		}

		else{

			for ( size_type i = 0; i <= size(); ++i ){

				if (i == size()){
					// Ojektet är större än de i arrayen
					// och ska in sist.
					vec[size()] = value;
				}

				if (value < vec[i]){
					for (size_type j = size(); j > i; --j){
						// Flytta alla ett steg upp
						vec[j] = vec[j - 1];
					}

					vec[i] = value; // Sätt vec[i] till value
					i = (size() + 1); // i incrementeras sedan med ett och blir större än numObjects
				}

			}

		}

		numObjects++;

    }

	else{

		return false; // SortedVector är full.

	}

	return true;
};

template <class T, std::size_t mSize>//, class Allocator >
const T& SortedVector<T, mSize>/*, Allocator>*/::median() const{
    // Returnera mittenelementet eller det första av de två i mitten om det
    // jämnt antal.

        return vec[ ( size()/2 ) ];
        // I det här fallet har jag utgått från att det automatiskt avrundas ner
        // det skulle gå att använda floor() från cmath för att vara säker på att det blir rätt.

};

template <class T, std::size_t mSize>//, class Allocator >
void SortedVector<T, mSize>/*, Allocator>*/::removeLarger(const T& v){

	for (size_type i = (numObjects - 1); i > 0; --i){
        // Loopen börjar på slutet av vektorn så det blir enkelt att räkna ner numObjects
        if(vec[i] > v){
            vec[i] = T();
            numObjects--;
        }
    }
};

template <class T, std::size_t mSize>//, class Allocator >
void SortedVector<T, mSize>/*, Allocator>*/::print(std::ostream &os){
	
	if( empty() ){
		os << "Empty!\n";
	}
	else{
		for (unsigned int i = 0; i < size(); ++i){
			os << vec[i] << "\n";
		}
	}
	
};

template <class T, std::size_t mSize>//, class Allocator >
bool SortedVector<T, mSize>/*, Allocator>*/::empty() const _NOEXCEPT{
	//return (begin() == end());
	return (numObjects == 0);
};

template <class T, std::size_t mSize>//, class Allocator >
typename SortedVector<T, mSize>/*, Allocator>*/::size_type SortedVector<T, mSize>/*, Allocator>*/::size() const _NOEXCEPT{
	//return std::distance(begin(), end());
	return numObjects;
};

template <class T, std::size_t mSize>//, class Allocator >
typename SortedVector<T, mSize>/*, Allocator>*/::size_type SortedVector<T, mSize>/*, Allocator>*/::max_size() const _NOEXCEPT{
	// return  std::numeric_limits<size_type>::max()
	return mSize;
};

template <class T, std::size_t mSize>//, class Allocator >
void SortedVector<T, mSize>/*, Allocator>*/::reserve(std::size_t new_cap){
	// To be implemented
};

template <class T, std::size_t mSize>//, class Allocator >
typename SortedVector<T, mSize>/*, Allocator>*/::size_type SortedVector<T, mSize>/*, Allocator>*/::capacity() const _NOEXCEPT{
	// To be implemented
};

template <class T, std::size_t mSize>//, class Allocator >
void SortedVector<T, mSize>/*, Allocator>*/::shrink_to_fit(){
	// To be implemented
};

template <class T, std::size_t mSize>//, class Allocator >
void SortedVector<T, mSize>/*, Allocator>*/::clear() _NOEXCEPT{
	// To be implemented
	for(auto& i : vec){
		i = T();
	};

	numObjects = 0;

};

}
#endif