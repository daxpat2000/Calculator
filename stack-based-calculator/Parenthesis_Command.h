/*
 * Class For Parenthesis Command
 * 
 */

#ifndef _PARENTHESIS_COMMAND_H_
#define _PARENTHESIS_COMMAND_H_

#include "Command.h"

class Parenthesis_Command : public Command
{
    public:
        //default constructor
        Parenthesis_Command();

        //destructor
        ~Parenthesis_Command();

        //precedence
        int precedence(void);

        //evaluate
        void execute(void);
};

#endif