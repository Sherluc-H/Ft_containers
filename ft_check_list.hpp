/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:36:46 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/12 19:42:10 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_LIST_HPP
# define FT_CHECK_LIST_HPP

# include <iostream>
# include "ft_check_utils.hpp"

template <class T>
void	ft_print_basic(T &t)
{
	if (!t.empty())
		std::cout << "size: " << t.size() << "| empty: " << t.empty() << "| front: " << t.front() << "| back: " << t.back() << std::endl;
	else
		std::cout << "empty" << std::endl;
}

template <class T>
void	ft_list_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T one;

	std::cout << "max_size: " << one.max_size() << std::endl;
	ft_print_basic(one);

	T two(20, 50);
	ft_print_basic(two);

	T three((size_t)20, 1);
	ft_print_basic(three);

	T four = one;

	one.push_back(2);
	ft_print_basic(one);
	ft_print_basic(four);

	one.pop_back();
	one.push_front(2);
	one.push_front(3);
	one.push_back(1);
	ft_print_basic(one);
	ft_print_basic(four);

	T five = one;

	five.pop_front();
	five.push_front(2);
	five.push_front(3);
	five.pop_front();
	five.push_back(1);
	five.push_back(10);
	five.pop_back();

	ft_print_basic(one);
	ft_print_basic(five);

	T six(one);
	ft_print_basic(six);

	T seven;

	six = five;
	ft_print_basic(six);
	seven = one;
	ft_print_basic(seven);

	T eight(3, 5);
	ft_print_basic(one);
	ft_print_basic(eight);
	eight = one;
	ft_print_basic(one);
	ft_print_basic(eight);
	one.assign(1, 1);
	eight = one;
	ft_print_basic(one);
	ft_print_basic(eight);

	const T nine(5, 6);
	ft_print_basic(nine);

	ft_check_all_comp(one, five);
	ft_check_all_comp(five, four);
	ft_check_all_comp(one, six);
	ft_check_all_comp(six, seven);
	ft_check_all_comp(eight, nine);
	ft_check_all_comp(five, five);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(five.begin(), five.end());
	one = five;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(five.begin(), five.end());

	const T c_one = one;
	int& b1 = one.front();
	const int& b2 = c_one.front();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic(one);
	ft_print_basic(c_one);
	std::cout << "b1:" << b1 << "|" << "b2:" << b2 << std::endl;
	b1 = 100;
	std::cout << "b1:" << b1 << "|" << "b2:" << b2 << std::endl;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic(one);
	ft_print_basic(c_one);
}

template <class T>
void	ft_list_iterator_check()
{
	std::cout << "---iterator check---" << std::endl;

	T one;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);

	one.push_back(0);
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);

	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_end(one.end());
	ft_print_basic(one);

	std::cout << *one_it_begin << std::endl;
	*one_it_begin = 6;
	std::cout << *one_it_begin << std::endl;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	
	T two(one_it_begin, one_it_end);

	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	T three(one_it_begin, one_it_begin);

	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);

	typename T::iterator one_it_begin2 = one_it_begin;

	ft_print_it_range(one_it_begin, one.end());
	ft_print_it_range(one_it_begin2, one.end());

	ft_check_eq(one_it_begin, one_it_begin2);
	ft_check_dif(one_it_begin, one_it_begin2);

	one_it_begin2++;

	ft_print_it_range(one_it_begin, one.end());
	ft_print_it_range(one_it_begin2, one.end());

	ft_check_eq(one_it_begin, one_it_begin2);
	ft_check_dif(one_it_begin, one_it_begin2);

	T four(one_it_begin, ++one_it_begin2);

	ft_print_it_range(four.begin(), four.end());
	ft_print_it_range(four.rbegin(), four.rend());
	ft_print_basic(four);

	std::cout << (*one_it_begin) << std::endl;
	std::cout << (*one_it_begin2) << std::endl;
	std::cout << *one_it_begin++ << std::endl;
	std::cout << *one_it_begin << std::endl;
	std::cout << *++one_it_begin << std::endl;
	std::cout << *one_it_begin << std::endl;
	std::cout << *++one_it_begin << std::endl;
	std::cout << *one_it_begin-- << std::endl;
	std::cout << *--one_it_begin << std::endl;
	std::cout << *one_it_begin << std::endl;
	ft_print_it_range(one_it_begin, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);

	typename T::const_iterator one_cit_begin = one.begin();
	typename T::const_iterator one_cit_end(one.end());
	// one_it_begin = one_cit_begin;
	// one_cit_begin = 0;
	ft_print_it_range(one_cit_begin, one_cit_end);
	std::cout << (*one_cit_begin) << std::endl;
	std::cout << *one_cit_begin++ << std::endl;
	std::cout << *one_cit_begin << std::endl;
	std::cout << *++one_cit_begin << std::endl;
	std::cout << *one_cit_begin << std::endl;
	std::cout << *++one_cit_begin << std::endl;
	std::cout << *one_cit_begin-- << std::endl;
	std::cout << *--one_cit_begin << std::endl;
	std::cout << *one_cit_begin << std::endl;
	ft_print_it_range(one_cit_begin, one_cit_end);

	one_cit_begin = one_it_begin;
	one_cit_end = one_it_end;
	ft_print_it_range(one_cit_begin, one_cit_end);

	const T c_one = one;
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_it_range(c_one.rbegin(), c_one.rend());
	ft_print_basic(c_one);
}

