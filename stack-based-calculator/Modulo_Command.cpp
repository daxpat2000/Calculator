#include "Modulo_Command.h"

Modulo_Command::Modulo_Command(Stack<int> & stack)
    :Binary_Command(stack)
{

}

Modulo_Command::~Modulo_Command(void)
{

}

int Modulo_Command::evaluate(int x1, int x2)
{
    if(x1 == 0)
    {
        throw std::runtime_error("Zero Modulo Error: Attempt to modulo a number by zero\n");
    }
    return x2 % x1;
}

int Modulo_Command::precedence(void)
{
    return 3;
}