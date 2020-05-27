/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/05/27 23:31:37 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include <list>

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

	typename T::iterator ctnr_it = ctnr.begin();
	typename T::iterator ctnr_it_end = ctnr.end();

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

	T ctnr5(ctnr_it, ++ctnr_it2);

	std::cout << "size: " << ctnr5.size() << std::endl;
	std::cout << "front: " << ctnr5.front() << std::endl;
	std::cout << "back: " << ctnr5.back() << std::endl;

	while (ctnr_it != ctnr_it_end)
	{
		std::cout << *ctnr_it << std::endl;
		ctnr_it++;
	}

}

int		main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_common_check<ft::list<int>>();
		ft_iterator_check<ft::list<int>>();
		return (0);
	}
	std::string arg_str(argv[1]);
	if (argc == 2 && arg_str.compare("ft") == 0)
	{
		ft_common_check<ft::list<int>>();
		ft_iterator_check<ft::list<int>>();
		return (0);
	}
	else if (argc == 2 && arg_str.compare("std") == 0)
	{
		ft_common_check<std::list<int>>();
		ft_iterator_check<std::list<int>>();
	}
	else
		std::cout << "Wrong arguments" << std::endl;
	return (0);
}
