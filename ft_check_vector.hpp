/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:40:53 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/11 19:06:12 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_VECTOR_HPP
# define FT_CHECK_VECTOR_HPP

# include <iostream>
# include "ft_check_utils.hpp"

template <class T>
void	ft_print_basic2(T &t)
{
	if (!t.empty())
		std::cout << "size: " << t.size() << "|capacity: " << t.capacity() << "| empty: " << t.empty() << "| front: " << t.front() << "| back: " << t.back() << std::endl;
	else
		std::cout << "empty" << "|size: " << t.size() << "|capacity: " << t.capacity() << std::endl;
}

template <class T>
void	ft_vector_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T one;

	std::cout << "max_size: " << one.max_size() << std::endl;
	ft_print_basic2(one);

	T two(20, 50);
	ft_print_basic2(two);

	T three((size_t)20, 1);
	ft_print_basic2(three);

	T four = one;

	one.push_back(2);
	ft_print_basic2(one);
	ft_print_basic2(four);

	one.pop_back();
	// one.push_front(2);
	// one.push_front(3);
	one.push_back(1);
	ft_print_basic2(one);
	ft_print_basic2(four);

	T five = one;

	// five.pop_front();
	// five.push_front(2);
	// five.push_front(3);
	// five.pop_front();
	five.push_back(1);
	five.push_back(10);
	five.pop_back();

	ft_print_basic2(one);
	ft_print_basic2(five);

	T six(one);
	ft_print_basic2(six);

	T seven;

	six = five;
	ft_print_basic2(six);
	seven = one;
	ft_print_basic2(seven);

	T eight(3, 5);
	std::cout << "---here" << std::endl;
	one.push_back(2);
	ft_print_basic2(one);
	ft_print_basic2(eight);
	eight = one;
	ft_print_basic2(one);
	ft_print_basic2(eight);
	one.assign(1, 1);
	eight = one;
	ft_print_basic2(one);
	ft_print_basic2(eight);

	const T nine(5, 6);
	ft_print_basic2(nine);

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
	ft_print_basic2(one);
	ft_print_basic2(c_one);
	std::cout << "b1:" << b1 << "|" << "b2:" << b2 << std::endl;
	std::cout << one.at(0) << "|" << one.at(1) << "|" << one[0] << "|" << one[1] << std::endl;
	std::cout << c_one.at(0) << "|" << c_one.at(1) << "|" << c_one[0] << "|" << c_one[1] << std::endl;
	b1 = 100;
	std::cout << one.at(0) << "|" << one.at(1) << "|" << one[0] << "|" << one[1] << std::endl;
	std::cout << c_one.at(0) << "|" << c_one.at(1) << "|" << c_one[0] << "|" << c_one[1] << std::endl;
	std::cout << "b1:" << b1 << "|" << "b2:" << b2 << std::endl;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);

	one.at(0) = 1;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);
	one.at(1) = 2;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);
	// one.at(2) = 3;
	// c_one.at(0) = 11;
	one[0] = 3;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);
	one[1] = 4;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);
	// one[2] = 33;
	// c_one[0] = 111;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_basic2(one);
	ft_print_basic2(c_one);

	std::cout << "-------------------here" << std::endl;

	T vec;

	std::cout << vec.max_size() << std::endl;
	ft_print_basic2(vec);

	vec.reserve(3);
	ft_print_basic2(vec);
	// vec.pop_back();
	vec.push_back(1);
	ft_print_basic2(vec);
	std::cout << vec[0] << std::endl;
	vec.push_back(2);
	ft_print_basic2(vec);
	vec.push_back(3);
	ft_print_basic2(vec);
	vec.push_back(4);
	ft_print_basic2(vec);
	vec.push_back(1);
	ft_print_basic2(vec);
	vec.push_back(3);
	ft_print_basic2(vec);
	vec.push_back(5);
	ft_print_basic2(vec);
	vec.pop_back();
	ft_print_basic2(vec);
	vec.pop_back();
	ft_print_basic2(vec);
	vec.pop_back();
	ft_print_basic2(vec);
	vec.pop_back();
	ft_print_basic2(vec);
	vec.pop_back();
	ft_print_basic2(vec);
	vec.pop_back();
	// vec.pop_back();
	ft_print_basic2(vec);
	vec.push_back(1);
	ft_print_basic2(vec);
	vec.push_back(2);
	ft_print_basic2(vec);
	vec.push_back(3);
	ft_print_basic2(vec);
	// vec.pop_back();
	// vec.clear();
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	ft_print_basic2(vec);
	vec.resize(14);
	std::cout << vec.at(13) << std::endl;
	ft_print_basic2(vec);
	vec.resize(0, 1);
	ft_print_basic2(vec);
	vec.resize(3, 8);
	ft_print_basic2(vec);
	// vec.resize(-10, 1);
	ft_print_basic2(vec);

	const T vec2 = vec;
	ft_print_basic2(vec);
	ft_print_basic2(vec2);
	std::cout << vec2[1] << std::endl;
	std::cout << vec2.at(2) << std::endl;

	ft_print_basic2(vec);
	vec.reserve(5);
	ft_print_basic2(vec);
	vec.reserve(0);
	ft_print_basic2(vec);
	vec.reserve(1);
	ft_print_basic2(vec);
	vec.reserve(10);
	ft_print_basic2(vec);
	vec.reserve(100);
	ft_print_basic2(vec);
}

