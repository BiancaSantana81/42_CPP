/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gem.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 13:47:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gem.hpp"

Gem::Gem(void): _name("Crystal Gem")
{
    for (int i = 0; i < 4; i++)
        _stock[i] = NULL;
}

Gem::Gem(std::string name): _name(name)
{
    std::cout << "I'm " << _name << "!" <<std::endl;
    for (int i = 0; i < 4; i++)
        _stock[i] = NULL;
}

Gem::Gem(Gem const &other)
{
    std::cout << "Gem: Copy constructor called." << std::endl;
    *this = other;
}

Gem &Gem::operator=(Gem const &other)
{
    if (this != &other)
    {
        _name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (other._stock[i])
                _stock[i] = other._stock[i]->clone();
            else
                _stock[i] = NULL;
        }
    }
    return (*this);
}

/* GETTER AND SETTER */

std::string const & Gem::getName(void) const
{
    return (_name);
}

void Gem::setName(std::string newName)
{
    _name = newName;
}

/* Functions with behaviour defined in Gem */

void Gem::equip(AMateria* m)
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

void Gem::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    std::cout << _name << " unequipped " << _stock[idx]->getType() << "." << std::endl;
    _unequipped.push_back(_stock[idx]);
    _stock[idx] = NULL;
}

void Gem::reequip(std::string const &type, int stockIdx)
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
            std::cout << "Materia: " << type << " re-equipped in the slot " << stockIdx << "." << std::endl;
            return ;
        }
    }
}

void Gem::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4 || _stock[idx] == NULL)
        return ;
    _stock[idx]->use(target);
}

/* DESTRUCTOR */

Gem::~Gem(void)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_stock[i] != NULL)
        {
            delete _stock[i];
            _stock[i] = NULL;
        }
    }
    for (size_t i = 0; i < _unequipped.size(); i++)
        delete _unequipped[i];
}
