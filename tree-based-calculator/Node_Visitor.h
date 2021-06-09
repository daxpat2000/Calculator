/*
 * Abstract classd for Visitor Pattern
 * 
 */

#ifndef _NODE_VISITOR_H_
#define _NODE_VISITOR_H_

class Addition_Node;
class Binary_Node;
class Division_Node;
class Modulo_Node;
class Multiplication_Node;
class Number_Node;
class Subtraction_Node;

class Node_Visitor
{   
    public:
        // default constructor
        Node_Visitor(void);

        // default destructor
        virtual ~Node_Visitor(void);

        // addition node visitor
        virtual void Visit_Addition_Node(const Addition_Node & node);

        // division node visitor
        virtual void Visit_Division_Node(const Division_Node & node);

        // modulo node visitor
        virtual void Visit_Modulo_Node(const Modulo_Node & node);

        // multiplication node visitor
        virtual void Visit_Multiplication_Node(const Multiplication_Node & node);

        // number node visitor
        virtual void Visit_Number_Node(const Number_Node & node);

        // subtraction node visitor
        virtual void Visit_Subtraction_Node(const Subtraction_Node & node);
};

#endif