/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:33:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/05 17:56:28 by bsantana         ###   ########.fr       */
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
        std::cout << "Error." << std::endl;

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
                return ;
        }

        int a = _values.top();
        _values.pop();

        int b = _values.top();
        _values.pop();
        // continuar com construção da calculate para RPN
    }
}

bool RPN::validInput(std::string input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
    {
        if (!isOperator(token) && isNumber(token) == false)
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
    if (number < 1 || number > 9)
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