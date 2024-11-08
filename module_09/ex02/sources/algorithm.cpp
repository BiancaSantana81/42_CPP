/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:37:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 13:06:50 by bsantana         ###   ########.fr       */
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

    printValues(_dequeContainer, "Deque after sort: ");
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

    //clock_t start = clock();

    std::vector<int> minValues;
    std::vector<int> maxValues;

    separateValues(minValues, maxValues);

    // clock_t end = clock();
    // double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printValues(minValues, "Min values: ");
    printValues(maxValues, "Max values: ");

    // std::cout << "Time to process a range of " <<
    // BRIGHT_YELLOW <<_vectorContainer.size() << RESET << " elements with " <<
    // BRIGHT_GREEN "vector: " RESET << elapsed << "s" << std::endl;

    // printValues(_vectorContainer, "Vector after sort: ");
}

/*2. Separar os valores em dois vetores -> min e max */

void PmergeMe::separateValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    int size = _vectorContainer.size();

    for (int i = 0; i < size; i++)
    {
       if (i + 1 < size && _vectorContainer[i] > _vectorContainer[i + 1])
        {
            minValues.push_back(_vectorContainer[i + 1]);
            maxValues.push_back(_vectorContainer[i]);
            i++; // Pular o próximo valor, pois já foi considerado
        }
        else
            maxValues.push_back(_vectorContainer[i]);
    }
}


// void PmergeMe::separateValues(std::vector<int> &minValues, std::vector<int> &maxValues)
// {
//     int size = _vectorContainer.size();

//     for (int i = 0; i < size; i++)
//     {
//         if (i + 1 < size && _vectorContainer[i] > _vectorContainer[i + 1])
//         {
//             // Inserir valores ordenados em minValues e maxValues
//             int minVal = _vectorContainer[i + 1];
//             int maxVal = _vectorContainer[i];
            
//             // Inserção ordenada em minValues
//             bool insertedMin = false;
//             for (std::vector<int>::iterator it = minValues.begin(); it != minValues.end(); ++it)
//             {
//                 if (*it > minVal)
//                 {
//                     minValues.insert(it, minVal);
//                     insertedMin = true;
//                     break;
//                 }
//             }
//             if (!insertedMin)
//                 minValues.push_back(minVal);

//             // Inserção ordenada em maxValues
//             bool insertedMax = false;
//             for (std::vector<int>::iterator it = maxValues.begin(); it != maxValues.end(); ++it)
//             {
//                 if (*it > maxVal)
//                 {
//                     maxValues.insert(it, maxVal);
//                     insertedMax = true;
//                     break;
//                 }
//             }
//             if (!insertedMax)
//                 maxValues.push_back(maxVal);

//             i++; // Pular o próximo valor, pois já foi considerado
//         }
//         else
//         {
//             // Inserção ordenada em maxValues
//             int val = _vectorContainer[i];
//             bool insertedMax = false;
//             for (std::vector<int>::iterator it = maxValues.begin(); it != maxValues.end(); ++it)
//             {
//                 if (*it > val)
//                 {
//                     maxValues.insert(it, val);
//                     insertedMax = true;
//                     break;
//                 }
//             }
//             if (!insertedMax)
//                 maxValues.push_back(val);
//         }
//     }
// }
