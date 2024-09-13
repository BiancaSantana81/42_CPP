/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:04:38 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/13 16:41:13 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
# include<string>
#include <stdlib.h>
#include "colors.hpp"

class Contact
{
    private:

    std::string _name;
    std::string _lastName;
    std::string _nickname;
    std::string _darkestSecret;
    std::string _phoneNumber;
    std::string truncateString(std::string content) const;

    public:

    /* Functions constructor and destructor */

    Contact();
    ~Contact();

    /* Functions for get values */
    std::string getName() const;
    std::string getLast() const;
    std::string getNick() const;
    std::string getSecret() const;
    std::string getNumber() const;

    /* Functions for set values */
    void setName(std::string &newName);
    void setLast(std::string &newLastName);
    void setNickname(std::string &newNickname);
    void setSecret(std::string &darkestSecret);
    void setNumber(std::string &newNumber);

    /* Functions for get values truncate */
    std::string getTruncName(void) const;
    std::string getTruncLast(void) const ;
    std::string getTruncNick(void) const;

};

#endif