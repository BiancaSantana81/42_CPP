/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:27 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 15:30:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL)
{
    std::cout << this->_name << " born!" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << this->_name << " died!" << std::endl;
}

void HumanB::attack(void)
{
    if (this->_weapon == NULL)
        std::cout << this->_name << " attacks with punches!" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}