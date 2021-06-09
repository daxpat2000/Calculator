/*
 * Binary Node - Base binary operation node class
 * 
 */

#ifndef _BINARY_NODE_H_
#define _BINARY_NODE_H_

#include "Node.h"

class Binary_Node : public Node
{
    public:
        // default constructor
        Binary_Node(void);

        // constructor
        Binary_Node(Node * left, Node * right);

        // default destructor
        virtual ~Binary_Node(void);

        // pass down the evaluate method
        virtual int evaluate(void) const = 0;

        // pass down the predence method
        virtual int precedence(void) = 0;

        // pass visitor accept method
        void accept(Node_Visitor & visitor) = 0;

        // to set the left child
        void set_left(Node * left);

        // to set the right child
        void set_right(Node * right);

        // provide acces to left child
        Node * get_left(void);

        // provide access to right child
        Node * get_right(void);

    protected:
        Node * left_;
        Node * right_;
};

#endif