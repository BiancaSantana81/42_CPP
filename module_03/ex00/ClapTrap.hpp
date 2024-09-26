/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:10:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/26 16:11:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_MAGENTA "\033[95m"
#define RESET   "\033[0m"

class ClapTrap
{
    private:

    std::string _name;
    int         _hitPoints; // Pontos de vida (10)
    int         _energyPoints; // Pontos de energia (10)
    int         _attackDamage; // Dano de ataque (0)

    public:

    /*Constructors and Destructor*/

    ClapTrap(); // Construtor padrão
    ~ClapTrap(); // Destrutor padrão
    ClapTrap(const ClapTrap &other); // Construtor de cópia
    ClapTrap &operator=(const ClapTrap &other); // Atribuição por cópia

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