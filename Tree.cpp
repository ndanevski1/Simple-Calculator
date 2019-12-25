//
// Created by nick on 12/25/19.
//

#include "Tree.h"

//Implementation of the methods for the class Tree_Node
Tree_Node::Tree_Node(string label) {
    this->label = move(label);
    this->left = nullptr;
    this->right = nullptr;
    this->value = 0;
}
Tree_Node *Tree_Node::get_left() {
    return this->left;
}
Tree_Node *Tree_Node::get_right() {
    return this->right;
}
int Tree_Node::get_value() {
    return this->value;
}
string Tree_Node::get_label() {
    return this->label;
}
void Tree_Node::set_left(Tree_Node* l) {
    this->left = l;
}
void Tree_Node::set_right(Tree_Node* r) {
    this->right = r;
}
void Tree_Node::set_value(int val) {
    this->value = val;
}
void print_state(Tree_Node* root, int space) {
    if(root == nullptr)
        return;
    for(int i = 0; i < space; i++) {
        printf(" ");
    }
    cout << root->get_label() << endl;
    if(root->get_left() != nullptr)
        print_state(root->get_left(), space + 4);
    if(root->get_right() != nullptr)
        print_state(root->get_right(), space + 4);
}

void Tree_Node::print_Tree() {
    print_state(this, 0);
}

Tree_Node::~Tree_Node() {
    delete this->left;
    delete this->right;
}


Tree_Node* build_parsing_tree(const string& in) {
    list<string> postfix = convert_infix_2_postfix(in);
    stack<Tree_Node*> nodes;
    for(string s: postfix) {
        if (is_digit(s[0])) {
            Tree_Node* t = new Tree_Node(s);
            t->set_value(stoi(s));
            nodes.push(t);
        }
        else { // it has to be an operator
            Tree_Node* t = new Tree_Node(s);
            Tree_Node* t1 = nodes.top();
            nodes.pop();
            Tree_Node* t2 = nodes.top();
            nodes.pop();
            t->set_left(t2);
            t->set_right(t1);
            switch (s[0]) { //the first entry of the string is the full string, and represents the operator
                case '+': {
                    t->set_value(t2->get_value() + t1->get_value());
                    break;
                }
                case '-': {
                    t->set_value(t2->get_value() - t1->get_value());
                    break;
                }
                case '*': {
                    t->set_value(t2->get_value() * t1->get_value());
                    break;
                }
                case '/': {
                    t->set_value(t2->get_value() / t1->get_value());
                    break;
                }
                case '^': {
                    t->set_value(pow(t2->get_value(), t1->get_value()));
                    break;
                }
            }
            nodes.push(t);
        }
    }
    Tree_Node* t = nodes.top();
    nodes.pop();
    return t;
}
int calculate_expression(const string& in) {
    Tree_Node* t = build_parsing_tree(in);
    int res = t->get_value();
    delete t;
    return res;
}

