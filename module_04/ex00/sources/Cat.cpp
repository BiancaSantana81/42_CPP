/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/01 17:29:17 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << BRIGHT_YELLOW "Cat: constructor called!" RESET << std::endl;
}

Cat::~Cat(void)
{
    std::cout << BRIGHT_YELLOW "Cat: destructor called!" RESET << std::endl;
}

Cat::Cat(const Cat &other)
{
    std::cout << BRIGHT_YELLOW "Cat: Copy constructor called." RESET << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << BRIGHT_YELLOW "Cat: assignment operator called." RESET << std::endl;
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
