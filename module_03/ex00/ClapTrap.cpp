/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:49 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/25 19:00:45 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap(std:: string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap: Default constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap: Destructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap: Copy constructor called." << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        _name = other.getName();
        _hitPoints = other.getHit();
        _energyPoints = other.getEnergy();
        _attackDamage = other.getDamage();
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

int ClapTrap::getHit() const
{
    return (this->_hitPoints);
}

int ClapTrap::getEnergy() const
{
    return (this->_energyPoints);
}

int ClapTrap::getDamage() const
{
   return (this->_attackDamage);
}

/* SETTERS */

void ClapTrap::setName(std::string newName)
{
    this->_name = newName;
}
void ClapTrap::setHit(int newHit)
{
    this->_hitPoints = newHit;
}
void ClapTrap::setEnergy(int newEnergy)
{
    this->_energyPoints = newEnergy;
}
void ClapTrap::setDamage(int newDamage)
{
    this->_attackDamage = newDamage;
}

/* Functions game */

void ClapTrap::attack(const std::string &target)
{
   if (this->_hitPoints <= 0 && this->_energyPoints <= 0) {
	std::cout << BRIGHT_RED "YOU'RE A DEAD PERSON!!!" RESET << std::endl;
	return ;
   }
   else if (this->_energyPoints <= 0) {
        std::cout << BRIGHT_RED "You're out of energy points! Go and rest before entering combat." RESET << std::endl;
        return ;
   }
   else if (this->_hitPoints <= 0) {
        std::cout << BRIGHT_RED "You're dead! Are you sure you want to keep fighting?" RESET << std::endl;
        return ;
   }
    this->_energyPoints--;
    std::cout << "ClapTrap " << getName() << " attacked! Causing " << this->getDamage() << " points of damage to " << target << "." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    this->_hitPoints -= amount;
    std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    (void)amount;
    std::cout << "ClapTrap " << getName() << " repairs " << amount << " hit points!" << std::endl;
}
