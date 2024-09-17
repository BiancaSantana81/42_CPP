/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 15:29:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:

    std::string _name;
    Weapon *_weapon;
    
    public:
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon &weapon);
    void attack(void);
};

#endif