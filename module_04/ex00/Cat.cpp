/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 15:35:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void)
{
    std::cout << "Cat: constructor called!!" << std::endl;
    this->_type = "Cat";
}

Cat::~Cat(void)
{
    std::cout << "Cat: destructor called!" << std::endl;
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat: Copy constructor called." << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat: assignment operator called." << std::endl;
    if (this != &other)
        _type = other._type;
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
