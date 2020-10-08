/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:45:28 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/08 22:59:46 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_MAP_HPP
# define FT_CHECK_MAP_HPP

# include <iostream>
# include <map>

template <class T>
void ft_check_map()
{
	T valcmp;
	std::cout << valcmp.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
	typename T::value_compare valc = valcmp.value_comp();
	std::cout << valc(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 2)) << std::endl;
	// std::cout << valcmp.value_comp() << std::endl;
	// ft::map<int, int> fvalcmp;
	// std::cout << fvalcmp.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
	// ft::map<int, int>::value_compare fvalc = fvalcmp.value_comp();
	// std::cout << fvalc(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 2)) << std::endl;

	// std::cout << std::map<int, int>::value_compare()(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 1)) << std::endl;
	// std::cout << ft::map<int, int>::value_compare()(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 1)) << std::endl;
	// std::pair<const int, int> a(1, 2);
	// std::pair<const int, int> b(2, 2);
	// std::less<int> ls;
	// ft::map<int, int>::value_compare test(ls);
	// std::cout << test(a, b) << std::endl;
	// std::map<int, int>::value_compare test2(ls);
	// std::cout << test2(a, b) << std::endl;
	typename T::value_compare::first_argument_type f(10, 2);
	// f = a;
	std::cout << f.first << std::endl;
	
	std::map<int, int> m;
    m[1] = 2;
	m[2] = 3;
	std::cout << m.size() << "|" << m[1] << std::endl;
	std::map<int, int> m2;
	m2 = m;
	std::cout << m2.size() << "|" << m2[1] << "|" << m.size() << "|" << (m[1]) << std::endl;

	std::cout << valcmp.max_size() << std::endl;
	// std::cout << fvalcmp.max_size() << std::endl;

	T mm;
	std::pair<const int, int> p(1, 2);
	std::pair<const int, int> p2(2, 2);
	// mm.ft_show_all();
	std::cout << mm.size() << std::endl;
	mm.insert(p2);
	// mm.insert(p2);
	// mm.insert(p2);
	// mm.ft_show_all();
	std::cout << mm.size() << std::endl;
	// mm.insert(p);
	mm.insert(p);
	std::cout << mm.size() << std::endl;
	// mm.insert(p);
	std::cout << mm.size() << std::endl;
	std::pair<const int, int> p3(3, 3);
	mm.insert(p3);
	std::cout << mm.size() << std::endl;
	// mm.ft_show_all();
	// std::pair<const int, int> p2(2, 2);
	// p = p2;

	T map_test;
	map_test.insert(std::pair<const int, int>(11, 11));
	// map_test.insert(std::pair<const int, int>(11, 11));
	map_test.insert(std::pair<const int, int>(5, 5));
	map_test.insert(std::pair<const int, int>(8, 8));
	map_test.insert(std::pair<const int, int>(3, 3));
	map_test.insert(std::pair<const int, int>(1, 1));
	map_test.insert(std::pair<const int, int>(4, 4));
	map_test.insert(std::pair<const int, int>(2, 2));
	map_test.insert(std::pair<const int, int>(9, 9));
	map_test.insert(std::pair<const int, int>(6, 6));
	map_test.insert(std::pair<const int, int>(10, 10));
	map_test.insert(std::pair<const int, int>(20, 20));
	map_test.insert(std::pair<const int, int>(15, 15));
	map_test.insert(std::pair<const int, int>(25, 25));
	map_test.insert(std::pair<const int, int>(30, 30));
	map_test.insert(std::pair<const int, int>(31, 31));
	map_test.insert(std::pair<const int, int>(12, 12));
	ft_print_it_range_pair(map_test.begin(), map_test.end());
	std::cout << "size:" << map_test.size() << std::endl;
	typename T::iterator it_begin = map_test.begin();
	++it_begin;
	++it_begin;
	map_test.erase(it_begin);
	std::cout << map_test[3] << std::endl;
	ft_print_it_range_pair(map_test.begin(), map_test.end());
	std::cout << "size:" << map_test.size() << std::endl;
	// map_test.ft_show_all();
	// map_test.insert(std::pair<const int, int>(12, 12));
	std::cout << map_test.size() << std::endl;
	std::cout << "here1" << std::endl;
	const T mapc = map_test;
	std::cout << "here:" << (*(mapc.find(1))).first << std::endl;
	std::cout << mapc.count(10) << std::endl;
	std::cout << (*(mapc.lower_bound(2))).first << std::endl;
	std::cout << (*(mapc.upper_bound(3))).first << std::endl;
	// T::ft_comp_lower(2, 3);
	// map_test.ft_show_all();
	std::pair<typename T::const_iterator, typename T::const_iterator> its = mapc.equal_range(25);
	std::cout << (*(its.first)).first << std::endl;
	std::cout << (*(its.second)).first << std::endl;

	it_begin = map_test.begin();
	typename T::iterator it_end = map_test.end();
	const typename T::iterator cit_begin = it_begin;
	std::cout << (*cit_begin).first << std::endl;
	// cit_begin++;
	// --cit_begin;
	while (it_begin != it_end)
	{
		// std::cout << "c" << std::endl;
		std::cout << "|" << (*it_begin).first << "|" << (*it_begin).second << std::endl;
		// std::cout << "d" << std::endl;
		it_begin++;
	}
	it_end--;
	std::cout << (*it_end).first << std::endl;
	it_begin--;
	it_begin--;
	std::cout << "e:" << (*it_begin).first << std::endl;
	// map_test.erase(it_begin);
	std::cout << "e:" << (*it_begin).first << std::endl;
	it_begin = map_test.begin();
	it_end = map_test.end();
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
	it_begin++;
    std::cout << "BEGIN" << (*it_begin).first << std::endl;
	std::cout << map_test.size() << std::endl;
	std::cout << map_test.count(3) << std::endl;
	// std::cout << map_test[3] << std::endl;
	typename T::iterator it_begin_next = it_begin;
	it_begin_next++;
	map_test.erase(3);
	// map_test.insert(std::pair<const int, int>(11, 11));
	// map_test.ft_show_all();
	// map_test.insert(std::pair<const int, int>(11, 11));
	// std::cout << "first" << map_test.front() << std::endl;
	// map_test.erase(++it_begin);
	// std::cout << map_test[3] << std::endl;
	std::cout << map_test.count(3) << std::endl;
	// std::cout << "B:" << (*it_begin).first << std::endl;
	// std::cout << "HERE" << (*it_begin_next).first << std::endl;//probleme ici
	std::cout << map_test.size() << std::endl;
	// map_test.erase(it_begin);
	// map_test[10] = 100;
	// map_test[22] = 9;
	// map_test[22] = 22;
	// std::cout << map_test[1] << std::endl;
	// map_test.insert(std::pair<int, int>(1, 1));
	// map_test.insert(std::pair<int, int>(1, 1));
	// map_test.insert(std::pair<int, int>(1, 1));
	it_begin = map_test.begin();
	it_end = map_test.end();
	while (it_begin != it_end)
	{
		std::cout << (*it_begin).first << std::endl;
		it_begin++;
	}
	// std::cout << "hh:" << &(*it_begin) << "|" << (*it_end).first << std::endl;
}

