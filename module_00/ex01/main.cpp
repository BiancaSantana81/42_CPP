/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 18:20:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    std::cout << MAGENTA << "Welcome to PhoneBook!" << RESET << std::endl;
    while (true)
    {
        std::cout << "Type your choice:" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "EXIT")
            break ;
        else
        {
            std::cout << BRIGHT_RED << "Invalid!" << RESET << std::endl;
            std::cout << "Please type: ADD, SEARCH or EXIT." << std::endl;
        }
    }
    std::cout << BRIGHT_CYAN <<"Bye!" << RESET  << std::endl;
    return (0);
}
