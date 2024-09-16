/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:32:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 11:36:44 by bsantana         ###   ########.fr       */
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
    bool        valid_number;

    if (_contactCount >= MAX_CONTACTS)
        std::cout << RED "Full list. The oldest contact added will be replaced by this one." RESET << std::endl;
    index = _contactCount % MAX_CONTACTS;

    while (content.empty())
    {
        std::cout << BRIGHT_MAGENTA "Enter first name: " RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1) 
            return;
        if (content.empty())
            std::cout << RED "Please, type a first name." RESET << std::endl;
    }
    this->_contact[index].setName(content);
    content.clear();

    while (content.empty())
    {
        std::cout << BRIGHT_MAGENTA "Enter last name: " RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1)
            return ;
        if (content.empty())
            std::cout << RED "Please, type a last name." RESET << std::endl;
    }
    this->_contact[index].setLast(content);
    content.clear();

    while (content.empty())
    {
        std::cout << BRIGHT_MAGENTA "Enter nickname: " RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1)
            return ;
        if (content.empty())
            std::cout << RED "Please, type a nickname." RESET << std::endl;
    }
    this->_contact[index].setNickname(content);
    content.clear();

    while (content.empty())
    {
        std::cout << BRIGHT_MAGENTA "Enter darkest secret: " RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1)
            return ;
        if (content.empty())
            std::cout << RED "Please, type a darkest secret." RESET << std::endl;
    }
    this->_contact[index].setSecret(content);
    content.clear();

    while (content.empty() || !valid_number)
    {
        valid_number = true;
        std::cout << BRIGHT_MAGENTA "Enter number: " RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1) 
            return ;
        for (size_t i = 0; i < content.size(); i++)
        {
            if (!isdigit(content[i]))
            {
                valid_number = false;
                std::cout << RED "Just numbers! ";
                break;
            }
        }
        if (content.empty() || !valid_number)
            std::cout << BRIGHT_RED "Please, type a valid number." RESET << std::endl;
    }
    this->_contact[index].setNumber(content);
    content.clear();
    _contactCount++;
}

void PhoneBook::searchContact(void)
{
    std::string content;
    int         valid_index;
    int         max_display;

    valid_index = -1;
    if (_contactCount == 0)
    {
        std::cout << BRIGHT_RED << "PhoneBook is empty." << RESET << std::endl;
        return;
    }
    
    utilsHeaderSearch();
    max_display = (_contactCount > 8) ? 8 : _contactCount;
    utilsPrintContacts(max_display);
    std::cout << "" << std::endl;

    while (valid_index == -1 || content.empty())
    {
        std::cout << "Type the index of the contact: " << RESET;
        std::getline(std::cin, content);
        if (std::cin.sync() == -1)
            return ;
        if (content.empty())
        {
            std::cout << BRIGHT_RED << "Please, type a valid index." << RESET << std::endl;
            continue;
        }
        valid_index = this->convertInt(content);
        if (valid_index < 1 || valid_index > max_display)
        {
            std::cout << BRIGHT_RED << "Invalid index. Please enter a number between 1 and " << max_display << "." << RESET << std::endl;
            valid_index = -1;
            continue;
        }
        utilsDisplayDetails(valid_index);
    }
}

void PhoneBook::exit(void)
{
    std::cout << BRIGHT_GREEN "*******************************" << std::endl;
    std::cout << BRIGHT_GREEN "* Exiting PhoneBook. Goodbye! *" RESET << std::endl;
    std::cout << BRIGHT_GREEN "*******************************" << std::endl;
    std::exit(0);
}

/* Utils for print display Header, contacts and details */

void PhoneBook::utilsHeaderSearch(void)
{
    std::cout << BRIGHT_MAGENTA "    ***********************************************" << std::endl;
    std::cout << BRIGHT_MAGENTA "    *********      PHONEBOOK          *************" << std::endl;
    std::cout << BRIGHT_MAGENTA "    ***********************************************" << std::endl;
    
    std::cout << BRIGHT_CYAN "    Index  " << "|";
    std::cout << BRIGHT_CYAN "    Name    " << "|";
    std::cout << BRIGHT_CYAN "  LastName  " << "|";
    std::cout << BRIGHT_CYAN " Nickname  " << " | " << RESET << std::endl;
}

void PhoneBook::utilsPrintContacts(int max_display) const
{
    for (int i = 0; i < max_display; i++)
    {
        std::cout <<std::setw(10) << (i + 1) << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncName() << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncLast() << " | ";
        std::cout <<std::setw(10) << this->_contact[i].getTruncNick() << " | " << std::endl;
    }
}

void PhoneBook::utilsDisplayDetails(int valid_index)
{
    std::cout << BRIGHT_GREEN "*****************************" << std::endl;
        std::cout << BRIGHT_GREEN << "**** Details contact [" << valid_index << "] ****" << std::endl;
        std::cout << BRIGHT_GREEN "*****************************" << std::endl;

        std::cout << BRIGHT_MAGENTA "Name: " RESET << this->_contact[valid_index - 1].getName() << std::endl;
        std::cout << BRIGHT_MAGENTA "Last name: " RESET << this->_contact[valid_index - 1].getLast() << std::endl;
        std::cout << BRIGHT_MAGENTA "Nickname: " RESET << this->_contact[valid_index - 1].getNick() << std::endl;
        std::cout << BRIGHT_MAGENTA "DarkestSecret: " RESET << this->_contact[valid_index - 1].getSecret() << std::endl;
        std::cout << BRIGHT_MAGENTA "Number: " RESET << this->_contact[valid_index - 1].getNumber() << std::endl;
}

void PhoneBook::utilsHeader(void)
{
    std::cout << BRIGHT_MAGENTA "*************" << std::endl;
    std::cout << BRIGHT_MAGENTA "* PHONEBOOK *" << std::endl;
    std::cout << BRIGHT_MAGENTA "*************" << std::endl;
    std::cout << BRIGHT_MAGENTA "* 1. ADD    *" << std::endl;
    std::cout << BRIGHT_MAGENTA "* 2. SEARCH *" << std::endl;
    std::cout << BRIGHT_MAGENTA "* 3. EXIT   *" << std::endl;
    std::cout << BRIGHT_MAGENTA "*************" RESET << std::endl;
    std::cout << BRIGHT_MAGENTA "Type your choice: " RESET;
}

/* Convert string to Int and check double index and letters in index input*/

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
            std::cout << BRIGHT_RED << "Just numbers, please." << RESET << std::endl;
            return (-1);
        }
        if (has_space)
        {
            std::cout << BRIGHT_RED << "One number, please." << RESET << std::endl;
            return (-1);
        }
        has_digit = true;
    }
    const char* c_str = content.c_str();
    number = atoi(c_str);
    return number;
}