template <class T>
void ft_list_reverse_iterator_check()
{
	std::cout << "---reverse iterator check---" << std::endl;

	T one;
	one.push_back(0);
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);
	typename T::iterator one_it_begin;
	one_it_begin = one.begin();
	typename T::iterator one_it_end(one.end());
	typename T::reverse_iterator one_rit_begin;
	one_rit_begin = one.rbegin();
	typename T::reverse_iterator one_rit_end(one.rend());

	typename T::reverse_iterator one_rit_begin2(one.end());
	typename T::reverse_iterator one_rit_end2(one.begin());
	ft_print_it_range(one_rit_begin2, one_rit_end2);

	ft_print_it_range(one_it_begin, one_it_end);
	ft_print_it_range(one_rit_begin, one_rit_end);
	ft_print_it_range(one_rit_end, one_rit_end);
	ft_print_it_range(one_rit_begin.base(), one_it_end);
	ft_print_it_range(one_rit_end.base(), one_it_end);
	std::cout << *--one_rit_end << std::endl;
	std::cout << *one_rit_begin << std::endl;
	std::cout << *one_rit_begin++ << std::endl;
	std::cout << *one_rit_begin << std::endl;
	std::cout << *++one_rit_begin << std::endl;
	std::cout << *one_rit_begin << std::endl;
	std::cout << *++one_rit_begin << std::endl;
	std::cout << *one_rit_begin << std::endl;
	std::cout << *--one_rit_begin << std::endl;
	std::cout << *one_rit_begin << std::endl;
	std::cout << *one_rit_begin-- << std::endl;
	std::cout << *one_rit_begin << std::endl;
	ft_print_it_range(one_rit_begin, one_rit_end);
	ft_print_it_range(one_rit_begin.base(), one_it_end);
	ft_print_it_range(one_rit_end.base(), one_it_end);
	ft_print_it_range(one_rit_begin, one_rit_begin);
	*one_rit_begin = 10;
	ft_print_it_range(one_rit_begin, one_rit_end);
	ft_print_it_range(one_rit_begin.base(), one_it_end);
	ft_print_it_range(one_rit_end.base(), one_it_end);
	ft_print_it_range(one_rit_begin, one_rit_begin);

	typename T::const_reverse_iterator one_rcit_begin = one.rbegin();
	typename T::const_reverse_iterator one_rcit_end(one.rend());
	// *one_rcit_begin = 0;
	// one_rit_begin = one_rcit_begin;
	ft_print_it_range(one_rcit_begin, one_rcit_end);
	std::cout << *--one_rcit_end << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	std::cout << *one_rcit_begin++ << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	std::cout << *++one_rcit_begin << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	std::cout << *++one_rcit_begin << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	std::cout << *--one_rcit_begin << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	std::cout << *one_rcit_begin-- << std::endl;
	std::cout << *one_rcit_begin << std::endl;
	ft_print_it_range(one_rcit_begin, one_rcit_end);

	one_rcit_begin = one_rit_begin;
	one_rcit_end = one_rit_end;
	ft_print_it_range(one_rcit_begin, one_rcit_end);

	const T c_one = one;
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_it_range(c_one.rbegin(), c_one.rend());
	ft_print_basic(c_one);
}

