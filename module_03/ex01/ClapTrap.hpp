/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/30 10:43:13 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN   "\033[96m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_GREEN  "\033[92m"
#define RESET   "\033[0m"

class ClapTrap
{
    protected:

    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

    public:

    /*Constructors and Destructor*/

    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);

    /* Getters */
    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getDamagePoints() const;

    /* Setters */
    void setName(std::string newName);
    void setHitPoints(int newHit);
    void setEnergyPoints(int newEnergy);
    void setDamagePoints(int newDamage);

    /* Functions game */

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif