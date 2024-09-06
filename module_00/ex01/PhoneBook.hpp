/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:10:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/05 13:27:29 by bsantana         ###   ########.fr       */
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
    Contact people[8];

};

#endif