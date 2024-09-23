/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:57:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/23 16:53:06 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << BRIGHT_MAGENTA "=== Test 1: Initial values ​​for a and b ===\n" RESET;
    std::cout << BRIGHT_RED"a: " RESET << a << std::endl;
    std::cout << BRIGHT_RED "b: " RESET << b << std::endl;

    std::cout << BRIGHT_MAGENTA "=== Test 2: Increment and Decrement ===\n" RESET;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after ++a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after a++: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a after --a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a after a--: " << a << std::endl;

    std::cout << BRIGHT_MAGENTA "\n=== Test 3: Arithmetic Operations===\n" RESET;
    Fixed c(3.5f);
    Fixed d(2.5f);
    
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << BRIGHT_MAGENTA "=== Test 4: Comparisons===\n" RESET;
    std::cout << BRIGHT_RED"c: " RESET << c << std::endl;
    std::cout << BRIGHT_RED "d: " RESET << d << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;

    std::cout << BRIGHT_MAGENTA "=== Test 4: Min e Max===\n" RESET;
    std::cout << "Min(a, b): " << Fixed::min(a, b) << std::endl; // Esperado: 0
    std::cout << "Max(a, b): " << Fixed::max(a, b) << std::endl; // Esperado: 10.1
    std::cout << "Min(c, d): " << Fixed::min(c, d) << std::endl; // Esperado: 2.5
    std::cout << "Max(c, d): " << Fixed::max(c, d) << std::endl; // Esperado: 3.5

    return (0);
}

// int main(void)
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;

//     return (0);
// }