/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:34:09 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 13:29:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

/* CONSTRUCTORS */

Ice::Ice(void): AMateria("ice")
{
    return ;
}

Ice::Ice(const Ice &other): AMateria(other)
{
    return ;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

/* VIRTUAL FUNCTIONS */

AMateria *Ice::clone(void) const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

/* DESTRUCTOR */

Ice::~Ice(void)
{
    return ;
}