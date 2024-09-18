/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:56:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>
#include "Weapon.hpp"


/*
   The HumanA class must have a weapon (Weapon) when it is created, because its attribute
   _weapon attribute is a reference to a Weapon object. The only way to change the type of the associated 
   is through the setType method, which is publicly available in the Weapon class. 
   HumanA's attack method uses getType to get the weapon's current type.
*/

class HumanA
{
    private:

    std::string _name;
    Weapon &_weapon; // Reference to weapon created in Weapon class
    
    public:

    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    
    void attack(void);
};

#endif