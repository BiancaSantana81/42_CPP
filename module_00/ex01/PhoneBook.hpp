/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:37 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/11 15:50:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include<string>
#include <stdlib.h>
#include <iomanip>

#include "Contact.hpp"
#include "colors.hpp"

class PhoneBook
{
    public:

    PhoneBook(void);
    ~PhoneBook(void);
    void addContact(void);
    void searchContact(void);
    int convertInt(std::string content);

    private:

    static const int MAX_CONTACTS = 8;
    Contact _contact[MAX_CONTACTS];
    int     _contactCount;
};

#endif