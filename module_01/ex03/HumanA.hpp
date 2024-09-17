/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 14:58:57 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>

class HumanA
{
    private:

    std::string _name;
    //Weapon *_weapon;
    
    public:

    HumanA(std::string name);
    ~HumanA(void);
    
    void attack(void);
};

#endif