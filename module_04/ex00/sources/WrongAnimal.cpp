/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:13:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 18:26:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"

/* CONSTRUCTOR AND COPY ASSIGNMENT */

WrongAnimal::WrongAnimal(void): _type("WrongAnimal")
{
    std::cout << BRIGHT_MAGENTA "WrongAnimal: constructor called!" RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal: " << this->_type << " default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << BRIGHT_MAGENTA "WrongAnimal: Copy constructor called." RESET << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << BRIGHT_MAGENTA "WrongAnimal: assignment operator called." RESET << std::endl;
    if (this != &other)
        _type = other._type;
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

/* DESTRUCTOR */

WrongAnimal::~WrongAnimal(void)
{
    std::cout << BRIGHT_MAGENTA "WrongAnimal: destructor called!" RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}

/* FUNCTION MAKE SOUND */

void WrongAnimal::makeSound(void) const
{
    std::cout << BRIGHT_RED "The wrong animal!"  RESET << std::endl;
}