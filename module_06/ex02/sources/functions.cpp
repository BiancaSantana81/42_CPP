/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:03:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 11:12:40 by bsantana         ###   ########.fr       */
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
        A& a = dynamic_cast<A&>(p);
        std::cout << "return: A (with reference)." << std::endl;
        (void)a;
        return ;
    } catch (std::exception &e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "return: B (with reference)." << std::endl;
        (void)b;
        return ;
    } catch (std::exception &e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "return: C (with reference)." << std::endl;
        (void)c;
        return ;
    } catch (std::exception &e) {}

    std::cout << "return: null. Unkown type. (with reference)" << std::endl;
}
