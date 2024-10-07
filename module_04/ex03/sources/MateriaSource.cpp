/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:39:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 16:03:50 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/AMateria.hpp"

/* Constructors */

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource: Default constructor called." << std::endl;
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
    if (!materia)
    {
        std::cout << "Cannot learn a null materia." << std::endl;
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] == NULL)
        {
            _materias[i] = materia;
            std::cout << "Materia learned in slot " << i << "." << std::endl;
            return ;
        }
    }
    std::cout << "All materia slots are full, cannot learn more materias." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] && _materias[i]->getType() == type)
            return (_materias[i]->clone());
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return (0);
}

/* Destructor */

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource: Destructor called." << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        if (_materias[i] != NULL)
        {
            delete _materias[i];
            _materias[i] = NULL;
        }
    }
}

