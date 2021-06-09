/*
 * Concrete Addition Node
 * 
 */

#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Node.h"

class Addition_Node : public Binary_Node
{
    public:
        // default constructor
        Addition_Node(void);

        // constructor
        Addition_Node(Node * left, Node * right);

        // destructor
        virtual ~Addition_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement accept visitor
        void accept(Node_Visitor & visitor);
};

#endif