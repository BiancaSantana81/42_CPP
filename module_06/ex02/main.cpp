/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:47:45 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/18 10:35:27 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/functions.hpp"
#include "includes/Base.hpp"
#include "includes/A.hpp"
#include "includes/B.hpp"
#include "includes/C.hpp"

int main(void)
{
    for (int i = 0; i < 5; ++i) {
        Base* instance = generate();
        identify(instance);
        identify(*instance); 
        delete instance;  // Libera a memória alocada
    }
    return 0;
}
