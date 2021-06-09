#include "Array_Iterator.h"

//default constructor
template <typename T>
Array_Iterator <T>::Array_Iterator(void)
    :curr_ (0),
     array_ (nullptr)
{

}

//init constructor
template <typename T>
Array_Iterator <T>::Array_Iterator(const Array<T> & array)
    :curr_ (0),
     array_ (array)
{

}

//destructor
template <typename T>
Array_Iterator <T>::~Array_Iterator(void)
{

}

//has next
template <typename T>
bool Array_Iterator <T>::has_next(void)
{   
    return (this->curr_ < this->array_.cur_size_);
}

//next
template <typename T>
void Array_Iterator <T>::next(void)
{
    ++(this->curr_);
}

//overload * operator
template <typename T>
T & Array_Iterator <T>::operator * (void)
{
    return this->array_.data_[this->curr_];
}

//overload -> operator
template <typename T>
T * Array_Iterator <T>::operator -> (void)
{
    return &this->array_.data_[this->curr_];
}