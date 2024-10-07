/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:36:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_STOCK 4

/* A classe Character implementa um novo personagem seguindo o modelo da classe abstrata ICharacter.
Nela, o personagem adquire um nome e pode ter um estoque de até 4 matérias (AMateria), que podem ser 
equipadas ou desapegadas ou utilizadas através dos métodos equip, unequip e use.
*/

class Character: public ICharacter
{
    private:

    AMateria *_stock[MAX_STOCK];
    std::string _name;

    public:

    // Constructors
    Character(void);
    Character(std::string name);
    Character(Character const &other);
    Character &operator=(Character const &other);

    // Getter and Setter
    std::string const & getName() const;
    void setName(std::string newName);

    // Virtual functions

    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    // Destructor
    ~Character(void);
};

#endif