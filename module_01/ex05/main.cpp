/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:26:07 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/19 15:16:20 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl complainer;

    complainer.complain("DEBUG");
    complainer.complain("INFO");
    complainer.complain("WARNING");
    complainer.complain("ERROR");
    complainer.complain("Unknown");

    return (0);
}