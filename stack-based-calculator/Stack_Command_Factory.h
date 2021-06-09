/*
 * Concrete Class For Calculatore - dervied from abstract factory
 * 
 */

#ifndef _STACK_COMMAND_FACTORY_H_
#define _STACK_COMMAND_FACTORY_H_

#include "Command_Factory.h"

class Stack_Command_Factory : public Command_Factory
{
    public:
        Stack_Command_Factory(Stack<int> & stack);
        ~Stack_Command_Factory(void);
        virtual Addition_Command * create_addition_command(void);
        virtual Division_Command * create_division_command(void);
        virtual Modulo_Command * create_modulo_command(void);
        virtual Multiply_Command * create_multiply_command(void);
        virtual Number_Command * create_number_command(int x);
        virtual Subtraction_Command * create_subtraction_command(void);
    private:
        Stack<int> & stack_;
};

#endif