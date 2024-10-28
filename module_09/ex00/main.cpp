/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:24:53 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/28 12:35:43 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/init.hpp"

int main(int argc, char **argv)
{
    if (!parsing(argc, argv))
        return (1);
    runProgram(std::string(argv[1]));
    return (0);
}
