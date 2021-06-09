/*
 * Tree builder concrete class
 * 
 */

#ifndef _TREE_BUILDER_H_
#define _TREE_BUILDER_H_

#include "Binary_Node.h"
#include "Expression_Builder.h"
#include "Node.h"
#include "Stack.h"
#include "Tree_Expression.h"

class Tree_Builder : public Expression_Builder
{
    public:
        // default constructot
        Tree_Builder(void);

        // default destructor
        ~Tree_Builder(void);

        // get expression
        Tree_Expression * get_expression(void);

        // start expression method
        void start_expression(void);

        // build addition
        void build_addition(void);

        // build division
        void build_division(void);

        // build modulo
        void build_modulo(void);

        // build multiplication
        void build_multiplication(void);

        // build number
        void build_number(int number);

        // build subtraction
        void build_subtraction(void);

    private:
        // method to update tree as nodes are created
        bool update_expression(Binary_Node * node);

        // unstack - internal function used during parsing
        void unstack(void);

        // final expression to be built
        Tree_Expression * expression_;

        // operator specific stack used while buidling tree expression
        Stack<Binary_Node*> operator_stack_;

        // operand specific stack used while buidling tree expression
        Stack<Node*> operand_stack_;
        
        // node stack to store postfix
        Stack<Node*> node_stack_;

};

#endif

