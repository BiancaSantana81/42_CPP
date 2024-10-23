/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 12:55:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int number)
{
   typename T::iterator found;
   
    found = std::find(container.begin(), container.end(), number);
    
    if (found == container.end())
        throw std::runtime_error("Error: value not found in container!");
    return (found);
}


template <typename T, size_t N>
T *begin(T (&container)[N])
{
    return (container);
}

template <typename T, size_t N>
T *end(T (&container)[N])
{
    return (container + N);
}

template <typename T>
void printContainer(const T& container)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
