/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:37:17 by bsantana          #+#    #+#             */
/*   Updated: 2024/11/12 11:38:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"


/* 
   The algorithm chosen to solve this exercise was merge-insertion sort.
   First, the container values are separated into two containers (min and max) and
   inserted in ascending order. Next, the values from the max container are inserted into the min
   container in ascending order, ensuring total sorting. The algorithm has been implemented for the deque and vector containers.
*/

/* =============== ALGORITHM FOR DEQUE ============== */

/* 1. insert values from argv into the deque container and cout time to process sorted deque */

void PmergeMe::sortDeque(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _dequeContainer.push_back(atoi(argv[i]));

    clock_t start = clock();

    std::deque<int> minValues;
    std::deque<int> maxValues;

    separateValues(minValues, maxValues);
    insertValues(minValues, maxValues);

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " <<
    BRIGHT_YELLOW <<_dequeContainer.size() << RESET << " elements with " <<
    BRIGHT_GREEN "deque: " RESET << std::fixed << std::setprecision(6) << elapsed << "s" << std::endl;
}

/* 2. separate the values of dequeContainer into two deques (min and max), add values in order */

void PmergeMe::separateValues(std::deque<int> &minValues, std::deque<int> &maxValues)
{
    int size = _dequeContainer.size();

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int minVal, maxVal;
            if (_dequeContainer[i] < _dequeContainer[i + 1])
            {
                minVal = _dequeContainer[i];
                maxVal = _dequeContainer[i + 1];
            }
            else
            {
                minVal = _dequeContainer[i + 1];
                maxVal = _dequeContainer[i];
            }

            std::deque<int>::iterator minPos = std::lower_bound(minValues.begin(), minValues.end(), minVal);
            minValues.insert(minPos, minVal);

            std::deque<int>::iterator maxPos = std::lower_bound(maxValues.begin(), maxValues.end(), maxVal);
            maxValues.insert(maxPos, maxVal);
        }
        else
        {
            std::deque<int>::iterator pos = std::lower_bound(minValues.begin(), minValues.end(), _dequeContainer[i]);
            minValues.insert(pos, _dequeContainer[i]);
        }
    }
}

/* 3. insert the values of maxValues into minValues in order */

void PmergeMe::insertValues(std::deque<int> &minValues, std::deque<int> &maxValues)
{
    std::deque<int>::iterator it;

    for (it = maxValues.begin(); it != maxValues.end(); ++it)
    {
        std::deque<int>::iterator pos = std::upper_bound(minValues.begin(), minValues.end(), *it);
        minValues.insert(pos, *it);
    }
}

/* =============== ALGORITHM FOR VECTOR ============== */

/* 1. insert values from argv into the vector container and cout time to process sorted vector */

void PmergeMe::sortVector(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
        _vectorContainer.push_back(atoi(argv[i]));

    if (!isSorted(_vectorContainer))
    {
        std::cout << BRIGHT_RED "The values are already sorted!! " RESET << std::endl;
        exit(1);
    }

    printValues(_vectorContainer, "BEFORE: ");

    clock_t start = clock();

    std::vector<int> minValues;
    std::vector<int> maxValues;

    separateValues(minValues, maxValues);
    insertValues(minValues, maxValues);

    _vectorContainer = minValues;

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    printValues(_vectorContainer, "AFTER: ");

    std::cout << "Time to process a range of " <<
    BRIGHT_YELLOW <<_vectorContainer.size() << RESET << " elements with " <<
    BRIGHT_GREEN "vector: " RESET << std::fixed << std::setprecision(6) << elapsed << "s" << std::endl;

}

/* 2. separate the values of _vectorContainer into two vectors (min and max), add values in order */

void PmergeMe::separateValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    int size = _vectorContainer.size();

    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int minVal, maxVal;
            if (_vectorContainer[i] < _vectorContainer[i + 1])
            {
                minVal = _vectorContainer[i];
                maxVal = _vectorContainer[i + 1];
            }
            else
            {
                minVal = _vectorContainer[i + 1];
                maxVal = _vectorContainer[i];
            }

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

/* 3. insert the values of maxValues into minValues in order*/

void PmergeMe::insertValues(std::vector<int> &minValues, std::vector<int> &maxValues)
{
    std::vector<int>::iterator it;

    for (it = maxValues.begin(); it != maxValues.end(); ++it)
    {
        std::vector<int>::iterator pos = std::upper_bound(minValues.begin(), minValues.end(), *it);
        minValues.insert(pos, *it);
    }
}
