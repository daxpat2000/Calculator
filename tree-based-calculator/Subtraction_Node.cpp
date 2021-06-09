#include "Subtraction_Node.h"

Subtraction_Node::Subtraction_Node(void)
    :Binary_Node()
{
    
}

Subtraction_Node::Subtraction_Node(Node * left, Node * right)
    :Binary_Node(left, right)
{

}

Subtraction_Node::~Subtraction_Node(void)
{

}

int Subtraction_Node::evaluate(void) const
{
    int left = this->left_->evaluate();
    int right = this->right_->evaluate();

    return right - left;
}

int Subtraction_Node::precedence(void)
{
    return 2;
}

void Subtraction_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Subtraction_Node(*this);
}