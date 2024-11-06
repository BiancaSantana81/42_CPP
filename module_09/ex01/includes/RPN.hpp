/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/06 11:17:25 by bsantana         ###   ########.fr       */
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

    std::stack<int> _values;

    public:

    //constructors and destructor
    RPN(void);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN(void);

    // methods

    void calculate(std::string input);

    bool validInput(std::string line);
    bool isOperator(std::string token);
    bool isNumber(std::string token);

    int convertNumber(std::string token);

};

#endif