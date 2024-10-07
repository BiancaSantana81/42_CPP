/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:44 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:12:50 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>


/* A classe ICharacter é abstrata e tem como finalidade assegurar que todos os personagens criados no jogo
sigam um modelo padrão. Ao declarar essa classe como abstrata e permitir o polimorfismo nas classes filhas,
garantimos a padronização e a consistência para todos os personagens, facilitando a implementação de diferentes tipos
de personagens que compartilham comportamentos comuns.
*/


class AMateria; // Declaração antecipada da classe AMateria para evitar dependência circular.

class ICharacter
{
    public:

    virtual ~ICharacter(void) {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif