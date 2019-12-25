//
// Created by nick on 12/25/19.
//

#include "Tree.h"

int main() {
    cout << "This is a simple calculator. Type $ to exit.\n";
    while(true) {
        cout << "Input an expression\n";
        string in;
        cin >> in;
        if(in == "$")
            break;
        Tree_Node* t = build_parsing_tree(in);
        cout << "Value is " << t->get_value() << endl;

//        The previous 2 lines could have look like this:
//        cout << "Value is " << calculate_expression(in) << endl;
//        However, I chose not to, so that it is possible for the user to see the expression tree printed, as below.
//
//        Uncomment the following 3 lines to see the expression tree printed!

//        cout << "Printing the expression tree: " << endl;
//        t->print_Tree();
//        cout << endl;

        delete t;
    }
    cout << "End of the program." << endl;
    return 0;
}


/* Some test cases that you can try the calculator on.
 *
 * 8*12-4+13*7-12*(4+10)
 * 2^(3+4)
 * 15-3^(1*4)
 */