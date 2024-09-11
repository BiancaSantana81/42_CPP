/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:37 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/10 19:01:40 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include<string>
#include <stdlib.h>
#include <iomanip> // adicionei para criar a minha planilha.

#include "Contact.hpp"
#include "colors.hpp"

class PhoneBook
{
    public:

    PhoneBook(void);
    ~PhoneBook(void);
    void addContact(void);
    void searchContact(void);

    private:

    static const int MAX_CONTACTS = 8;
    Contact _contact[MAX_CONTACTS];
    int     _contactCount;
};

#endif