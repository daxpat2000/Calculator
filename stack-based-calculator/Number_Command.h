/*
 * Number Command
 *
 */

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Command.h"
#include "Stack.h"

class Number_Command : public Command
{
    public:
        //init constructor
        Number_Command(Stack<int> & stack, int x);

        //destructor
        ~Number_Command(void);

        //implement the execute method
        virtual void execute(void);

        //implement precedence
        virtual int precedence(void);
        
    private:
        Stack<int> & stack_;
        int x_;

};

#endif
