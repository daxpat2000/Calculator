#include <iostream>
#include "Node_Visitor.h"

Node_Visitor::Node_Visitor(void)
{

}

Node_Visitor::~Node_Visitor(void)
{
    
}

void Node_Visitor::Visit_Addition_Node(const Addition_Node & node)
{
    std::cout << "!-------Addition Node---------!" << "\n";
}

void Node_Visitor::Visit_Division_Node(const Division_Node & node)
{
    std::cout << "!-------Division Node---------!" << "\n";
}

void Node_Visitor::Visit_Modulo_Node(const Modulo_Node & node)
{
    std::cout << "!-------Modulo Node---------!" << "\n";
}

void Node_Visitor::Visit_Multiplication_Node(const Multiplication_Node & node)
{
    std::cout << "!-------Multiplication Node---------!" << "\n";
}

void Node_Visitor::Visit_Number_Node(const Number_Node & node)
{
    std::cout << "!-------Number Node---------!" << "\n";
}

void Node_Visitor::Visit_Subtraction_Node(const Subtraction_Node & node)
{
    std::cout << "!-------Subtraction Node---------!" << "\n";
}