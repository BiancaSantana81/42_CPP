/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:51:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 13:48:22 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

#include "Gem.hpp"
#include "Future.hpp"
#include "Electro.hpp"

#define CYAN   "\033[96m"
#define RESET   "\033[0m"

int main(void)
{
    std::cout << CYAN "============ ADDITIONAL TESTS ============" RESET << std::endl;

    std::cout << CYAN "==== Tests 1: Criando um novo personagem ===" RESET << std::endl;
    ICharacter *newPeople = new Gem("Garnet");
    (void)newPeople;
    
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


    std::cout << CYAN "==== Tests 3: Personagem usando as materias adquiridas ===" RESET << std::endl;

    newPeople->use(0, *newPeople);
    newPeople->use(1, *newPeople);
    newPeople->use(2, *newPeople);
    newPeople->use(3, *newPeople);

    std::cout << CYAN "==== Tests 2: Cópia profunda dos personagem ===" RESET << std::endl;
    ICharacter *copyOfNewPeople = new Gem(*static_cast<Gem*>(newPeople));
    copyOfNewPeople->use(0, *copyOfNewPeople);

    std::cout << CYAN "==== Tests 4: Personagem desequipa matérias da bag ===" RESET << std::endl;
    newPeople->unequip(2);
    newPeople->use(2, *newPeople);

    std::cout << CYAN "==== Tests 9: Tentativa de adicionar materiais além da capacidade ===" RESET << std::endl;
    for (int i = 0; i < 5; ++i)
    { 
        AMateria* materia = bag->createMateria("psychic");
        newPeople->equip(materia);
    }

    std::cout << CYAN "==== Tests 9: Personagem adquiri novamente uma materia que foi desquipada ===" RESET << std::endl;
    newPeople->unequip(2);
    newPeople->reequip("psychic", 2);

    delete newPeople;
    delete bag;
    delete copyOfNewPeople;

    return (0);
}