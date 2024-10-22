/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:07:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/22 11:25:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"
#include <iostream>

#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

struct ComplexType
{
    std::string name;
    int         age;
};

std::ostream &operator<<(std::ostream &os, const ComplexType &obj)
{
   os << " " << obj.name << " " << " , age: "  << obj.age;
   return (os);
}

int main(void)
{
    {
        std::cout << BRIGHT_YELLOW "============= ROUND 01: SIMPLE TESTS WITH INT ============= " RESET << std::endl;
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
    }
    {
       std::cout << BRIGHT_YELLOW "============= ROUND 02: DEEP COPY ============= " RESET << std::endl;
       std::cout << BRIGHT_CYAN "=== Test 5: Deep Copy ===" RESET << std::endl;
        Array<int> original(3);
        original[0] = 10;
        original[1] = 20;
        original[2] = 30;

        Array<int> copy = original;

        std::cout << "Original array: ";
        for (unsigned int i = 0; i < original.size(); i++)
            std::cout << original[i] << " ";
        std::cout << std::endl;

        std::cout << "Copy array: ";
        for (unsigned int i = 0; i < copy.size(); i++)
            std::cout << copy[i] << " ";
        std::cout << std::endl;

        copy[0] = 100;
        std::cout << "After modifying the copy:" << std::endl;
        std::cout << "Original[0]: " << original[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;
    }
    {
        std::cout << BRIGHT_YELLOW "============= ROUND 02: COMPLEX TYPES ============= " RESET << std::endl;
        
        std::cout << BRIGHT_CYAN "=== Test 6: TwoPeople test ===" RESET << std::endl;
        Array<ComplexType> twoPeople(2);
        twoPeople[0].name = "Maria Eduarda";
        twoPeople[0].age = 27;
        twoPeople[1].name = "Carlos Rodrigues";
        twoPeople[1].age = 28;

        for (unsigned int i = 0; i < twoPeople.size(); i++)
            std::cout << "People: " << i + 1 << twoPeople[i] << std::endl;
        
        std::cout << BRIGHT_CYAN "=== Test 7: Deep Copy TwoPeople ===" RESET << std::endl;
        
        Array<ComplexType> copyTwoPeople = twoPeople;
        for (unsigned int i = 0; i < copyTwoPeople.size(); i++)
            std::cout << "People: " << i + 1 << copyTwoPeople[i] << std::endl;

        std::cout << BRIGHT_CYAN "=== Test 8: modifying the copy ===" RESET << std::endl;
        copyTwoPeople[0].name = "Juliana Soares";
        
        std::cout << "Original:  " << twoPeople[0] << std::endl;
        std::cout << "Copy:  " << copyTwoPeople[0] << std::endl;
    }
    return (0);
}
