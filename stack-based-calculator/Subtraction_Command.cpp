#include "Subtraction_Command.h"

Subtraction_Command::Subtraction_Command(Stack<int> & stack)
    :Binary_Command(stack)
{

}

Subtraction_Command::~Subtraction_Command(void)
{
    
}

int Subtraction_Command::evaluate(int x1, int x2)
{
    return x2 - x1;
}

int Subtraction_Command::precedence(void)
{
    return 2;
}