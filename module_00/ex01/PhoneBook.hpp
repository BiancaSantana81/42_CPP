/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 11:53:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
# include<string>

#include "Contact.hpp"

class PhoneBook
{
    public:

    PhoneBook( void );
    ~PhoneBook( void );

    private:

    static const int MAX_CONTACTS = 8;
    Contact _contacts[MAX_CONTACTS];
};

#endif