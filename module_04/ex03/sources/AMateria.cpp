/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:10 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 16:59:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

/* CONSTRUCTORS */

AMateria::AMateria(void): _type("Unknown")
{
    return ;
}

AMateria::AMateria(std::string const &type): _type(type)
{
   return ;
}

AMateria::AMateria(const AMateria &other): _type(other._type)
{
   return ;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this != &other)
    {
        _type = other._type;
    }
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET << std::endl;
    return (*this);
}

/* GETTER AND SETTER */

std::string const &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::setType(std::string newType)
{
    _type = newType;
}

/* FUNCTIONS */

void	AMateria::use(ICharacter &target)
{
	(void)target;
}


/* DESTRUCTOR */

AMateria::~AMateria(void)
{
    return ;
}
