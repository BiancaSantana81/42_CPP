/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:13:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/10/19 12:26:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

/* Templates são instanciados em tempo de compilação com base nos tipos usados.
Caso a implementação de um template seja adicionada em um arquivo .cpp separado,
 podem ocorrer erros de linkagem, impedindo a criação da instância do template.
*/

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif