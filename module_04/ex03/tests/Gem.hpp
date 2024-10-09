/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gem.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:05:10 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/09 11:52:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEM_HPP
#define GEM_HPP

#include <iostream>
#include <vector>

#include "../includes/ICharacter.hpp"
#include "../includes/AMateria.hpp"

class Gem: public ICharacter
{
    private:

    AMateria *_stock[4];
    std::string _name;
    std::vector<AMateria*> _unequipped; // vector de matérias desequipadas durante o programa

    public:

    // Constructors
    Gem(void);
    Gem(std::string name);
    Gem(Gem const &other);
    Gem &operator=(Gem const &other);

    // Getter and Setter
    std::string const & getName() const;
    void setName(std::string newName);

    // Virtual fuctions
    void equip(AMateria *m);
    void unequip(int idx);
    void reequip(std::string const &type, int stockIdx);
    void use(int idx, ICharacter &target);

    // Destructor
    ~Gem(void);
};

#endif