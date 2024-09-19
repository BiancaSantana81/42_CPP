/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:14:54 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/19 14:09:42 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define BRIGHT_CYAN   "\033[96m"
#define YELLOW  "\033[33m"
#define RESET         "\033[0m"

int main(void)
{
    std::string string = "HI THIS IS BRAIN"; // variable containing the actual value
    std::string *stringPTR = &string; // pointer containing the memory address of the string (can be initialized with NULL)
    std::string &stringREF = string; // reference to string cannot be initialized NULL

    /* Printing the memory addresses */
    std::cout << BRIGHT_CYAN "***************************************" RESET << std::endl;
    std::cout << "Endereço de string: " << &string << std::endl;
    std::cout << "Endereço de *strPTR: " << stringPTR << std::endl;
    std::cout << "Endereço de strREF: " << &stringREF << std::endl;

    /* Accessing the initial values */
    std::cout << BRIGHT_CYAN "***************************************" RESET << std::endl;
    std::cout << "string: " << string << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

    /* Modifying values */
    std::cout << BRIGHT_CYAN "***************************************" RESET << std::endl;
    std::cout << YELLOW "string before modified *strPTR: " RESET << string << std::endl;
    *stringPTR = "Hi! Value changed with *strPTR"; // dereferencing string with strPTR
    std::cout << BRIGHT_CYAN"string after dereferencing: " RESET << string << std::endl;

    std::cout << YELLOW "string before modified string REF: " RESET << string << std::endl;
    stringREF = "Hi! Value changed with strREF";
    std::cout << BRIGHT_CYAN "string after modified string REF: " RESET << string << std::endl;

    return (0);
}
