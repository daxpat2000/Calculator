#include "Binary_Node.h"

Binary_Node::Binary_Node(void)
    :left_ (nullptr),
     right_ (nullptr)
{
    
}

Binary_Node::Binary_Node(Node * left, Node * right)
    :left_ (left),
     right_ (right)
{

}

Binary_Node::~Binary_Node(void)
{    
    if(this->left_ != nullptr)
    {
        delete this->left_;
    }
    if(this->right_ != nullptr)
    {
        delete this->right_;
    }
}

void Binary_Node::set_left(Node * left)
{
    this->left_ = left;
}

void Binary_Node::set_right(Node * right)
{
    this->right_ = right;
}

Node * Binary_Node::get_left(void)
{
    return this->left_;
}

Node * Binary_Node::get_right(void)
{
    return this->right_;
}