/***
 *  File: a5.hpp
 *  Author: FirstName LastName UBITName
 */

#ifndef A5_HPP
#define A5_HPP

#include "token.hpp"
#include <stack>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::stack;

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT FUNCTION RPN BELOW
// YOU ARE NOT ALLOWED TO ALTER THE RPN FUNCTION INTERFACE
// INSIDE THE FUNCTION YOU CAN DO WHATEVER YOU LIKE

template <typename Iter> double RPN(Iter first, Iter last) {
    stack<double> xiaoming;
    if (first != last) {
        // if the input is a number, then push in to the stackl
        if (first->is_operand()) xiaoming.push(first->as_operand());
        // else eval this thing, and eval the result;
        else if(first->is_operator() ) {
            double result = 0;
            char op = first->as_operator();
            // below to determin the first number;
            if (xiaoming.empty()) throw std::runtime_error("error");
            double aa = xiaoming.top();
            // cout << "first number is -> " << aa << endl;
            xiaoming.pop();

            // below to determin the second number;
            if (xiaoming.empty()) throw std::runtime_error("error");
            double bb = xiaoming.top();
            xiaoming.pop();
            // cout << "second number is -> " << bb << endl;

            if (op == '+') result = aa + bb;
            if (op == '-') result = bb - aa;
            if (op == '*') result = bb * aa;
            if (op == '/') result = bb / aa;

            xiaoming.push(result);

            cout<< "result is -> " << result;

        }
    }

    if (xiaoming.size() ==1)  return xiaoming.top();
    else  throw std::runtime_error("error");

  // IMPLEMENT ME!
} // RPN

#endif // A5_HPP
