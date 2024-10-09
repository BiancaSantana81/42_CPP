/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:44 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:06:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

/* The ICharacter class is abstract and its purpose is to ensure that all the characters created in the game
follow a standard model. By declaring this class as abstract and allowing polymorphism in child classes,
we guarantee standardisation and consistency for all characters, making it easier to implement different types of
of characters that share common behaviours.
*/

#include <iostream>
#include <string>

class AMateria; // Early declaration of the AMateria class to avoid circular dependency.

class ICharacter
{
    public:

    virtual ~ICharacter(void) {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;

    /*extra function: handle management of unequipped intes*/
    virtual void reequip(std::string const &type, int stockIdx) = 0;
};

#endif