template <class T>
void	ft_vector_iterator_check()
{
	std::cout << "---iterator check---" << std::endl;

	T one;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);

	one.push_back(0);
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);

	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_end(one.end());
	ft_print_basic2(one);

	std::cout << *one_it_begin << std::endl;
	*one_it_begin = 6;
	std::cout << *one_it_begin << std::endl;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	
	T two(one_it_begin, one_it_end);

	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(two);

	T three(one_it_begin, one_it_begin);

	ft_print_it_range(three.begin(), three.end());
	ft_print_it_range(three.rbegin(), three.rend());
	ft_print_basic2(three);

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
	ft_print_basic2(four);

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
	ft_print_basic2(one);

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
	ft_print_basic2(c_one);

	ft_check_all_comp(one.begin(), one.end());
	ft_check_all_comp(one.begin(), one.begin());
	ft_check_all_comp(one.begin(), ++one.begin());
	ft_check_all_comp(one.begin(), --one.end());
	ft_check_all_comp(one.end(), one.end());
	ft_check_all_comp(c_one.begin(), c_one.end());
	ft_check_all_comp(c_one.begin(), c_one.begin());
	ft_check_all_comp(c_one.begin(), ++c_one.begin());
	ft_check_all_comp(c_one.begin(), --c_one.end());
	ft_check_all_comp(c_one.end(), c_one.end());

	//iterator random access

	std::cout << one.begin() - one.end() << std::endl;
	std::cout << one.begin() - --one.end() << std::endl;
	std::cout << one.begin() - --(--one.end()) << std::endl;
	std::cout << ++one.begin() - one.end() << std::endl;
	std::cout << one.begin()++ - one.end() << std::endl;
	std::cout << one.end() - one.end() << std::endl;
	std::cout << one.end() - one.begin() << std::endl;
	std::cout << one.end() - ++one.begin() << std::endl;
	std::cout << one.end() - --one.end() << std::endl;
	std::cout << one.end() - one.end()-- << std::endl;

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.begin() + 0, one.end() + -2);
	ft_print_it_range(one.begin() - -1, one.end() - 1);
	ft_print_it_range(one.begin() + 2, one.end() - 0);
	ft_print_it_range(one.begin(), one.end() - 3);

	ft_print_it_range(0 + one.begin(), one.end());
	ft_print_it_range(1 + one.begin(), one.end());
	ft_print_it_range(2 + one.begin(), one.end());
	ft_print_it_range(3 + one.begin(), one.end());
	ft_print_it_range(one.begin(), 1 + --one.end());

	typename T::iterator one_it_begin3 = one.begin();
	typename T::iterator one_it_end3 = one.end();

	ft_print_it_range(one_it_begin3, one_it_end3);
	ft_print_it_range(one_it_begin3 + 1, one_it_end3);
	ft_print_it_range(one_it_begin3, one_it_end3 - 2);
	ft_print_it_range(3 + one_it_begin3, one_it_end3);
	std::cout << one_it_end3 - one_it_begin3 << std::endl;

	ft_print_it_range(one_it_begin3, one_it_end3);
	one_it_begin3+=2;
	one_it_end3-=2;
	ft_print_it_range(one_it_begin3, one_it_end3);

	one_it_begin3 = one.begin();
	one_it_end3 = one.end();
	ft_print_it_range(one_it_begin3, one_it_end3);
	one_it_begin3-=-2;
	one_it_end3+=-2;
	ft_print_it_range(one_it_begin3, one_it_end3);

	one_it_begin3 = one.begin();
	one_it_end3 = one.end();
	ft_print_it_range(one_it_begin3, one_it_end3);
	one_it_begin3+=1;
	one_it_end3+=-2;
	ft_print_it_range(one_it_begin3, one_it_end3);

	ft_print_it_range(one.begin(), one.end());
	std::cout << one_it_begin3[0] << std::endl;
	std::cout << one_it_begin3[1] << std::endl;
	std::cout << one_it_begin3[2] << std::endl;
	std::cout << one_it_begin3[-1] << std::endl;
	// std::cout << one_it_begin3[-2] << std::endl;
	std::cout << one_it_end3[0] << std::endl;
	std::cout << one_it_end3[1] << std::endl;
	// std::cout << one_it_end3[2] << std::endl;
	std::cout << one_it_end3[-1] << std::endl;
	std::cout << one_it_end3[-2] << std::endl;
	ft_print_it_range(one.begin(), one.end());
	one_it_begin3[0] = 10;
	one_it_end3[0] = 100;
	ft_print_it_range(one.begin(), one.end());
	one_it_begin3[-1] = 20;
	one_it_end3[1] = 200;
	ft_print_it_range(one.begin(), one.end());

	//const_iterator random access

	std::cout << c_one.begin() - c_one.end() << std::endl;
	std::cout << c_one.begin() - --c_one.end() << std::endl;
	std::cout << c_one.begin() - --(--c_one.end()) << std::endl;
	std::cout << ++c_one.begin() - c_one.end() << std::endl;
	std::cout << c_one.begin()++ - c_one.end() << std::endl;
	std::cout << c_one.end() - c_one.end() << std::endl;
	std::cout << c_one.end() - c_one.begin() << std::endl;
	std::cout << c_one.end() - ++c_one.begin() << std::endl;
	std::cout << c_one.end() - --c_one.end() << std::endl;
	std::cout << c_one.end() - c_one.end()-- << std::endl;

	ft_print_it_range(c_one.begin(), c_one.end());
	ft_print_it_range(c_one.begin() + 0, c_one.end() + -2);
	ft_print_it_range(c_one.begin() - -1, c_one.end() - 1);
	ft_print_it_range(c_one.begin() + 2, c_one.end() - 0);
	ft_print_it_range(c_one.begin(), c_one.end() - 3);

	ft_print_it_range(0 + c_one.begin(), c_one.end());
	ft_print_it_range(1 + c_one.begin(), c_one.end());
	ft_print_it_range(2 + c_one.begin(), c_one.end());
	ft_print_it_range(3 + c_one.begin(), c_one.end());
	ft_print_it_range(c_one.begin(), 1 + --c_one.end());

	typename T::const_iterator c_one_it_begin3 = c_one.begin();
	typename T::const_iterator c_one_it_end3 = c_one.end();

	ft_print_it_range(c_one_it_begin3, c_one_it_end3);
	ft_print_it_range(c_one_it_begin3 + 1, c_one_it_end3);
	ft_print_it_range(c_one_it_begin3, c_one_it_end3 - 2);
	ft_print_it_range(3 + c_one_it_begin3, c_one_it_end3);
	std::cout << c_one_it_end3 - c_one_it_begin3 << std::endl;

	ft_print_it_range(c_one_it_begin3, c_one_it_end3);
	c_one_it_begin3+=2;
	c_one_it_end3-=2;
	ft_print_it_range(c_one_it_begin3, c_one_it_end3);

	c_one_it_begin3 = c_one.begin();
	c_one_it_end3 = c_one.end();
	ft_print_it_range(c_one_it_begin3, c_one_it_end3);
	c_one_it_begin3-=-2;
	c_one_it_end3+=-2;
	ft_print_it_range(c_one_it_begin3, c_one_it_end3);

	c_one_it_begin3 = c_one.begin();
	c_one_it_end3 = c_one.end();
	ft_print_it_range(c_one_it_begin3, c_one_it_end3);
	c_one_it_begin3+=1;
	c_one_it_end3+=-2;
	ft_print_it_range(c_one_it_begin3, c_one_it_end3);

	ft_print_it_range(c_one.begin(), c_one.end());
	std::cout << c_one_it_begin3[0] << std::endl;
	std::cout << c_one_it_begin3[1] << std::endl;
	std::cout << c_one_it_begin3[2] << std::endl;
	std::cout << c_one_it_begin3[-1] << std::endl;
	// std::cout << c_one_it_begin3[-2] << std::endl;
	std::cout << c_one_it_end3[0] << std::endl;
	std::cout << c_one_it_end3[1] << std::endl;
	// std::cout << c_one_it_end3[2] << std::endl;
	std::cout << c_one_it_end3[-1] << std::endl;
	std::cout << c_one_it_end3[-2] << std::endl;
	ft_print_it_range(c_one.begin(), c_one.end());
	// c_one_it_begin3[0] = 10;
	// c_one_it_end3[0] = 100;
	ft_print_it_range(c_one.begin(), c_one.end());
	// c_one_it_begin3[-1] = 20;
	// c_one_it_end3[1] = 200;
	ft_print_it_range(c_one.begin(), c_one.end());
}

