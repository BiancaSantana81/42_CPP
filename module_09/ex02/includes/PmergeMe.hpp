/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:59:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/06 16:40:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include <vector>
#include <deque>

#define BRIGHT_RED    "\033[91m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_GREEN  "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define RESET   "\033[0m"

class PmergeMe
{
    private:

    std::deque<int> _dequeContainer;
    std::vector<int> _vectorContainer;

    public:

    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe(void);

    // métodos para parseamento do input
    bool parsing(int argc, char **argv);
    bool validNumber(std::string input);

    // printar valores ordenados
    void printValues(void);
};

#endif