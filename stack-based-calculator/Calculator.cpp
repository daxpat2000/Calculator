#include <iostream>
#include <sstream>
#include <stdexcept>
#include "Calculator.h"
#include "Array_Iterator.h"
#include "Parenthesis_Command.h"
#include "Stack_Command_Factory.h"

Calculator::Calculator(const std::string & infix)
    :infix_ (infix),
     postfix_ (),
     stack_ (),
     factory (stack_)    
{

}

Calculator::~Calculator(void)
{

}

bool Calculator::infix_to_postfix()
{   
    //string streams to iterate over input expression
    std::string token;
    std::istringstream input(this->infix_);

    //temp command object to hold each command during iteration
    Command * current_command = nullptr;
    Stack<Command*> commands;

    //to append commands at a index to class member postfix 
    size_t i = 0;

    int parenthesis_not_matching = 0;

    while(!input.eof())
    {
        input >> token;
        //create a command object depending on the type of command
        if(token == "+")
        {
            current_command = this->factory.create_addition_command();
        }
        else if(token == "-")
        {
            current_command = this->factory.create_subtraction_command();
        }
        else if(token == "*")
        {
            current_command = this->factory.create_multiply_command();
        }
        else if(token == "/")
        {
            current_command = this->factory.create_division_command();
        }
        else if(token == "%")
        {
            current_command = this->factory.create_modulo_command();
        }
        else if(token == "(")
        {
            /*
             *  Stuck here - best way to deal with parenthesis? 
             */
            
            // COMMENT That is for you to figure out. ;-)
            // RESPONSE - push open parenthesis on stack
            commands.push(new Parenthesis_Command());
            parenthesis_not_matching += 1;
            continue;
        }
        else if(token == ")")
        {
            /*
             *  Stuck here - best way to deal with parenthesis? 
             */
            
            // COMMENT That is for you to figure out. ;-)
            // RESPONSE pop until matching ')' is found
            // add mismatch parenthesis check
            if(parenthesis_not_matching > 0)
            {
                while (!commands.is_empty())
                {
                    this->postfix_.resize(i + 1);
                    this->postfix_[i] = commands.top();
                    commands.pop();
                    i++;
                    if(commands.top()->precedence() == 1)
                    {
                        break;
                    }
                }
                delete commands.top();  // make sure to deallocate the memory
                commands.pop();
                parenthesis_not_matching -= 1;
            }
            else
            {
                throw std::runtime_error("Invalid Expression Error: Encountered closed ')' before open '(' \n");
            }
            
            continue;
        }
        else
        {   //if number command
            current_command = this->factory.create_number_command(std::stoi(token));
            this->postfix_.resize(this->postfix_.size() + 1);
            this->postfix_[i] = current_command;
            i++;
            continue;
        }
        
        //add the operator command to stack 
        //depending on precedence
        while(!commands.is_empty() && current_command->precedence() <= commands.top()->precedence())
        {
            this->postfix_.resize(this->postfix_.size() + 1);
            this->postfix_[i] = commands.top();
            commands.pop();
            i++;
        }
        commands.push(current_command);
    }
    
    // throw error if mismatch in parenthesis after above loop
    if(parenthesis_not_matching != 0)
    {
        throw std::runtime_error("Invalid Expression Error: Mismatch in open-close paranthesis in the input expresion\n");
    }

    //if there remain any more
    //elements on stack, pop 
    //and add them to postfix
    while(!commands.is_empty())
    {
        this->postfix_.resize(this->postfix_.size() + 1);
        this->postfix_[i] = commands.top();
        commands.pop();
        i++;
    }

    return true;
}

int Calculator::calculate_expression()
{
    if(this->infix_to_postfix())
    {
        Array_Iterator<Command*> itr(this->postfix_);
        while(itr.has_next())
        {   // add exception handling to provide program from crashing
            try
            {
                (*itr)->execute();      //here is where design patterns make life easier
            }
            catch(std::exception & e)
            {
                //delete allocated memory before exiting the program
                while(itr.has_next()){
                    delete (*itr);
                    itr.next();
                }
                throw std::runtime_error(e.what());            
            }
            catch(...)
            {
                //delete allocated memory before exiting the program
                while(itr.has_next()){
                    delete (*itr);
                    itr.next();
                }
                throw std::runtime_error("An Exception occured while executing the program\n");
            }
            delete (*itr);          //make sure to deallocated memory when done with the command
            itr.next();             
        }
        return this->stack_.top();
    }  
    return 0;
}
