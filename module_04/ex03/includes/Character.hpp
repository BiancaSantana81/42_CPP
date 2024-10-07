/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 12:37:01 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_STOCK 4


// Classe Character implementa a interface ICharacter. 
// Ela gerencia um estoque de até 4 matérias (AMateria) e 
// fornece métodos para equipar, desequipar e usar essas matérias 
// em alvos (ICharacter). A classe também armazena o nome do 
// personagem, que é definido no construtor.


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
    void unequip(int curr);
    void use(int curr, ICharacter &target);

    // Destructor
    ~Character(void);
    
};

#endif