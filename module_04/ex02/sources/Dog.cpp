/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:24:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 17:01:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

Dog::Dog(void): Animal("Dog"), _brain(new Brain())
{
    std::cout << BRIGHT_BLUE "Dog: constructor called!" RESET << std::endl;
    for (int i = 0;  i < 100; i++)
         _brain->setIdea(i, "I want meat!");
}

Dog::~Dog(void)
{
    std::cout << BRIGHT_BLUE "Dog: destructor called!" RESET << std::endl;
    delete _brain;
}

Dog::Dog(const Dog &other): Animal(other)
{
    std::cout << BRIGHT_BLUE "Dog: Copy constructor called." RESET << std::endl;
    _brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << BRIGHT_BLUE "Dog: assignment operator called." RESET << std::endl;
    if (this != &other)
    {
        _type = other._type;
        _brain = new Brain(*other._brain);
    }
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::printIdeas() const
{
    _brain->showIdeas();
}
