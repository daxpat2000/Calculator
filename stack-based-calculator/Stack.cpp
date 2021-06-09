// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.
#include "Stack.h"
//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
    :num_elements_ (0),
     container_ (INIT_SIZE)   //size of 20 if not specified
{

}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    :num_elements_ (stack.size()),
     container_ (stack.container_) //use array class copy constructor     
{

}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    //nothing required. When Stack goes out of scope
    //Array's class's desctructor will be called
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    if((this->num_elements_ + 1) > this->container_.size()){
        //stack is full, allocate more memory
        container_.resize(INCR_SIZE);
    }
    container_.set(this->num_elements_, element);
    this->num_elements_ += 1;
  
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if(this->num_elements_ == 0){
        throw empty_exception("Stack empty");
    }
    //no need to clear the data in the array
    //as it will be re-written ass stack grows
    this->num_elements_ -= 1;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    if((&rhs != nullptr) && (this != &rhs)){
        this->container_ = rhs.container_;
        //update num elements
        this->num_elements_ = rhs.size();
    }
    return (*this);
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    //no need to clear contents. They will be rewritten as stack grows again
    this->num_elements_ = 0; 
}