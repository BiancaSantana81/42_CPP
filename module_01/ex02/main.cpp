/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:14:54 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 12:14:31 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define BRIGHT_CYAN   "\033[96m"
#define RESET         "\033[0m"

int main(void)
{
    std::string string = "HI THIS IS BRAIN"; // variable containing the actual value
    std::string *stringPTR = &string; // pointer holding the memory address of string
    std::string &stringREF = string; // reference (alias) for string

    /* Imprimindo os endereços de memória */
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
    *stringPTR = "Hi! Value changed with *strPTR"; // dereferencing string with strPTR
    std::cout << "string after dereferencing: " << string << std::endl;

    stringREF = "Hi! Value changed with strREF";
    std::cout << "string after modified string REF: " << string << std::endl;

    return (0);
}
