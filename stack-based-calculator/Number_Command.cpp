#include "Number_Command.h"

Number_Command::Number_Command(Stack<int> & stack ,int x)
    :x_ (x),
     stack_ (stack)
{

}

Number_Command::~Number_Command(void)
{

}

void Number_Command::execute(void)
{
    this->stack_.push(this->x_);
}

int Number_Command::precedence(void)
{
    return 1;
}