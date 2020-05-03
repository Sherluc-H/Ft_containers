/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:50:42 by lhuang            #+#    #+#             */
/*   Updated: 2020/05/04 01:16:47 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "list.hpp"
#include <list>

int		main(void)
{
	ft::list<int> l;

	std::list<int> li;
	std::cout << li.front() << std::endl;
//	li.pop_back();
	l.push_back(2);
	std::cout << l.front() << std::endl;
	std::cout << l.back() << std::endl;
	l.show_all();
	l.pop_back();
	l.show_all();
	l.push_front(2);
	l.show_all();
	l.pop_front();
	l.show_all();
	l.push_front(3);
	std::cout << l.size() << std::endl;
	std::cout << l.max_size() << std::endl;

	ft::list<int> fl(3, 5);
	const ft::list<int> fl2(3, 5);
	fl.show_all();
	fl.push_back(10);
	ft::list<int>::iterator it = fl.begin();
	ft::list<int>::iterator it22 = fl.begin();
	ft::list<int>::iterator end = fl.end();
	ft::list<int> h(it, end);
	std::cout << "hey h: " << h.front() << std::endl;
	std::cout << "end h: " << h.back() << std::endl;
	std::cout << "hey: " << fl.front() << std::endl;
	std::cout << "end: " << fl.back() << *(--(fl.end())) << std::endl;
//	*it = 2;
//	std::cout << "it: " << *(it--) << std::endl;
	it22++;
	it22++;
	it22++;
	it22++;
	std::cout << "!" << std::endl;
	while (it != it22)
	{
		std::cout << "hey it = " << *it << std::endl;
	std::cout << "!!" << std::endl;
		it++;
	std::cout << "!!!" << std::endl;
	}
//	std::cout << "hey: " << fl.front() << std::endl;
//	const ft::list<int> cli = fl;
	ft::list<int>::const_iterator tcli = fl2.begin();

	li.push_back(1);
	li.push_back(2);
	li.push_back(3);
//	std::list<int>::iterator itl = li.begin();
//	*itl = 0;
	std::cout << li.front()<< std::endl;
	return (0);
}
