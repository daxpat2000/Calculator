/*
 * Muliply Command Interface
 * 
 */

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Binary_Command.h"

class Multiply_Command : public Binary_Command
{
    public:
        //init constructor
        Multiply_Command(Stack<int> & stack);

        //destructor
        ~Multiply_Command(void);

        //implement evaluate function
        virtual int evaluate(int x1, int x2);

        //implement precedence
        virtual int precedence(void);
};

#endif