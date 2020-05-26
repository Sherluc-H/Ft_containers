/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/05/26 18:57:39 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include <list>

int		main(void)
{
	ft::list<int> ft_l;
	std::list<int> std_l;

	ft::list<int> ft_l3 = ft_l;
	std::list<int> std_l3 = std_l;

	std::cout << std_l.front() << std::endl;
	std::cout << std_l.back() << std::endl;

	ft_l.push_back(2);
	std_l.push_back(2);
	std::cout << "fl: " << ft_l.front() << std::endl;
	std::cout << "fl: " << ft_l.back() << std::endl;
	std::cout << "sl: " << std_l.front() << std::endl;
	std::cout << "sl: " << std_l.back() << std::endl;
//	ft_l.show_all();
//	std_l.show_all();
	ft_l.pop_back();
	std_l.pop_back();
//	ft_l.show_all();
//	std_l.show_all();
	ft_l.push_front(2);
	ft_l.push_front(3);
	std_l.push_front(2);
	std_l.push_front(3);
	ft_l.push_back(1);
	std_l.push_back(1);
//	ft_l.show_all();
	std::cout << "fl size: " << ft_l.size() << std::endl;
	std::cout << "fl: " << ft_l.max_size() << std::endl;
	std::cout << "sl size: " << std_l.size() << std::endl;
	std::cout << "sl: " << std_l.max_size() << std::endl;
	std::cout << "fl: " << ft_l.front() << std::endl;
	std::cout << "fl: " << ft_l.back() << std::endl;
	std::cout << "sl: " << std_l.front() << std::endl;
	std::cout << "sl: " << std_l.back() << std::endl;

	ft::list<int> ft_l2 = ft_l;
	std::list<int> std_l2 = std_l;

	ft::list<int>::iterator ft_l_it = ft_l.begin();
	std::list<int>::iterator std_l_it = std_l.begin();
	ft::list<int>::iterator ft_l_it_end = ft_l.end();
	std::list<int>::iterator std_l_it_end = std_l.end();

	std::cout << "fl: " << *ft_l_it << std::endl;
	std::cout << "sl: " << *std_l_it << std::endl;
	*ft_l_it = 1;
	*std_l_it = 1;
	std::cout << "fl: " << *ft_l_it << std::endl;
	std::cout << "sl: " << *std_l_it << std::endl;

	std::cout << "fl2: " << ft_l2.front() << std::endl;
	std::cout << "fl2: " << ft_l2.back() << std::endl;
	std::cout << "sl2: " << std_l2.front() << std::endl;
	std::cout << "sl2: " << std_l2.back() << std::endl;

	ft::list<int> ft_l4(ft_l_it, ft_l_it_end);
	std::list<int> std_l4(std_l_it, std_l_it_end);
	std::cout << "fl4 size: " << ft_l4.size() << std::endl;
	std::cout << "sl4 size: " << std_l4.size() << std::endl;
	std::cout << "fl: " << ft_l4.front() << std::endl;
	std::cout << "fl: " << ft_l4.back() << std::endl;
	std::cout << "sl: " << std_l4.front() << std::endl;
	std::cout << "sl: " << std_l4.back() << std::endl;

	ft::list<int> ft_l6(ft_l_it, ft_l_it);
	std::list<int> std_l6(std_l_it, std_l_it);
	std::cout << "fl6 size: " << ft_l6.size() << std::endl;
	std::cout << "sl6 size: " << std_l6.size() << std::endl;
//	std::cout << "fl: " << ft_l6.front() << std::endl;
//	std::cout << "fl: " << ft_l6.back() << std::endl;
//	std::cout << "sl: " << std_l6.front() << std::endl;
//	std::cout << "sl: " << std_l6.back() << std::endl;

	ft::list<int>::iterator ft_l_it2 = ft_l.begin();
	std::list<int>::iterator std_l_it2 = std_l.begin();
	ft::list<int> ft_l7(ft_l_it, ++ft_l_it2);
	std::list<int> std_l7(std_l_it, ++std_l_it2);
	std::cout << "fl7 size: " << ft_l7.size() << std::endl;
	std::cout << "sl7 size: " << std_l7.size() << std::endl;
	std::cout << "fl: " << ft_l7.front() << std::endl;
	std::cout << "fl: " << ft_l7.back() << std::endl;
	std::cout << "sl: " << std_l7.front() << std::endl;
	std::cout << "sl: " << std_l7.back() << std::endl;

	while (ft_l_it != ft_l_it_end)
	{
		std::cout << "fl: " << *ft_l_it << std::endl;
		ft_l_it++;
	}
	while (std_l_it != std_l_it_end)
	{
		std::cout << "sl: " << *std_l_it << std::endl;
		std_l_it++;
	}

	ft::list<int> ft_l5(3, 5);
	std::list<int> std_l5(3, 5);
	std::cout << "fl5 size: " << ft_l5.size() << std::endl;
	std::cout << "sl5 size: " << std_l5.size() << std::endl;
	std::cout << "fl: " << ft_l5.front() << std::endl;
	std::cout << "fl: " << ft_l5.back() << std::endl;
	std::cout << "sl: " << std_l5.front() << std::endl;
	std::cout << "sl: " << std_l5.back() << std::endl;

	ft_l5 = ft_l6;
	std_l5 = std_l6;
	std::cout << "fl5 size: " << ft_l5.size() << std::endl;
	std::cout << "sl5 size: " << std_l5.size() << std::endl;
//	std::cout << "fl: " << ft_l5.front() << std::endl;
//	std::cout << "fl: " << ft_l5.back() << std::endl;
//	std::cout << "sl: " << std_l5.front() << std::endl;
//	std::cout << "sl: " << std_l5.back() << std::endl;

	const ft::list<int> ft_l8(5, 6);
	const ft::list<int> std_l8(5, 6);
	std::cout << "fl8 size: " << ft_l8.size() << std::endl;
	std::cout << "sl8 size: " << std_l8.size() << std::endl;
	std::cout << "fl: " << ft_l8.front() << std::endl;
	std::cout << "fl: " << ft_l8.back() << std::endl;
	std::cout << "sl: " << std_l8.front() << std::endl;
	std::cout << "sl: " << std_l8.back() << std::endl;

	return (0);
}
