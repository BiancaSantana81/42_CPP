/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:00:33 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 17:43:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe init;
    
    if (!init.parsing(argc, argv))
        return (1);

    init.sortVector(argc, argv);
    init.sortDeque(argc, argv);

    return (0);
}
