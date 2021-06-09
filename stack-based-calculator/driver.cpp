#include <iostream>
#include <string>
#include <stdexcept>
#include "Calculator.h"

template <typename T>
void print(const Array<T> & arr);

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