/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:44 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 13:22:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"

int main(void)
{
    int arrayValues[5] = {10, 200, 300, 54, 42};

    // adding values to containers..."

    std::vector<int> vectorContainer(begin(arrayValues), end(arrayValues));
    std::deque<int> dequeContainer(begin(arrayValues), end(arrayValues));
    std::list<int> listContainer(begin(arrayValues), end(arrayValues));

    // printing values to containers...
    
    std::cout << BRIGHT_YELLOW "Vector Container: " RESET ;
    printContainer(vectorContainer);

    std::cout << BRIGHT_YELLOW "Deque Container: " RESET;
    printContainer(dequeContainer);

    std::cout << BRIGHT_YELLOW "List Container: " RESET;
    printContainer(listContainer);

    // tests with different containers
    std::cout << BRIGHT_MAGENTA "tests with different containers " RESET << std::endl;

    // vector tests
    
    try {
        std::vector<int>::iterator itVector = easyfind(vectorContainer, 42);
        std::cout << "Found in vector: " << *itVector << std::endl;

        std::vector<int>::iterator itVectorError = easyfind(vectorContainer, -42);
        std::cout << "Found in vector: " << *itVectorError << std::endl;
        
    } catch (std::runtime_error &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }

    // deque tests

    try {
        std::deque<int>::iterator itDeque = easyfind(dequeContainer, 42);
        std::cout << "Found in deque: " << *itDeque << std::endl;

        std::deque<int>::iterator itDequeError = easyfind(dequeContainer, -42);
        std::cout << "Found in deque: " << *itDequeError << std::endl;
        
    } catch (std::runtime_error &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }

    // list tests

    try {
        std::list<int>::iterator itList = easyfind(listContainer, 42);
        std::cout << "Found in list: " << *itList << std::endl;

        std::list<int>::iterator itListError = easyfind(listContainer, -42);
        std::cout << "Found in list: " << *itListError << std::endl;
        
    } catch (std::runtime_error &e) {
        std::cout << BRIGHT_RED << e.what() << RESET << std::endl;
    }

    return (0);
}
