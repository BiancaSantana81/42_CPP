/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:54:37 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 11:56:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime> 

class ShrubberyCreationForm : public AForm
{
    private:

    std::string _target;

    public:

    /* constructor */

    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm & other);
    virtual ~ShrubberyCreationForm(void);

    /* method */

    void        execute(Bureaucrat const & executor) const;
};

#endif