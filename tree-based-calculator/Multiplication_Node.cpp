#include "Multiplication_Node.h"

Multiplication_Node::Multiplication_Node(void)
    :Binary_Node()
{
    
}

Multiplication_Node::Multiplication_Node(Node * left, Node * right)
    :Binary_Node(left, right)
{

}

Multiplication_Node::~Multiplication_Node(void)
{

}

int Multiplication_Node::evaluate(void) const
{
    int left = this->left_->evaluate();
    int right = this->right_->evaluate();

    return left * right;
}

int Multiplication_Node::precedence(void)
{
    return 3;
}

void Multiplication_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Multiplication_Node(*this);
}