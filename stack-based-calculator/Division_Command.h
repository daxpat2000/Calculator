/*
 * Divison Command Interface
 * 
 */

#ifndef _DIVISION_COMMAND_H_
#define _DIVISION_COMMAND_H_

#include "Binary_Command.h"
#include <stdexcept>

class Division_Command : public Binary_Command
{
    public:
        //init constructor
        Division_Command(Stack<int> & stack);

        //destructor
        ~Division_Command(void);

        //implement the evaluate
        virtual int evaluate(int x1, int x2);

        //implement precedence
        virtual int precedence(void);
};

#endif