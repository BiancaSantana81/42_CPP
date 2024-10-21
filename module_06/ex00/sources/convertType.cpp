/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertType.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:32:20 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 10:11:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/types.hpp"
#include "../includes/ScalarConveter.hpp"

/* functions to print the converted values and print the values in each type. */

static void typeChar(std::string input);
static void typeInt(std::string input);
static void typeFloat(std::string input);
static void typeDouble(std::string input);
static void typePseudoLiteral(std::string input);

/* functions to check if it is possible to convert a type to its previous
 one (if not, it will inform you that it is out of bounds) 
*/

static void rangeChar(double num);
static void rangeInt(int num, double d);
static void rangeFloat(float num, double d);

/* identifies the type and sends it to the respective conversion function */

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
            typePseudoLiteral(input);
            break ;
        case MEGA_IMPOSSIBLE:
            std::cout << " unknown type." << std::endl;
            break ;
    }
}

static void typeChar(std::string input)
{
    char c = input[0];

    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: '" << static_cast<int>(c) << "'" << std::endl;
    std::cout << "float: '" << static_cast<float>(c) << "f'" << std::endl;
    std::cout << "double: '" << static_cast<double>(c) << "'" << std::endl;
}

static void typeInt(std::string input)
{
    std::istringstream iss(input);
    
    int num;
    iss >> num;
    
    rangeChar(static_cast<double>(num));
    std::cout << "int: '" << num << "'" << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f'" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << "'" << std::endl;
    
}

static void typeFloat(std::string input)
{
    std::istringstream iss(input);
    
    float num;
    iss >> num;
    
    rangeChar(static_cast<double>(num));
    rangeInt(static_cast<int>(num), static_cast<double>(num));
    std::cout << "float: '" << num << "'" << std::endl;
	std::cout << "double: '" << static_cast<double>(num) << "'" << std::endl;
}

static void typeDouble(std::string input)
{
    std::istringstream iss(input);
    
    double num;
    iss >> num;
    
    rangeChar(num);
    rangeInt(static_cast<int>(num), static_cast<double>(num));
    rangeFloat(static_cast<float>(num), static_cast<double>(num));
    std::cout << "double: '" << num << "'" << std::endl;
}

static void typePseudoLiteral(std::string input)
{
    std::cout << "off limits: impossible to convert to char." << std::endl;
    std::cout << "off limits: impossible to convert to int." << std::endl;
    
    if (input == "+inff" || input == "+inf")
    {
        std::cout << "float: +inff" << std::endl;
        std::cout << "float: +inf" << std::endl;
    }
    else if (input == "-inff" || input == "-inf")
    {
        std::cout << "float: -inff" << std::endl;
        std::cout << "float: -inf" << std::endl;
    }
    else
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
}

static void rangeChar(double num)
{
    if (!std::isalpha(static_cast<char>(num)))
        std::cout << "off limits: impossible to convert to char." << std::endl;
    else
    {
        char c = static_cast<char>(num);
        std::cout << "char: '" << c << "'" << std::endl;
    }
}

static void rangeInt(int num, double d)
{
    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "off limits: impossible to convert to int." << std::endl;
    else
        std::cout << "int: '" << num << "'" << std::endl;
}

static void rangeFloat(float num, double d)
{
    if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
        std::cout << "off limits: impossible to convert to float." << std::endl;
    else
        std::cout << "float: '" << num << "'" << std::endl;
}
