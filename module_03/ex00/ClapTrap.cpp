/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/26 16:15:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap(): _name("Unknown"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap: Default constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    //std::cout << "ClapTrap: Copy constructor called." << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    //std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        _name = other.getName();
        _hitPoints = other.getHitPoints();
        _energyPoints = other.getEnergyPoints();
        _attackDamage = other.getDamagePoints();
    }
    else
        std::cout << BRIGHT_RED "Self-attribution detected! The objects already have the same address." RESET <<std::endl;
    return (*this);
}

/* GETTERS */

std::string ClapTrap::getName() const
{
    return (this->_name);
}

int ClapTrap::getHitPoints() const
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergyPoints() const
{
    return (this->_energyPoints);
}

int ClapTrap::getDamagePoints() const
{
   return (this->_attackDamage);
}

/* SETTERS */

void ClapTrap::setName(std::string newName)
{
    this->_name = newName;
}
void ClapTrap::setHitPoints(int newHit)
{
    this->_hitPoints = newHit;
}
void ClapTrap::setEnergyPoints(int newEnergy)
{
    this->_energyPoints = newEnergy;
}
void ClapTrap::setDamagePoints(int newDamage)
{
    this->_attackDamage = newDamage;
}

/* Functions game */

void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0) {
        std::cout << BRIGHT_RED "You're out of energy points! Go and rest before entering combat." RESET << std::endl;
        return ;
   }
   if (this->_hitPoints <= 0) {
        std::cout << BRIGHT_RED "You're dead! Are you sure you want to keep fighting?" RESET << std::endl;
        return ;
   }
   else
   {
        this->_energyPoints--;
        std::cout << "ClapTrap " << getName() << " attacked! Causing " << this->getDamagePoints() << " points of damage to " << target << "." << std::endl;
   }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0)
    {
        std::cout << "ClapTrap " << getName() << " is already dead!" << std::endl;
        return;
    }
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    if (this->_hitPoints <= 0)
        std::cout << "ClapTrap " << this->_name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0)
    {
        std::cout << BRIGHT_RED "ClapTrap " << getName() << " has no energy left to repair!" RESET << std::endl;
        return ;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
}
