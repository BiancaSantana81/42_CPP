/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:47:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/21 11:08:16 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/functions.hpp"
#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

int main(void)
{
    int num_tests = 6;
    
    std::cout << BRIGHT_CYAN " ======= Test 1: identifying randomly generated classes ======= " RESET << std::endl;
    for (int i = 0; i < num_tests; ++i)
    {
        Base* instance = generate();
    
        if (instance)
        {
            // Identifying via pointer
            identify(instance);
            // Identifying via reference
            identify(*instance); 
            
            delete instance;  
        }
        else
            std::cout << "Failed to generate instance." << std::endl;
    }
    
    std::cout << BRIGHT_CYAN "======= Test 2: unidentifiable type (Base type class) ======= " RESET << std::endl;

    Base *base_instance = new Base();

    identify(base_instance);
    identify(*base_instance);

    delete base_instance;
    
    return (0);
}
