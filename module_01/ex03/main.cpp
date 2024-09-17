/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:35 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 16:37:37 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"
#include "defines.hpp"

int main(void)
{
    /* Test 1: HumanA is created with your weapon */
    {
        std::cout << RED "*****************************" RESET << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    /* Test 2: HumanB is created and then picks up his weapon */
    {
        std::cout << RED "*****************************" RESET << std::endl;
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    /* Test 3: HumanB can be raised and attack without a weapon */
    {
        std::cout << RED "*****************************" RESET << std::endl;
        HumanB alice("Alice");
        alice.attack(); // Alice attacks with nothing
    }
    // Teste 5: Combat!
    {
        std::cout << RED "*****************************" << std::endl;
        std::cout << "A REAL FIGTH!" RESET << std::endl;
        /* HumanA attacks with gun and HumanB unarmed */
        Weapon chair = Weapon("chair");
        HumanA helena("Helena", chair);
        HumanB alice("Alice");
        helena.attack();
        alice.attack();
        /* Helena and Alice change weapons */
        Weapon flipFlops = Weapon("flipFlops");
        flipFlops.setType("flipFlops");
        alice.setWeapon(flipFlops);
        alice.attack();
        helena.attack();
    }
    return (0);
}

// int main()
// {
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanA bob("Bob", club);
//         bob.attack();
//         club.setType("some other type of club");
//         bob.attack();
//     }
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanB jim("Jim");
//         jim.setWeapon(club);
//         jim.attack();
//         club.setType("some other type of club");
//         jim.attack();
//     }
//     return (0);
// }