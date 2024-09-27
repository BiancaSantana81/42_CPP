/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 16:47:59 by bsantana         ###   ########.fr       */
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

    std::cout << BRIGHT_YELLOW "=== Test 1: Scav João attack ===\n" RESET << std::endl;
    scav1.attack(scav2.getName());
    scav2.takeDamage(scav1.getDamagePoints());
    seePoints(&scav2);
    
    std::cout << BRIGHT_YELLOW "=== Test 2: Roberto GuardMode ===" RESET << std::endl;
    scav2.guardGate();

    std::cout << BRIGHT_YELLOW "=== Test 3: ScavTrap Roberto regaining life points ===" RESET << std::endl;
    scav2.beRepaired(30);
    seePoints(&scav2);

    std::cout << BRIGHT_YELLOW "=== Test 4: Testing the copy constructor ===" RESET << std::endl;
    ScavTrap scavCopy1(scav2);
    seePoints(&scavCopy1);

    std::cout << BRIGHT_YELLOW "=== Test 5: Testing the Copy assignment operator ===" RESET << std::endl;
    ScavTrap scavCopy2("João Copy");
    
    scavCopy2 = scav1;
    seePoints(&scavCopy2);

    return (0);
}
