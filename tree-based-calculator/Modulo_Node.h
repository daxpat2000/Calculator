/*
 * Concrete class for Modulo
 * 
 */

#ifndef _MODULO_NODE_H_
#define _MODULO_NODE_H_

#include "Binary_Node.h"

class Modulo_Node : public Binary_Node
{
    public:
        //default constructor
        Modulo_Node(void);
        
        // constructor
        Modulo_Node(Node * left, Node * right);

        // Destructor
        virtual ~Modulo_Node(void);

        // implement evaluate
        int evaluate(void) const;

        // implement precedence
        int precedence(void);

        // implement accept visitor
        void accept(Node_Visitor & visitor);
};

#endif