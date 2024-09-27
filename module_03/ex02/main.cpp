/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/27 17:04:22 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    // hello ex02
    return (0);
}

