/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:00:33 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/12 14:20:57 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    PmergeMe sortManager;

    if (!sortManager.parsing(argc, argv))
        return (1);

    sortManager.sortVector(argc, argv);
    sortManager.sortDeque(argc, argv);

    return (0);
}
