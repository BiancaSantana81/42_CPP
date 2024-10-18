/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConveter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 15:28:52 by bsantana         ###   ########.fr       */
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
        input = input.substr(start, end - start + 1); // Limita a string ao intervalo encontrado
    else if (start != std::string::npos)
        input = input.substr(start); // Se só houver espaços no começo
    else if (end != std::string::npos)
        input = input.substr(0, end + 1); // Se só houver espaços no final
    
    /* 2: function for detect type */
    ECases type = detectType(input);
    convertType(type);
}

/* DESTRUCTOR */

ScalarConveter::~ScalarConveter(void) {};