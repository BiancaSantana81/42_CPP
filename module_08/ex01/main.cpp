/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:44:59 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 17:51:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Span.hpp"

static void basicTests(void);
static void smallContainer(void);
static void biggerContainer(void);
static void duplicateNumbersTest(void);

int main(void)
{
    basicTests();
    smallContainer();
    biggerContainer();
    duplicateNumbersTest();
    
}

static void basicTests(void)
{
    std::cout << BRIGHT_MAGENTA "basic tests (with five values) " RESET << std::endl;
    try {
        Span test1(5);
    
        test1.addNumber(3);
        test1.addNumber(6);
        test1.addNumber(17);
        test1.addNumber(9);
        test1.addNumber(11);

        std::cout << BRIGHT_GREEN "Shortest Span: " RESET << test1.shortestSpan() << std::endl;
        std::cout << BRIGHT_GREEN "Longest Span: " RESET << test1.longestSpan() << std::endl;

        std::cout << BRIGHT_MAGENTA "trying to add more values than possible... " RESET << std::endl;
        test1.addNumber(42);

    } catch (const std::exception &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }
}

static void smallContainer(void)
{
    std::cout << BRIGHT_MAGENTA "smallContainer test " RESET << std::endl;
    try {
        Span test2(1);

        test2.addNumber(42);
    
        test2.shortestSpan();
        test2.longestSpan();
        
    } catch (const std::exception &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }
}

static void biggerContainer(void)
{
    try {
        Span test3(10000);
        
        srand(static_cast<unsigned int>(time(NULL)));
        for (size_t i = 0; i < 10000; ++i) {
            test3.addNumber(rand() % 100000);
        }

        std::cout << "Shortest Span: " << test3.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << test3.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

static void duplicateNumbersTest(void)
{
    std::cout << BRIGHT_MAGENTA "duplicateNumbersTest " RESET << std::endl;
    try {
        Span test4(3);
        test4.addNumber(5);
        test4.addNumber(5);
        test4.addNumber(5);
        
        std::cout << BRIGHT_GREEN "Shortest Span: " RESET << test4.shortestSpan() << std::endl;
        std::cout << BRIGHT_GREEN "Longest Span: " RESET << test4.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }
}
