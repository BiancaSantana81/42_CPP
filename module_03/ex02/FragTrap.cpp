/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:01:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/30 11:17:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

/* CONSTRUCTORS AND COPY ASSIGNMENT OPERATOR */

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << BRIGHT_RED "FragTrap: " RESET << _name << " Default constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
     std::cout << BRIGHT_RED "FragTrap:" RESET << "Copy constructor called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setDamagePoints(other.getDamagePoints());
	}
	return *this;
}

/* FUNCTIONS GAME */

void FragTrap::highFivesGuys(void)
{
    std::cout << BRIGHT_RED "FragTrap: " RESET << this->getName() << " requests high fives!" << std::endl;
}

/* DESTRUCTOR */

FragTrap::~FragTrap(void)
{
    std::cout << BRIGHT_RED "FragTrap: " RESET << _name << " Destructor called." << std::endl;
}
