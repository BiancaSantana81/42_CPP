/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 10:33:42 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 17:01:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

/* CONSTRUCTORS */

Cure::Cure(void): AMateria("Cure")
{
    return ;
}

Cure::Cure(const Cure &other): AMateria(other)
{
    return ;
}

Cure &Cure::operator=(const Cure &other)
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

AMateria *Cure::clone(void) const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds with positive energy *" << std::endl;
}

/* DESTRUCTOR */

Cure::~Cure(void)
{
    return ;
}