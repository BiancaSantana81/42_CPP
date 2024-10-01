/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 15:35:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void)
{
    std::cout << "Dog: constructor called!!" << std::endl;
    this->_type = "Dog";
}

Dog::~Dog(void)
{
    std::cout << "Dog: destructor called!" << std::endl;
}

Dog::Dog(const Dog &other)
{
    std::cout << "Dog: Copy constructor called." << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog: assignment operator called." << std::endl;
    if (this != &other)
        _type = other._type;
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}