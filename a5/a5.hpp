/***
 *  File: a5.hpp
 *  Author: FirstName LastName UBITName
 */

#ifndef A5_HPP
#define A5_HPP

#include "token.hpp"
#include <stdlib.h>

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT FUNCTION RPN BELOW
// YOU ARE NOT ALLOWED TO ALTER THE RPN FUNCTION INTERFACE
// INSIDE THE FUNCTION YOU CAN DO WHATEVER YOU LIKE

template <typename Iter> double RPN(Iter first, Iter last) {

    std::stack::Iter xiaoming;
    for (first != last){
        if (first.is_operand()) xiaoming.push( first);
        else if(first.is_operator() ) {
            double aa = xiaoming.top().as_operand();
            xiaoming.pop();
            double bb = xiaoming.top().as_operand();
        }
    }

  // IMPLEMENT ME!
} // RPN

#endif // A5_HPP
