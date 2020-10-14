/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:45:28 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/14 00:09:49 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_MAP_HPP
# define FT_CHECK_MAP_HPP

# include <iostream>
# include <map>

template <class T>
void	ft_print_basic3(T &t)
{
	if (!t.empty())
		std::cout << "size: " << t.size() << "| empty: " << t.empty() << std::endl;
	else
		std::cout << "empty" << std::endl;
}

template <class T>
void	ft_map_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T one;

	std::cout << "max_size: " << one.max_size() << std::endl;
	ft_print_basic3(one);

	T two(one);
	ft_print_basic3(one);
	ft_print_basic3(two);

	T four = one;

	ft_print_basic3(one);
	ft_print_basic3(four);

	one.insert(std::pair<int, int>(10, 10));

	ft_print_basic3(one);
	ft_print_basic3(four);

	T five = one;

	five.insert(std::pair<int, int>(2, 2));
	five.insert(std::pair<int, int>(3, 3));
	five.insert(std::pair<int, int>(1, 1));
	five.insert(std::pair<int, int>(10, 10));
	five.insert(std::pair<int, int>(10, 10));
	five.insert(std::pair<int, int>(10, 10));

	ft_print_basic3(one);
	ft_print_basic3(five);

	T six(one);
	ft_print_basic3(one);
	ft_print_basic3(six);

	T seven;

	six = five;
	ft_print_basic3(six);
	seven = one;
	ft_print_basic3(seven);

	std::cout << "----------------------here" << std::endl;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(six.begin(), six.end());
	ft_print_basic3(one);
	ft_print_basic3(six);
	six = one;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(six.begin(), six.end());
	ft_print_basic3(one);
	ft_print_basic3(six);

	ft_print_basic3(one);

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(five.begin(), five.end());
	one = five;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(five.begin(), five.end());

	five = seven;
	ft_print_it_range_pair(five.begin(), five.end());

	const T c_one = one;
	std::pair<const int, int>& b1 = *(one.begin());
	const std::pair<const int, int>& b2 = *(c_one.begin());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(c_one.begin(), c_one.end());
	ft_print_basic3(one);
	ft_print_basic3(c_one);
	std::cout << (*one.begin()).first << (*one.begin()).second << std::endl;
	std::cout << (*c_one.begin()).first << (*c_one.begin()).second << std::endl;
	std::cout << "b1:" << b1.first << "|" << b1.second << "|" << "b2:" << b2.first << "|" << b2.second << std::endl;
	b1.second = 100;
	std::cout << (*one.begin()).first << (*one.begin()).second << std::endl;
	std::cout << (*c_one.begin()).first << (*c_one.begin()).second << std::endl;
	std::cout << "b1:" << b1.first << "|" << b1.second << "|" << "b2:" << b2.first << "|" << b2.second << std::endl;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(c_one.begin(), c_one.end());
	ft_print_basic3(one);
	ft_print_basic3(c_one);
}

