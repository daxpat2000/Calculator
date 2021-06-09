#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Calculator.h"

Calculator::Calculator(const std::string & infix)
    :infix_ (infix),
     builder (),
     visitor ()
{

}

Calculator::~Calculator(void)
{

}

bool Calculator::parse_expression(void)
{
    //string streams to iterate over input expression
    std::string token;
    std::istringstream input(this->infix_);

    //signal builder to start buidling
    this->builder.start_expression();

    while(!input.eof())
    {
        input >> token;
        //build nodes on the tree depending on the type of command
        if(token == "+")
        {
            this->builder.build_addition();
        }
        else if(token == "-")
        {
            this->builder.build_subtraction();
        }
        else if(token == "*")
        {
            this->builder.build_multiplication();    
        }
        else if(token == "/")
        {
            this->builder.build_division();
        }
        else if(token == "%")
        {
            this->builder.build_modulo();
        }
        else if(token == "(")
        {   
            std::string temp = "";

            int parenthesis = 1;

            while(!input.eof() || parenthesis != 0)
            {
                input >> token;

                if(token == ")")
                {
                    parenthesis--;

                    // calculate the expression in side ( )
                    Calculator calc(temp);
                    int result = calc.calculate_expression();
                    this->builder.build_number(result);

                    // clear temp for future use
                    temp.clear();
                    temp = std::to_string(result);
                }
                else if(token == "(")
                {
                    parenthesis++;
                }
                else
                {
                    temp += token;
                    temp += " ";
                }
            }
            if(parenthesis != 0)
            {
                throw std::runtime_error("Invalid Expression Error\n");
            }
        }
        else
        {   //if number
            this->builder.build_number(std::stoi(token));
        }
    }
    return true;
}

int Calculator::calculate_expression(void)
{
    try
    {
        this->parse_expression();
    }
    catch(const std::exception& e)
    {
        throw std::runtime_error(e.what());
    }

    // use the visitor pattern to evaluate the expression
    Tree_Expression * exp = this->builder.get_expression();

    exp->accept(this->visitor);

    return this->visitor.result();
}