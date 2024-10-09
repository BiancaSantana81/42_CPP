/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 13:49:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* CONSTRUCTORS */

Character::Character(void): _name("weird guy")
{
    for (int i = 0; i < MAX_STOCK; i++)
        _stock[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
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

void Character::equip(AMateria* m)
{
    if (m == NULL)
    {
        std::cout << BRIGHT_RED "Cannot equip a null materia!" RESET << std::endl;
        return ;
    }
    for (int i = 0; i < 4; ++i)
    {
        if (_stock[i] == NULL)
        {
            _stock[i] = m;
            return ;
        }
    }
    _unequipped.push_back(m);
    std::cout << BRIGHT_RED << _name << " could not equip " << m->getType() << " because the bag is full!" RESET << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_STOCK)
        return ;
    std::cout << _name << " unequipped " << _stock[idx]->getType() << "." << std::endl;
    _stock[idx] = NULL;
}

void Character::reequip(std::string const &type, int stockIdx)
{
    if (stockIdx < 0 || stockIdx >= 4 || _stock[stockIdx] != NULL)
    {
        std::cout << BRIGHT_RED " Error: the bag is full or there is already an item in this position! " RESET << std::endl;
        return ;
    }
    for (size_t i = 0; i < _unequipped.size(); i++)
    {
        if (_unequipped[i]->getType() == type)
        {
            _stock[stockIdx] = _unequipped[i];
            _unequipped.erase(_unequipped.begin() + i);
            std::cout << "Materia" << type << " re-equipped in the slot " << stockIdx << "." << std::endl;
            return ;
        }
    }
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
    for (int i = 0; i < MAX_STOCK; ++i)
    {
        if (_stock[i] != NULL)
        {
            delete _stock[i];
            _stock[i] = NULL;
        }
    }
}