template <class T, class T1, class T2>
void ft_map_common_check2()
{
	T mp;
	T1 mpb;
	T2 mps;

	mp[0] = 0;
	mp[1] = 1;
	mp[2] = 2;
	mp[3] = 3;

	mpb[0] = 0;
	mpb[1] = 1;
	mpb[2] = 2;
	mpb[3] = 3;

	mps[0] = 0;
	mps[1] = 1;
	mps[2] = 2;
	mps[3] = 3;

	ft_print_it_range_pair(mp.begin(), mp.end());
	ft_print_it_range_pair(mpb.begin(), mpb.end());
	ft_print_it_range_pair(mps.begin(), mps.end());
	ft_print_it_range_pair(mp.rbegin(), mp.rend());
	ft_print_it_range_pair(mpb.rbegin(), mpb.rend());
	ft_print_it_range_pair(mps.rbegin(), mps.rend());

	T1 mb2 = mpb;
	T2 ms2 = mps;
	ft_print_it_range_pair(mpb.begin(), mpb.end());
	ft_print_it_range_pair(mps.begin(), mps.end());
	ft_print_it_range_pair(mb2.begin(), mb2.end());
	ft_print_it_range_pair(ms2.begin(), ms2.end());
	ft_print_it_range_pair(mpb.rbegin(), mpb.rend());
	ft_print_it_range_pair(mps.rbegin(), mps.rend());
	ft_print_it_range_pair(mb2.rbegin(), mb2.rend());
	ft_print_it_range_pair(ms2.rbegin(), ms2.rend());
	mpb[5] = 5;
	ms2[5] = 5;
	ft_print_it_range_pair(mpb.begin(), mpb.end());
	ft_print_it_range_pair(mps.begin(), mps.end());
	ft_print_it_range_pair(mb2.begin(), mb2.end());
	ft_print_it_range_pair(ms2.begin(), ms2.end());
	ft_print_it_range_pair(mpb.rbegin(), mpb.rend());
	ft_print_it_range_pair(mps.rbegin(), mps.rend());
	ft_print_it_range_pair(mb2.rbegin(), mb2.rend());
	ft_print_it_range_pair(ms2.rbegin(), ms2.rend());

	T t;
	T1 t1;
	T2 t2;
	typename T::value_compare tvalue_comp = t.value_comp();
	typename T1::value_compare t1value_comp = t1.value_comp();
	typename T2::value_compare t2value_comp = t2.value_comp();
	typename T::key_compare tkey_comp = t.key_comp();
	typename T1::key_compare t1key_comp = t1.key_comp();
	typename T2::key_compare t2key_comp = t2.key_comp();

	std::cout << tvalue_comp(std::pair<int, int>(1, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << t1value_comp(std::pair<int, int>(1, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << t2value_comp(std::pair<int, int>(1, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << tkey_comp(1, 1) << std::endl;
	std::cout << t1key_comp(1, 1) << std::endl;
	std::cout << t2key_comp(1, 1) << std::endl;
	std::cout << tvalue_comp(std::pair<int, int>(0, 1), std::pair<int, int>(0, 1)) << std::endl;
	std::cout << t1value_comp(std::pair<int, int>(0, 1), std::pair<int, int>(0, 1)) << std::endl;
	std::cout << t2value_comp(std::pair<int, int>(0, 1), std::pair<int, int>(0, 1)) << std::endl;
	std::cout << tkey_comp(0, 1) << std::endl;
	std::cout << t1key_comp(0, 1) << std::endl;
	std::cout << t2key_comp(0, 1) << std::endl;
	std::cout << tvalue_comp(std::pair<int, int>(1, 0), std::pair<int, int>(1, 0)) << std::endl;
	std::cout << t1value_comp(std::pair<int, int>(1, 0), std::pair<int, int>(1, 0)) << std::endl;
	std::cout << t2value_comp(std::pair<int, int>(1, 0), std::pair<int, int>(1, 0)) << std::endl;
	std::cout << tkey_comp(1, 0) << std::endl;
	std::cout << t1key_comp(1, 0) << std::endl;
	std::cout << t2key_comp(1, 0) << std::endl;
	std::cout << tvalue_comp(std::pair<int, int>(0, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << t1value_comp(std::pair<int, int>(0, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << t2value_comp(std::pair<int, int>(0, 1), std::pair<int, int>(1, 1)) << std::endl;
	std::cout << tvalue_comp(std::pair<int, int>(1, 1), std::pair<int, int>(0, 1)) << std::endl;
	std::cout << t1value_comp(std::pair<int, int>(1, 1), std::pair<int, int>(0, 1)) << std::endl;
	std::cout << t2value_comp(std::pair<int, int>(1, 1), std::pair<int, int>(0, 1)) << std::endl;
	

	std::cout << t.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
	std::cout << t1.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
	std::cout << t2.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
	typename T1::value_compare::first_argument_type f1(10, 2);
	std::cout << f1.first << std::endl;

}

template <class T>
void	ft_map_iterator_check()
{
	std::cout << "---iterator check---" << std::endl;

	T one;

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);

	one[0] = 1;
	one[1] = 1;
	one[2] = 2;
	one[0] = 0;
	one[3] = 3;

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);

	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_end(one.end());
	ft_print_basic3(one);

	std::cout << (*one_it_begin).first << std::endl;
	(*one_it_begin).second = 6;
	std::cout << (*one_it_begin).first << std::endl;

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);
	
	T two(one_it_begin, one_it_end);

	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(two);

	T three(one_it_begin, one_it_begin);

	ft_print_it_range_pair(three.begin(), three.end());
	ft_print_it_range_pair(three.rbegin(), three.rend());
	ft_print_basic3(three);

	typename T::iterator one_it_begin2 = one_it_begin;

	ft_print_it_range_pair(one_it_begin, one.end());
	ft_print_it_range_pair(one_it_begin2, one.end());

	ft_check_eq(one_it_begin, one_it_begin2);
	ft_check_dif(one_it_begin, one_it_begin2);

	one_it_begin2++;

	ft_print_it_range_pair(one_it_begin, one.end());
	ft_print_it_range_pair(one_it_begin2, one.end());

	ft_check_eq(one_it_begin, one_it_begin2);
	ft_check_dif(one_it_begin, one_it_begin2);

	T four(one_it_begin, ++one_it_begin2);

	ft_print_it_range_pair(four.begin(), four.end());
	ft_print_it_range_pair(four.rbegin(), four.rend());
	ft_print_basic3(four);

	std::cout << ((*one_it_begin)).first << std::endl;
	std::cout << ((*one_it_begin2)).first << std::endl;
	std::cout << (*one_it_begin++).first << std::endl;
	std::cout << (*one_it_begin).first << std::endl;
	std::cout << (*++one_it_begin).first << std::endl;
	std::cout << (*one_it_begin).first << std::endl;
	std::cout << (*++one_it_begin).first << std::endl;
	std::cout << (*one_it_begin--).first << std::endl;
	std::cout << (*--one_it_begin).first << std::endl;
	std::cout << (*one_it_begin).first << std::endl;
	ft_print_it_range_pair(one_it_begin, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);

	typename T::const_iterator one_cit_begin = one.begin();
	typename T::const_iterator one_cit_end(one.end());
	ft_print_it_range_pair(one_cit_begin, one_cit_end);
	std::cout << ((*one_cit_begin)).first << std::endl;
	std::cout << (*one_cit_begin++).first << std::endl;
	std::cout << (*one_cit_begin).first << std::endl;
	std::cout << (*++one_cit_begin).first << std::endl;
	std::cout << (*one_cit_begin).first << std::endl;
	std::cout << (*++one_cit_begin).first << std::endl;
	std::cout << (*one_cit_begin--).first << std::endl;
	std::cout << (*--one_cit_begin).first << std::endl;
	std::cout << (*one_cit_begin).first << std::endl;
	ft_print_it_range_pair(one_cit_begin, one_cit_end);

	one_cit_begin = one_it_begin;
	one_cit_end = one_it_end;
	ft_print_it_range_pair(one_cit_begin, one_cit_end);

	const T c_one = one;
	ft_print_it_range_pair(c_one.begin(), c_one.end());
	ft_print_it_range_pair(c_one.rbegin(), c_one.rend());
	ft_print_basic3(c_one);
}

template <class T>
void ft_map_reverse_iterator_check()
{
	std::cout << "---reverse iterator check---" << std::endl;

	T one;
	one[0] = 0;
	one[1] = 1;
	one[2] = 2;
	one[3] = 3;
	typename T::iterator one_it_begin;
	one_it_begin = one.begin();
	typename T::iterator one_it_end(one.end());
	typename T::reverse_iterator one_rit_begin;
	one_rit_begin = one.rbegin();
	typename T::reverse_iterator one_rit_end(one.rend());

	typename T::reverse_iterator one_rit_begin2(one.end());
	typename T::reverse_iterator one_rit_end2(one.begin());
	ft_print_it_range_pair(one_rit_begin2, one_rit_end2);

	ft_print_it_range_pair(one_it_begin, one_it_end);
	ft_print_it_range_pair(one_rit_begin, one_rit_end);
	ft_print_it_range_pair(one_rit_end, one_rit_end);
	ft_print_it_range_pair(one_rit_begin.base(), one_it_end);
	ft_print_it_range_pair(one_rit_end.base(), one_it_end);
	std::cout << (*--one_rit_end).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	std::cout << (*one_rit_begin++).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	std::cout << (*++one_rit_begin).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	std::cout << (*++one_rit_begin).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	std::cout << (*--one_rit_begin).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	std::cout << (*one_rit_begin--).first << std::endl;
	std::cout << (*one_rit_begin).first << std::endl;
	ft_print_it_range_pair(one_rit_begin, one_rit_end);
	ft_print_it_range_pair(one_rit_begin.base(), one_it_end);
	ft_print_it_range_pair(one_rit_end.base(), one_it_end);
	ft_print_it_range_pair(one_rit_begin, one_rit_begin);
	(*one_rit_begin).second = 10;
	ft_print_it_range_pair(one_rit_begin, one_rit_end);
	ft_print_it_range_pair(one_rit_begin.base(), one_it_end);
	ft_print_it_range_pair(one_rit_end.base(), one_it_end);
	ft_print_it_range_pair(one_rit_begin, one_rit_begin);

	typename T::const_reverse_iterator one_rcit_begin = one.rbegin();
	typename T::const_reverse_iterator one_rcit_end(one.rend());
	ft_print_it_range_pair(one_rcit_begin, one_rcit_end);
	std::cout << (*--one_rcit_end).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	std::cout << (*one_rcit_begin++).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	std::cout << (*++one_rcit_begin).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	std::cout << (*++one_rcit_begin).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	std::cout << (*--one_rcit_begin).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	std::cout << (*one_rcit_begin--).first << std::endl;
	std::cout << (*one_rcit_begin).first << std::endl;
	ft_print_it_range_pair(one_rcit_begin, one_rcit_end);

	one_rcit_begin = one_rit_begin;
	one_rcit_end = one_rit_end;
	ft_print_it_range_pair(one_rcit_begin, one_rcit_end);

	const T c_one = one;
	ft_print_it_range_pair(c_one.begin(), c_one.end());
	ft_print_it_range_pair(c_one.rbegin(), c_one.rend());
	ft_print_basic3(c_one);
}

template <class T>
void ft_map_modifiers_check()
{
	std::cout << "---modifiers check---" << std::endl;
	T one;
	one[1] = 1;
	one[2] = 2;
	one[3] = 3;
	one[4] = 4;
	one[6] = 6;
	T two;
	two[10] = 10;
	two[20] = 20;
	two[30] = 30;
	two[40] = 40;
	two[50] = 50;
	two[60] = 60;

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);

	std::cout << "------------------point----------------" << std::endl;

	std::pair<typename T::iterator, bool> pit;

	pit = one.insert(std::pair<int, int>(2, 2));
	ft_print_basic3(one);
	if (pit.second)
		ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	pit = one.insert(std::pair<int, int>(9, 9));
	ft_print_basic3(one);
	if (pit.second)
		ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	pit = one.insert(std::pair<int, int>(6, 6));
	ft_print_basic3(one);
	if (pit.second)
		ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	pit = one.insert(std::pair<int, int>(10, 10));
	ft_print_basic3(one);
	if (pit.second)
		ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	pit = one.insert(std::pair<int, int>(20, 20));
	ft_print_basic3(one);
	if (pit.second)
		ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	typename T::iterator it;
	it = one.insert(one.begin(), std::pair<int, int>(10, 10));
	ft_print_basic3(one);
	ft_print_basic3(two);
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	it = one.insert(one.end(), std::pair<int, int>(11, 11));
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	it = one.insert(++one.begin(), std::pair<int, int>(12, 12));
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);

	one.insert(two.begin(), two.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.insert(two.begin(), two.begin());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.insert(two.begin(), --two.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);

	one.erase(one.begin());
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(++one.begin());
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);
	one.erase(++(++one.begin()));
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(--one.end());
	ft_print_it_range_pair(it, one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	one[1] = 1;
	one[5] = 5;
	one[2] = 2;
	one[9] = 9;
	one[8] = 8;
	one[2] = 2;
	one[5] = 5;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	one.erase(1000);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(1);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(0);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	one.erase(one.begin(), one.begin());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(one.begin(), ++one.begin());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(one.begin(), ++one.begin());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(++one.begin(), --one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(one.begin(), one.end());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	one[1] = 1;
	one[2] = 2;
	one[10] = 10;
	one[20] = 20;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);
	
	one.swap(two);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	two.swap(one);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);

	one.clear();
	two.clear();
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);
	one.clear();
	two.clear();
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	ft_print_basic3(one);
	ft_print_basic3(two);
	
}

template <class T>
void ft_map_operations_check()
{
	T one;

	one[0] = 0;
	one.insert(std::pair<int, int>(15, 15));
	one[10] = 10;
	one.insert(std::pair<int, int>(5, 5));
	one[25] = 25;
	one.insert(std::pair<int, int>(10, 10));
	one[100] = 100;
	one.insert(std::pair<int, int>(20, 20));
	one[30] = 30;
	one[2] = 2;
	one[3] = 3;
	one[4] = 4;
	one[5] = 5;
	one[6] = 6;
	one[7] = 7;
	one[8] = 8;
	one[9] = 9;
	one[10] = 10;
	one[11] = 11;
	one[10] = 10;

	const T c_one = one;

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	ft_print_it_range_pair(one.find(1), one.end());
	ft_print_it_range_pair(one.find(10000), one.end());
	ft_print_it_range_pair(one.find(9), one.end());
	ft_print_it_range_pair(one.find(20), one.end());
	ft_print_it_range_pair(one.find(30), one.end());
	
	ft_print_it_range_pair(c_one.find(1), c_one.end());
	ft_print_it_range_pair(c_one.find(10000), c_one.end());
	ft_print_it_range_pair(c_one.find(9), c_one.end());
	ft_print_it_range_pair(c_one.find(20), c_one.end());
	ft_print_it_range_pair(c_one.find(30), c_one.end());

	std::cout << one.count(1) << std::endl;
	std::cout << one.count(10000) << std::endl;
	std::cout << one.count(9) << std::endl;
	std::cout << one.count(20) << std::endl;
	std::cout << one.count(30) << std::endl;

	std::cout << c_one.count(1) << std::endl;
	std::cout << c_one.count(10000) << std::endl;
	std::cout << c_one.count(9) << std::endl;
	std::cout << c_one.count(20) << std::endl;
	std::cout << c_one.count(30) << std::endl;

	ft_print_it_range_pair(one.lower_bound(1), one.end());
	ft_print_it_range_pair(one.lower_bound(10000), one.end());
	ft_print_it_range_pair(one.lower_bound(9), one.end());
	ft_print_it_range_pair(one.lower_bound(20), one.end());
	ft_print_it_range_pair(one.lower_bound(30), one.end());
	
	ft_print_it_range_pair(c_one.lower_bound(1), c_one.end());
	ft_print_it_range_pair(c_one.lower_bound(10000), c_one.end());
	ft_print_it_range_pair(c_one.lower_bound(9), c_one.end());
	ft_print_it_range_pair(c_one.lower_bound(20), c_one.end());
	ft_print_it_range_pair(c_one.lower_bound(30), c_one.end());

	ft_print_it_range_pair(one.upper_bound(1), one.end());
	ft_print_it_range_pair(one.upper_bound(10000), one.end());
	ft_print_it_range_pair(one.upper_bound(9), one.end());
	ft_print_it_range_pair(one.upper_bound(20), one.end());
	ft_print_it_range_pair(one.upper_bound(30), one.end());
	
	ft_print_it_range_pair(c_one.upper_bound(1), c_one.end());
	ft_print_it_range_pair(c_one.upper_bound(10000), c_one.end());
	ft_print_it_range_pair(c_one.upper_bound(9), c_one.end());
	ft_print_it_range_pair(c_one.upper_bound(20), c_one.end());
	ft_print_it_range_pair(c_one.upper_bound(30), c_one.end());

	std::pair<typename T::iterator, typename T::iterator> pit = one.equal_range(1);
	ft_print_it_range_pair(pit.first, pit.second);
	ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(pit.second, one.end());
	pit = one.equal_range(10000);
	ft_print_it_range_pair(pit.first, pit.second);
	ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(pit.second, one.end());
	pit = one.equal_range(9);
	ft_print_it_range_pair(pit.first, pit.second);
	ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(pit.second, one.end());
	pit = one.equal_range(20);
	ft_print_it_range_pair(pit.first, pit.second);
	ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(pit.second, one.end());
	pit = one.equal_range(30);
	ft_print_it_range_pair(pit.first, pit.second);
	ft_print_it_range_pair(pit.first, one.end());
	ft_print_it_range_pair(pit.second, one.end());

	std::pair<typename T::const_iterator, typename T::const_iterator> cpit = c_one.equal_range(1);
	ft_print_it_range_pair(cpit.first, cpit.second);
	ft_print_it_range_pair(cpit.first, c_one.end());
	ft_print_it_range_pair(cpit.second, c_one.end());
	cpit = c_one.equal_range(10000);
	ft_print_it_range_pair(cpit.first, cpit.second);
	ft_print_it_range_pair(cpit.first, c_one.end());
	ft_print_it_range_pair(cpit.second, c_one.end());
	cpit = c_one.equal_range(9);
	ft_print_it_range_pair(cpit.first, cpit.second);
	ft_print_it_range_pair(cpit.first, c_one.end());
	ft_print_it_range_pair(cpit.second, c_one.end());
	cpit = c_one.equal_range(20);
	ft_print_it_range_pair(cpit.first, cpit.second);
	ft_print_it_range_pair(cpit.first, c_one.end());
	ft_print_it_range_pair(cpit.second, c_one.end());
	cpit = c_one.equal_range(30);
	ft_print_it_range_pair(cpit.first, cpit.second);
	ft_print_it_range_pair(cpit.first, c_one.end());
	ft_print_it_range_pair(cpit.second, c_one.end());
}

#endif
