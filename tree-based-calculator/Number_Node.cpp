#include "Number_Node.h"

Number_Node::Number_Node(int n)
    :number_ (n)
{

}

Number_Node::~Number_Node(void)
{

}

int Number_Node::evaluate(void) const
{
    return this->number_;
}

int Number_Node::precedence(void)
{
    return 1;
}

void Number_Node::accept(Node_Visitor & visitor)
{
    visitor.Visit_Number_Node(*this);
}
