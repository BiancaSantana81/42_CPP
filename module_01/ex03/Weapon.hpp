/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 14:46:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
    
    std::string _type;

    public:

    Weapon(std::string type);
    ~Weapon();

    const std::string getType(void) const;
    void setType(std::string newType);
};

#endif