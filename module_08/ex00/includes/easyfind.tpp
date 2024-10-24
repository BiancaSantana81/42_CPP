/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/24 10:10:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

/*
    This function looks for the occurrence of a specific value in a container.
    If the value is found, it returns an iterator to the value's position in the container.
    Otherwise, it throws an std::runtime_error exception stating that the value was not found.
    T: Container type, which must support begin() and end() operations.
    number: The value to look for in the container.
*/
template <typename T>
typename T::iterator easyfind(T &container, int number)
{
    typename T::iterator found;

    found = std::find(container.begin(), container.end(), number);

    if (found == container.end())
        throw std::runtime_error("Error: value not found in container!");
    return (found);
}

/*
    Browse the container (array or STL) and print its values.
*/

template <typename T>
void printContainer(const T& container)
{
    std::copy(container.begin(), container.end(), std::ostream_iterator<typename T::value_type>(std::cout, " "));
    std::cout << std::endl;
}
