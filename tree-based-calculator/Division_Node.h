/* 
 * Concrete division class
 * 
 */

#ifndef _DIVISION_NODE_H_
#define _DIVISION_NODE_H_

#include "Binary_Node.h"

class Division_Node : public Binary_Node
{
    public:
        // default constructor
        Division_Node(void);

        // constructor
        Division_Node(Node * left, Node * right);

        // desctructor
        virtual ~Division_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement accept visitor
        void accept(Node_Visitor & visitor);
};

#endif