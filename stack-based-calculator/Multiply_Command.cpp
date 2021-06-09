#include "Multiply_Command.h"

Multiply_Command::Multiply_Command(Stack<int> & stack)
    :Binary_Command(stack)
{

}

Multiply_Command::~Multiply_Command(void)
{

}

int Multiply_Command::evaluate(int x1, int x2)
{
    return x2 * x1;
}

int Multiply_Command::precedence(void)
{
    return 3;
}