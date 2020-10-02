/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/02 18:00:47 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>

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
	one.push_back(6);
	T two;
	two.push_back(10);
	two.push_back(20);
	two.push_back(30);
	two.push_back(40);
	two.push_back(50);
	// two.push_back(6);
	// const T one1 = one;
	// const T two2 = two;
	// const ft::list<int> one1 = one;
	// const ft::list<int> two1 = two;
	if (one >= two)
		std::cout << "bigger or eq" << std::endl;
	else
		std::cout << "smaller" << std::endl;
	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_begin2 = one.begin();
	// typename T::const_iterator cit = one_it_begin;//conversion ok
	// typename T::iterator iit = cit;//conversion pas ok
	one_it_begin2--;
	// one_it_begin2--;
	// std::cout << "begin:" << *one_it_begin << &(*one_it_begin) << std::endl;
	// std::cout << "begin:" << *one_it_begin2 << &(*one_it_begin2) << std::endl;
	if (one_it_begin == one_it_begin2)
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;
	// one_it_begin--;
	// std::cout << "b" << *one_it_begin << &(*one_it_begin) << std::endl;
	// one_it_begin--;
	// std::cout << "b" << *one_it_begin << &(*one_it_begin) << std::endl;
	// one_it_begin--;
	// one_it_begin--;
	// one_it_begin++;
	std::cout << "b" << *one_it_begin << &(*one_it_begin) << std::endl;
	typename T::iterator two_it_begin = two.begin();
	// one.insert(one_it_begin, 1, 2);
	// one.assign(1, 2);
	// typename T::iterator two_it_end = two.end();
	// std::swap(one, two);
	one.swap(two);
	std::cout << "c" << std::endl;
	two.push_back(60);//il y avait probleme ici
	std::cout << "d" << std::endl;
	typename T::iterator two_it_end = two.end();
	typename T::iterator one_it_end = one.end();
	// std::swap(one, two);
	std::cout << "e" << std::endl;
	while (one_it_begin != two_it_end)
	{
		std::cout << "one: " << *one_it_begin << std::endl;
		one_it_begin++;
	}
	one_it_end--;
	std::cout << "end" << *one_it_end << std::endl;
	while (two_it_begin != one_it_end)
	{
		std::cout << "two" << *two_it_begin << std::endl;
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
	// l.sort();//il y avait un soucis ici
	std::cout << l.front() << std::endl;
	// l.pop_front();
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

template <class T>
void ft_data_type_struct_check()
{
	t_data data;
	data.a = 1;
	data.s = "test";
	data.b = 2;
	t_data *test = &data;
	std::cout << test->a << "|" << (*test).a << std::endl;
	T list;
	list.push_back(data);
	std::cout << list.front().b << std::endl;
	list.pop_front();
	std::cout << "here" << std::endl;
	// typename T::iterator ita = list.begin();
	// std::cout << ita->a << ita->s << ita->b << std::endl;
}

template <class T>
void ft_const_check()
{
	std::cout << "---const check---" << std::endl;
	T cl;
	cl.push_back(1);
	cl.push_back(2);
	typename T::iterator it_begin = cl.begin();
	typename T::iterator it_end = cl.end();
	*it_begin = 3;
	while (it_begin != it_end)
	{
		std::cout << *it_begin << std::endl;
		it_begin++;
	}
	const T cl2 = cl;
	typename T::const_iterator cit_begin = cl2.begin();
	typename T::const_iterator cit_end = cl2.end();
	// *cit_begin = 3;
	while (cit_begin != cit_end)
	{
		std::cout << *cit_begin << std::endl;
		cit_begin++;
	}

	typename T::reverse_iterator rit_begin = cl.rbegin();
	typename T::reverse_iterator rit_end = cl.rend();
	*rit_begin = 6;
	while (rit_begin != rit_end)
	{
		std::cout << *rit_begin << std::endl;
		rit_begin++;
	}
	if (rit_begin == rit_end)
		std::cout << "same" << std::endl;
	else
		std::cout << "not same" << std::endl;
	// std::reverse_iterator<std::list<int>::iterator> cc = cl.rbegin();
	// std::cout << *cc << std::endl;
	// *cc = 1;
	// typename T::const_reverse_iterator cri = cl.rbegin();//ne marchait pas
	// ft::reverse_iterator<ft::list<int>::iterator> cd = cl.rbegin();
	// *cd = 1;
	T clr = cl;
	typename T::reverse_iterator cri = clr.rbegin();
	std::cout << *cri << std::endl;
	*cri = 8;

	typename T::const_reverse_iterator r2 = clr.rend();
	r2 = cri;
	std::cout << *r2 << std::endl;
	*cri = 9;
	// *r2 = 10;
	*cri = 7;
	std::cout << *r2 << std::endl;
}

class test
{
	public:
		test()
		{
			std::cout << "constructor test" << std::endl;
			this->p = new int();
		}
		~test()
		{
			delete this->p;
			std::cout << "destructor test" << std::endl;
		}
	private:
		int *p;
};

template <class T>
void ft_check()
{
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
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;
	// vec.push_back(1);
	// vec.push_back(2);
	// vec.push_back(3);
	// vec.pop_back();
	// vec.clear();
	// std::cout << vec[1] << std::endl;
	// std::cout << vec[2] << std::endl;
	vec.resize(14);
	// std::cout << vec.at(0) << std::endl;
	std::cout << vec.capacity() << "|" << vec.size() << std::endl;

	std::vector<test> v1;
	test a;
	// v1.push_back(a);
	ft::vector<test> v2;
	// v2.push_back(a);
	// v2.pop_back();

	const T vec2 = vec;
	std::cout << vec2.capacity() << std::endl;
	std::cout << vec2.size() << std::endl;
	std::cout << vec2[1] << std::endl;
	std::cout << vec2.at(2) << std::endl;
}

template <class T>
void	ft_iterator_rand_access_check()
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

	typename T::const_iterator ccit = ctnr_it;
	typename T::const_iterator ccit_end = ctnr_it_end;
	typename T::reverse_iterator rcit = ctnr.rend();
	typename T::const_reverse_iterator crcit = ctnr.rend();

	if (crcit == rcit)
		std::cout << "eq" << std::endl;
	// if (rcit == crcit)
		// std::cout << "eq" << std::endl;
	// rcit = ccit;
	// ccit = rcit;
	// if (rcit == ccit)
	// 	std::cout << "eq" << std::endl;
	// else
	// 	std::cout << "not eq" << std::endl;

	// typename T::iterator iit = ccit;

	std::cout << *(ccit + 1) << std::endl;
	std::cout << *(1 + ccit) << std::endl;
	std::cout << &(ccit) << std::endl;
	// if (ctnr_it == ccit)
	// {
	// 	std::cout << "eq" << std::endl;
	// }
	// else
	// 	std::cout << "not eq" << std::endl;
	if (ccit == ctnr_it)
	{
		std::cout << "bigger" << std::endl;
	}
	else
		std::cout << "smaller" << std::endl;
	if (ccit == ccit_end)
	{
		std::cout << "bigger" << std::endl;
	}
	else
		std::cout << "smaller" << std::endl;
	// std::cout << ccit - ccit_end << std::endl;
	// std::cout << ccit - ctnr_it_end << std::endl;
	// std::cout << ctnr_it - ccit_end << std::endl;

	ctnr_it++;

	std::cout << *ctnr_it << std::endl;
	std::cout << ctnr_it[0] << std::endl;
	std::cout << ctnr_it[1] << std::endl;
	std::cout << *ctnr_it_end << std::endl;
	std::cout << ctnr_it_end[-1] << std::endl;
	std::cout << ctnr_it_end[-2] << std::endl;

	ctnr_it--;

	const typename T::iterator cit = ctnr_it;
	const typename T::iterator cit_end = ctnr_it_end;

	std::cout << "const" << std::endl;
	std::cout << *(cit) << std::endl;
	std::cout << *(cit +2) << std::endl;
	// ++cit;

	if (cit > cit_end)
	{
		std::cout << "bigger" << std::endl;
	}
	else
		std::cout << "not bigger" << std::endl;
	if (cit == cit_end)
	{
		std::cout << "equal" << std::endl;
	}
	else
		std::cout << "not equal" << std::endl;
	
	if (ctnr_it > ctnr_it)
		std::cout << "bigger" << std::endl;
	else
		std::cout << "not bigger" << std::endl;

	// std::cout << (--ctnr_it) << std::endl;
	// std::cout << (ctnr_it++2) << std::endl;

	std::cout << cit_end - cit << std::endl;
	std::cout << ctnr_it_end - cit << std::endl;
	std::cout << cit - ctnr_it << std::endl;
	// cit++;

	std::cout << "here" << std::endl;
	std::cout << *cit << std::endl;
	// cit+=1;
	std::cout << *cit << std::endl;
	*cit = 5;

	std::cout << "hey" << std::endl;
	std::cout << *ctnr_it << std::endl;
	ctnr_it+=-1;
	std::cout << *(ctnr_it-=-1) << std::endl;
	// std::cout << &(ctnr_it+=1) << std::endl;
	// ctnr_it+=1;
	std::cout << *ctnr_it << std::endl;
	// ctnr_it-=2;
	std::cout << *(ctnr_it + 1) << std::endl;
	std::cout << *(1 + ctnr_it - -1) << std::endl;
	// std::cout << &(ctnr_it + 1) << std::endl;
	*(ctnr_it + 1) = 8;
	std::cout << *(1 + ctnr_it) << std::endl;
	std::cout << *(3 + ctnr_it - 2) << std::endl;
	std::cout << ctnr_it_end - ctnr_it << std::endl;
	std::cout << ctnr_it_end - (ctnr_it + 2) << std::endl;

	typename T::const_iterator cc(ctnr_it);
	// typename T::iterator ccc(cc);

	// ft_iterator_check<T>();
	std::cout << "first: " << (*ctnr_it) << std::endl;
	std::cout << ctnr.size() << std::endl;
	ctnr.insert(ctnr_it, 100);
	ctnr_it = ctnr.begin();//pour vector les iterator sont invalides apres une reallocation
	ctnr_it_end = ctnr.end();
	std::cout << ctnr.size() << std::endl;
	std::cout << "first: " << (*ctnr_it) << std::endl;
	*ctnr_it = 6;
	std::cout << "first: " << *ctnr_it << std::endl;

	std::cout << "front: " << ctnr.front() << std::endl;
	std::cout << "back: " << ctnr.back() << std::endl;

	std::cout << "A" << std::endl;
	std::cout << *ctnr_it << "|" << *ctnr_it_end << std::endl;
	typename T::iterator ctnr_it22 = ctnr_it;
	typename T::iterator ctnr_it_end22 = ctnr_it_end;
	while (ctnr_it22 != ctnr_it_end22)
	{
		std::cout << "h:" << *ctnr_it22 << std::endl;
		ctnr_it22++;
	}
	// ctnr_it++;
	T ctnr2(ctnr_it, ctnr_it_end);
	// ctnr2.ft_show_all();
	size_t i = 0;
	while (i < ctnr2.size())
	{
		std::cout << ctnr2[i] << std::endl;
		i++;
	}
	std::cout << "B" << std::endl;

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
	std::cout << m.size() << "|" << &(m[1]) << std::endl;
	std::map<int, int> m2;
	m2 = m;
	std::cout << m2.size() << "|" << &(m2[1]) << "|" << m.size() << "|" << &(m[1]) << std::endl;

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
		std::cout << &(*it_begin) << "|" << (*it_begin).first << "|" << (*it_begin).second << std::endl;
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

template <class T>
void ft_check_stack()
{
	T s;
	T s2;
	std::cout << s.size() << "|" << s.empty() << std::endl;
	if (s == s2)
		std::cout << "same1" << std::endl;
	else
		std::cout << "diff1" << std::endl;
	if (s != s2)
		std::cout << "diff2" << std::endl;
	else
		std::cout << "same2" << std::endl;
	if (s <= s2)
		std::cout << "smaller ou eq1" << std::endl;
	std::cout << s.top() << std::endl;
	s.push(2);
	std::cout << s.top() << std::endl;
	s.push(5);
	s.push(6);
	s.push(8);
	s.push(9);
	std::cout << s.size() << "|" << s.top() << "|" << s.empty() << std::endl;
	s.pop();
	std::cout << s.size() << "|" << s.top() << "|" << s.empty() << std::endl;
	if (s == s2)
		std::cout << "same3" << std::endl;
	if (s <= s2)
		std::cout << "smaller ou eq2" << std::endl;
}

template <class T>
void ft_check_queue()
{
	T q;
	T q2;

	std::cout << q.size() << "|" << q.empty() << std::endl;
	if (q == q2)
		std::cout << "same1" << std::endl;
	if (q <= q2)
		std::cout << "smaller ou eq1" << std::endl;
	q.push(3);
	if (q == q2)
		std::cout << "same2" << std::endl;
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	q.push(2);
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	std::cout << q.size() << "|" << q.empty() << std::endl;
	q.push(5);
	q.push(6);
	q.push(8);
	q.push(9);
	std::cout << q.front() << "|" << q.back() << "|" << q.size() << "|" << q.empty() << std::endl;
	q.pop();
	std::cout << q.front() << "|" << q.back() << "|" << q.size() << "|" << q.empty() << std::endl;
	if (q <= q2)
		std::cout << "smaller ou eq2" << std::endl;
}

int		main(int argc, char *argv[])
{
	std::string arg_str;
	if (argc > 1)
		arg_str = argv[1];
	else if (argc < 2 || argc > 3)
	{
		std::cout << "Wrong number of argument" << std::endl;
		return (1);
	}
	if (argc == 1 || (argc == 2 && arg_str.compare("list") == 0) || (argc == 3 && arg_str.compare("list") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 1 || argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_common_check<ft::list<int>>();
			ft_iterator_check<ft::list<int>>();
			ft_swap_check<ft::list<int>>();
			ft_reverse_iterator_check<ft::list<int>>();
			ft_data_type_struct_check<ft::list<t_data>>();
			ft_const_check<ft::list<int>>();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_common_check<std::list<int>>();
			ft_iterator_check<std::list<int>>();
			ft_swap_check<std::list<int>>();
			ft_reverse_iterator_check<std::list<int>>();
			ft_data_type_struct_check<std::list<t_data>>();
			ft_const_check<std::list<int>>();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else if ((argc == 2 && arg_str.compare("vector") == 0) || (argc == 3 && arg_str.compare("vector") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check<ft::vector<int>>();
			ft_iterator_rand_access_check<ft::vector<int>>();
			ft_swap_check<ft::vector<int>>();
			ft_reverse_iterator_check<ft::vector<int>>();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check<std::vector<int>>();
			ft_iterator_rand_access_check<std::vector<int>>();
			ft_swap_check<std::vector<int>>();
			ft_reverse_iterator_check<std::vector<int>>();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else if ((argc == 2 && arg_str.compare("map") == 0) || (argc == 3 && arg_str.compare("map") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check_map<ft::map<int, int>>();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_map<std::map<int, int>>();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
		// std::map<int, int> valcmp;
		// std::cout << valcmp.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
		// std::map<int, int>::value_compare valc = valcmp.value_comp();
		// std::cout << valc(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 2)) << std::endl;
		// // std::cout << valcmp.value_comp() << std::endl;
		// ft::map<int, int> fvalcmp;
		// std::cout << fvalcmp.value_comp()(std::pair<const int, int>(1, 2), std::pair<const int, int>(2, 3)) << std::endl;
		// ft::map<int, int>::value_compare fvalc = fvalcmp.value_comp();
		// std::cout << fvalc(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 2)) << std::endl;

		// // std::cout << std::map<int, int>::value_compare()(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 1)) << std::endl;
		// // std::cout << ft::map<int, int>::value_compare()(std::pair<const int, int>(1, 1), std::pair<const int, int>(1, 1)) << std::endl;
		// // std::pair<const int, int> a(1, 2);
		// // std::pair<const int, int> b(2, 2);
		// // std::less<int> ls;
		// // ft::map<int, int>::value_compare test(ls);
		// // std::cout << test(a, b) << std::endl;
		// // std::map<int, int>::value_compare test2(ls);
		// // std::cout << test2(a, b) << std::endl;
		// ft::map<int, int>::value_compare::first_argument_type f(10, 2);
		// // f = a;
		// std::cout << f.first << std::endl;
		
		// std::map<int, int> m;
		// m[1] = 2;
		// m[2] = 3;
		// std::cout << m.size() << "|" << &(m[1]) << std::endl;
		// std::map<int, int> m2;
		// m2 = m;
		// std::cout << m2.size() << "|" << &(m2[1]) << "|" << m.size() << "|" << &(m[1]) << std::endl;

		// std::cout << valcmp.max_size() << std::endl;
		// std::cout << fvalcmp.max_size() << std::endl;

		// ft::map<int, int> mm;
		// std::pair<const int, int> p(1, 2);
		// std::pair<const int, int> p2(2, 2);
		// mm.ft_show_all();
		// std::cout << mm.size() << std::endl;
		// mm.insert(p2);
		// mm.insert(p2);
		// mm.insert(p2);
		// mm.ft_show_all();
		// std::cout << mm.size() << std::endl;
		// mm.insert(p);
		// mm.insert(p);
		// std::cout << mm.size() << std::endl;
		// mm.insert(p);
		// std::cout << mm.size() << std::endl;
		// std::pair<const int, int> p3(3, 3);
		// mm.insert(p3);
		// std::cout << mm.size() << std::endl;
		// mm.ft_show_all();
		// // std::pair<const int, int> p2(2, 2);
		// // p = p2;

		// ft::map<int, int> map_test;
		// map_test.insert(std::pair<const int, int>(11, 11));
		// map_test.insert(std::pair<const int, int>(5, 5));
		// map_test.insert(std::pair<const int, int>(8, 8));
		// map_test.insert(std::pair<const int, int>(3, 3));
		// map_test.insert(std::pair<const int, int>(1, 1));
		// map_test.insert(std::pair<const int, int>(4, 4));
		// map_test.insert(std::pair<const int, int>(2, 2));
		// map_test.insert(std::pair<const int, int>(9, 9));
		// map_test.insert(std::pair<const int, int>(6, 6));
		// map_test.insert(std::pair<const int, int>(10, 10));
		// map_test.insert(std::pair<const int, int>(20, 20));
		// map_test.insert(std::pair<const int, int>(15, 15));
		// map_test.insert(std::pair<const int, int>(25, 25));
		// map_test.insert(std::pair<const int, int>(30, 30));
		// map_test.insert(std::pair<const int, int>(31, 31));
		// std::cout << map_test.size() << std::endl;
		// map_test.ft_show_all();

		// ft::map<int, int>::iterator it;
		// *it;
	}
	else if ((argc == 2 && arg_str.compare("stack") == 0) || (argc == 3 && arg_str.compare("stack") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check_stack<ft::stack<int, ft::list<int>>>();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_stack<std::stack<int, std::list<int>>>();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else if ((argc == 2 && arg_str.compare("queue") == 0) || (argc == 3 && arg_str.compare("queue") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check_queue<ft::queue<int, ft::list<int>>>();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_queue<std::queue<int, std::list<int>>>();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else
		std::cout << "Wrong arguments" << std::endl;
	std::list<int>::const_iterator it;
	ft::list<int>::const_iterator it2;
	return (0);
}
