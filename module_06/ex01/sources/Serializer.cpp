/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 11:17:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/* 
   reinterpret_cast allows conversion between unrelated types, such as between (void*) and int. 
   This type of conversion is useful for manipulating pointers or accessing low-level data.
   However, it should be used with extreme caution, as it can cause undefined behaviour 
   and errors that are difficult to detect (such as a segmentation fault in test 5 of my programme). 
   In test 5, an invalid pointer conversion was performed, resulting in an invalid 
   address that cannot be accessed safely.
*/

/* CONSTRUCTORS */

Serializer::Serializer(void)
{
    std::cout << "Default constructor called." << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor called." << std::endl;
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    return (*this);
}

/* TYPE CONVERSION METHODS */

uintptr_t Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

/* DESTRUCTOR */

Serializer::~Serializer(void)
{
    std::cout << "Default destructor called." << std::endl;
}
