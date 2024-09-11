/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:31:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/11 18:25:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Functions constructor and destructor */

Contact::Contact( void )
{
    return ;
}

/* Functions for get values */

Contact::~Contact( void )
{
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

std::string Contact::getNumber(void) const
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

void Contact::setNumber(std::string &newNumber)
{
    this->_phoneNumber = newNumber;
}

/* Functions for get values truncate */

std::string Contact::getTruncName(void)
{
    return trucateString(this->_name);
}

std::string Contact::getTruncLast(void)
{
    return trucateString(this->_lastName);
}

std::string Contact::getTruncNick(void)
{
    return trucateString(this->_nickname);
}

/* Utils for Contact */

std::string Contact::trucateString(std::string content)
{
    unsigned int length = 9;

    if (content.length() >= length)
        return (content.substr(0, length) + ".");
    return (content);
}
