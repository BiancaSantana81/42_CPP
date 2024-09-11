/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:32:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/11 18:24:30 by bsantana         ###   ########.fr       */
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

// limpar o cin para não dar erro com CTRL D

void PhoneBook::addContact(void)
{
    std::string content;
    int         index;
    bool        valid_number;

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
    while (content.empty() || valid_number == false)
    {
        valid_number = true;
        std::cout << "Enter number: ";
        std::getline(std::cin, content);
        for (size_t i = 0; i < content.size(); i++)
        {
            if (!isdigit(content[i]))
            {
                valid_number = false;
                std::cout << RED << "Just numbers! ";
                break ;
            }
        }
        if (content.empty() || valid_number == false)
            std::cout << "Please, type number." << RESET << std::endl;
        this->_contact[index].setNumber(content);
    }
    content.clear();
    _contactCount++;
}

void PhoneBook::searchContact(void)
{
    std::string content;
    int         valid_index;

    valid_index = -1;
    if (_contactCount == 0)
        std::cout << RED << "PhoneBook is empty." << RESET;

    std::cout << std::setw(10) << MAGENTA << "   Index  " << "|";
    std::cout << std::setw(10) << MAGENTA << "   Name   " << "|";
    std::cout << std::setw(10) << MAGENTA << " LastName " << "|";
    std::cout << std::setw(10) << MAGENTA << " Nickname " << " | " << RESET << std::endl;
    
    for (int i = 0; i < _contactCount; i++) // eu acho que da seg fault por que eu to usando _contactCount que é realmente maior que o index.
    {
        std::cout <<std::setw(10) << (i + 1) << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncName() << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncLast() << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncNick() << " | " << std::endl;
    }

    std::cout << "" << std::endl;
    while (valid_index == -1)
    {
        std::cout << MAGENTA << "Type the index of the contact: " << RESET;
        std::getline(std::cin, content);
        if (content.empty())
        {
            std::cout << RED << "Please, type a valid index." << RESET << std::endl;
            continue ;
        }
        valid_index = this->convertInt(content);
        if (valid_index < 1 || valid_index > _contactCount) // vou trocar por números aqui ao invés de _contactCount
        {
            std::cout << RED << "Invalid index. Please enter a number between 1 and " << _contactCount << "." << RESET << std::endl;
            valid_index = -1;
        }
        std::cout << "" << std::endl;
        std::cout << MAGENTA << " **** Details contact **** " << RESET << std::endl;
        std::cout << "" << std::endl;
        std::cout << MAGENTA "Name: " RESET << this->_contact[valid_index - 1].getName() << std::endl;
        std::cout << MAGENTA "Last name: " RESET << this->_contact[valid_index - 1].getLast() << std::endl;
        std::cout << MAGENTA "Nickname: " RESET << this->_contact[valid_index - 1].getNick() << std::endl;
        std::cout << MAGENTA "DarkestSecret: " RESET << this->_contact[valid_index - 1].getSecret() << std::endl;
        std::cout << MAGENTA "Number: " RESET << this->_contact[valid_index - 1].getNumber() << std::endl;
    }
}

int PhoneBook::convertInt(std::string content)
{
    int number;
    bool has_digit;
    bool has_space;

    has_digit = false;
    has_space = false;
    for (unsigned int i = 0; i < content.length(); i++)
    {
        if (content[i] == ' ')
        {
            if (has_digit)
                has_space = true;
            continue ;
        }
        if (!isdigit(content[i]))
        {
            std::cout << RED << "Just numbers, please." << RESET << std::endl;
            return (-1);
        }
        if (has_space)
        {
            std::cout << RED << "One number, please." << RESET << std::endl;
            return (-1);
        }
        has_digit = true;
    }
    const char* c_str = content.c_str();
    number = atoi(c_str);
    return number;
}