/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/11 22:49:27 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "deque.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include "ft_check_utils.hpp"
#include "ft_check_list.hpp"
#include "ft_check_vector.hpp"
#include "ft_check_map.hpp"

// typedef struct	s_data
// {
// 	int a;
// 	std::string s;
// 	int b;
// 	struct ~s_data
// 	{
// 		s.~string();
// 	}
// }				t_data;

template <class T>
void ft_data_type_struct_check()
{
	std::string data = "test";
	// t_data data;
	// data.a = 1;
	// data.s = "test";
	// data.b = 2;
	// t_data *test = &data;
	// std::cout << test->a << "|" << (*test).a << std::endl;
	T list;
	list.push_back(data);
	// std::cout << list.front().b << std::endl;
	// list.pop_front();
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
void ft_check_iterator_constructibility()
{
	std::cout << std::is_default_constructible<typename T::iterator>::value << std::endl;
	std::cout << std::is_default_constructible<typename T::const_iterator>::value << std::endl;
	std::cout << std::is_copy_constructible<typename T::iterator>::value << std::endl;
	std::cout << std::is_copy_constructible<typename T::const_iterator>::value << std::endl;
	std::cout << std::is_copy_assignable<typename T::iterator>::value << std::endl;
	std::cout << std::is_copy_assignable<typename T::const_iterator>::value << std::endl;
	std::cout << std::is_destructible<typename T::iterator>::value << std::endl;
	std::cout << std::is_destructible<typename T::const_iterator>::value << std::endl;
	std::cout << std::is_default_constructible<typename T::reverse_iterator>::value << std::endl;
	std::cout << std::is_default_constructible<typename T::const_reverse_iterator>::value << std::endl;
	std::cout << std::is_copy_constructible<typename T::reverse_iterator>::value << std::endl;
	std::cout << std::is_copy_constructible<typename T::const_reverse_iterator>::value << std::endl;
	std::cout << std::is_copy_assignable<typename T::reverse_iterator>::value << std::endl;
	std::cout << std::is_copy_assignable<typename T::const_reverse_iterator>::value << std::endl;
	std::cout << std::is_destructible<typename T::reverse_iterator>::value << std::endl;
	std::cout << std::is_destructible<typename T::const_reverse_iterator>::value << std::endl;
}

template <class T>
void ft_check_stack()
{
	T s;
	T s2;
	std::cout << s.size() << "|" << s.empty() << std::endl;
	ft_check_all_comp(s, s2);
	s.push(2);
	std::cout << s.top() << std::endl;
	s.push(5);
	s.push(6);
	s.push(8);
	s.push(9);
	std::cout << s.size() << "|" << s.top() << "|" << s.empty() << std::endl;
	s.pop();
	std::cout << s.size() << "|" << s.top() << "|" << s.empty() << std::endl;
	T s3 = s;
	std::cout << s3.size() << "|" << s3.top() << "|" << s3.empty() << std::endl;
	ft_check_all_comp(s, s2);
	ft_check_all_comp(s, s3);
}

template <class T>
void ft_check_queue()
{
	T q;
	T q2;

	std::cout << q.size() << "|" << q.empty() << std::endl;
	ft_check_all_comp(q, q2);
	q.push(3);
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
	T q3 = q;
	std::cout << q3.front() << "|" << q3.back() << "|" << q3.size() << "|" << q3.empty() << std::endl;
	ft_check_all_comp(q, q2);
	ft_check_all_comp(q, q3);
}

template<class T>
class Bigger
{
	public:
		bool operator()(const T& a, const T& b) const
		{
			return (a > b);
		}
};

template<class T>
class Smaller
{
	public:
		bool operator()(const T& a, const T& b) const
		{
			return (a < b);
		}
};

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
			ft_check_iterator_constructibility<ft::list<int> >();
			ft_list_common_check<ft::list<int> >();
			ft_list_iterator_check<ft::list<int> >();
			ft_list_reverse_iterator_check<ft::list<int> >();
			ft_list_modifiers_check<ft::list<int> >();
			// ft_data_type_struct_check<ft::list<std::string> >();
			// ft_const_check<ft::list<int> >();
			ft_list_operations_check<ft::list<int> >();
			// ft::list<int> a;
			// ft::list<int> b;
			// ft::swap(a, b);
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::list<int> >();
			ft_list_common_check<std::list<int> >();
			ft_list_iterator_check<std::list<int> >();
			ft_list_reverse_iterator_check<std::list<int> >();
			ft_list_modifiers_check<std::list<int> >();
			// ft_data_type_struct_check<std::list<std::string> >();
			// ft_const_check<std::list<int> >();
			ft_list_operations_check<std::list<int> >();
			// std::list<int> a;
			// std::list<int> b;
			// std::swap(a, b);
			// std::cout << "std" << std::endl;
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
			ft_check_iterator_constructibility<ft::vector<int> >();
			ft_vector_common_check<ft::vector<int> >();
			ft_vector_iterator_check<ft::vector<int> >();
			ft_vector_reverse_iterator_check<ft::vector<int> >();
			ft_vector_modifiers_check<ft::vector<int> >();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::vector<int> >();
			ft_vector_common_check<std::vector<int> >();
			ft_vector_iterator_check<std::vector<int> >();
			ft_vector_reverse_iterator_check<std::vector<int> >();
			ft_vector_modifiers_check<std::vector<int> >();
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
			ft_check_iterator_constructibility<ft::map<int, int> >();
			ft_map_common_check<ft::map<int, int> >();
			ft_map_common_check2<ft::map<int, int>, ft::map<int, int, Bigger<int> >, ft::map<int, int, Smaller<int> > >();
			ft_map_iterator_check<ft::map<int, int> >();
			ft_map_reverse_iterator_check<ft::map<int, int> >();
			ft_map_modifiers_check<ft::map<int, int> >();
			ft_map_operations_check<ft::map<int, int> >();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::map<int, int> >();
			ft_map_common_check<std::map<int, int> >();
			ft_map_common_check2<std::map<int, int>, std::map<int, int, Bigger<int> >, std::map<int, int, Smaller<int> > >();
			ft_map_iterator_check<std::map<int, int> >();
			ft_map_reverse_iterator_check<std::map<int, int> >();
			ft_map_modifiers_check<std::map<int, int> >();
			ft_map_operations_check<std::map<int, int> >();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else if ((argc == 2 && arg_str.compare("stack") == 0) || (argc == 3 && arg_str.compare("stack") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check_stack<ft::stack<int, ft::list<int> > >();
			// ft_check_stack<ft::stack<int, ft::deque<int> > >();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_stack<std::stack<int, std::list<int> > >();
			// ft_check_stack<std::stack<int, std::deque<int> > >();
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
			ft_check_queue<ft::queue<int, ft::list<int> > >();
			// ft_check_queue<ft::queue<int, ft::deque<int> > >();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_queue<std::queue<int, std::list<int> > >();
			// ft_check_queue<std::queue<int, std::deque<int> > >();
		}
		else
			std::cout << "namespace not recognized" << std::endl;
	}
	else if ((argc == 2 && arg_str.compare("deque") == 0) || (argc == 3 && arg_str.compare("deque") == 0))
	{
		if (argc == 3)
			arg_str = argv[2];
		if (argc == 2 || (argc == 3 && arg_str.compare("ft") == 0))
		{
			ft_check_iterator_constructibility<ft::deque<int> >();
			ft_list_common_check<ft::deque<int> >();
			// ft_vector_common_check<ft::deque<int> >();
			// ft_vector_iterator_check<ft::deque<int> >();
			// ft_vector_reverse_iterator_check<ft::deque<int> >();
			// ft_vector_modifiers_check<ft::deque<int> >();
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::deque<int> >();
			ft_list_common_check<std::deque<int> >();
			// ft_vector_common_check<std::deque<int> >();
			// ft_vector_iterator_check<std::deque<int> >();
			// ft_vector_reverse_iterator_check<std::deque<int> >();
			// ft_vector_modifiers_check<std::deque<int> >();
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
