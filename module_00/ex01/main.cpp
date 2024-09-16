/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    while (true)
    {
        phone.utilsHeader();
        std::getline(std::cin, command);
        if (std::cin.sync() == -1)
            return (0);
        if (command == "ADD")
            phone.addContact();
        else if (command == "SEARCH")
            phone.searchContact();
        else if (command == "EXIT")
            phone.exit();
        else
            std::cout << BRIGHT_RED "Invalid input!" RESET << std::endl;
    }
    return (0);
}
