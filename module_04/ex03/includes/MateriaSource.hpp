/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 14:53:22 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIALSOURCE_HPP

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