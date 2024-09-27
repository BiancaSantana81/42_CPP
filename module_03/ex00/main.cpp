/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 12:08:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void seePoints(ClapTrap *clap)
{
    std::cout << "*** " << clap->getName() << " ***" << std::endl;
    std::cout << "HitPoints: " << clap->getHitPoints()  << std::endl;
    std::cout << "EnergyPoints: " << clap->getEnergyPoints()  << std::endl;
    std::cout << "AtacckDamage: " << clap->getDamagePoints()  << std::endl;
    std::cout << "*****************"  << std::endl;
}

int main(void)
{
    ClapTrap clap1 ("Daniel");
    ClapTrap clap2 ("Ricardo");

    std::cout << BRIGHT_MAGENTA "=== Test 1: ClapTrap attacks with enough energy and hit points ===\n" RESET;
    clap1.attack(clap2.getName());
    seePoints(&clap1);

    std::cout << BRIGHT_MAGENTA "=== Test 2: Daniel attacks Ricardo and deals 4 points of damage ===\n" RESET;
    clap1.setDamagePoints(5);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getDamagePoints());
    seePoints(&clap1);
    seePoints(&clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 3: Ricardo regains 5 life points ===\n" RESET;
    clap2.beRepaired(5);
    seePoints(&clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 4: Ricardo receives 11 points of damage, which kills him ===\n" RESET;
    clap1.setDamagePoints(11);
    clap2.takeDamage(clap1.getDamagePoints());
    seePoints(&clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 5: Ricardo tries to attack after dying ===\n" RESET;
    clap2.attack("Another Enemy");
    seePoints(&clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 6: Ricardo tries to make amends after his death ===\n" RESET;
    clap2.beRepaired(5);
    seePoints(&clap2);

    ClapTrap clap3("Bob");
    std::cout << BRIGHT_MAGENTA "=== Test 7: ClapTrap Bob attacks until it runs out of energy ===\n" RESET;
    for (int i = 0; i < 11; i++)
        clap3.attack("Enemy");
    seePoints(&clap3);

    std::cout << BRIGHT_MAGENTA "=== Test 8: ClapTrap Bob tries to attack again without energy  ===\n" RESET;
    clap3.attack("Enemy");
    seePoints(&clap3);

    std::cout << BRIGHT_MAGENTA "=== Test 9: ClapTrap Bob tries to repair itself without power ===\n" RESET;
    clap3.beRepaired(5);
    seePoints(&clap3);

    return (0);
}