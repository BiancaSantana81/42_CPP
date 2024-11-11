/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/11 18:06:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <stack>

#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_RED    "\033[91m"
#define RESET   "\033[0m"

class RPN
{
    private:

    /*
        This class uses the `stack` container to store values, 
        making it easier to calculate an expression in Reverse Polish Notation (RPN).
        The choice of `stack` allows quick access to the element at the top, 
        ideal for recalling the most recent operands, which simplifies 
        the implementation of the RPN algorithm by following the natural flow of the stack 
        (last in, first out - LIFO).
    */

    std::stack<int> _values;

    public:

    //constructors and destructor

    RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN(void);

    // methods

    void calculate(std::string input);
    int performingOperation(std::string token, int a, int b);

    bool validInput(std::string line);
    bool isOperator(std::string token);
    bool isNumber(std::string token);

    int convertNumber(std::string token);

};

#endif