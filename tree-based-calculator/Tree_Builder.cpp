#include "Addition_Node.h"
#include "Division_Node.h"
#include "Modulo_Node.h"
#include "Multiplication_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Tree_Builder.h"
#include <iostream>

Tree_Builder::Tree_Builder(void)
    :expression_ (nullptr),
     operand_stack_ (),
     operator_stack_ (),
     node_stack_ ()
{

}

Tree_Builder::~Tree_Builder(void)
{
    delete this->expression_;
}

void Tree_Builder::start_expression(void)
{
    this->expression_ = new Tree_Expression();
}

Tree_Expression * Tree_Builder::get_expression(void)
{
    while (!this->operator_stack_.is_empty())
    {
 
        this->unstack();
        this->operator_stack_.pop();
    }

    // return tree expression
    this->expression_->set_root(static_cast<Binary_Node *> (this->operand_stack_.top()));
    return this->expression_;
}

void Tree_Builder::build_addition(void)
{
    Addition_Node * node = new Addition_Node();
    this->update_expression(node);
}

void Tree_Builder::build_division(void)
{
    Division_Node * node = new Division_Node();
    this->update_expression(node);
}

void Tree_Builder::build_modulo(void)
{
    Modulo_Node * node = new Modulo_Node();
    this->update_expression(node);
}

void Tree_Builder::build_multiplication(void)
{
    Multiplication_Node * node = new Multiplication_Node();
    this->update_expression(node);
}
void Tree_Builder::build_number(int number)
{
    Number_Node * node = new Number_Node(number);
    this->operand_stack_.push(node);
}

void Tree_Builder::build_subtraction(void)
{
    Subtraction_Node * node = new Subtraction_Node();
    this->update_expression(node);
}

void Tree_Builder::unstack(void)
{
    // create a binary tree from top binary node
    Binary_Node * temp = this->operator_stack_.top();

    temp->set_left(this->operand_stack_.top());
    this->operand_stack_.pop();

    temp->set_right(this->operand_stack_.top());
    this->operand_stack_.pop();

    operand_stack_.push(temp);
}

bool Tree_Builder::update_expression(Binary_Node * new_node)
{
    while((!this->operator_stack_.is_empty()) && (new_node->precedence() <= this->operator_stack_.top()->precedence()))
    {   
        // assign childs to binary node
        this->unstack();

        // remove the top operator after putting it into node stack
        this->operator_stack_.pop();
    }
    this->operator_stack_.push(new_node);

    return true;
}