/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:40:30 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:07:00 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define MAX_STOCK 4

/* The Character class implements a new character modelled on the ICharacter abstract class.
In it, the character acquires a name and can have a stock of up to 4 materials (AMateria), which can be 
equipped or detached or used via the equip, unequip and use methods.
*/

class Character: public ICharacter
{
    private:

    AMateria *_stock[MAX_STOCK];
    std::string _name;
    std::vector<AMateria*> _unequipped; 

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

     /*extra function: handle management of unequipped intes*/
    void reequip(std::string const &type, int stockIdx);

    // Destructor
    ~Character(void);
};

#endif