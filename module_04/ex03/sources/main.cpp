/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:27:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 12:39:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"

// int main(void)
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }


int main() {
    // Criação de um personagem
    Character character1("Hero");

    // Criação de matérias
    AMateria *cure = new Cure();
    AMateria *ice = new Ice();

    // Equipando matérias
    character1.equip(cure);
    character1.equip(ice);

    // Desequipando uma matéria
    character1.unequip(0);

    // Testando a classe de cópia
    Character character2(character1); // Usando o construtor de cópia
    std::cout << character2.getName() << " has been copied from " << character1.getName() << "." << std::endl;

    // Limpando a memória
    delete cure; // Libera a memória da Cure
    delete ice;  // Libera a memória do Ice

    return 0;
}