/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 15:00:31 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp" 

HumanA::HumanA(std::string name): _name(name)
{
    std::cout << this->_name << ": born!" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << this->_name << " :died!" << std::endl;
}
