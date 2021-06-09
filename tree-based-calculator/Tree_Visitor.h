#ifndef _TREE_VISITOR_H_
#define _TREE_VISITOR_H_

#include "Node_Visitor.h"
#include "Addition_Node.h"
#include "Division_Node.h"
#include "Modulo_Node.h"
#include "Multiplication_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"

class Tree_Visitor : public Node_Visitor
{
    public:
        // default construtor
        Tree_Visitor(void);

        // destructor
        ~Tree_Visitor(void);

        // addition node visitor
        void Visit_Addition_Node(const Addition_Node & node);

        // division node visitor
        void Visit_Division_Node(const Division_Node & node);

        // modulo node visitor
        void Visit_Modulo_Node(const Modulo_Node & node);

        // multiplication node visitor
        void Visit_Multiplication_Node(const Multiplication_Node & node);

        // number node visitor
        void Visit_Number_Node(const Number_Node & node);

        // subtraction node visitor
        void Visit_Subtraction_Node(const Subtraction_Node & node);

        // result method - evaluates the expression
        int result(void);
        
    private:
        // store result of evaluation
        int result_;
};

#endif