template <class T>
void ft_list_modifiers_check()
{
	std::cout << "---modifiers check---" << std::endl;
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
	two.push_back(60);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	std::cout << "a" << std::endl;
	one.assign(one.begin(), --one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());

	two.assign(2, 2);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	two.assign(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());

	one.assign(8, 8);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	std::cout << "------------------point----------------" << std::endl;
	typename T::iterator it;
	it = one.insert(one.begin(), 10);
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.insert(one.end(), 11);
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.insert(++one.begin(), 12);
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	one.insert(one.begin(), 1, 1);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), 2, 2);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), 3, 3);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	one.insert(one.begin(), (size_t)1, 1);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), (size_t)2, 2);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), (size_t)3, 3);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	one.insert(one.begin(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	one.resize(5, 10);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	it = one.erase(one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(++one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	it = one.erase(++(++one.begin()));
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(--one.end());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());

	one.push_back(1);
	one.push_back(5);
	one.push_back(2);
	one.push_back(9);
	one.push_back(8);
	one.push_back(2);
	one.push_back(5);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());

	it = one.erase(one.begin(), one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(one.begin(), ++one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(one.begin(), ++one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(++one.begin(), --one.end());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(one.begin(), one.end());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());

	one.push_back(1);
	one.push_back(2);
	one.push_back(10);
	one.push_back(20);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	
	one.swap(two);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	two.swap(one);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	one.resize(0);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	one.resize(10);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	one.clear();
	two.clear();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	one.clear();
	two.clear();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	
}

template<class T>
bool ft_is_digit2(const T& value)
{
	return (value >= 10);
}

template<class T>
bool ft_is_smaller(const T& a, const T& b)
{
	return (a < b);
}

template <class T>
bool ft_is_bigger(const T& a, const T& b)
{
	return (a > b);
}

template <class T>
void ft_list_operations_check()
{
	std::cout << "---operations check---" << std::endl;
	T one;
	T two;
	T three;

	one.assign(3, 3);
	two.assign(6, 6);
	three.assign(9, 9);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	one.splice(one.begin(), two);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	two.assign(2, 2);
	one.splice(++one.begin(), two);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	two.assign(5, 5);
	one.splice(one.end(), two);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	two.assign(10, 10);

	one.splice(one.end(), two, two.begin());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	one.splice(one.end(), two, ++two.begin());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	one.splice(one.end(), two, --two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	one.splice(one.begin(), three, three.begin(), three.begin());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	one.splice(++one.begin(), three, three.begin(), ++three.begin());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	one.splice(one.end(), three, three.begin(), three.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	three.assign(7, 7);
	two = one;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	std::cout << "-------------------HERE" << std::endl;
	three.remove(5);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.remove(10);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.remove(7);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.remove(1);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.push_back(1);
	three.push_front(2);
	three.push_front(1);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.remove(1);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.remove(2);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	one.push_back(100);
	one.push_back(2);
	one.push_back(10);
	one.push_back(11);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	one.remove_if(ft_is_digit2<int>);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);

	std::cout << "--------------------here2" << std::endl;
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.unique();
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.push_back(1);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.unique();
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.push_back(1);
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	three.unique();
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(three);
	one.unique();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);
	one.swap(two);
	one.unique();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	one.unique(ft_is_smaller<int>);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);
	one.unique(ft_is_bigger<int>);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic(one);

	one.sort();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	two.sort();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	three.sort();
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	one.merge(two);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);
	three.clear();
	one.push_back(1);
	three.push_back(2);
	one.merge(three);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic(one);
	ft_print_basic(two);
	ft_print_basic(three);

	one.merge(one);

	T five;
	
	five.reverse();

	one.push_back(1000);
	two.push_back(1);
	two.push_front(10);
	two.push_front(2);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	two.sort(ft_is_bigger<int>);
	one.sort(ft_is_bigger<int>);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	two.merge(one, ft_is_bigger<int>);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(one);
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);
	
	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.clear();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.push_back(2);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.push_front(1);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic(two);

	ft_check_all_comp(one, two);
	ft_check_all_comp(two, one);
	ft_check_all_comp(one, three);
	ft_check_all_comp(three, one);
	ft_check_all_comp(two, three);
	ft_check_all_comp(three, two);
}

#endif
