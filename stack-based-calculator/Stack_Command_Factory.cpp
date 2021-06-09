#include "Stack_Command_Factory.h"

Stack_Command_Factory::Stack_Command_Factory(Stack<int> & stack)
    :stack_ (stack)
{

}

Stack_Command_Factory::~Stack_Command_Factory(void)
{

}

Addition_Command * Stack_Command_Factory::create_addition_command(void)
{
    return new Addition_Command(this->stack_);
}

Division_Command * Stack_Command_Factory::create_division_command(void)
{
    return new Division_Command(this->stack_);
}

Modulo_Command * Stack_Command_Factory::create_modulo_command(void)
{
    return new Modulo_Command(this->stack_);
}

Multiply_Command * Stack_Command_Factory::create_multiply_command(void)
{
    return new Multiply_Command(this->stack_);
}

Number_Command * Stack_Command_Factory::create_number_command(int x)
{
    return new Number_Command(this->stack_, x);
}

Subtraction_Command * Stack_Command_Factory::create_subtraction_command(void)
{
    return new Subtraction_Command(this->stack_);
}