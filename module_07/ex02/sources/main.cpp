/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:07:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 17:45:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

#define BRIGHT_CYAN   "\033[96m"
#define RESET   "\033[0m"

int main(void)
{
    try {
        std::cout << BRIGHT_CYAN "=== Test 1: Empty Array ===" RESET << std::endl;
    Array<int> emptyArray;
    std::cout << "size of the array: " << emptyArray.size() << std::endl;
    
    std::cout << BRIGHT_CYAN "=== Test 2: Array [5] elements ===" RESET << std::endl;
    Array<int> fiveElements(5);
    std::cout << "size of the array: " << fiveElements.size() << std::endl;
    for (unsigned int i = 0; i < fiveElements.size(); i++)
        std::cout << "Element " << i << ": " << fiveElements[i] << std::endl;

    std::cout << BRIGHT_CYAN "=== Test 3: Modifying the values of fiveArray ===" RESET << std::endl;
    
    fiveElements[0] = 1;
    fiveElements[1] = 2;
    fiveElements[2] = 3;
    fiveElements[3] = 4;
    fiveElements[4] = 5;

    for (unsigned int i = 0; i <fiveElements.size(); i++)
        std::cout << "Element " << i << ": " << fiveElements[i] << std::endl;

    std::cout << BRIGHT_CYAN "=== Test 4: Invalid acess in index ===" RESET << std::endl;
    std:: cout << fiveElements[10] << std::endl;
    
    } catch (const std::exception& e) {
         std::cerr << "Exceção: " << e.what() << std::endl;
    }
    return (0);
}
