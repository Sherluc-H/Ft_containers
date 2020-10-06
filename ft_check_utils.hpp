/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:31:49 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/05 00:56:54 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_UTILS_HPP
# define FT_CHECK_UTILS_HPP

# include <iostream>

template <class Iterator>
void ft_print_it_range(Iterator first, Iterator last)
{
    std::cout << "print" << std::endl;
    while (first != last)
    {
        // std::cout << "b" << std::endl;
        std::cout << *first << std::endl;
        first++;
    }
}

template <class T>
void ft_check_eq(T a, T b)
{
    if (a == b)
        std::cout << "eq" << std::endl;
    else
        std::cout << "not eq" << std::endl;
}

template <class T>
void ft_check_dif(T a, T b)
{
    if (a != b)
        std::cout << "dif" << std::endl;
    else
        std::cout << "not dif" << std::endl;
}

template <class T>
void ft_check_smaller(T a, T b)
{
    if (a < b)
        std::cout << "smaller" << std::endl;
    else
        std::cout << "not smaller" << std::endl;
}

template <class T>
void ft_check_smaller_eq(T a, T b)
{
    if (a <= b)
        std::cout << "smaller or eq" << std::endl;
    else
        std::cout << "not smaller nor eq" << std::endl;
}

template <class T>
void ft_check_bigger(T a, T b)
{
    if (a > b)
        std::cout << "bigger" << std::endl;
    else
        std::cout << "not bigger" << std::endl;
}

template <class T>
void ft_check_bigger_eq(T a, T b)
{
    if (a >= b)
        std::cout << "bigger eq" << std::endl;
    else
        std::cout << "not bigger nor eq" << std::endl;
}

template <class T>
void ft_check_all_comp(T a, T b)
{
    ft_check_eq(a, b);
    ft_check_dif(a, b);
    ft_check_smaller(a, b);
    ft_check_smaller_eq(a, b);
    ft_check_bigger(a, b);
    ft_check_bigger_eq(a, b);
}

#endif
