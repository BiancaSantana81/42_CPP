/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:40:24 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/02 17:04:04 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

/* CONSTRUCTORS */

Brain::Brain(void)
{
    std::cout << "Brain: constructor called!" << std::endl;
    for (int i = 0; i < 100; i++)
        _ideas[i] = "Default idea.";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain: copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain: assignment operator called." << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    else
        std::cout << "Self-attribution detected! The objects already have the same address." << std::endl;
    return *this;
}

/* GETTER AND SETTER */

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return _ideas[index];
    else
    {
        std::cout << RED "Invalid index. Returning an empty string." RESET << std::endl;
        return "";
    }
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
    else
    {
        std::cout << RED "Invalid index. No array idea has been modified." RESET << std::endl;
        return ;
    }
}

/* PRINT IDEA */

void Brain::showIdeas() const
{
    for (int i = 0; i < 100; i++)
        std::cout << GREEN "Index " << i + 1 << "  " RESET << _ideas[i] << std::endl;
}

/* DESTRUCTOR */

Brain::~Brain(void)
{
    std::cout << "Brain: destructor called!" << std::endl;
}
