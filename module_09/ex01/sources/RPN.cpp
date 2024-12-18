/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/12 12:21:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* Constructors */

RPN::RPN(void): _values() {}

RPN::RPN(const RPN &other) : _values(other._values) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _values = other._values;
    else
         std::cout << "Self-attribution detected! The objects already have the same address." <<std::endl;
    return (*this);
}

/* Methods for Reverse Polish Notation */

void RPN::calculate(std::string input)
{
    if (!validInput(input))
    {
        std::cout << BRIGHT_RED "Error: Invalid characters in input." RESET << std::endl;
        return ;
    }

    std::istringstream iss(input);
    std::string token;
    int number;

    while (iss >> token)
    {
        if (isNumber(token))
        {
            number = convertNumber(token);
            _values.push(number);
        }
        else if (isOperator(token))
        {
            if (_values.size() < 2)
                continue ;

            int b = _values.top();
            _values.pop();

            int a = _values.top();
            _values.pop();
        
            int result = performingOperation(token, a, b);

            if (result == INT_MIN)
                return ;

            _values.push(result);
        }
    }

    if (_values.size() == 1)
        std::cout << BRIGHT_MAGENTA "Result: " RESET << _values.top() << std::endl;
    else
        std::cout << BRIGHT_RED "Error: Invalid expression." RESET << std::endl;
}

int RPN::performingOperation(std::string token, int a, int b)
{
    int result = 0;

    if (token == "+")
        result = a + b;
    else if (token == "-")
        result = a - b;
    else if (token == "*")
        result = a * b;
    else if (token == "/")
    {
        if (b == 0)
        {
            std::cout << BRIGHT_RED "Error:  Division by zero." RESET << std::endl;
            return (INT_MIN);
        }
    result = a / b;
    }
    return (result);
}

bool RPN::validInput(std::string input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (!isOperator(token) && !isNumber(token))
            return (false);
    }
    return (true);
}

bool RPN::isOperator(std::string token)
{
    if (token == "+" || token == "-" || token == "/" || token == "*")
        return (true);
    return (false);
}

bool RPN::isNumber(std::string token)
{
    std::istringstream iss(token);
    int number;

    iss >> number;
    if (iss.fail())
        return (false);
    if (number < 0 || number > 9)
        return (false);
    return (true);
}

int RPN::convertNumber(std::string token)
{
    std::istringstream iss(token);
    int number;

    iss >> number;
    return (number);
}

/* DESTRUCTOR */

RPN::~RPN(void) {}