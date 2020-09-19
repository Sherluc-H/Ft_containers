/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/09/19 21:05:11 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include <list>
#include <vector>

template <class T>
void	ft_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T ctnr;

	std::cout << "size: " << ctnr.size() << std::endl;
	std::cout << "max_size: " << ctnr.max_size() << std::endl;

	T ctnr3 = ctnr;

	ctnr.push_back(2);
	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	ctnr.pop_back();
	ctnr.push_front(2);
	ctnr.push_front(3);
	ctnr.push_back(1);

	std::cout << "size: " << ctnr.size() << std::endl;
	std::cout << "max_size: " << ctnr.max_size() << std::endl;
	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	T ctnr2 = ctnr;

	ctnr2.pop_front();
	ctnr2.push_front(2);
	ctnr2.push_front(3);
	ctnr2.pop_front();
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
}

template <class T>
void	ft_iterator_check()
{
	std::cout << "---iterator check---" << std::endl;
	T ctnr;

	ctnr.push_back(1);
	ctnr.push_back(2);
	ctnr.push_back(0);
	ctnr.push_back(3);

	// int *p = ctnr.get_allocator().allocate(10);
	// ctnr.get_allocator().deallocate(p, 5);

	typename T::iterator ctnr_it = ctnr.begin();
	typename T::iterator ctnr_it_end = ctnr.end();

	std::cout << "first: " << *ctnr_it << std::endl;
	std::cout << ctnr.size() << std::endl;
	ctnr.insert(ctnr_it, 100);
	std::cout << ctnr.size() << std::endl;
	std::cout << "first: " << *ctnr_it << std::endl;
	*ctnr_it = 6;
	std::cout << "first: " << *ctnr_it << std::endl;

	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	T ctnr2(ctnr_it, ctnr_it_end);

	std::cout << "size: " << ctnr2.size() << std::endl;
	std::cout << "front: " << ctnr2.front() << std::endl;
	std::cout << "back: " << ctnr2.back() << std::endl;

	T ctnr3(ctnr_it, ctnr_it);

	std::cout << "size: " << ctnr3.size() << std::endl;

	typename T::iterator ctnr_it2 = ctnr.begin();
	// ctnr_it2++;
	T ctnr5(ctnr_it, ++ctnr_it2);
	std::cout << &(*ctnr_it) << std::endl;
	std::cout << &(*ctnr_it2) << std::endl;

	std::cout << "size: " << ctnr5.size() << std::endl;
	std::cout << "front: " << ctnr5.front() << std::endl;
	std::cout << "back: " << ctnr5.back() << std::endl;

	std::cout << *ctnr_it << std::endl;
	ctnr_it--;
	std::cout << *ctnr_it << std::endl;
	while (ctnr_it != ctnr_it_end)
	{
		std::cout << *ctnr_it << std::endl;
		ctnr_it++;
	}
	// typename T::iterator it;
	// std::cout << *it << std::endl;
}

template <class T>
void ft_swap_check()
{
	std::cout << "---swap check---" << std::endl;
	T one;
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);
	one.push_back(4);
	one.push_back(5);
	T two;
	two.push_back(10);
	two.push_back(20);
	two.push_back(30);
	two.push_back(40);
	two.push_back(50);
	// two.push_back(6);
	if (one >= two)
		std::cout << "bigger or eq" << std::endl;
	else
		std::cout << "smaller" << std::endl;
	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_end = one.end();
	typename T::iterator two_it_begin = two.begin();
	// typename T::iterator two_it_end =
	// one.insert(one_it_begin, 1, 2);
	// one.assign(1, 2);
	// typename T::iterator two_it_end = two.end();
	// std::swap(one, two);
	one.swap(two);
	std::cout << "c" << std::endl;
	// two.push_back(60);
	std::cout << "d" << std::endl;
	typename T::iterator two_it_end = two.end();
	// std::swap(one, two);
	std::cout << "e" << std::endl;
	while (one_it_begin != two_it_end)
	{
		std::cout << "one: " << *one_it_begin << std::endl;
		one_it_begin++;
	}
	while (two_it_begin != one_it_end)
	{
		std::cout << "two: " << *two_it_begin << std::endl;
		two_it_begin++;
	}
	std::cout << "here" << std::endl;
	one_it_begin = one.begin();
	one_it_end = one.end();
	two_it_begin = two.begin();
	two_it_end = two.end();
	while (one_it_begin != one_it_end)
	{
		std::cout << "one: " << *one_it_begin << std::endl;
		one_it_begin++;
	}
	std::cout << "here" << std::endl;
	while (two_it_begin != two_it_end)
	{
		std::cout << "two: " << *two_it_begin << std::endl;
		two_it_begin++;
	}
	std::cout << "hey" << std::endl;
}

template <class T>
void ft_reverse_iterator_check()
{
	std::cout << "---reverse iterator check---" << std::endl;
	T l;
	l.push_back(1);
	l.push_back(3);
	l.push_back(5);
	l.push_back(2);
	typename T::iterator b = l.begin();
	typename T::iterator e = l.end();
	// std::cout << *e << std::endl;
	e--;
	std::cout << *e << std::endl;
	// T::iterator::iterator_category c;
	// std::bidirectional_iterator_tag btt;
	// std::iterator<std::bidirectional_iterator_tag, T> tt = l.begin;
	typename T::reverse_iterator d = l.rbegin();
	// std::cout << "+" << *(d - 3) << std::endl;//a tester avec vector
	// T::reverse_iterator aaa;
	// aaa = 3 + l.rbegin();
	typename T::reverse_iterator f = l.rend();
	std::cout << "begin:" << *d << std::endl;
	// std::cout << "fend:" << *f << std::endl;
	typename T::iterator dd = d.base();
	dd--;
	std::cout << *dd << std::endl;
	// std::cout << "base begin:" << *d.base() << std::endl;
	std::cout << "base fend:" << *f.base() << std::endl;
	while (d != f)
	{
		std::cout << *d << "|" << &(*d) << std::endl;
		d++;
	}
	// l.sort();//un soucis ici
	l.pop_front();
	b = l.begin();
	e = l.end();
	std::cout << "start" << std::endl;
	while (b != e)
	{
		std::cout << *b << "||" << &(*b) << std::endl;
		b++;
	}
}

typedef struct	s_data
{
	int a;
	std::string s;
	int b;
}				t_data;

int		main(int argc, char *argv[])
{
	t_data data;
	data.a = 1;
	data.s = "test";
	data.b = 2;
	t_data *test = &data;
	std::cout << test->a << "|" << (*test).a << std::endl;
	ft::list<s_data> list;
	list.push_back(data);
	list.pop_front();
	std::cout << "here" << std::endl;
	// std::list<s_data>::iterator ita = list.begin();
	// std::cout << ita->a << ita->s << ita->b << std::endl;
	std::string arg_str;
	if (argc > 1)
		arg_str = argv[1];
	if (argc == 1 || (argc == 2 && arg_str.compare("ft") == 0))
	{
		ft_common_check<ft::list<int>>();
		ft_iterator_check<ft::list<int>>();
		ft_swap_check<ft::list<int>>();
		ft_reverse_iterator_check<ft::list<int>>();
	}
	else if (argc == 2 && arg_str.compare("std") == 0)
	{
		ft_common_check<std::list<int>>();
		ft_iterator_check<std::list<int>>();
		ft_swap_check<std::list<int>>();
		ft_reverse_iterator_check<std::list<int>>();
	}
	else
		std::cout << "Wrong arguments" << std::endl;
	std::list<int>::const_iterator it;
	ft::list<int>::const_iterator it2;
	return (0);
}
