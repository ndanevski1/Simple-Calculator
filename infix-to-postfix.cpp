//
// Created by nick on 12/25/19.
//

#include "infix-to-postfix.h"
#include <stack>

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
int operator_precedence(char c) {
    switch(c) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return -1;
    }
}
string convert_infix_2_postfix(string in) {
    string out;
    stack<char> st;
    for(char curr : in) {
        if(!is_operator(curr) && curr != '(' && curr != ')') {  //if current symbol is operand
            out += curr;
            continue;
        }
        if(curr == '(') {
            st.push(curr);
            continue;
        }
        else if(curr == ')') {
            while (st.top() != '(') {
                char add = st.top();    //add every operator that is inside the parenthesis
                st.pop();
                out += add;
            }
            if (st.top() == '(')
                st.pop();
            continue;
        }
        else if (is_operator(curr)) {
//            if the current precedence is less than or equal to the one on the top of the stack,
//            then first "calculate" the previous expression and then continue with the current one
            while(!st.empty() && operator_precedence(curr) <= operator_precedence(st.top())) {
                out += st.top();
                st.pop();
            }
            st.push(curr);
        }
    }
    while(!st.empty()) {    //add any remaining elements in the stack
        out += st.top();
        st.pop();
    }
    return out;
}