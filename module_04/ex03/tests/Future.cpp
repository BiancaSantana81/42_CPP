/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Future.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:20:10 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 15:50:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"
#include "Future.hpp"

/* CONSTRUCTORS */

Future::Future(void): AMateria("psychic")
{
    return ;
}

Future::Future(const Future &other): AMateria(other)
{
    return ;
}

Future &Future::operator=(const Future &other)
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

AMateria *Future::clone(void) const
{
    return (new Future(*this));
}

void Future::use(ICharacter &target)
{
    std::cout << target.getName() << " saw your future and said: * I saw your future, and it is certainly bright! *" << std::endl;
}

/* DESTRUCTOR */

Future::~Future(void)
{
    return ;
}
