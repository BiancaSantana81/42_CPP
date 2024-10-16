/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:32:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/16 15:50:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

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
