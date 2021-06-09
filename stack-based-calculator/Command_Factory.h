/*
 * Base class for abstract factory pattern
 * 
 */

#ifndef _COMMAND_FACTORY_H_
#define _COMMAND_FACTORY_H_

#include "Addition_Command.h"
#include "Division_Command.h"
#include "Modulo_Command.h"
#include "Multiply_Command.h"
#include "Number_Command.h"
#include "Subtraction_Command.h"

class Command_Factory
{
    public:
        virtual Addition_Command * create_addition_command(void) = 0;
        virtual Division_Command * create_division_command(void) = 0;
        virtual Modulo_Command * create_modulo_command(void) = 0;
        virtual Multiply_Command * create_multiply_command(void) = 0;
        virtual Number_Command * create_number_command(int x) = 0;
        virtual Subtraction_Command * create_subtraction_command(void) = 0;
};

#endif