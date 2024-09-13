/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/13 17:05:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    std::cout << BRIGHT_MAGENTA << "Welcome to PhoneBook!" << RESET << std::endl;
    while (true)
    {
        std::cout << "Type your choice:" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "EXIT")
            phone.exit();
        else
            std::cout << BRIGHT_RED "Invalid!" RESET " Please type:" BRIGHT_CYAN " ADD, SEARCH or EXIT." RESET << std::endl;
    }
    return (0);
}
