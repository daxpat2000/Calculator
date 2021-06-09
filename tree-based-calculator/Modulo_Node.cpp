#include <stdexcept>
#include "Modulo_Node.h"

Modulo_Node::Modulo_Node(void)
    :Binary_Node()
{
    
}

Modulo_Node::Modulo_Node(Node* left, Node * right)
    :Binary_Node(left, right)
{
    
}

Modulo_Node::~Modulo_Node(void)
{

}

int Modulo_Node::evaluate(void) const
{
    int left = this->left_->evaluate();
    int right = this->right_->evaluate();

    if(left == 0)
    {
        throw std::runtime_error("Zero Modulo Error: Attempt to modulo a number by zero\n");
    }

    return right % left;
}

int Modulo_Node::precedence(void)
{
    return 3;
}

void Modulo_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Modulo_Node(*this);
}