/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:22:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConveter.hpp"

/* CONSTRUCTORS */

ScalarConveter::ScalarConveter(void) {};

ScalarConveter::ScalarConveter(const ScalarConveter &other)
{
    *this = other;
}

ScalarConveter &ScalarConveter::operator=(const ScalarConveter &other)
{
    (void)other;
    return (*this);
}

/* METHOD*/

void ScalarConveter::convert(std::string input)
{
    /* 1: clean entry for convert */
    size_t start = input.find_first_not_of(" \t");
    size_t end = input.find_last_not_of(" \t");

    if (start != std::string::npos && end != std::string::npos)
        input = input.substr(start, end - start + 1);
    else if (start != std::string::npos)
        input = input.substr(start);
    else if (end != std::string::npos)
        input = input.substr(0, end + 1);
    
    /*2: identifies the type and converts the input */
    ECases type = detectType(input);
    convertType(type, input);
}

/* DESTRUCTOR */

ScalarConveter::~ScalarConveter(void) {};