template <class T>
void ft_check_map_modifiers()
{
	T one;

	std::cout << one.empty() << "|" << one.size() << "|" << one.max_size() << std::endl;
	one[50] = 50;
	one[40] = 40;
	one[60] = 60;
	one[10] = 10;
	std::cout << one.empty() << "|" << one.size() << "|" << one.max_size() << std::endl;
	std::pair<typename T::iterator, bool> p1 = one.insert(std::pair<int, int>(5, 5));
	std::cout << p1.second << std::endl;
	ft_print_it_range_pair(p1.first, one.end());
	one.insert(std::pair<int, int>(11, 11));
	one.insert(std::pair<int, int>(22, 22));
	one.insert(std::pair<int, int>(33, 33));
	one.insert(std::pair<int, int>(55, 55));
	std::cout << one.empty() << "|" << one.size() << "|" << one.max_size() << std::endl;
	one[33] = 33;
	one[40] = 40;
	one[60] = 61;
	one[25] = 25;
	one[5] = 6;
	one[11] = 11;
	p1 = one.insert(std::pair<int, int>(6, 6));
	std::cout << p1.second << std::endl;
	ft_print_it_range_pair(p1.first, one.end());
	p1 = one.insert(std::pair<int, int>(55, 55));
	std::cout << p1.second << std::endl;
	ft_print_it_range_pair(p1.first, one.end());
	one.insert(std::pair<int, int>(22, 23));
	p1 = one.insert(std::pair<int, int>(60, 60));
	std::cout << p1.second << std::endl;
	ft_print_it_range_pair(p1.first, one.end());
	one.insert(std::pair<int, int>(50, 51));
	std::cout << one.empty() << "|" << one.size() << "|" << one.max_size() << std::endl;

	ft_print_it_range_pair(one.find(10), one.end());
	ft_print_it_range_pair(one.find(10000), one.find(20000));
	ft_print_it_range_pair(one.find(60), one.find(50000));

	ft_print_it_range_pair(one.lower_bound(20), one.end());
	ft_print_it_range_pair(one.lower_bound(2000), one.end());
	ft_print_it_range_pair(one.lower_bound(10), one.lower_bound(20));

	ft_print_it_range_pair(one.upper_bound(20), one.end());
	ft_print_it_range_pair(one.upper_bound(2000), one.end());
	ft_print_it_range_pair(one.upper_bound(10), one.upper_bound(20));

	std::pair<typename T::iterator, typename T::iterator> p_eq = one.equal_range(60);
	std::pair<typename T::iterator, typename T::iterator> p_eq2 = one.equal_range(1000);
	ft_print_it_range_pair(p_eq.first, p_eq.second);
	ft_print_it_range_pair(p_eq2.first, p_eq2.second);

	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(++(one.begin()));
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase((one.begin()));
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	one.erase(--(one.end()));
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	// one.erase((one.end()));
	// ft_print_it_range_pair(one.begin(), one.end());
	// ft_print_it_range_pair(one.rbegin(), one.rend());

	// one.erase(one.end());
	std::cout << "a" << std::endl;
	std::cout << one.erase(1) << std::endl;
	std::cout << "a1" << std::endl;
	std::cout << one.erase(2) << std::endl;
	std::cout << "a2" << std::endl;
	std::cout << one.erase(3) << std::endl;
	std::cout << "a3" << std::endl;
	std::cout << one.erase(10) << std::endl;
	std::cout << "a4" << std::endl;
	std::cout << one.erase(20) << std::endl;
	std::cout << "a5" << std::endl;
	std::cout << one.erase(60) << std::endl;
	std::cout << "a6" << std::endl;
	std::cout << one.erase(33) << std::endl;
	std::cout << "b" << std::endl;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());

	std::cout << "----------size:" << one.size() << std::endl;
	// one.erase(one.begin(), one.end());
	// ft_print_it_range_pair(one.begin(), one.end());
	// ft_print_it_range_pair(one.rbegin(), one.rend());

	T two = one;
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());
	T three = T(one.begin(), one.end());
	ft_print_it_range_pair(three.begin(), three.end());
	ft_print_it_range_pair(three.rbegin(), three.rend());
	T five = T(one);
	ft_print_it_range_pair(five.begin(), five.end());
	ft_print_it_range_pair(five.rbegin(), five.rend());
	const T six = one;
	ft_print_it_range_pair(six.begin(), six.end());
	ft_print_it_range_pair(six.rbegin(), six.rend());
	const T seven = T(one.begin(), one.end());
	ft_print_it_range_pair(seven.begin(), seven.end());
	ft_print_it_range_pair(seven.rbegin(), seven.rend());
	const T eight = T(one);
	ft_print_it_range_pair(eight.begin(), eight.end());
	ft_print_it_range_pair(eight.rbegin(), eight.rend());
	const T nine = one;
	ft_print_it_range_pair(nine.begin(), nine.end());
	ft_print_it_range_pair(nine.rbegin(), nine.rend());
	T ten = six;
	ft_print_it_range_pair(ten.begin(), ten.end());
	ft_print_it_range_pair(ten.rbegin(), ten.rend());

	typename T::iterator it_b = one.begin();
	typename T::iterator it_e = one.end();
	typename T::const_iterator cit_b = it_b;
	typename T::const_iterator cit_e = it_e;
	// it_b = cit_b;
	// it_e = cit_e;
	ft_print_it_range_pair(it_b, it_e);
	// *it_b = std::pair<int, int>(10000, 10000);
	// ft_print_it_range_pair(it_b, it_e);
	ft_print_it_range_pair(cit_b, cit_e);
	// *cit_b = 1000000;

	T eleven;
	eleven[11] = 11;
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());
	one.swap(eleven);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());
	eleven.swap(one);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());

	eleven.clear();
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());

	one.swap(eleven);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());
	eleven.swap(one);
	ft_print_it_range_pair(one.begin(), one.end());
	ft_print_it_range_pair(one.rbegin(), one.rend());
	ft_print_it_range_pair(eleven.begin(), eleven.end());
	ft_print_it_range_pair(eleven.rbegin(), eleven.rend());

	std::cout << two.size() << std::endl;
	std::cout << "hey2:" << (*(--(--two.end()))).first << std::endl;
	typename T::iterator iit = two.insert((--two.end()), std::pair<int, int>(58, 58));
	typename T::iterator iit2 = two.insert((--two.end()), std::pair<int, int>(55, 55));
	ft_print_it_range_pair(iit, two.end());
	ft_print_it_range_pair(iit2, two.end());
	std::cout << two.size() << std::endl;
	two.insert(two.end(), std::pair<int, int>(55, 55));
	std::cout << two.size() << std::endl;
	ft_print_it_range_pair(two.begin(), two.end());
	ft_print_it_range_pair(two.rbegin(), two.rend());

	std::cout << "s:" << two.size() << "|" << three.size() << std::endl;
	three.insert(two.begin(), two.end());
	std::cout << "s:" << two.size() << "|" << three.size() << std::endl;
	ft_print_it_range_pair(three.begin(), three.end());
	ft_print_it_range_pair(three.rbegin(), three.rend());
}

#endif
