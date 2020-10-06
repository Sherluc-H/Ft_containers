/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:40:53 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/03 22:25:50 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_VECTOR_HPP
# define FT_CHECK_VECTOR_HPP

# include <iostream>
# include "ft_check_utils.hpp"

template <class T>
void	ft_vector_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T ctnr;

	std::cout << "size: " << ctnr.size() << std::endl;
    std::cout << "empty: " << ctnr.empty() << std::endl;
	std::cout << "max_size: " << ctnr.max_size() << std::endl;

	T ctnr3 = ctnr;

	ctnr.push_back(2);
    std::cout << "empty: " << ctnr.empty() << std::endl;
	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	ctnr.pop_back();
	// ctnr.push_front(2);
	// ctnr.push_front(3);
	ctnr.push_back(1);

	std::cout << "size: " << ctnr.size() << std::endl;
	std::cout << "max_size: " << ctnr.max_size() << std::endl;
	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	T ctnr2 = ctnr;

	// ctnr2.pop_front();
	// ctnr2.push_front(2);
	// ctnr2.push_front(3);
	// ctnr2.pop_front();
	ctnr2.push_back(1);

	std::cout << "size: " << ctnr2.size() << std::endl;
	std::cout << "front: " << ctnr2.front() << std::endl;
	std::cout << "back: " << ctnr2.back() << std::endl;

	std::cout << "size: " << ctnr.size() << std::endl;
	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	T ctnr5(ctnr);

	std::cout << "size: " << ctnr5.size() << std::endl;
	std::cout << "front: " << ctnr5.front() << std::endl;
	std::cout << "back: " << ctnr5.back() << std::endl;

	T ctnr6;

	ctnr6 = ctnr;

	std::cout << "size: " << ctnr6.size() << std::endl;
	std::cout << "front: " << ctnr6.front() << std::endl;
	std::cout << "back: " << ctnr6.back() << std::endl;

	T ctnr7(3, 5);

	std::cout << "size: " << ctnr7.size() << std::endl;
	std::cout << "front: " << ctnr7.front() << std::endl;
	std::cout << "back: " << ctnr7.back() << std::endl;

	const T ctnr8(5, 6);

	std::cout << "size: " << ctnr8.size() << std::endl;
	std::cout << "front: " << ctnr8.front() << std::endl;
	std::cout << "back: " << ctnr8.back() << std::endl;

    ft_check_all_comp(ctnr, ctnr2);
    ft_check_all_comp(ctnr2, ctnr3);
    ft_check_all_comp(ctnr, ctnr5);
    ft_check_all_comp(ctnr5, ctnr6);
    ft_check_all_comp(ctnr7, ctnr8);

	T vec;

	std::cout << vec.max_size() << std::endl;

	vec.reserve(3);
	// vec.pop_back();
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(1);
	std::cout << vec[0] << std::endl;
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(2);
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(3);
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(4);
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	vec.pop_back();
	// vec.pop_back();
    std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	// vec.pop_back();
	// vec.clear();
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	vec.resize(14);
	std::cout << vec.at(13) << std::endl;
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;

	// std::vector<test> v1;
	// test a;
	// // v1.push_back(a);
	// ft::vector<test> v2;
	// v2.push_back(a);
	// v2.pop_back();

	const T vec2 = vec;
	std::cout << vec2.capacity() << std::endl;
	std::cout << vec2.size() << std::endl;
	std::cout << vec2[1] << std::endl;
	std::cout << vec2.at(2) << std::endl;
}

#endif
