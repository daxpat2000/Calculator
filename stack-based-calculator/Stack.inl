// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{   //top keeps counts starting 0
    return (this->num_elements_);
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if(this->num_elements_ == 0){
        throw empty_exception("Stack empty");
    }
    return this->container_.get(this->num_elements_ - 1);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if(this->num_elements_ == 0){
        return true;
    }
    return false;
}
