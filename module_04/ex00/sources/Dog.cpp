/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 17:15:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::Dog(void): Animal("Dog")
{
    std::cout << BRIGHT_BLUE "Dog: constructor called!" RESET << std::endl;
}

Dog::~Dog(void)
{
    std::cout << BRIGHT_BLUE "Dog: destructor called!" RESET << std::endl;
}

Dog::Dog(const Dog &other)
{
    std::cout << BRIGHT_BLUE "Dog: Copy constructor called." RESET << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << BRIGHT_BLUE "Dog: assignment operator called." RESET << std::endl;
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