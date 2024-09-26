/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:09:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/26 18:00:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void seePoints(const ClapTrap &clap)
{
    std::cout << "*** " << clap.getName() << " ***" << std::endl;
    std::cout << "Name: " << clap.getName() << std:: endl;
    std::cout << "HitPoints: " << clap.getHitPoints()  << std::endl;
    std::cout << "EnergyPoints: " << clap.getEnergyPoints()  << std::endl;
    std::cout << "AtacckDamage: " << clap.getDamagePoints()  << std::endl;
    std::cout << "*****************"  << std::endl;
}

int main(void)
{
    ClapTrap clap1;
    ClapTrap clap2;

    clap1.setName("Daniel");
    clap2.setName("Ricardo");

    std::cout << BRIGHT_MAGENTA "=== Test 1: ClapTrap attacks with enough energy and hit points ===\n" RESET;
    clap1.attack(clap2.getName());
    seePoints(clap1);

    std::cout << BRIGHT_MAGENTA "=== Test 2: Daniel ataca Ricardo e causa 4 pontos de dano ===\n" RESET;
    clap1.setDamagePoints(5);
    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getDamagePoints());
    seePoints(clap1);
    seePoints(clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 3: Ricardo recupera 5 pontos de vida ===\n" RESET;
    clap2.beRepaired(5);
    seePoints(clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 4: Ricardo recebe 11 pontos de dano, o que o mata ===\n" RESET;
    clap1.setDamagePoints(11);
    clap2.takeDamage(clap1.getDamagePoints());
    seePoints(clap2);

    std::cout << BRIGHT_MAGENTA "=== Test 5: ClapTrap tenta atacar após ter morrido ===\n" RESET;
    clap2.attack("Outro Inimigo");
    seePoints(clap2);

    // std::cout << BRIGHT_MAGENTA "=== Test 6: Ricardo tenta se reparar após ter morrido ===\n" RESET;
    // clap2.beRepaired(5);
    // seePoints(clap2);

    //Teste 7: Criação de um novo ClapTrap "Bob" e gastar toda sua energia atacando
    ClapTrap clap3;
    clap3.setName("Bob");
    std::cout << BRIGHT_MAGENTA "=== Test 7: ClapTrap \"Bob\" ataca até ficar sem energia ===\n" RESET;
    for (int i = 0; i < 11; i++)
        clap3.attack("Enemy");
    seePoints(clap3);

    std::cout << BRIGHT_MAGENTA "=== Teste 8: ClapTrap \"Bob\" tenta atacar novamente sem energia ===\n" RESET;
    clap3.attack("Enemy");
    seePoints(clap3);

    std::cout << BRIGHT_MAGENTA "=== Teste 9: ClapTrap \"Bob\" tenta se reparar sem energia ===\n" RESET;
    clap3.beRepaired(5);
    seePoints(clap3);

    return (0);
}