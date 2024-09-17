/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 17:12:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
    HumanB pode ser criado sem uma arma, pois o atributo _weapon é um ponteiro para um
    objeto Weapon. Inicialmente, o ponteiro pode ser configurado como NULL. Para atribuir uma
    arma a um objeto HumanB depois de sua criação, usamos o método setWeapon, que está disponível
    publicamente na classe Weapon e altera o ponteiro _weapon para referenciar o novo objeto Weapon.
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