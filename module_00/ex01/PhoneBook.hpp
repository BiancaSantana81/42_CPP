/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:01:37 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 11:37:04 by bsantana         ###   ########.fr       */
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
    void exit(void);
    int convertInt(std::string content);

    /* Utils for print display Header, contacts and details */
    
    void utilsHeader(void);
    void utilsHeaderSearch(void);
    void utilsPrintContacts(int max_display) const;
    void utilsDisplayDetails(int valid_index);

    private:

    static const int MAX_CONTACTS = 8;
    Contact _contact[MAX_CONTACTS];
    int     _contactCount;
};

#endif