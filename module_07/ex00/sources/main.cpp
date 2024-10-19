/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:13:51 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 13:05:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/template.hpp"

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

int main(void)
{
    int a = 42, b = 10;

    std::cout << BRIGHT_RED " =============== TEST 1: WITH INT =============== " RESET << std::endl;

    std::cout << BRIGHT_YELLOW "before swap:  " RESET  << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "min ( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max ( a, b) = " << ::max(a, b) << std::endl;

    ::swap(a, b);

    std::cout << BRIGHT_YELLOW "after swap: " RESET  << std::endl;
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "min ( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max ( a, b) = " << ::max(a, b) << std::endl;

    std::cout << BRIGHT_RED " =============== TEST 2: WITH DOUBLE =============== " RESET << std::endl;
    double x = 3.14, y = 2.71;
    
    std::cout << BRIGHT_YELLOW "before swap:  " RESET << std::endl;
    std::cout << "x = " << x << " y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    ::swap(x, y);
    std::cout << BRIGHT_YELLOW "after swap: " RESET  << std::endl;
    std::cout << "x = " << x << " y = " << y << std::endl;
    std::cout << "min(x, y) = " << ::min(x, y) << std::endl;
    std::cout << "max(x, y) = " << ::max(x, y) << std::endl;

    std::cout << BRIGHT_RED " =============== TEST 3: WITH STRINGS =============== " RESET << std::endl;
    std::string s1 = "apple", s2 = "banana";

    std::cout << BRIGHT_YELLOW "before swap:  " RESET << std::endl;
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;

    ::swap(s1, s2);
    
    std::cout << BRIGHT_YELLOW "After swap: s1 = " RESET << s1 << ", s2 = " << s2 << std::endl;

    std::cout << BRIGHT_RED " =============== TEST 4: WHIT EQUAL VALUES =============== " RESET << std::endl;
    int c = 7, d = 7;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
}

// int main( void )
// {
//     int a = 2;
//     int b = 3;
//     ::swap( a, b );
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
//     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
//     std::string c = "chaine1";
//     std::string d = "chaine2";
//     ::swap(c, d);
//     std::cout << "c = " << c << ", d = " << d << std::endl;
//     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
//     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//     return (0);
// }