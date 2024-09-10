/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 12:12:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    while (true)
    {
        std::cout << "Enter ADD, SEARCH or EXIT:" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
        {
            return (0);
        }
        else if (command == "SEARCH")
        {
            return (0);
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting program." << std::endl;
            break ;
        }
        else
        {
            std::cout << "Please chose a valid command." << std::endl;
        }
    }
    return (0);
}
