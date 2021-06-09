/*
 * Subtract Command Interface
 * 
 */

#ifndef _SUBTRACTION_COMMAND_H_
#define _SUBTRACTION_COMMAND_H_

#include "Binary_Command.h"

class Subtraction_Command : public Binary_Command
{
    public:
        //initializing constructor
        Subtraction_Command(Stack<int> & stack);

        //destructor
        ~Subtraction_Command(void);

        //implement evaluate
        virtual int evaluate(int x1, int x2);

        //implement precedence
        virtual int precedence(void);
};

#endif