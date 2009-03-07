#include "Array.h"

template< typename T >
Array< T >::Array() {
	setSize( 1 );
	ptr = new T[ size() ];

	ptr[ 0 ] = 0;
}

template< typename T >
Array< T >::Array( int n, T b ) {
	setSize( n );
	ptr = new T[ size() ];
	
	for( int i = 0; i < size(); i++ ) {
		ptr[ i ] = b;
	}
}

template< typename T >
Array< T >::Array( Array< T > &array2 ) {
	setSize( array2.size() );
	ptr = new T[ size() ];

	for( int i = 0; i < size(); i++ ) {
		ptr[ i ] = array2[ i ];
	}
}

template< typename T >
Array< T >::~Array() {
	delete[] ptr;
}

template< typename T >
void Array< T >::setSize( int n ) {
	n > 0 ? this->Size = n : this->Size = 1;
}

template< typename T >
int Array< T >::size() const {
	return this->Size;
}

template< typename T >
T &Array< T >::operator[] ( int a ) {
	return ptr[ a ];
}

template< typename T >
T Array< T >::operator[] ( int a ) const {
	return ptr[ a ];
}

template< typename T >
void Array< T >::operator+ ( Array< T > &array2 ) {
	(*this).append( array2 );
}

template< typename T >
void Array< T >::operator= ( Array< T > &array2 ) {
	if( array2.size() == this->size() ) {
		for( int i = 0; i < this->size(); i++ ) {
			ptr[ i ] = array2[ i ];
		}
	} else {
		setSize( array2.size() );
		delete[] ptr;

		ptr = new T[ this->size() ];

		for( int i = 0; i < this->size(); i++ ) {
			ptr[ i ] = array2[ i ];
		}
	}
}

template< typename T >
bool Array< T >::operator== ( Array< T > &array2 ) {
	if( array2.size() != this->size() ) {
		return false;
	}

	for( int i = 0; i < this->size(); i++ ) {
		if( ptr[ i ] != array2[ i ] ) {
			return false;
		}
	}

	return true;
}

template< typename T >
bool Array< T >::operator!= ( Array< T > &array2 ) {
	if( (*this) == array2 ) {
		return false;
	} else {
		return true;
	}
}

template< typename T >
void Array< T >::operator+= ( Array< T > &array2 ) {
	(*this).append( array2 );
}

template< typename T >
void Array< T >::operator> ( Array< T > &array2 ) {
	if( this->size() < array2.size() ) {
		return false;
	} else if( this->size() > array2.size() ) {
		return true;
	} else {
		for( int i = 0; i < this->size(); i++ ) {
			if( ptr[ i ] > array2[ i ] ) {
				return true;
			}
		}
	}

	return false;
}

template< typename T >
void Array< T >::operator< ( Array< T > &array2 ) {
	if( (*this) > array2 ) {
		return false;
	} else {
		return true;
	}
}

template< typename T >
void Array< T >::append( Array< T > &array2 ) {
	int newSize = this->size() + array2.size();
	T *ptr2 = new T[ newSize ];

	for( int i = 0; i < this->size(); i++ ) {
		ptr2[ i ] = ptr[ i ];
	}

	for( int i = this->size(); i < newSize; i++ ) {
		ptr2[ i ] = array2[ i - this->size() ];
	}

	delete[] ptr;
	ptr = new T[ newSize ];
	
	for( int i = 0; i < newSize; i++ ) {
		ptr[ i ] = ptr2[ i ];
	}

	setSize( newSize );

	delete[] ptr2;
	ptr2 = 0;
}

template< typename T >
void Array< T >::print() const {
	for( int i = 0; i < this->size(); i++ ) {
		std::cout << ptr[ i ] << " ";
	}
}

template< typename T >
void Array< T >::pushBack( T n ) {
	int newSize = this->size() + 1;
	T *ptr2 = new T[ newSize ];

	for( int i = 0; i < this->size(); i++ ) {
		ptr2[ i ] = ptr[ i ];
	}

	ptr2[ this->size() ] = n;

	delete[] ptr;
	this->setSize( newSize );
	ptr = new T[ this->size() ];

	for( int i = 0; i < this->size(); i++ ) {
		ptr[ i ] = ptr2[ i ];
	}

	delete[] ptr2;
	ptr2 = 0;

}

template< typename T >
void Array< T >::pushFront( T n ) {
	int newSize = this->size() + 1;
	T *ptr2 = new T[ newSize ];

	ptr2[ 0 ] = n;
	for( int i = 0; i < this->size(); i++ ) {
		ptr2[ i + 1 ] = ptr[ i ];
	}

	delete[] ptr;
	this->setSize( newSize );
	ptr = new T[ this->size() ];

	for( int i = 0; i < this->size(); i++ ) {
		ptr[ i ] = ptr2[ i ];
	}

	delete[] ptr2;
	ptr2 = 0;
}

template< typename T >
bool Array< T >::has( T n ) const {
	for( int i = 0; i < size(); i++ ) {
		if( ptr[ i ] == n ) {
			return true;
		}
	}

	return false;
}

template< typename T >
std::ostream &operator<< ( std::ostream &output, Array< T > &array ) {
	for( int i = 0; i < array.size(); i++ ) {
		output << array[ i ] << " ";
	}
	return output; //enabling cascading
}

template< typename T >
std::istream &operator>> ( std::istream &input, Array< T > &array ) {
	for( int i = 0; i < array.size(); i++ ) {
		input >> array[ i ];
	}
	return input; //enabling cascading
}
