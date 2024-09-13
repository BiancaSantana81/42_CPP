/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/13 17:36:41 by bsantana         ###   ########.fr       */
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
        phone.header();
        std::getline(std::cin, command);

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
