/*
 * Tree expression evaluator
 *
 */

#ifndef _TREE_EXPRESSION_H_
#define _TREE_EXPRESSION_H_

#include "Node.h"
#include "Binary_Node.h"
#include "Tree_Visitor.h"

class Tree_Expression
{
    public:
        // default constructor
        Tree_Expression(void);

        // default destructor
        ~Tree_Expression(void);

        // set root
        void set_root(Binary_Node * root);

        // accept a tree visitor
        void accept(Tree_Visitor & visitor);

    private:
        // root of the tree
        Binary_Node * root_;

};


#endif