/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsTests.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:26:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/23 16:24:49 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Function that receives Fixed by value
Fixed createFixedByValue(Fixed f)
{
    std::cout << "Function createFixedByValue called." << std::endl;
    return (f);
}

// Function that receives Fixed by reference
void assignFixedByReference(Fixed& target, const Fixed& source)
{
    target = source; // targer receives the value of source
    std::cout << "Inside function: assignment made." << std::endl;
}

// Function that returns Fixed by value
Fixed returnFixedByValue()
{
    Fixed temp;
    temp.setRawBits(100);
    std::cout << "Function returnFixedByValue called." << std::endl;
    return (temp);
}

void runFixedTests(Fixed &a, Fixed &b, Fixed &c)
{
    std::cout << BRIGHT_MAGENTA "\n=== Test 2: Self-attribution ===" RESET << std::endl;
    a = a;

    std::cout << BRIGHT_MAGENTA "\n=== Test 3: Assignment chaining ===" RESET << std::endl;
    a.setRawBits(42);
    Fixed d;
    Fixed e;
    d = e = a;
    std::cout << "d: " << d.getRawBits() << std::endl;
    std::cout << "e: " << e.getRawBits() << std::endl;

    std::cout << BRIGHT_MAGENTA "\n=== Test 4: Passing by Value to Function ===" RESET << std::endl;
    Fixed f = createFixedByValue(a);
    std::cout << "f: " << f.getRawBits() << std::endl;

    std::cout << BRIGHT_MAGENTA "\n=== Test 5: Passing by Reference to Function ===" RESET << std::endl;
    assignFixedByReference(b, c);
    std::cout << "b after assignment via function: " << b.getRawBits() << std::endl;

    std::cout << BRIGHT_MAGENTA "\n=== Test 6: Return by Function Value ===" RESET << std::endl;
    Fixed g = returnFixedByValue();
    std::cout << "g: " << g.getRawBits() << std::endl;

    std::cout << BRIGHT_MAGENTA "\n=== Test 7: Use with Constant Objects ===" RESET << std::endl;
    const Fixed constFixedOne = a;
    const Fixed constFixedTwo;
    std::cout << "constFixedOne: " << constFixedOne.getRawBits() << std::endl;
    std::cout << "constFixedTwo: " << constFixedTwo.getRawBits() << std::endl;
    // Tentar modificar constantes vai gerar erro de compilação:
    // constFixedTwo = a; 
    // constFixedOne.setRawBits(5);
}
