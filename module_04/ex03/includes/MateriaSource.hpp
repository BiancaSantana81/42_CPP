/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 14:05:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

/*
   The MateriaSource concrete class is responsible for managing and creating new materials for characters. 
   It stores up to four materials, providing specific implementations for the 
   learnMateria and createMateria methods.
*/

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    protected:

    AMateria *_materias[4];
    
    public:
    
    /* Constructors */
    
    MateriaSource(void);
    MateriaSource(MateriaSource const &other);
    MateriaSource &operator=(MateriaSource const &other);

    /* Virtual functions */

    void learnMateria(AMateria *materia);
    AMateria *createMateria(std::string const &type);
    
    /* Destructor */
    
    ~MateriaSource(void);
};

#endif