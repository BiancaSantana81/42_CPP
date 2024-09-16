/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:42:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/16 15:55:52 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std:: cout << _name << ": BraiiiiiiinnnzzzZ...";
    return ;
}

std::string Zombie::getName(void) const
{
    return (this->_name);
}

void Zombie::setName(std::string &newName)
{
    this->_name = newName;
}