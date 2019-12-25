# Simple-Calculator

This is a simple calculator that I made in C++.
The operations it accepts are addition (+), subtraction (-), multiplication (*), division(/) and power (^).

It reads a mathematical expression using these operations as a string from the user and calculates the value.
After reading the input, I convert the string into a postfix notation to get rid of the parenthesis and simplify the
calculation algorithm using a stack. I create an expression tree from the stack, and in the end, the top of the tree
holds the value that the expression is equal to. The tree can be printed if you uncomment 3 lines in main.