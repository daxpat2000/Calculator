/*
 * Command for handling addition operation
 * 
 */

#ifndef _ADDITION_COMMAND_H_
#define _ADDITION_COMMAND_H_

#include "Binary_Command.h"

class Addition_Command : public Binary_Command
{
    public:
        //initializing constructor
        Addition_Command(Stack<int> & stack);

        //destructor
        ~Addition_Command(void);

        //implement evaluate
        virtual int evaluate(int x1, int x2);

        //implement precedence
        virtual int precedence(void);
};

#endif