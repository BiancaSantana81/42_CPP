/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:39:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 17:03:59 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"

/* Constructors */

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
        _materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
    std::cout << "MateriaSource: Copy constructor called." << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
    std::cout << "MateriaSource: Assignment operator called." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_materias[i] != NULL)
                delete _materias[i];
            if (other._materias[i] != NULL)
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return (*this);
}

/* Virtual functions */

void MateriaSource::learnMateria(AMateria *materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = materia;
            return ;
        }
    }
    std::cout << "No empty slot to learn more materias." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materias[i] && _materias[i]->getType() == type)
        {
            return (_materias[i]->clone());
        }
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return NULL;
}

/* Destructor */

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] != NULL)
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

