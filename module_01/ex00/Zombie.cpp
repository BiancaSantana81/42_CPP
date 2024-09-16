/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:42:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 17:38:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* Constructor and Destructor */

Zombie::Zombie(void)
{
    return ;
}

Zombie::~Zombie( void )
{
    return ;
}

/* Zombie class functions */

void Zombie::announce(void)
{
    std:: cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Getters and setters */

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::setName(const std::string &newName)
{
    this->_name = newName;
}
