/*
 * Base Class For Binary Operation Command
 * 
 */

#ifndef _BINARY_COMMAND_H_
#define _BINARY_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Binary_Command : public Command
{
    protected:
        //initializing constructor
        Binary_Command(Stack<int> & stack);

        //destructor
        ~Binary_Command();
    public:
        //implement the execute function from base class
        void execute(void);

        //precedence of a command
        virtual int precedence(void) = 0;

        //evaluate - Should I use floating point instead?
        virtual int evaluate(int x1, int x2) = 0;
    private:
        //container to perform calculations on
        Stack<int> & stack_;
};

#endif