/*
 * Base class for builder pattern
 * 
 */

#ifndef _EXPRESSION_BUILDER_H_
#define _EXPRESSION_BUILDER_H_

class Expression_Builder
{
    public:
        // virtual destructor
        ~Expression_Builder(void);

        // start expression method
        virtual void start_expression(void) = 0;

        // build addition
        virtual void build_addition(void) = 0;

        // build division
        virtual void build_division(void) = 0;

        // build modulo
        virtual void build_modulo(void) = 0;

        // build multiplication
        virtual void build_multiplication(void) = 0;

        // build number
        virtual void build_number(int number) = 0;

        // build subtraction
        virtual void build_subtraction(void) = 0;
};

#endif