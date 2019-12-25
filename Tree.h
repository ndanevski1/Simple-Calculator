//
// Created by nick on 12/25/19.
//

/*
 * After taking a string in infix notation, I create an expression tree that when parsed, calculates the result.
 */
#ifndef SIMPLE_CALCULATOR_TREE_H
#define SIMPLE_CALCULATOR_TREE_H


#include "infix-to-postfix.h"

class Tree_Node {
private:
    int value;
    string label;
    Tree_Node* left;
    Tree_Node* right;

public:
    //Definition of the methods for the class Tree_Node
    explicit Tree_Node(string label);
    ~Tree_Node();
    Tree_Node* get_left();
    Tree_Node* get_right();
    int get_value();
    string get_label();
    void set_left(Tree_Node* l);
    void set_right(Tree_Node* r);
    void set_value(int val);
    void print_Tree();
};
Tree_Node* build_parsing_tree(const string& in);
int calculate_expression(const string& in);
#endif //SIMPLE_CALCULATOR_TREE_H
