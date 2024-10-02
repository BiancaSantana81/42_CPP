/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:13:09 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 15:06:54 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
    std::cout << BRIGHT_MAGENTA "WrongCat: constructor called!" RESET << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << BRIGHT_MAGENTA "WrongCat: destructor called!" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
    std::cout << BRIGHT_MAGENTA "WrongCat: Copy constructor called." RESET << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << BRIGHT_MAGENTA "WrongCat: assignment operator called." RESET << std::endl;
    if (this != &other)
        _type = other._type;
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "$@#*&?!" << std::endl;
}
