/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/17 18:49:52 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv)
{
    std::ifstream input;
    std::ofstream output;
    std::string s1, s2;
    

    if (!processInput(argc, argv, input, output, s1, s2))
        return (1);
    replace(input, output, s1, s2);

    input.close();
    output.close();

    std::cout << "File processed successfully. Output: " << argv[1] << ".replace" << std::endl;
    return (0);
}
