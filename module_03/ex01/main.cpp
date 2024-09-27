/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 16:42:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void seePoints(ScavTrap *scav)
{
    std::cout << "*** " << scav->getName() << " ***" << std::endl;
    std::cout << "HitPoints: " << scav->getHitPoints()  << std::endl;
    std::cout << "EnergyPoints: " << scav->getEnergyPoints()  << std::endl;
    std::cout << "AtacckDamage: " << scav->getDamagePoints()  << std::endl;
    std::cout << "*****************"  << std::endl;
}

int main(void)
{
    ScavTrap scav1("João");
    ScavTrap scav2("Roberto");

    std::cout << "=== Test 1: Scav João attack ===\n" << std::endl;
    scav1.setDamagePoints(50);
    scav1.attack(scav2.getName());
    scav2.takeDamage(scav1.getDamagePoints());
    
    std::cout << "=== Test 2: Roberto GuardMode ===" << std::endl;
    scav2.guardGate();

    std::cout << "=== Test 3: ScavTrap Roberto regaining life points ===" << std::endl;
    scav2.beRepaired(30);
    seePoints(&scav2);

    std::cout << "=== Test 4: Testing the copy constructor ===" << std::endl;
    ScavTrap scavCopy1(scav2);
    seePoints(&scavCopy1);

    std::cout << "=== Test 5: Testing the Copy assignment operator ===" << std::endl;
    ScavTrap scavCopy2("João Copy");
    
    scavCopy2 = scav1;
    seePoints(&scavCopy2);

    return (0);
}
