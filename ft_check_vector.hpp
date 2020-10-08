/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:40:53 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/08 10:37:20 by lhuang           ###   ########.fr       */
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

template <class T>
void ft_vector_swap_check()
{
	std::cout << "---swap check---" << std::endl;
	T one;
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);
	one.push_back(4);
	one.push_back(6);
	T two;
	two.push_back(10);
	two.push_back(20);
	two.push_back(30);
	two.push_back(40);
	two.push_back(50);

	ft_check_bigger_eq(one, two);
	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_begin2 = one.begin();
	// typename T::const_iterator cit = one_it_begin;//conversion ok
	// typename T::iterator iit = cit;//conversion pas ok
	one_it_begin2--;
	ft_check_eq(one_it_begin, one_it_begin2);
	typename T::iterator two_it_begin = two.begin();
	// std::swap(one, two);
	one.swap(two);
	two.push_back(60);//il y avait probleme ici

	typename T::iterator two_it_end = two.end();
	typename T::iterator one_it_end = one.end();
	ft_print_it_range(one_it_begin, two_it_end);
	one_it_end--;
	ft_print_it_range(two_it_begin, one_it_end);
	one_it_begin = one.begin();
	one_it_end = one.end();
	two_it_begin = two.begin();
	two_it_end = two.end();
	ft_print_it_range(one_it_begin, one_it_end);
	ft_print_it_range(two_it_begin, two_it_end);

	T three;
	three.push_back(100);
	three.push_back(200);
	typename T::iterator three_it_begin = three.begin();
	typename T::iterator three_it_end = three.end();
	two.assign(three_it_begin, three_it_end);
	ft_print_it_range(three_it_begin, three_it_end);
	three.assign(10, 1000);
	two_it_begin = two.begin();
	two_it_end = two.end();
	ft_print_it_range(two_it_begin, two_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);

	three.insert(three_it_begin, 50);

	ft_print_it_range(three.begin(), three.end());

	three_it_begin = three.insert(three.begin(), 500);
	three_it_end = three.insert(three.end(), 5000);
	three.insert(three_it_begin, 2, 2);
	ft_print_it_range(three_it_begin, three_it_end);
	ft_print_it_range(three_it_begin, three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);
	three_it_begin++;
	three.insert(three_it_begin, two_it_begin, two_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);

	// three_it_begin = three.begin();
	// three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	// three.erase(three_it_begin, three_it_end);
	std::cout << three.size() << std::endl;

	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);
	std::cout << one.size() << std::endl;
	--one_it_end;
	std::cout << "i:" << *one_it_end << std::endl;
	one_it_begin = one.erase(++one_it_begin, one_it_end);
	// one_it_begin = one.begin();
	// one_it_end = one.end();
	ft_print_it_range(one_it_begin, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	std::cout << one.size() << std::endl;

	one.resize(1);
	std::cout << one.size() << std::endl;
	one.resize(20);
	std::cout << one.size() << std::endl;
	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);

	// std::cout << one.size() << "|" << one.empty() << std::endl;
	// one.clear();
	// std::cout << one.size() << "|" << one.empty() << std::endl;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.rbegin(), three.rend());

	std::cout << one.size() << "|" << one.capacity() << "|" << one.empty() << std::endl;
	std::cout << two.size() << "|" << two.capacity() << "|" << two.empty() << std::endl;
	std::cout << three.size() << "|" << three.capacity() << "|" << three.empty() << std::endl;

	one.clear();

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.rbegin(), three.rend());


	std::cout << one.size() << "|" << one.capacity() << "|" << one.empty() << std::endl;
	std::cout << two.size() << "|" << two.capacity() << "|" << two.empty() << std::endl;
	std::cout << three.size() << "|" << three.capacity() << "|" << three.empty() << std::endl;

	ft_check_all_comp(one, two);
	ft_check_all_comp(two, one);
	ft_check_all_comp(one, three);
	ft_check_all_comp(three, one);
	ft_check_all_comp(two, three);
	ft_check_all_comp(three, two);
	
	T five;
	five.assign(5,5);
	five.assign(2, 2);

	ft_print_it_range(five.begin(), five.end());
	ft_print_it_range(five.rbegin(), five.rend());

	ft_check_all_comp(one.begin(), one.end());
	ft_check_all_comp(two.begin(), two.end());
	ft_check_all_comp(three.begin(), three.end());
	ft_check_all_comp(one.end(), one.begin());
	ft_check_all_comp(two.end(), two.begin());
	ft_check_all_comp(three.end(), three.begin());
	ft_check_all_comp(one.rbegin(), one.rend());
	ft_check_all_comp(two.rbegin(), two.rend());
	ft_check_all_comp(three.rbegin(), three.rend());
	ft_check_all_comp(one.rend(), one.rbegin());
	ft_check_all_comp(two.rend(), two.rbegin());
	ft_check_all_comp(three.rend(), three.rbegin());

	typename T::iterator three_it_begin2 = three.begin();
	typename T::reverse_iterator three_rev_it_begin2 = three.rbegin();

	std::cout << three_it_begin2[0] << std::endl;
	std::cout << three_it_begin2[2] << std::endl;
	std::cout << three_it_begin2[10] << std::endl;
	std::cout << three_rev_it_begin2[0] << std::endl;
	std::cout << three_rev_it_begin2[2] << std::endl;
	std::cout << three_rev_it_begin2[10] << std::endl;

	if (three.end() == three.end())
	{
		std::cout << "same" << std::endl;
	}
	else
		std::cout << "not same" << std::endl;
}

#endif
