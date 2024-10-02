/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:33:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 13:44:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/* CONSTRUCTORS */

Animal::Animal(void) : _type("Animal")
{
    std::cout << "Animal: Default constructor called." << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal: " << this->_type << " default constructor called." << std::endl;
} 

Animal::~Animal(void)
{
    std::cout << "Animal: Destructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal Copy constructor called." << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
        _type = other.getType();
    else
         std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

/* GETTER AND SETTER */

std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::setType(std::string newType)
{
    this->_type = newType;
}

/* Function sound animal */

void Animal::makeSound() const
{
    std::cout << "Sounds of an identified animal." << std::endl;
}
