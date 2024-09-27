/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 16:46:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "string"
#include "iostream"

#include "ClapTrap.hpp" 

class ScavTrap: public ClapTrap
{
    public:
    
    ScavTrap(std::string name); // Construtor padrão
    ScavTrap(const ScavTrap &other); // Construtor de cópia
    ScavTrap &operator=(const ScavTrap &other); // Atribuição por cópia
    ~ScavTrap();  // Destrutor padrão

    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getDamagePoints() const;
    void setName(std::string newName);
    void setHitPoints(int newHit);
    void setEnergyPoints(int newEnergy);
    void setDamagePoints(int newDamage);
    
    void attack(const std::string &target);
    void guardGate();
};

#endif