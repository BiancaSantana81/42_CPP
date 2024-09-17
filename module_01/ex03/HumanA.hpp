/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 15:37:27 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:

    std::string _name;
    Weapon &_weapon;
    
    public:

    HumanA(std::string name, Weapon &weapon);
    ~HumanA(void);
    
    void attack(void);
};

#endif