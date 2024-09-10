/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:32:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 17:55:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    _contactCount = 0;
    return ;
}

PhoneBook::~PhoneBook( void )
{
    return ;
}

void PhoneBook::addContact(void)
{
    std::string content;
    int         index;

    if (_contactCount >= MAX_CONTACTS)
        std::cout << RED << "Full list. The oldest contact added will be replaced by this one." << RESET << std::endl;
    index = _contactCount % MAX_CONTACTS;
    while (content.empty())
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Please, type a  first name." << RESET<< std::endl;
        this->_contact[index].setName(content);
    }
    content.clear();
    while (content.empty())
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Please, type a last name." << RESET<< std::endl;
        this->_contact[index].setLast(content);
    }
    content.clear();
    while (content.empty())
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Please, type nickname." << RESET<< std::endl;
        this->_contact[index].setNickname(content);
    }
    content.clear();
    while (content.empty())
    {
        std::cout << "Enter darkest secret: ";
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Please, type nickname." << RESET<< std::endl;
        this->_contact[index].setSecret(content);
    }
    content.clear();
    while (content.empty())
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, content);
        if (content.empty())
            std::cout << RED << "Please, type number." << RESET<< std::endl;
        this->_contact[index].setNumber(content);
    }
    content.clear();
    _contactCount++;
}

void PhoneBook::searchContact(void)
{
    return ;
}
