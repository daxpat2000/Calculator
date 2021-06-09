#include "Tree_Expression.h"
#include <iostream>

Tree_Expression::Tree_Expression(void)
    :root_ (nullptr)
{

}

Tree_Expression::~Tree_Expression(void)
{
    if(this->root_)
    {
        delete this->root_;
    }
}

void Tree_Expression::set_root(Binary_Node * root)
{
    this->root_ = root;
}

// int Tree_Expression::evaluate(void)
// {
//     // COMMENT You are to evaluate the tree using the visitor pattern.
//     // RESPONSE Added a new accept method to tree expression, which
//     // passes the control to visitor to deal with the tree evaluation
//     // Due to this new feature, I have deprecated the evaluate method
//     return this->root_->evaluate();
// }

void Tree_Expression::accept(Tree_Visitor & visitor)
{
    this->root_->accept(visitor);
}