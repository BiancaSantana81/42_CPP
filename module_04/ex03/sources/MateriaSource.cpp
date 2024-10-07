/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:39:34 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 14:53:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"

/* CONSTRUCTORS */

#include "../includes/AMateria.hpp"
#include <iostream>

/* Constructors */

// Construtor padrão
MateriaSource::MateriaSource(void) {
    std::cout << "MateriaSource: Default constructor called." << std::endl;
    for (int i = 0; i < 4; ++i) {
        _materias[i] = NULL;  // Inicializa os slots de matérias com NULL
    }
}

// Construtor de cópia
MateriaSource::MateriaSource(MateriaSource const &other) {
    std::cout << "MateriaSource: Copy constructor called." << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (other._materias[i] != NULL)
            _materias[i] = other._materias[i]->clone();  // Clona as matérias do outro objeto
        else
            _materias[i] = NULL;
    }
}

// Operador de atribuição
MateriaSource &MateriaSource::operator=(MateriaSource const &other) {
    std::cout << "MateriaSource: Assignment operator called." << std::endl;
    if (this != &other) {
        // Apaga as matérias atuais
        for (int i = 0; i < 4; ++i) {
            if (_materias[i] != NULL)
                delete _materias[i];
            // Clona as matérias do outro objeto
            if (other._materias[i] != NULL)
                _materias[i] = other._materias[i]->clone();
            else
                _materias[i] = NULL;
        }
    }
    return *this;
}

/* Virtual functions */

// Aprender nova matéria
void MateriaSource::learnMateria(AMateria *materia) {
    if (!materia) {
        std::cout << "Cannot learn a null materia." << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] == NULL) {  // Encontra o primeiro slot vazio
            _materias[i] = materia;
            std::cout << "Materia learned in slot " << i << "." << std::endl;
            return;
        }
    }
    std::cout << "All materia slots are full, cannot learn more materias." << std::endl;
}

// Criar nova matéria com base no tipo
AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] && _materias[i]->getType() == type) {
            return _materias[i]->clone();  // Clona e retorna uma nova matéria do mesmo tipo
        }
    }
    std::cout << "Materia of type " << type << " not found." << std::endl;
    return NULL;
}

/* Destructor */

// Destrutor
MateriaSource::~MateriaSource(void) {
    std::cout << "MateriaSource: Destructor called." << std::endl;
    for (int i = 0; i < 4; ++i) {
        if (_materias[i] != NULL) {
            delete _materias[i];  // Apaga todas as matérias aprendidas
            _materias[i] = NULL;
        }
    }
}

