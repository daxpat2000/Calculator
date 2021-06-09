/*
 * Concrete class for Subtraction
 * 
 */

#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include "Binary_Node.h"

class Subtraction_Node : public Binary_Node
{
    public:
        // default constructor
        Subtraction_Node(void);

        // constructor
        Subtraction_Node(Node * left, Node * right);

        // Destructor
        virtual ~Subtraction_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement accept visitor
        void accept(Node_Visitor & visitor);
};

#endif