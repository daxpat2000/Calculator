#include "Addition_Command.h"

Addition_Command::Addition_Command(Stack<int> & stack)
    :Binary_Command(stack)
{

}

Addition_Command::~Addition_Command(void)
{

}

int Addition_Command::evaluate(int x1, int x2)
{
    return x2 + x1;
}

int Addition_Command::precedence(void)
{
    return 2;
}