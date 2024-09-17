/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:37:23 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 17:06:36 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include <string>
#include "Weapon.hpp"

/*
   A classe HumanA deve obrigatoriamente ter uma arma (Weapon) ao ser criada, pois seu atributo
   _weapon é uma referência para um objeto Weapon. A única forma de modificar o tipo da arma 
   associada é através do método setType, que está disponível publicamente na classe Weapon. 
   O método attack de HumanA utiliza a getType para obter o tipo atual da arma.
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