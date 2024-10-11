/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:51:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/11 09:14:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Cure.hpp"
#include "includes/Ice.hpp"
#include "includes/IMateriaSource.hpp"
#include "includes/MateriaSource.hpp"

#include "tests/Gem.hpp"
#include "tests/Future.hpp"
#include "tests/Electro.hpp"

#define CYAN   "\033[96m"
#define RESET   "\033[0m"

int main(void)
{
    std::cout << CYAN "============ ADDITIONAL TESTS ============" RESET << std::endl;

    std::cout << CYAN "==== Test 1: Creating a new character ===" RESET << std::endl;
    ICharacter *newPeople = new Gem("Garnet");
    
    // Creating a learning bag for the character

    IMateriaSource *bag = new MateriaSource();
    bag->learnMateria(new Future());
    bag->learnMateria(new Electro());
    bag->learnMateria(new Ice());
    bag->learnMateria(new Cure());

    // Adding materials to the character's bag

    AMateria *tmp;
    tmp = bag->createMateria("psychic");
    newPeople->equip(tmp);
    tmp = bag->createMateria("electro");
    newPeople->equip(tmp);
    tmp = bag->createMateria("ice");
    newPeople->equip(tmp);
    tmp = bag->createMateria("cure");
    newPeople->equip(tmp);

    std::cout << CYAN "==== Test 2: Character using the materials acquired ===" RESET << std::endl;

    newPeople->use(0, *newPeople);
    newPeople->use(1, *newPeople);
    newPeople->use(2, *newPeople);
    newPeople->use(3, *newPeople);

    std::cout << CYAN "==== Test 3: Deep character copy ===" RESET << std::endl;
    ICharacter *copyOfNewPeople = new Gem(*static_cast<Gem*>(newPeople));
    copyOfNewPeople->use(0, *copyOfNewPeople);

    std::cout << CYAN "==== Test 4: Character unequips items from bag ===" RESET << std::endl;
    newPeople->unequip(2);
    newPeople->use(2, *newPeople);

    std::cout << CYAN "==== Test 5: Attempting to add materials beyond capacity ===" RESET << std::endl;
    for (int i = 0; i < 5; ++i)
    { 
        AMateria* materia = bag->createMateria("psychic");
        newPeople->equip(materia);
    }

    std::cout << CYAN "==== Test 6: Character re-acquires a material that has been unequipped ===" RESET << std::endl;
    newPeople->unequip(2);
    newPeople->reequip("psychic", 2);

    delete newPeople;
    delete bag;
    delete copyOfNewPeople;

    return (0);
}