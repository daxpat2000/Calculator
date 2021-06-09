#include <iostream>
#include <string>
#include <stdexcept>
#include "Addition_Node.h"
#include "Array.h"
#include "Array_Iterator.h"
#include "Calculator.h"
#include "Node.h"
#include "Number_Node.h"

template <typename T>
void print(const Array<T> & arr);

void test_composite(void);

int main(void)
{
    //using abstractions to make main program simpler
    std::string infix;

    //read input
    std::getline(std::cin, infix);

    while(infix != "QUIT")
    {   
        //calculate current expression
        Calculator calculator(infix);   
        int result = 0;
        try
        {
            result = calculator.calculate_expression();
            std::cout << result << "\n";
        }
        catch(std::exception & e)
        {
            std::cout << e.what();
        }
        
        //read next expression
        std::getline(std::cin, infix);
    }
    return 0;
}

//this was to test functionality of iterator.
template <typename T>
void print(const Array<T> & arr)
{
    Array_Iterator<T> itr(arr);
    while (itr.has_next())
    {
        std::cout << (T)*itr << ",";
        itr.next();
    }
    std::cout << "\n";    
}

void test_composite(void)
{
    Node * left = new Number_Node(4);
    Node * right = new Number_Node(5);
    Node * add = new Addition_Node(left, right);

    std::cout << "4 + 5 = " << add->evaluate() << "\n";

    delete add;
}