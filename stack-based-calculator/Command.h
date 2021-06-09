/*
 *  Base Command Class
 *   
 */

#ifndef _COMMAND_H_
#define _COMMAND_H_

class Command 
{
    public:
        virtual void execute (void) = 0;

        //will be used during infix-to-postfix algorithm
        virtual int precedence(void) = 0;   
};

#endif