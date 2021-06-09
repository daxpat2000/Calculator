#include "Binary_Command.h"

Binary_Command::Binary_Command(Stack<int> & stack)
    :stack_ (stack)
{

}

Binary_Command::~Binary_Command()
{

}

//execute command
void Binary_Command::execute(void)
{
    //get first two integers from the stack
    int x1 = this->stack_.top();
    this->stack_.pop();
    int x2 = this->stack_.top();
    this->stack_.pop();

    //evaluate and push on stack
    int result = this->evaluate(x1, x2);
    this->stack_.push(result);
}