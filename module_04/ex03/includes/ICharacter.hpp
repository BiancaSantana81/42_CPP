/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:44 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 11:40:08 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>


/* Declaração antecipada da classe AMateria para evitar dependência circular.
Isso permite que a interface ICharacter use ponteiros para AMateria
sem a necessidade de incluir o cabeçalho de AMateria, prevenindo assim
problemas de compilação causados por ciclos de inclusão. */

class AMateria;

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