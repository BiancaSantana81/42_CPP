/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:10:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/22 10:23:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Iter.hpp"

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

int main(void)
{
    std::cout << BRIGHT_RED " =============== TEST 1: WITH INT ARRAY =============== " RESET << std::endl;

    int intArray[5] = {1, 2, 3, 4, 5};
    int sizeInt = 5;

    std::cout << BRIGHT_YELLOW "original int array: " RESET;
    iter(intArray, sizeInt, printMatrix);
    std::cout << std::endl;

    iter(intArray, sizeInt, static_cast<void(*)(int&)>(incrementMatrix));

    std::cout << BRIGHT_YELLOW "modified array: " RESET;
    iter(intArray, sizeInt, printMatrix);
    std::cout << std::endl;

    std::cout << BRIGHT_RED " =============== TEST 2: WITH CHAR ARRAY =============== " RESET << std::endl;

    char charArray[5] = {'a', 'b', 'c', 'd', 'e'};
    int sizeChar = 5;

    std::cout << BRIGHT_YELLOW "original char array: " RESET;
    iter(charArray, sizeChar, printMatrix);
    std::cout << std::endl;

    iter(charArray, sizeChar, static_cast<void(*)(char&)>(incrementMatrix));

    std::cout << BRIGHT_YELLOW "modified array: " RESET;
    iter(charArray, sizeChar, printMatrix);
    std::cout << std::endl;

    std::cout << BRIGHT_RED " =============== TEST 3: WITH CHAR FLOAT =============== " RESET << std::endl;

    float floatArray[5] = {1.1f, 1.2f, 1.3f, 1.4f, 1.5f};
    int sizeFloat = 5;

    std::cout << BRIGHT_YELLOW "original char array: " RESET;
    iter(floatArray, sizeFloat, printMatrix);
    std::cout << std::endl;

    iter(floatArray, sizeFloat, static_cast<void(*)(float&)>(incrementMatrix));

    std::cout << BRIGHT_YELLOW "modified array: " RESET;
    iter(floatArray, sizeFloat, printMatrix);
    std::cout << std::endl;

    return (0);
}
