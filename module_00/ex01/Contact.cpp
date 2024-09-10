/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:31:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 12:13:53 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Functions constructor and destructor */

Contact::Contact( void )
{
    std::cout << "Constructor Contact called." << std::endl;
    return ;
}

/* Functions for get values */

Contact::~Contact( void )
{
    std::cout << "Destructor Contact called." << std::endl;
    return ;
}

std::string Contact::getName(void) const
{
    return (this->_name);
}

std::string Contact::getLast(void) const
{
    return (this->_lastName);
}

std::string Contact::getNick(void) const
{
    return (this->_nickname);
}

std::string Contact::getSecret(void) const
{
    return (this->_darkestSecret);
}

int Contact::getNumber(void) const
{
    return (this->_phoneNumber);
}

/* Functions for set values */

void Contact::setName(std::string &newName)
{
    this->_name = newName;
}

void Contact::setLast(std::string &newLastName)
{
    this->_lastName = newLastName;
}

void Contact::setNickname(std::string &newNick)
{
    this->_nickname = newNick;
}

void Contact::setSecret(std::string &newdarkestSecret)
{
    this->_darkestSecret = newdarkestSecret;
}

void Contact::setNumber(int &newNumber)
{
    this->_phoneNumber = newNumber;
}
