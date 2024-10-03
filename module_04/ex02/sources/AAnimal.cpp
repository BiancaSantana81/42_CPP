/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:33:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 13:44:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/* CONSTRUCTORS */

AAnimal::AAnimal(void) : _type("AAnimal")
{
    std::cout << "AAnimal: Default constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
    std::cout << "AAnimal: " << this->_type << " default constructor called." << std::endl;
} 

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal: Destructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal Copy constructor called." << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _type = other.getType();
    else
         std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

/* GETTER AND SETTER */

std::string AAnimal::getType(void) const
{
    return this->_type;
}

void AAnimal::setType(std::string newType)
{
    this->_type = newType;
}
