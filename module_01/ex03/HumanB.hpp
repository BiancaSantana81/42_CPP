/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:57:54 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
    HumanB can be created without a weapon, because the _weapon attribute is a pointer to a
    Weapon object. Initially, the pointer can be set to NULL. To assign a
    weapon to a HumanB object after its creation, we use the setWeapon method, which is publicly available in the
    publicly available in the Weapon class and changes the _weapon pointer to reference the new Weapon object.
*/

class HumanB
{
    private:

    std::string _name;
    Weapon *_weapon; // Pointer to _weapon
    
    public:
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon &weapon);
    void attack(void);
};

#endif