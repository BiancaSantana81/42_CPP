/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:32:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 12:01:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

/*
   A classe concreta MateriaSource é responsável pela gestão e criação de novas matérias para os personagens. 
   Ela mantém um armazenamento de até quatro matérias, fornecendo implementações específicas para os métodos 
   learnMateria e createMateria.
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