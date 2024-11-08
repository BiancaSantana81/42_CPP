/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:37:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 15:38:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* =============== ALGORITHM FOR DEQUE ============== */

/* 1. insert values from argv into the deque container and cout time to process sorted deque */

void PmergeMe::sortDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _dequeContainer.push_back(atoi(argv[i]));

    //printValues(_dequeContainer, "Before sort: ");

    //clock_t start = clock();

    // sort the deque container

    // clock_t end = clock();
    // double elapsed = double(end - start) / CLOCKS_PER_SEC;

    // std::cout << "Time to process a range of " <<
    // BRIGHT_YELLOW <<_dequeContainer.size() << RESET << " elements with " <<
    // BRIGHT_GREEN "deque: " RESET << elapsed << "s" << std::endl;

    //printValues(_dequeContainer, "Deque after sort: ");
}

/* 2. sort the deque container */


/* =============== ALGORITHM FOR VECTOR ============== */

/*1. Inserir valores na deque;
* 2. Separar os valores em dois vetores -> min e max;
* 3. Contagem de tempo para ordenação dos vetores;
*/

void PmergeMe::sortVector(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _vectorContainer.push_back(atoi(argv[i]));

    clock_t start = clock();

    std::vector<int> minValues;
    std::vector<int> maxValues;

    separateValues(minValues, maxValues);
    insertValues(minValues, maxValues);

    _vectorContainer = minValues;

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " <<
    BRIGHT_YELLOW <<_vectorContainer.size() << RESET << " elements with " <<
    BRIGHT_GREEN "vector: " RESET << elapsed << "s" << std::endl;

    //printValues(_vectorContainer, "Vector after sort: ");
}

/*2. Separar os valores em dois vetores -> min e max */

void PmergeMe::separateValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    int size = _vectorContainer.size();

    for (int i = 0; i < size; i++)
    {
        // encontrar maior valor em um par de dois elementos
        if (i + 1 < size && _vectorContainer[i] > _vectorContainer[i + 1])
        {
            // criar variáveis para armazenar os valores
            int minVal = _vectorContainer[i + 1];
            int maxVal = _vectorContainer[i];

            bool insertedMin = false;
            for (std::vector<int>::iterator it = minValues.begin(); it != minValues.end(); ++it)
            {
                // se a posição atual for maior que o valor mínimo, insira o valor mínimo na posição atual
                if (*it > minVal)
                {
                    minValues.insert(it, minVal);
                    insertedMin = true;
                    break ;
                }
            }
            // se não houver uma posição maior que o valor mínimo, insira o valor mínimo no final
            if (!insertedMin)
                minValues.push_back(minVal);

            bool insertedMax = false;
            for (std::vector<int>::iterator it = maxValues.begin(); it != maxValues.end(); ++it)
            {
                if (*it > maxVal)
                {
                    maxValues.insert(it, maxVal);
                    insertedMax = true;
                    break ;
                }
            }
            if (!insertedMax)
                maxValues.push_back(maxVal);

            i++;
        }
        else
        {
            int val = _vectorContainer[i];
            bool insertedMax = false;
            for (std::vector<int>::iterator it = maxValues.begin(); it != maxValues.end(); ++it)
            {
                if (*it > val)
                {
                    maxValues.insert(it, val);
                    insertedMax = true;
                    break ;
                }
            }
            if (!insertedMax)
                maxValues.push_back(val);
        }
    }
}

/*3. merge das duas listas -> min e max */

void PmergeMe::insertValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    generateIndexJacobsthal(_vectorContainer.size());
}

/* 3.1 Gerar indíces de Jacobsthal para inserir os valores ordenados */

void PmergeMe::generateIndexJacobsthal(unsigned int sizeContainer)
{
    _jacobsthalSequence.clear();

    if (sizeContainer == 1)
    {
        _jacobsthalSequence.push_back(0);
        return ;
    }
    
    _jacobsthalSequence.push_back(0);
    _jacobsthalSequence.push_back(1);

    unsigned long nextNumber = 1 * 2 + 0; // J(2) = 1*2 + 0 = 2

    while (nextNumber <= sizeContainer)
    {
        _jacobsthalSequence.push_back(nextNumber);
        nextNumber = _jacobsthalSequence[_jacobsthalSequence.size() - 1] * 2 + _jacobsthalSequence[_jacobsthalSequence.size() - 2];
    }
}

/* 3.2 Inserir valores ordenados com base nos indexes gerados por Jacobsthal */

