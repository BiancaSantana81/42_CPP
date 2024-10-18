/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:03:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 10:48:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/functions.hpp"

Base * generate(void)
{
    static bool first = true;

    if (first)
    {
        srand(time(NULL));
        first = false;
    }

    int choice = rand() % 3;

    switch (choice)
    {
        case 0:
            std::cout << BRIGHT_CYAN "class of type A created!" RESET << std::endl;
            return new A();
        case 1:
            std::cout << BRIGHT_YELLOW "class of type B created!" RESET << std::endl;
            return new B();
        case 2:
            std::cout << BRIGHT_GREEN "class of type C created!" RESET << std::endl;
            return new C();
        default:
            std::cout << "error: some error occurred when generating a new class." << std::endl;
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "return: A (with pointer)." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "return: B (with pointer)." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "return: C (with pointer)." << std::endl;
    else
        std::cout << "return: null. Unkown type. (with pointer)" << std::endl;
}

void identify(Base& p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "return: A (with reference)." << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "return: B (with reference)." << std::endl;
        return ;
    } catch (std::exception &e) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "return: C (with reference)." << std::endl;
        return ;
    } catch (std::exception &e) {}

    std::cout << "return: null. Unkown type. (with reference)" << std::endl;
}
