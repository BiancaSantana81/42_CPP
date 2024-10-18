/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:00:13 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 16:28:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.hpp"
#include "../includes/ScalarConveter.hpp"

static bool isChar(const std::string &input);
static bool isInt(const std::string &input);
static bool isFloat(const std::string &input);
static bool isDouble(const std::string &input);
static bool isPseudoLiteral(const std::string &input);

ECases detectType(const std::string &input)
{
    if (isChar(input))
        return (CHAR);
    else if (isInt(input))
        return (INT);
    else if (isFloat(input))  
      return (FLOAT);
    else if (isDouble(input))  
       return (DOUBLE);
    else if (isPseudoLiteral(input))
        return (PSEUDO_LITERAL);
    return (MEGA_IMPOSSIBLE);
}

static bool isChar(const std::string &input)
{
    if (input.length() == 1 && std::isalpha(input[0]))
        return (true);
    return (false);
}

static bool isInt(const std::string &input)
{
    std:: istringstream iss(input);
    int number;

    iss >> number;
    if (iss.fail() || !iss.eof()) 
        return (false);
    return (true);
}

static bool isFloat(const std::string &input)
{
    if (input[input.size() - 1] != 'f')
        return false;
    
    int dotCount = 0;
    for (unsigned int i = 0; i < input.length(); i++) {
        if (input[i] == '.')
            dotCount++;
    }
    if (dotCount != 1)
        return (false);

    std::istringstream iss(input);
    float number;

    iss >> number;
    if (iss.fail() || iss.eof())
        return (false);    
    return (true);
}

static bool isDouble(const std::string &input)
{
    if (input[input.size() - 1] == 'f')
        return false;
    
    int dotCount = 0;
    for (unsigned int i = 0; i < input.length(); i++) {
        if (input[i] == '.')
            dotCount++;
    }
    if (dotCount != 1)
        return (false);

    std::istringstream iss(input);
    double number;

    iss >> number;
    if (iss.fail() || !iss.eof())
        return (false);
    return (true);
}

static bool isPseudoLiteral(const std::string &input)
{
    if (input == "+inf" || input == "-inf" || input == "nan"
    || input == "+inff" || input == "-inff" || input == "nanf")
        return (true);
    return (false);
}
