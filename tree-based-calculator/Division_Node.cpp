#include <stdexcept>
#include "Division_Node.h"

Division_Node::Division_Node(void)
    :Binary_Node()
{
    
}

Division_Node::Division_Node(Node * left, Node * right)
    :Binary_Node(left, right)
{

}

Division_Node::~Division_Node(void)
{

}

int Division_Node::evaluate(void) const
{
    int left = this->left_->evaluate();
    int right = this->right_->evaluate();

    if(left == 0)
    {
        throw std::runtime_error("Zero Division Error: Attempt to divide a number by zero\n");
    }

    return right / left;
}

int Division_Node::precedence(void)
{
    return 3;
}

void Division_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Division_Node(*this);
}