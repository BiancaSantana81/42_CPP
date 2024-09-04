/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:31:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/04 17:55:51 by bsantana         ###   ########.fr       */
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

std::string Contact::getName(void)
{
    return (name);
}

std::string Contact::getLast(void)
{
    return (lastName);
}

std::string Contact::getNick(void)
{
    return (nickname);
}

int Contact::getNumber(void)
{
    return (phoneNumber);
}

/* Functions for set values */

