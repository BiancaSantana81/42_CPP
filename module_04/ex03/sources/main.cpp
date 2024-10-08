/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:27:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 13:28:57 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

int main(void)
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria *tmp;

    // Não esta conseguindo equipar na bolsa de 'me' os elementos
    tmp = src->createMateria("ice");
    //std::cout << tmp << std::endl;
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    return (0);
}

// int main(void)
// {
//     // Cria um personagem chamado "bob"
//     ICharacter *guy = new Character("bob");

//     // Cria uma matéria do tipo Ice
//     AMateria *ice = new Ice();

//     // Usa a matéria Ice no personagem "bob"
//     ice->use(*guy);

//     // Limpeza de memória
//     delete ice;
//     delete guy;

//     return 0;
// }
