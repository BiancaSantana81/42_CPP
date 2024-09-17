/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:39 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 15:29:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* Constructor and Destructor */

Weapon::Weapon(std::string type) : _type(type)
{
    std::cout << this->_type << ": created!" << std::endl;
}

Weapon::~Weapon(void)
{
    std::cout << this->_type << ": destroyed!" << std::endl;
}

/* Getter and Setter */

void Weapon::setType(std::string newType)
{
    this->_type = newType;
}

const std::string Weapon::getType(void) const
{
    return (this->_type);
}
