/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 17:01:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"

Cat::Cat(void) : Animal("Cat"), _brain(new Brain())
{
    std::cout << BRIGHT_YELLOW "Cat: constructor called!" RESET << std::endl;
    for (int i = 0;  i < 100; i++)
         _brain->setIdea(i, "I want fish!");
}

Cat::~Cat(void)
{
    std::cout << BRIGHT_YELLOW "Cat: destructor called!" RESET << std::endl;
    delete _brain;
}

Cat::Cat(const Cat &other): Animal(other)
{
    std::cout << BRIGHT_YELLOW "Cat: Copy constructor called." RESET << std::endl;
    _brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << BRIGHT_YELLOW "Cat: assignment operator called." RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

void Cat::printIdeas() const
{
    _brain->showIdeas();
}
