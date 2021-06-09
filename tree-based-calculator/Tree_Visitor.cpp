#include <iostream>
#include "Tree_Visitor.h"

Tree_Visitor::Tree_Visitor(void)
    :result_ (0)
{

}

Tree_Visitor::~Tree_Visitor(void)
{

}


int Tree_Visitor::result(void)
{   
    return this->result_;
}

void Tree_Visitor::Visit_Addition_Node(const Addition_Node & node)
{
    this->result_ = node.evaluate();
}

void Tree_Visitor::Visit_Division_Node(const Division_Node & node)
{
    this->result_ = node.evaluate();
}

void Tree_Visitor::Visit_Modulo_Node(const Modulo_Node & node)
{
    this->result_ = node.evaluate();
}

void Tree_Visitor::Visit_Multiplication_Node(const Multiplication_Node & node)
{
    this->result_ = node.evaluate();
}

void Tree_Visitor::Visit_Number_Node(const Number_Node & node)
{
    this->result_ = node.evaluate();
}

void Tree_Visitor::Visit_Subtraction_Node(const Subtraction_Node & node)
{
    this->result_ = node.evaluate();
}