template <class T>
void ft_vector_reverse_iterator_check()
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

	ft_check_all_comp(one.rbegin(), one.rend());
	ft_check_all_comp(one.rbegin(), one.rbegin());
	ft_check_all_comp(one.rbegin(), ++one.rbegin());
	ft_check_all_comp(one.rbegin(), --one.rend());
	ft_check_all_comp(one.rend(), one.rend());
	ft_check_all_comp(c_one.rbegin(), c_one.rend());
	ft_check_all_comp(c_one.rbegin(), c_one.rbegin());
	ft_check_all_comp(c_one.rbegin(), ++c_one.rbegin());
	ft_check_all_comp(c_one.rbegin(), --c_one.rend());
	ft_check_all_comp(c_one.rend(), c_one.rend());

	//reverse random access

	std::cout << one.rbegin() - one.rend() << std::endl;
	std::cout << one.rbegin() - --one.rend() << std::endl;
	std::cout << one.rbegin() - --(--one.rend()) << std::endl;
	std::cout << ++one.rbegin() - one.rend() << std::endl;
	std::cout << one.rbegin()++ - one.rend() << std::endl;
	std::cout << one.rend() - one.rend() << std::endl;
	std::cout << one.rend() - one.rbegin() << std::endl;
	std::cout << one.rend() - ++one.rbegin() << std::endl;
	std::cout << one.rend() - --one.rend() << std::endl;
	std::cout << one.rend() - one.rend()-- << std::endl;

	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(one.rbegin() + 0, one.rend() + -2);
	ft_print_it_range(one.rbegin() - -1, one.rend() - 1);
	ft_print_it_range(one.rbegin() + 2, one.rend() - 0);
	ft_print_it_range(one.rbegin(), one.rend() - 3);

	ft_print_it_range(0 + one.rbegin(), one.rend());
	ft_print_it_range(1 + one.rbegin(), one.rend());
	ft_print_it_range(2 + one.rbegin(), one.rend());
	ft_print_it_range(3 + one.rbegin(), one.rend());
	ft_print_it_range(one.rbegin(), 1 + --one.rend());

	typename T::reverse_iterator one_rit_begin3 = one.rbegin();
	typename T::reverse_iterator one_rit_end3 = one.rend();

	ft_print_it_range(one_rit_begin3, one_rit_end3);
	ft_print_it_range(one_rit_begin3 + 1, one_rit_end3);
	ft_print_it_range(one_rit_begin3, one_rit_end3 - 2);
	ft_print_it_range(3 + one_rit_begin3, one_rit_end3);
	std::cout << one_rit_end3 - one_rit_begin3 << std::endl;

	ft_print_it_range(one_rit_begin3, one_rit_end3);
	one_rit_begin3+=2;
	one_rit_end3-=2;
	ft_print_it_range(one_rit_begin3, one_rit_end3);

	one_rit_begin3 = one.rbegin();
	one_rit_end3 = one.rend();
	ft_print_it_range(one_rit_begin3, one_rit_end3);
	one_rit_begin3-=-2;
	one_rit_end3+=-2;
	ft_print_it_range(one_rit_begin3, one_rit_end3);

	one_rit_begin3 = one.rbegin();
	one_rit_end3 = one.rend();
	ft_print_it_range(one_rit_begin3, one_rit_end3);
	one_rit_begin3+=1;
	one_rit_end3+=-2;
	ft_print_it_range(one_rit_begin3, one_rit_end3);

	ft_print_it_range(one.rbegin(), one.rend());
	std::cout << one_rit_begin3[0] << std::endl;
	std::cout << one_rit_begin3[1] << std::endl;
	std::cout << one_rit_begin3[2] << std::endl;
	std::cout << one_rit_begin3[-1] << std::endl;
	// std::cout << one_rit_begin3[-2] << std::endl;
	std::cout << one_rit_end3[0] << std::endl;
	std::cout << one_rit_end3[1] << std::endl;
	// std::cout << one_rit_end3[2] << std::endl;
	std::cout << one_rit_end3[-1] << std::endl;
	std::cout << one_rit_end3[-2] << std::endl;
	ft_print_it_range(one.rbegin(), one.rend());
	one_rit_begin3[0] = 10;
	one_rit_end3[0] = 100;
	ft_print_it_range(one.rbegin(), one.rend());
	one_rit_begin3[-1] = 20;
	one_rit_end3[1] = 200;
	ft_print_it_range(one.rbegin(), one.rend());

	//const reverse random access

	std::cout << c_one.rbegin() - c_one.rend() << std::endl;
	std::cout << c_one.rbegin() - --c_one.rend() << std::endl;
	std::cout << c_one.rbegin() - --(--c_one.rend()) << std::endl;
	std::cout << ++c_one.rbegin() - c_one.rend() << std::endl;
	std::cout << c_one.rbegin()++ - c_one.rend() << std::endl;
	std::cout << c_one.rend() - c_one.rend() << std::endl;
	std::cout << c_one.rend() - c_one.rbegin() << std::endl;
	std::cout << c_one.rend() - ++c_one.rbegin() << std::endl;
	std::cout << c_one.rend() - --c_one.rend() << std::endl;
	std::cout << c_one.rend() - c_one.rend()-- << std::endl;

	ft_print_it_range(c_one.rbegin(), c_one.rend());
	ft_print_it_range(c_one.rbegin() + 0, c_one.rend() + -2);
	ft_print_it_range(c_one.rbegin() - -1, c_one.rend() - 1);
	ft_print_it_range(c_one.rbegin() + 2, c_one.rend() - 0);
	ft_print_it_range(c_one.rbegin(), c_one.rend() - 3);

	ft_print_it_range(0 + c_one.rbegin(), c_one.rend());
	ft_print_it_range(1 + c_one.rbegin(), c_one.rend());
	ft_print_it_range(2 + c_one.rbegin(), c_one.rend());
	ft_print_it_range(3 + c_one.rbegin(), c_one.rend());
	ft_print_it_range(c_one.rbegin(), 1 + --c_one.rend());

	typename T::const_reverse_iterator one_crit_begin3 = c_one.rbegin();
	typename T::const_reverse_iterator one_crit_end3 = c_one.rend();

	ft_print_it_range(one_crit_begin3, one_crit_end3);
	ft_print_it_range(one_crit_begin3 + 1, one_crit_end3);
	ft_print_it_range(one_crit_begin3, one_crit_end3 - 2);
	ft_print_it_range(3 + one_crit_begin3, one_crit_end3);
	std::cout << one_crit_end3 - one_crit_begin3 << std::endl;

	ft_print_it_range(one_crit_begin3, one_crit_end3);
	one_crit_begin3+=2;
	one_crit_end3-=2;
	ft_print_it_range(one_crit_begin3, one_crit_end3);

	one_crit_begin3 = c_one.rbegin();
	one_crit_end3 = c_one.rend();
	ft_print_it_range(one_crit_begin3, one_crit_end3);
	one_crit_begin3-=-2;
	one_crit_end3+=-2;
	ft_print_it_range(one_crit_begin3, one_crit_end3);

	one_crit_begin3 = c_one.rbegin();
	one_crit_end3 = c_one.rend();
	ft_print_it_range(one_crit_begin3, one_crit_end3);
	one_crit_begin3+=1;
	one_crit_end3+=-2;
	ft_print_it_range(one_crit_begin3, one_crit_end3);

	ft_print_it_range(c_one.rbegin(), c_one.rend());
	std::cout << one_crit_begin3[0] << std::endl;
	std::cout << one_crit_begin3[1] << std::endl;
	std::cout << one_crit_begin3[2] << std::endl;
	std::cout << one_crit_begin3[-1] << std::endl;
	// std::cout << one_crit_begin3[-2] << std::endl;
	std::cout << one_crit_end3[0] << std::endl;
	std::cout << one_crit_end3[1] << std::endl;
	// std::cout << one_crit_end3[2] << std::endl;
	std::cout << one_crit_end3[-1] << std::endl;
	std::cout << one_crit_end3[-2] << std::endl;
	ft_print_it_range(c_one.rbegin(), c_one.rend());
	// one_crit_begin3[0] = 10;
	// one_crit_end3[0] = 100;
	ft_print_it_range(c_one.rbegin(), c_one.rend());
	// one_crit_begin3[-1] = 20;
	// one_crit_end3[1] = 200;
	ft_print_it_range(c_one.rbegin(), c_one.rend());
}

