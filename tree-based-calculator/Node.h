/*
 * Node - Base expression node class
 * 
 */

#ifndef _NODE_H_
#define _NODE_H_

#include "Node_Visitor.h"

class Node
{   
    public:
        // default destructor
        virtual ~Node(void);

        // evaluate method
        virtual int evaluate(void) const = 0;

        // precedence method
        virtual int precedence(void) = 0;

        // visitor method
        virtual void accept(Node_Visitor & visitor) = 0;
};

#endif