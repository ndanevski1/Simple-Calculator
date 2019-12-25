//
// Created by nick on 12/25/19.
//

#include <iostream>
#include "infix-to-postfix.h"
using namespace std;

int main() {
    cout << "Input an expression\n";
    string s;
    cin >> s;
    cout << "In postfix is \n";
    cout << convert_infix_2_postfix(s);
    return 0;
}
