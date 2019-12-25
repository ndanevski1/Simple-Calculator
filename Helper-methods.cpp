//
// Created by nick on 12/25/19.
//

#include "Helper-methods.h"

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}