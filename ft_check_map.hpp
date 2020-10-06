/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:45:28 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/03 14:45:22 by lhuang           ###   ########.fr       */
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

	typename T::iterator it_begin = map_test.begin();
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
	map_test.insert(std::pair<const int, int>(11, 11));
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

#endif
