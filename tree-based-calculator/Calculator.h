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
#include "Tree_Builder.h"
#include "Tree_Expression.h"
#include "Tree_Visitor.h"


class Calculator
{
    public:
        // initializing constructor
        Calculator(const std::string & infix);

        // destructor
        ~Calculator();

        // evaluate expression line
        int calculate_expression(void);

    private:      
        // builds tree from infix string
        bool parse_expression();

        // input expression from user
        const std::string & infix_;

        // tree builder
        Tree_Builder builder;

        // tree visitor - in response to the COMMENT
        Tree_Visitor visitor;
};

#endif