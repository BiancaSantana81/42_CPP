/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:18:10 by bsantana          #+#    #+#             */
/*   Updated: 2024/09/18 16:18:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int convertEnum(std::string level)
{
    if (level == "DEBUG")
        return (DEBUG_LEVEL);
    else if (level == "INFO")
        return (INFO_LEVEL);
    else if (level == "WARNING")
        return (WARNING_LEVEL);
    else if (level == "ERROR")
        return (ERROR_LEVEL);
    else
        return (INVALID_LEVEL);
}
