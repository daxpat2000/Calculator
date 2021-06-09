/*
 * Modulo Operation Command
 * 
 */

#ifndef _MODULO_COMMAND_H_
#define _MODULO_COMMAND_H_

#include "Binary_Command.h"
#include <stdexcept>

class Modulo_Command : public Binary_Command
{
    public:
        //initializaing constructor
        Modulo_Command(Stack<int> & stack);

        //destructor
        ~Modulo_Command(void);

        //implement the evaluate method
        virtual int evaluate(int x1, int x2);

        //implement precedence
        virtual int precedence(void);
};

#endif