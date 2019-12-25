//
// Created by nick on 12/25/19.
//

#include "infix-to-postfix.h"
#include "Helper-methods.h"

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
list<string> convert_infix_2_postfix(const string& in) {
    string out;
    stack<char> st;
    list<string> postfix;
    string number;
    for(char curr : in) {
        if(is_digit(curr)) {  //if current symbol is operand
            number += curr;
            continue;
        }
        if(curr == '(') {
            st.push(curr);
            continue;
        }
        else if(curr == ')') {
            postfix.push_back(number);
            number = "";
            while (st.top() != '(') {
                char add = st.top();    //add every operator that is inside the parenthesis
                st.pop();
                postfix.push_back(string(1,add));
            }
            if (st.top() == '(')
                st.pop();
            continue;
        }
        else if (is_operator(curr)) {
//            if the current precedence is less than or equal to the one on the top of the stack,
//            then first "calculate" the previous expression and then continue with the current one
            postfix.push_back(number);
            number = "";
            while(!st.empty() && operator_precedence(curr) <= operator_precedence(st.top())) {
                char add = st.top();    //add every operator that is inside the parenthesis
                st.pop();
                postfix.push_back(string(1,add));
            }
            st.push(curr);
        }
    }
    if(!number.empty())
        postfix.push_back(number);
    while(!st.empty()) {    //add any remaining elements in the stack
        char add = st.top();    //add every operator that is inside the parenthesis
        st.pop();
        postfix.push_back(string(1,add));
    }
    return postfix;
}