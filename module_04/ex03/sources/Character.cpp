/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/07 15:35:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* CONSTRUCTORS */

Character::Character(void): _name("Unkown")
{
    std::cout << "Character: Default constructor called." << std::endl;
    for (int i = 0; i < MAX_STOCK; i++)
        _stock[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
    std::cout << "Character: " << _name  << " constructor called." << std::endl;
    for (int i = 0; i < MAX_STOCK; i++)
        _stock[i] = NULL;
}

Character::Character(Character const &other)
{
    std::cout << "Character: Copy constructor called." << std::endl;
    *this = other;
}

Character &Character::operator=(Character const &other)
{
    std::cout << "Character: Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < MAX_STOCK; ++i)
        {
            if (_stock[i])
                delete _stock[i];
            if (other._stock[i])
                _stock[i] = other._stock[i]->clone();
            else
                _stock[i] = NULL;
        }
    }
    return (*this);
}

/* GETTER AND SETTER */

std::string const & Character::getName(void) const
{
    return (_name);
}

void Character::setName(std::string newName)
{
    _name = newName;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < MAX_STOCK; i++)
    {
        if (_stock[i] == NULL)
        {
            _stock[i] = m;
            std::cout << _name << " equipped " << m->getType() << "." << std::endl;
            break ;
        }
    }
    std::cout << _name << "'s stock is full! Cannot equip more materias." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_STOCK || _stock[idx] == NULL)
        return ;
    std::cout << _name << " unequipped " << _stock[idx]->getType() << "." << std::endl;
    _stock[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= MAX_STOCK || _stock[idx] == NULL)
        return ;
    _stock[idx]->use(target);
}

/* DESTRUCTOR */

Character::~Character(void)
{
    std::cout << "Character: Destructor called." << std::endl;
    for (int i = 0; i < MAX_STOCK; ++i)
    {
        if (_stock[i] != NULL)
        {
            delete _stock[i];
            _stock[i] = NULL;
        }
    }
}


// Character::~Character(void)
// {
//     std::cout << "Character: Destructor called." << std::endl;
//     for (int i = 0; i < MAX_STOCK; ++i)
//     {
//         std::cout << "Deleting _stock[" << i << "]" << std::endl;
//         if (_stock[i] != NULL)
//         {
//             std::cout << "_stock[" << i << "] is not NULL, deleting..." << std::endl;
//             delete _stock[i];
//             _stock[i] = NULL;
//         }
//         else
//         {
//             std::cout << "_stock[" << i << "] is NULL, skipping..." << std::endl;
//         }
//     }
// }
