/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:26:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 16:04:39 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_HPP
#define IMATERIA_HPP

/*
   A classe abstrata (interface) IMateriaSource define a estrutura para uma fonte de matérias no sistema de jogo. 
   Ela estabelece dois métodos essenciais: learnMateria, que permite à fonte aprender novas matérias, 
   e createMateria, que possibilita a criação de uma nova instância de AMateria com base em um tipo 
   especificado. Como uma interface abstrata, IMateriaSource garante que todas as classes concretas que 
   a implementarem sigam um contrato consistente para manipulação de matérias, promovendo a extensibilidade 
   e a flexibilidade no sistema.
*/

#include "AMateria.hpp"

class IMateriaSource
{
    public:
    
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif