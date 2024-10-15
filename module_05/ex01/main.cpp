/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:08:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/15 13:33:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/Form.hpp"

void validSituations(void)
{
    std::cout << BRIGHT_YELLOW "===================== valid situations =====================" RESET << std::endl;
    std::cout << BRIGHT_CYAN "====== Test 1: sign Form  ======  " RESET << std::endl;
    
    Bureaucrat alice("Alice", 2);
    Form permission("Permission", 5, 2);
    
    std::cout << alice << std::endl;
    std::cout << permission << std::endl;

    alice.signForm(permission);

    std::cout << permission << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 2: boss signing multiple forms  ======  " RESET << std::endl;

    Bureaucrat boss("Boss", 1);
    std::cout << boss << std::endl;
    Form project("Project", 1, 1);
    Form proposal("Proposal", 5, 1);
    Form agreement("Agreement", 10, 1);

    boss.signForm(project);
    boss.signForm(proposal);
    boss.signForm(agreement);

    std::cout << project << std::endl;
    std::cout << proposal << std::endl;
    std::cout << agreement << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 3: Bureaucrat with grade 1 signing form with max grade required  ======  " RESET << std::endl;

    Bureaucrat topBureaucrat("Top Bureaucrat", 1);
    std::cout << topBureaucrat << std::endl;
    Form ultimateForm("Ultimate Form", 1, 1);

    topBureaucrat.signForm(ultimateForm);

    std::cout << ultimateForm << std::endl;

}

void testCopyConstructor(void)
{
    std::cout << BRIGHT_YELLOW "===================== Test: Copy Constructor =====================" RESET << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 1: Copy an unsigned Form  ======  " RESET << std::endl;

    Form originalForm("Original Form", 10, 5);
    std::cout << "Original Form: " << originalForm << std::endl;

    Form copiedForm(originalForm);
    std::cout << "Copied Form: " << copiedForm << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 2: Copy a signed Form  ======  " RESET << std::endl;

    Bureaucrat alice("Alice", 1);

    Form signedCopiedForm(originalForm);
    
    originalForm.beSigned(alice);

    std::cout << "Original Form (signed): " << originalForm << std::endl;
    std::cout << "Copied Signed Form: " << signedCopiedForm << std::endl;
}

void invalidSituations(void)
{
    std::cout << BRIGHT_YELLOW "===================== Invalid situations =====================" RESET << std::endl;

    std::cout << BRIGHT_CYAN "====== Test 1: Form with grade too high ======  " RESET << std::endl;
    try {
        Form invalidHighGradeForm("Invalid High", 0, 50);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << BRIGHT_CYAN "====== Test 2: Form with grade too low ======  " RESET << std::endl;
    try {
        Form invalidLowGradeForm("Invalid Low", 200, 100);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << BRIGHT_CYAN "====== Test 3: Bureaucrat with grade too low to sign ======  " RESET << std::endl;
    try {
        Bureaucrat bob("Bob", 150);
        Form importantForm("Important Form", 50, 50);
        bob.signForm(importantForm);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << BRIGHT_CYAN "====== Test 6: Form already signed ======  " RESET << std::endl;
    try {
        Bureaucrat alice("Alice", 1); 
        Form contract("Contract", 2, 2);
        
        alice.signForm(contract);
        alice.signForm(contract);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    validSituations();
    invalidSituations();
    testCopyConstructor();
    return (0);
}
