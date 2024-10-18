/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:32:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 16:30:57 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.hpp"
#include "../includes/ScalarConveter.hpp"

static void typeChar(std::string input);
static void typeInt(std::string input);
static void typeFloat(std::string input);
static void typeDouble(std::string input);
// static void typePseudoLiteral(std::string input);
static void convertToChar(double num);

void convertType(ECases type, std::string input)
{
    switch (type)
    {
        case CHAR:
            typeChar(input);
            break ;
        case INT:
            typeInt(input);
            break ;
        case FLOAT:
            typeFloat(input);
            break ;
        case DOUBLE:
            typeDouble(input);
            break ;
        case PSEUDO_LITERAL:
            //typePseudoLiteral(input);
            break ;
        case MEGA_IMPOSSIBLE:
            std::cout << "(mega_impossible) unknown type" << std::endl;
            break ;
    }
}

static void typeChar(std::string input)
{
    char c = input[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void typeInt(std::string input)
{
    std::istringstream iss(input);
    
    int num;
    iss >> num;
    
    convertToChar(static_cast<double>(num));
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
    
}

static void typeFloat(std::string input)
{
    std::istringstream iss(input);
    
    float num;
    iss >> num;
    
    convertToChar(static_cast<double>(num));
    std::cout << "int: " << static_cast<int>(num) << "f" << std::endl;
    std::cout << "float: " << num << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void typeDouble(std::string input)
{
    std::istringstream iss(input);
    
    double num;
    iss >> num;
    
    convertToChar(num);
	std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "double: " << num << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
}

static void convertToChar(double num)
{
    if (num < 0 || num > 127) {
        std::cout << "off limits: impossible to convert to char." << std::endl;
    } else {
        char c = static_cast<char>(num);
        std::cout << "char: '" << c << "'" << std::endl;
    }
}

// static void typePseudoLiteral(std::string input)
// {
    
// }
