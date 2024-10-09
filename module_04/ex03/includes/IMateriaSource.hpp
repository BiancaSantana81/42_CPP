/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:26:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:06:03 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIA_HPP
#define IMATERIA_HPP

/*
   The IMateriaSource interface defines the structure for a source of materials in the game system. 
   It establishes two essential methods: learnMateria, which allows the source to learn new materials, 
   and createMateria, which makes it possible to create a new instance of AMateria based on a specified type. 
   type. As an abstract interface, IMateriaSource ensures that all concrete classes that 
   classes that implement it follow a consistent contract for handling materials, promoting extensibility and 
   and flexibility in the system.
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