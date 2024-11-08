/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:59:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 17:52:35 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>

#include <algorithm>
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

    std::deque<int> _dequeContainer; // escolha do container deque
    std::vector<int> _vectorContainer; // escolha do container vector
    std::vector<int> _jacobsthalSequence; // sequência de Jacobsthal
    std::vector<int> _jacobsthalIndex; // índice da sequência de Jacobsthal

    public:

    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe(void);

    // métodos para parseamento do input
    bool parsing(int argc, char **argv);
    bool validNumber(std::string input);

    // métodos para inicialização dos containers e ordenação com deque

    void sortDeque(int argc, char **argv);
    void separateValues(std::vector<int> &minValues , std::vector<int> &maxValues);
    void insertValues(std::vector<int> &minValues, std::vector<int> &maxValues);

    // métodos para inicialização dos containers e ordenação com vector

    void sortVector(int argc, char **argv);
    void separateValues(std::deque<int> &minValues, std::deque<int> &maxValues);
    void insertValues(std::deque<int> &minValues, std::deque<int> &maxValues);

    // Jacobsthal sequence

    void generateJacobsthalSequence(unsigned int sizeContainer);
    void generateJacobsthalIndex(unsigned int sizeMaxValues);
};

template <typename T>
void printValues(const T& container, std::string status)
{
    std::cout << BRIGHT_MAGENTA << status << RESET;
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif