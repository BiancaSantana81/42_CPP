/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/30 11:26:52 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void seePoints(FragTrap *guy)
{
    std::cout << "*** " << guy->getName() << " ***" << std::endl;
    std::cout << "HitPoints: " << guy->getHitPoints()  << std::endl;
    std::cout << "EnergyPoints: " << guy->getEnergyPoints()  << std::endl;
    std::cout << "AtacckDamage: " << guy->getDamagePoints()  << std::endl;
    std::cout << "*****************"  << std::endl;
}

int main(void)
{
    FragTrap frag1("Maria");
    FragTrap frag2("Eduarda");

    std::cout << BRIGHT_GREEN "========= Initial player info =========\n" RESET << std::endl;
    seePoints(&frag1);
    seePoints(&frag2);
    std::cout << BRIGHT_GREEN "=======================================" RESET << std::endl;

    std::cout << BRIGHT_YELLOW "=== Test 1: Frag Maria attack Eduarda ===\n" RESET << std::endl;
    frag1.attack(frag2.getName());
    frag2.takeDamage(frag1.getDamagePoints());
    seePoints(&frag1);
    seePoints(&frag2);
    
    std::cout << BRIGHT_YELLOW "=== Test 2: Frag Eduarda regaining life points ===" RESET << std::endl;
    frag2.beRepaired(30);
    seePoints(&frag2);

    std::cout << BRIGHT_YELLOW "\n=== Test 3: Maria asks for a high five ===\n" RESET << std::endl;
    frag1.highFivesGuys();

    return (0);
}
