/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:08:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/14 17:25:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/AForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/ShrubberyCreationForm.hpp"

void validSituations(void)
{
    std::cout << BRIGHT_YELLOW "===================== valid situations =====================" RESET << std::endl;
    Bureaucrat amanda("Amanda", 1);

    std::cout << BRIGHT_CYAN "====== Test 1: Robotomy ======  " RESET << std::endl;

    srand(time(NULL));

    try {
        RobotomyRequestForm forms("forms");
        amanda.signForm(forms);
    
        amanda.executeForm(forms);
        amanda.executeForm(forms);
        amanda.executeForm(forms);
        amanda.executeForm(forms);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BRIGHT_CYAN "====== Test 2: PresidentialRequestForm ======  " RESET << std::endl;
    try {
        PresidentialPardonForm john("John");
        amanda.signForm(john);
        amanda.executeForm(john);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << BRIGHT_CYAN "====== Test 3: ShrubberyCreationForm ======  " RESET << std::endl;
    try {
        ShrubberyCreationForm target1("target1");
        amanda.signForm(target1);
        amanda.executeForm(target1);
    }  catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void testCopyConstructor(void)
{
    std::cout << BRIGHT_YELLOW "===================== Test: Copy Constructor =====================" RESET << std::endl;
    ShrubberyCreationForm original("Garden");

    // Testando o construtor de cópia
    std::cout << BRIGHT_CYAN "====== Test 1: Testando construtor de cópia  ======  " RESET << std::endl;
    ShrubberyCreationForm copy(original);
    std::cout << "Original: " << std::endl << original << std::endl;
    std::cout << "Copy: " << std::endl << copy << std::endl;

    // Testando atribuição
    std::cout << BRIGHT_CYAN "====== Test 2: Testando atribuição de cópia  ======  " RESET << std::endl;
    RobotomyRequestForm robot1("Old Target");
    RobotomyRequestForm robot2("New Target");
    robot1 = robot2;
    std::cout << "Robot1 after assignment: " << robot1 << std::endl;
    std::cout << "Robot2 after assignment: " << robot2 << std::endl;
    std::cout << BRIGHT_CYAN "=====================================================================  " RESET << std::endl;
}

void invalidSituations(void)
{
    std::cout << BRIGHT_YELLOW "===================== Invalid situations =====================" RESET << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 1: Tentar executar um formulário sem assinatura ======  " RESET << std::endl;

    try {
        Bureaucrat angela("Angela", 1);
        PresidentialPardonForm sorry("sorry");

        angela.executeForm(sorry);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << BRIGHT_CYAN "====== Test 2: Tentar executar um formulário com nota baixa para exec ======  " RESET << std::endl;
    try {
        Bureaucrat angela("Angela", 1);
        Bureaucrat marcela("Marcela", 150);
        PresidentialPardonForm sorry("sorry");
        sorry.beSigned(angela);

        marcela.executeForm(sorry);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}

int main(void)
{
    invalidSituations();
    validSituations();
    testCopyConstructor();
    return (0);
}
