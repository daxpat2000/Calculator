/*
 * Concrete class for multiplication
 * 
 */

#ifndef _MULTIPLICATION_NODE_H_
#define _MULTIPLICATION_NODE_H_

#include "Binary_Node.h"

class Multiplication_Node : public Binary_Node
{
    public:
        // default constructor
        Multiplication_Node(void);
        // constructor
        Multiplication_Node(Node * left, Node * right);

        // Destructor
        virtual ~Multiplication_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement visitor
        void accept(Node_Visitor & visitor);
};

#endif