/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:32:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 15:05:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
    return ;
}

PhoneBook::~PhoneBook( void )
{
    return ;
}

void PhoneBook::addContact(void)
{
    std::string content;

    if (_contactCount >= MAX_CONTACTS)
    {
        std::cout << RED << "Full list. The last contact added will be replaced by this one." << RESET << std::endl;
        return ;
    }

    std::cout << "Enter first name: ";
    std::getline(std::cin, content);
    this->_contacts[_contactCount].setName(content);

    std::cout << "Enter last name: ";
    std::getline(std::cin, content);
    this->_contacts[_contactCount].setLast(content);

    std::cout << "Enter nick name: ";
    std::getline(std::cin, content);
    this->_contacts[_contactCount].setNickname(content);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, content);
    this->_contacts[_contactCount].setSecret(content);

    // std::cout << "Enter number: ";
    // std::getline(std::cin, content);
    // this->_contacts[_contactCount].setNumber(content);
}

void PhoneBook::searchContact(void)
{
    return ;
}
