/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:37:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/08 17:07:05 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

#include <algorithm>

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

    printValues(_vectorContainer, "After: ");

    clock_t start = clock();

    std::vector<int> minValues;
    std::vector<int> maxValues;

    separateValues(minValues, maxValues);
    insertValues(minValues, maxValues);

    _vectorContainer = minValues;

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printValues(_vectorContainer, "Before: ");

    std::cout << "Time to process a range of " <<
    BRIGHT_YELLOW <<_vectorContainer.size() << RESET << " elements with " <<
    BRIGHT_GREEN "vector: " RESET << elapsed << "s" << std::endl;

}

/*2. Separar os valores em dois vetores -> min e max */

void PmergeMe::separateValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    int size = _vectorContainer.size();

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int minVal = (_vectorContainer[i] < _vectorContainer[i + 1]) ? _vectorContainer[i] : _vectorContainer[i + 1];
            int maxVal = (_vectorContainer[i] > _vectorContainer[i + 1]) ? _vectorContainer[i] : _vectorContainer[i + 1];

            std::vector<int>::iterator minPos = std::lower_bound(minValues.begin(), minValues.end(), minVal);
            minValues.insert(minPos, minVal);

            std::vector<int>::iterator maxPos = std::lower_bound(maxValues.begin(), maxValues.end(), maxVal);
            maxValues.insert(maxPos, maxVal);
        }
        else
        {
            std::vector<int>::iterator pos = std::lower_bound(minValues.begin(), minValues.end(), _vectorContainer[i]);
            minValues.insert(pos, _vectorContainer[i]);
        }
    }
}

/*3. merge das duas listas -> min e max */

void PmergeMe::insertValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    generateJacobsthalSequence(maxValues.size());
    generateJacobsthalIndex(maxValues.size());

    for (std::vector<int>::iterator it = _jacobsthalIndex.begin(); it != _jacobsthalIndex.end(); ++it)
    {
        if (*it < static_cast<int>(maxValues.size()))
        {
            int value = maxValues[*it];
            std::vector<int>::iterator pos = std::upper_bound(minValues.begin(), minValues.end(), value);
            minValues.insert(pos, value);
        }
    }
}

/* 3.1 Gerar indíces de Jacobsthal para inserir os valores ordenados */

void PmergeMe::generateJacobsthalSequence(unsigned int sizeContainer)
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

// void PmergeMe::generateJacobsthalIndex(unsigned int sizeMaxValues)
// {
//     // Inicializa o primeiro valor da sequência de índices
//     _jacobsthalIndex.push_back(_jacobsthalSequence.front());
    
//     // Loop para continuar adicionando índices até alcançar o tamanho desejado
//     while (_jacobsthalIndex.size() < sizeMaxValues)
//     {
//         // Remove o primeiro elemento já processado da sequência de Jacobsthal
//         _jacobsthalSequence.erase(_jacobsthalSequence.begin());

//         if (!_jacobsthalSequence.empty())
//         {
//             int last = _jacobsthalIndex.back();  // Último índice adicionado
//             int next = _jacobsthalSequence.front();  // Próximo valor da sequência

//             // Verifica se o próximo valor está no intervalo adequado
//             if (next > last && next < static_cast<int>(sizeMaxValues))
//             {
//                 _jacobsthalIndex.push_back(next);
                
//                 // Loop para adicionar valores decrescentes se o próximo for maior que o último
//                 while (next > last && _jacobsthalIndex.size() < sizeMaxValues)
//                 {
//                     // Evita adicionar duplicatas verificando se "next" já está em "_jacobsthalIndex"
//                     if (std::find(_jacobsthalIndex.begin(), _jacobsthalIndex.end(), next) == _jacobsthalIndex.end())
//                         _jacobsthalIndex.push_back(next);

//                     next--;  // Decrementa para verificar o próximo valor decrescente
//                 }
//             }
//         }
//         else
//         {
//             // Se não há mais valores na sequência de Jacobsthal, preenche os índices restantes
//             int missing = sizeMaxValues - _jacobsthalIndex.size();
//             while (_jacobsthalIndex.size() < sizeMaxValues && missing > 0)
//             {
//                 _jacobsthalIndex.push_back(_jacobsthalIndex.back() + 1);
//                 missing--;
//             }
//         }
//     }
// }


void PmergeMe::generateJacobsthalIndex(unsigned int sizeMaxValues)
{
    _jacobsthalIndex.clear();
    _jacobsthalIndex.push_back(_jacobsthalSequence.front());

    while (_jacobsthalIndex.size() < sizeMaxValues)
    {
        _jacobsthalSequence.erase(_jacobsthalSequence.begin());

        if (!_jacobsthalSequence.empty())
        {
            int last = _jacobsthalIndex.back();
            int next = _jacobsthalSequence.front();

            if (next > last && next < static_cast<int>(sizeMaxValues))
            {
                _jacobsthalIndex.push_back(next);

                while (--next > last && _jacobsthalIndex.size() < sizeMaxValues)
                {
                    if (std::find(_jacobsthalIndex.begin(), _jacobsthalIndex.end(), next) == _jacobsthalIndex.end())
                        _jacobsthalIndex.push_back(next);
                }
            }
        }
        else
        {
            int missing = sizeMaxValues - 1;
            while (missing > 0)
            {
                _jacobsthalIndex.push_back(_jacobsthalIndex.back() + 1);
                missing--;
            }
        }
    }
}
