/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:51:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 16:10:56 by bsantana         ###   ########.fr       */
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
    
    std::cout << CYAN "==== Tests 2: Criando bag de aprendizados para o personagem ===" RESET << std::endl;

    IMateriaSource *bag = new MateriaSource();
    bag->learnMateria(new Future());
    bag->learnMateria(new Electro());
    bag->learnMateria(new Ice());
    bag->learnMateria(new Cure());

    std::cout << CYAN "==== Tests 3: Adicionando mateŕias na bag do personagem ===" RESET << std::endl;
    AMateria *tmp;
    tmp = bag->createMateria("psychic");
    newPeople->equip(tmp);
    tmp = bag->createMateria("electro");
    newPeople->equip(tmp);
    tmp = bag->createMateria("ice");
    newPeople->equip(tmp);
    tmp = bag->createMateria("cure");
    newPeople->equip(tmp);

    std::cout << CYAN "==== Tests 4: Personagem usando as materias adquiridas ===" RESET << std::endl;

    newPeople->use(0, *newPeople);
    newPeople->use(1, *newPeople);
    newPeople->use(2, *newPeople);
    newPeople->use(3, *newPeople);

    // std::cout << CYAN "==== Tests 5: Personagem desequipa matérias da bag ===" RESET << std::endl;

    // std::cout << CYAN "==== Tests 6: Cópia profunda dos personagem  ===" RESET << std::endl;

     std::cout << CYAN "==== Tests 5: Personagem desequipa matérias da bag ===" RESET << std::endl;
    // newPeople->unequip(2); // Remove a matéria na posição 2 (Ice)
    // newPeople->use(2, *newPeople); // Tentativa de usar a matéria na posição 2 (agora deve ser nula)

    std::cout << CYAN "==== Tests 6: Cópia profunda dos personagem ===" RESET << std::endl;
    ICharacter *copyOfNewPeople = new Gem(*static_cast<Gem*>(newPeople)); // Usando o construtor de cópia
    //copyOfNewPeople->use(0, *copyOfNewPeople); // Usando a primeira matéria no novo personagem

    delete newPeople;
    delete bag;
    delete copyOfNewPeople;

    return (0);
}