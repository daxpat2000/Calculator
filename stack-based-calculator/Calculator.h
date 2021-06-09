/*
 * Calculator Class to deal
 * with program input
 * 
 */

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include "Array.h"
#include "Array_Iterator.h"
#include "Command.h"
#include "Stack_Command_Factory.h"


class Calculator
{
    public:
        //initializing constructor
        Calculator(const std::string & infix);

        //destructor
        ~Calculator();

        //evaluate expression line
        int calculate_expression();

    private:      
        //infix to posfix method
        bool infix_to_postfix();

        //input expression from user
        const std::string & infix_;

        //stack for factory commands
        Stack<int> stack_;

        //factory for generating commands
        Stack_Command_Factory factory;

        //converted postfix
        Array<Command*> postfix_;
};

#endif