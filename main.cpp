/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/12 20:05:01 by lhuang           ###   ########.fr       */
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
	T one;
	one.push_back(data);
	one.push_back(data);
	std::cout << one.front().b << std::endl;
	typename T::iterator ita = one.begin();
	std::cout << ita->a << ita->s << ita->b << std::endl;
	std::cout << one.size() << std::endl;
	one.pop_front();
	std::cout << one.size() << std::endl;
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
		test(const test& t)
		{
			*this = t;
		}
		test& operator=(const test& t)
		{
			this->p = t.p;
			return (*this);
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
		Bigger()
		{}
		~Bigger()
		{}
		Bigger(const Bigger& b)
		{
			*this = b;
		}
		Bigger& operator=(const Bigger& b)
		{
			(void)b;
			return (*this);
		}
		bool operator()(const T& a, const T& b) const
		{
			return (a > b);
		}
};

template<class T>
class Smaller
{
	public:
		Smaller()
		{}
		~Smaller()
		{}
		Smaller(const Smaller& s)
		{
			*this = s;
		}
		Smaller& operator=(const Smaller& s)
		{
			(void)s;
			return (*this);
		}
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
			ft_list_operations_check<ft::list<int> >();
			ft_data_type_struct_check<ft::list<t_data> >();
			ft::list<int> a;
			ft::list<int> b;
			ft::swap(a, b);
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::list<int> >();
			ft_list_common_check<std::list<int> >();
			ft_list_iterator_check<std::list<int> >();
			ft_list_reverse_iterator_check<std::list<int> >();
			ft_list_modifiers_check<std::list<int> >();
			ft_list_operations_check<std::list<int> >();
			ft_data_type_struct_check<std::list<t_data> >();
			std::list<int> a;
			std::list<int> b;
			std::swap(a, b);
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
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::vector<int> >();
			ft_vector_common_check<std::vector<int> >();
			ft_vector_iterator_check<std::vector<int> >();
			ft_vector_reverse_iterator_check<std::vector<int> >();
			ft_vector_modifiers_check<std::vector<int> >();
			// std::cout << "std" << std::endl;
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
			// std::cout << "ft" << std::endl;
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
			// std::cout << "std" << std::endl;
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
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_stack<std::stack<int, std::list<int> > >();
			// ft_check_stack<std::stack<int, std::deque<int> > >();
			// std::cout << "std" << std::endl;
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
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_queue<std::queue<int, std::list<int> > >();
			// ft_check_queue<std::queue<int, std::deque<int> > >();
			// std::cout << "std" << std::endl;
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
			// std::cout << "ft" << std::endl;
		}
		else if (argc == 3 && arg_str.compare("std") == 0)
		{
			ft_check_iterator_constructibility<std::deque<int> >();
			ft_list_common_check<std::deque<int> >();
			// ft_vector_common_check<std::deque<int> >();
			// ft_vector_iterator_check<std::deque<int> >();
			// ft_vector_reverse_iterator_check<std::deque<int> >();
			// ft_vector_modifiers_check<std::deque<int> >();
			// std::cout << "std" << std::endl;
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
