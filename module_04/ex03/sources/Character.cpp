/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:22:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/08 13:50:50 by bsantana         ###   ########.fr       */
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
    for (int i = 0; i < MAX_STOCK; ++i)
    {
        if (_stock[i] == NULL)
        {
            _stock[i] = m;
            return ;
        }
    }
    std::cout << BRIGHT_RED "Stock is full! Cannot equip more materia." RESET << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= MAX_STOCK)
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
    for (int i = 0; i < MAX_STOCK; ++i)
    {
        if (_stock[i] != NULL)
        {
            delete _stock[i];
            _stock[i] = NULL;
        }
    }
}
