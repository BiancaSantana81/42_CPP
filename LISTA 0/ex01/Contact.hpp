/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:04:38 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/04 17:55:15 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
# include<string>

class Contact
{
    private:

    std::string name;
    std::string lastName;
    std::string nickname;
    std::string darkestSecret;
    int         phoneNumber;

    public:

    /* Functions constructor and destructor */
        
    Contact( void );
    ~Contact( void );

    /* Functions for get values */
    
    std::string getName(void);
    std::string getLast(void);
    std::string getNick(void);
    int         getNumber(void);

    /* Functions for set values */
};

#endif
