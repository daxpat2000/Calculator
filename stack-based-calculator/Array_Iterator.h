/*
 * Iterator Class for Array
 *
 */

#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_

#include "Array.h"

template <typename T>
class Array_Iterator
{   
    public:
        //Type definition of the element type.
	    typedef T type;

        //default constructor
        Array_Iterator(void);

        //init constructor
        Array_Iterator(const Array<T> & array);

        //Destructor
        ~Array_Iterator(void);

        //has next - check if there is a next element.
        bool has_next(void);

        //next move to the next element
        void next(void);

        //overload for the * operator
        T & operator * (void);

        //overload for the -> operator
        T * operator -> (void);
    
    //class members
    private:
        size_t curr_;
        const Array<T> & array_;
};

#include "Array_Iterator.cpp"

#endif