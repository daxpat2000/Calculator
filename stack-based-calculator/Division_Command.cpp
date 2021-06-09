#include "Division_Command.h"

Division_Command::Division_Command(Stack<int> & stack)
    :Binary_Command(stack)
{

}

Division_Command::~Division_Command(void)
{

}

int Division_Command::evaluate(int x1, int  x2)
{
    // COMMENT: Your code will crash if you have divide by 0.
    // RESPONE: Program throws exception when attempting to divide by 0.
    //add a check for zero.
    if(x1 == 0)
    {
        throw std::runtime_error("Zero Division Error: Attempt to divide a number by zero\n");
    }
    return x2 / x1;
}

int Division_Command::precedence(void)
{
    return 3;
}
