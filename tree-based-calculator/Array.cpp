// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
	:Array_Base<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
	:Array_Base<T>(length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
	:Array_Base<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
	:Array_Base<T>(array.max_size())
{
	for(int i = 0; i < array.max_size(); i++){
		this->data_[i] = array.get(i);
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	// check for self assignment	
	if(this == &rhs){
		return (*this);
	}

	// if lhs not big enough to hold content of rhs, reallocate
	if(this->max_size_ < rhs.size()){
		delete [] this->data_;
		this->max_size_ = rhs.max_size();
		this->cur_size_ = rhs.size();
		this->data_ = new T[rhs.max_size()];
	}
	
	// copy over rhs data
	for(int i = 0; i < rhs.size(); i++){
		this->data_[i] = rhs.get(i);
	}
	
	return (*this);
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size > this->max_size_){
		T *temp = new T[new_size];
		for(int i = 0; i < this->max_size_; i++){
			temp[i] = this->data_[i];
		}
		this->max_size_ = new_size;
		this->cur_size_ = new_size;
		delete [] this->data_;
		this->data_ = temp;
	}
}

//shrink to reclaim unused space
template <typename T>
void Array <T>::shrink ()
{
	T *temp = new T[this->cur_size_];
	for(int i = 0; i < this->cur_size_; i++){
		temp[i] = this->data_[i];
	}
	this->max_size_ = this->cur_size_;
	delete [] this->data_;
	this->data_ = temp;
}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
	if(this == &rhs){
		return true;
	}
	if((&rhs != nullptr) && (rhs.size() == this->cur_size_)){
		for(int i = 0; i < this->cur_size_; i++){
			if(this->data_[i] != rhs[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
	if(*this == rhs){
		return false;
	}
	return true;
}

//slice
template <typename T>
Array<T> Array <T>::slice(size_t begin) const
{
	if(begin >= this->max_size_){
        throw std::out_of_range("index out of range");
    }
	//find size of new sliced array
	size_t new_size = this->max_size_ - begin;
    Array<T> sliced(new_size);
    size_t curr = 0;

    //fill the sliced array
    while(begin < this->max_size_){
        sliced.set(curr, this->data_[begin]);
        begin++;
        curr++; 
    }
    return sliced;
}

//sliced
template <typename T>
Array<T> Array <T>::slice (size_t begin, size_t end) const
{
    if(begin > end || begin >= this->max_size_|| end >= this->max_size_){
        throw std::out_of_range("index out of range");
    }
    //find size of new sliced array
    size_t new_size = end - begin;
    Array<T> sliced(new_size);
    size_t curr = 0;

    //fill the sliced array
    while(begin < end){
        sliced.set(curr, this->data_[begin]);
		begin++;
        curr++;
    }
    return sliced;
}