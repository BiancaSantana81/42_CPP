/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:54:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 17:12:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

static void build_tree(std::string target);

/* Constructors */

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 137, 145),_target(target)
{
    std::cout  << "ShrubberyCreationForm is available. Main target: "
    << _target << "." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
: AForm(other), _target(other._target)
{
    std::cout << "Copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    else
         std::cout << "Self-attribution detected! The objects already have the same address." << std::endl;
    return (*this);
}

/* Method - execute form */

void        ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned()) {
        throw AFormAlreadySignedException();
    }
    if (executor.getGrade() > getGradeExec()) {
        throw GradeTooLowException();
    }
    build_tree(_target);
}

/* Destructor */

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout  << "ShrubberyCreationForm with the target  objective: "
    << _target << " was destroyed in flames." << std::endl;
}

static void build_tree(std::string target)
{
    std::ifstream treeFile("./treeFile.txt");

    if (!treeFile)
    {
        std::cout  << "Error opening file Tree.txt " << target << std::endl;
        return ;
    }
    std::ofstream outfile(target.c_str());
    if (!outfile)
    {
        std::cout  << "Error creating file " << target << std::endl;
        return ;
    }
    std::string line;

    while (std::getline(treeFile, line))
    {
        outfile << line << std::endl;
    }
    treeFile.close();
    outfile.close();
}
