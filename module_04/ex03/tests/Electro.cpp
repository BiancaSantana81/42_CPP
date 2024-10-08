/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Electro.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:32:33 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 15:52:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include "Electro.hpp"

/* CONSTRUCTORS */

Electro::Electro(void): AMateria("electro")
{
    return ;
}

Electro::Electro(const Electro &other): AMateria(other)
{
    return ;
}

Electro &Electro::operator=(const Electro &other)
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

AMateria *Electro::clone(void) const
{
    return (new Electro(*this));
}

void Electro::use(ICharacter &target)
{
    std::cout << target.getName() << " shot lightning and said: * A little energy is always nice! * " << std::endl;
}

/* DESTRUCTOR */

Electro::~Electro(void)
{
    return ;
}
