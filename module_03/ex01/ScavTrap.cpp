/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:11 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 16:44:31 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp" 

/* CONSTRUCTORS */

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << BRIGHT_CYAN "ScavTrap: " RESET << _name << " Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << BRIGHT_CYAN "ScavTrap:" RESET << "Copy constructor called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
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

/* GETTERS */

std::string ScavTrap::getName() const
{
    return (this->_name);
}

int ScavTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

int ScavTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

int ScavTrap::getDamagePoints() const
{
   return (this->_attackDamage);
}

/* SETTERS */

void ScavTrap::setName(std::string newName)
{
    this->_name = newName;
}

void ScavTrap::setHitPoints(int newHit)
{
    this->_hitPoints = newHit;
}

void ScavTrap::setEnergyPoints(int newEnergy)
{
    this->_energyPoints = newEnergy;
}

void ScavTrap::setDamagePoints(int newDamage)
{
    this->_attackDamage = newDamage;
}


/* Functions game */

void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0) {
        std::cout << BRIGHT_CYAN "Scav: " << getName() << BRIGHT_RED " You're out of energy points! Go and rest before entering combat." RESET << std::endl;
        return ;
   }
   if (this->_hitPoints <= 0) {
        std::cout << BRIGHT_CYAN "Scav: " << getName() << BRIGHT_RED " You're dead! Are you sure you want to keep fighting?" RESET << std::endl;
        return ;
   }
   else
   {
        this->_energyPoints--;
        std::cout << BRIGHT_CYAN "Scav " RESET << getName() << " attacked! Causing " << this->getDamagePoints() << " points of damage to " << target << "." << std::endl;
   }
}


void ScavTrap::guardGate()
{
    std::cout << BRIGHT_CYAN "ScavTrap " RESET << this->getName() << " now he's got his guard up!" << std::endl;
}

/* DESTRUCTOR */

ScavTrap::~ScavTrap()
{
    std::cout << BRIGHT_CYAN "ScavTrap: " RESET << _name << " Destructor called." << std::endl;
}