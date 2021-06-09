/*
 * Number node class
 * 
 */

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Node.h"
#include "Node_Visitor.h"

class Number_Node : public Node
{
    public:
        // constructor
        Number_Node(int n);

        // destructor
        virtual ~Number_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement accept visitor
        void accept(Node_Visitor & visitor);

    private:
        int number_;
};

#endif