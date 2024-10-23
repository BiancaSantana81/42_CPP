/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:12:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/23 11:14:41 by bsantana         ###   ########.fr       */
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
