#include "Addition_Node.h"

Addition_Node::Addition_Node(void)
    :Binary_Node()
{
    
}

Addition_Node::Addition_Node(Node * left, Node * right)
    :Binary_Node(left, right)
{

}

Addition_Node::~Addition_Node(void)
{

}

int Addition_Node::evaluate(void) const
{
    int left = this->left_->evaluate();
    int right = this->right_->evaluate();

    return left + right;
}

int Addition_Node::precedence(void)
{
    return 2;
}

void Addition_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Addition_Node(*this);
}