template <class T>
void ft_vector_modifiers_check()
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

	// one.clear();
	// two.clear();

	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	std::cout << "a" << std::endl;
	one.assign(one.begin(), --one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());

	two.assign(2, 2);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	two.assign(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());

	one.assign(8, 8);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	std::cout << "------------------point----------------" << std::endl;
	// one.clear();
	// two.clear();
	typename T::iterator it;
	it = one.insert(one.begin(), 10);
	ft_print_basic2(one);
	ft_print_basic2(two);
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
	ft_print_basic2(one);
	ft_print_basic2(two);

	one.insert(one.begin(), 1, 1);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), 2, 2);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), 3, 3);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	one.insert(one.begin(), (size_t)1, 1);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), (size_t)2, 2);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), (size_t)3, 3);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	one.insert(one.begin(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(one.end(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	one.insert(++one.begin(), two.begin(), two.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	one.resize(5, 10);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);

	// one.clear();
	// one.push_back(1);
	it = one.erase(one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	it = one.erase(++one.begin());
	ft_print_it_range(it, one.end());
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);
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
	ft_print_basic2(one);
	ft_print_basic2(two);

	// one.clear();
	// two.clear();

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
	ft_print_basic2(one);
	ft_print_basic2(two);

	one.resize(0);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_basic2(one);
	one.resize(10);
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);
	one.clear();
	two.clear();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);
	one.clear();
	two.clear();
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(one.rbegin(), one.rend());
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	ft_print_basic2(one);
	ft_print_basic2(two);
	
}

#endif
