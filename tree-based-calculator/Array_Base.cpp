#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void)
	:cur_size_ (0),
	 max_size_ (0),
	 data_ (nullptr)
{

}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base(size_t length)
	:cur_size_ (length),
	 max_size_ (length),
	 data_ (new T[length])
{

}

//
// Array_Base(size_t, T)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
	:cur_size_ (length),
	 max_size_ (length),
	 data_ (new T[length])
{
	for(int i = 0; i < length; i++){
		this->data_[i] = fill;
	}
}

//
// Array_Base (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
	:cur_size_ (array.max_size()),
	 max_size_ (array.max_size()),
	 data_ (new T[array.max_size()])
{
	for(int i = 0; i < array.max_size(); i++){
		this->data_[i] = array.get(i);
	}
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	if(this->data_ != nullptr){
		delete [] this->data_;
	}
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if(index > this->max_size_ - 1){
		throw std::out_of_range("Index out of range");
	}	
	return this->data_[index];
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if(index > this->max_size_ - 1){
		throw std::out_of_range("Index out of range");
	}	
	return this->data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	if(index > this->max_size_ - 1){
		throw std::out_of_range("Index out of range");
	}
	return this->data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	if(index > this->max_size_ - 1){
		throw std::out_of_range("Index out of range");
	}
	this->data_[index] = value;
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	for(int i = 0; i < this->max_size_; i++){
		if(this->data_[i] == value){
			return i;
		}
	}
	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	if(start > this->max_size_ - 1){
		throw std::out_of_range("Starting index out of range");
	}

	for(int i = 0; i < this->max_size_; i++){
		if(this->data_[i] == val){
			return i;
		}
	}
	return -1;
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	if(this->max_size_ > 0){
		for(int i = 0; i < this->max_size_; i++){
			this->data_[i] = value;
		}
	}
}

//reverse
template <typename T>
void Array_Base <T>::reverse (void)
{
	T temp;
	int start = 0;
	int end = this->max_size_ - 1;
	while(start < end){
		temp = this->data_[start];
		this->data_[start] = this->data_[end];
		this->data_[end] = temp;
		start++;
		end--;
	}
}