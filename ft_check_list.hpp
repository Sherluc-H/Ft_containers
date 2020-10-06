/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:36:46 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/06 22:02:04 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_LIST_HPP
# define FT_CHECK_LIST_HPP

# include <iostream>
# include "ft_check_utils.hpp"

template <class T>
void	ft_list_common_check(void)
{
	std::cout << "---common check---" << std::endl;
	T ctnr;

	std::cout << "size: " << ctnr.size() << std::endl;
	std::cout << "empty: " << ctnr.empty() << std::endl;
	std::cout << "max_size: " << ctnr.max_size() << std::endl;

	T ctnr3 = ctnr;

	ctnr.push_back(2);
	std::cout << "empty: " << ctnr.empty() << std::endl;
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
	ctnr2.push_back(10);
	ctnr2.pop_back();

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

	// ft_check_all_comp(ctnr, ctnr2);
	// ft_check_all_comp(ctnr2, ctnr3);
	// ft_check_all_comp(ctnr, ctnr5);
	// ft_check_all_comp(ctnr5, ctnr6);
	// ft_check_all_comp(ctnr7, ctnr8);
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

	std::cout << ctnr.front() << "|" << ctnr.size() << std::endl;
	ctnr_it2++;
	T ctnr5(ctnr_it, ++ctnr_it2);
	std::cout << (*ctnr_it) << std::endl;
	std::cout << (*ctnr_it2) << std::endl;

	std::cout << "size: " << ctnr5.size() << std::endl;
	std::cout << "front: " << ctnr5.front() << std::endl;
	std::cout << "back: " << ctnr5.back() << std::endl;

	std::cout << *ctnr_it << std::endl;
	ctnr_it--;
	std::cout << *ctnr_it << std::endl;
	ft_print_it_range(ctnr_it, ctnr_it_end);
	typename T::reverse_iterator rev_it_begin = ctnr.rbegin();
	typename T::reverse_iterator rev_it_end = ctnr.rend();
	ft_print_it_range(rev_it_begin, rev_it_end);
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
	// T three;
	// three.push_back(100);
	// three.push_back(200);
	// typename T::iterator three_it_begin = three.begin();
	// typename T::iterator three_it_end = three.end();
	// two.assign(three_it_begin, three_it_end);
	// three.assign(10, 1000);
	// two.push_back(6);
	// const T one1 = one;
	// const T two2 = two;
	// const ft::list<int> one1 = one;
	// const ft::list<int> two1 = two;
	ft_check_bigger_eq(one, two);
	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_begin2 = one.begin();
	// typename T::const_iterator cit = one_it_begin;//conversion ok
	// typename T::iterator iit = cit;//conversion pas ok
	one_it_begin2--;
	// one_it_begin2--;
	// std::cout << "begin:" << *one_it_begin << &(*one_it_begin) << std::endl;
	// std::cout << "begin:" << *one_it_begin2 << &(*one_it_begin2) << std::endl;
	ft_check_eq(one_it_begin, one_it_begin2);
	// one_it_begin--;
	// std::cout << "b" << *one_it_begin << &(*one_it_begin) << std::endl;
	// one_it_begin--;
	// std::cout << "b" << *one_it_begin << &(*one_it_begin) << std::endl;
	// one_it_begin--;
	// one_it_begin--;
	// one_it_begin++;
	std::cout << "b" << *one_it_begin << (*one_it_begin) << std::endl;
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
	ft_print_it_range(one_it_begin, two_it_end);
	one_it_end--;
	std::cout << "end" << *one_it_end << std::endl;
	ft_print_it_range(two_it_begin, one_it_end);
	std::cout << "here" << std::endl;
	one_it_begin = one.begin();
	one_it_end = one.end();
	two_it_begin = two.begin();
	two_it_end = two.end();
	ft_print_it_range(one_it_begin, one_it_end);
	std::cout << "here" << std::endl;
	ft_print_it_range(two_it_begin, two_it_end);
	std::cout << "hey" << std::endl;

	T three;
	three.push_back(100);
	three.push_back(200);
	typename T::iterator three_it_begin = three.begin();
	typename T::iterator three_it_end = three.end();
	two.assign(three_it_begin, three_it_end);
	ft_print_it_range(three_it_begin, three_it_end);
	three.assign(10, 1000);
	two_it_begin = two.begin();
	two_it_end = two.end();
	ft_print_it_range(two_it_begin, two_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);

	three.insert(three_it_begin, 50);
	// std::cout << "here1" << std::endl;
	three_it_begin = three.insert(three_it_begin, 500);
	// std::cout << "here2" << std::endl;
	three.insert(three_it_end, 5000);
	// std::cout << "here3" << std::endl;
	// three_it_begin = three.begin();
	// three_it_end = three.end();
	three.insert(three_it_begin, 2, 2);
	ft_print_it_range(three_it_begin, three_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);
	three_it_begin++;
	three.insert(three_it_begin, two_it_begin, two_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);

	// three_it_begin = three.begin();
	std::cout << "in" << *three_it_begin << std::endl;
	three_it_begin = three.erase(three_it_begin);
	std::cout << "in2" << std::endl;
	std::cout << *three_it_begin << "|" << std::endl;
	// three_it_begin = three.begin();
	// three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);
	three_it_begin = three.begin();
	three_it_end = three.end();
	three.erase(three_it_begin, three_it_end);
	std::cout << three.size() << std::endl;

	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);
	std::cout << one.size() << std::endl;
	one.erase(++one_it_begin, --one_it_end);
	one_it_begin = one.begin();
	// one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);
	std::cout << one.size() << std::endl;

	one.resize(1);
	std::cout << one.size() << std::endl;
	one.resize(20);
	std::cout << one.size() << std::endl;
	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);
	
	std::cout << one.size() << "|" << one.empty() << std::endl;
	one.clear();
	std::cout << one.size() << "|" << one.empty() << std::endl;
}

template<class T>
bool ft_is_digit2(const T& value)
{
	return (value < 10);
}

template<class T>
bool ft_is_smaller(const T& a, const T& b)
{
	return (a < b);
}

template <class T>
bool ft_is_bigger(const T& a, const T& b)
{
	return (a > b);
}

template <class T>
void ft_list_advanced_check()
{
	std::cout << "---advanced check---" << std::endl;
	T one;
	T two;
	T three;

	one.assign(3, 3);
	two.assign(6, 6);
	three.assign(9, 9);

	std::cout << one.size() << std::endl;
	std::cout << two.size() << std::endl;
	std::cout << three.size() << std::endl;

	typename T::iterator one_it_begin = one.begin();
	typename T::iterator one_it_end = one.end();

	one.splice(one_it_begin, two);

	std::cout << one.size() << std::endl;
	std::cout << two.size() << std::endl;
	ft_print_it_range(one_it_begin, one_it_end);
	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);

	typename T::reverse_iterator one_rev_it_begin = one.rbegin();
	typename T::reverse_iterator one_rev_it_end = one.rend();
	ft_print_it_range(one_rev_it_begin, one_rev_it_end);

	typename T::iterator three_it_begin = three.begin();
	typename T::iterator three_it_end = three.end();
	
	one.splice(++one_it_begin, three, --three_it_end);
	one_it_begin = one.begin();
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);

	one_rev_it_begin = one.rbegin();
	one_rev_it_end = one.rend();
	ft_print_it_range(one_rev_it_begin, one_rev_it_end);

	three_it_end = three.end();

	// three_it_end--;

	one.splice(one_it_begin, three, --three_it_end);
	ft_print_it_range(one_it_begin, one_it_end);
	three_it_end = three.end();//sans ca ca boucle
	ft_print_it_range(three_it_begin, three_it_end);

	one_rev_it_begin = one.rbegin();
	one_rev_it_end = one.rend();
	ft_print_it_range(one_rev_it_begin, one_rev_it_end);

	one.splice(--one_it_end, three, --three_it_end);
	ft_print_it_range(one_it_begin, one_it_end);
	one_it_end = one.end();
	ft_print_it_range(one_it_begin, one_it_end);
	three_it_end = three.end();
	ft_print_it_range(three_it_begin, three_it_end);

	one_it_begin = one.begin();
	one_it_end = one.end();
	three_it_begin = three.begin();
	three_it_end = three.end();
	ft_print_it_range(one_it_begin, one_it_end);
	ft_print_it_range(three_it_begin, three_it_end);
	one.splice(one_it_end, three, three_it_begin);
	ft_print_it_range(one_it_begin, one_it_end);
	three_it_begin = three.begin();
	ft_print_it_range(three_it_begin, three_it_end);

	std::cout << one.size() << "|" << three.size() << std::endl;
	one.splice(one.begin(), three, three.begin(), three.end());
	std::cout << one.size() << "|" << three.size() << std::endl;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(three.begin(), three.end());

	one.splice(one.begin(), three, one.begin());
	ft_print_it_range(one.begin(), one.end());
	std::cout << one.size() << "|" << three.size() << std::endl;
	one.splice(one.begin(), three);

	std::cout << one.size() << std::endl;
	one.remove(3);
	ft_print_it_range(one.begin(), one.end());
	std::cout << one.size() << std::endl;

	one.remove_if(ft_is_digit2<typename T::value_type>);
	std::cout << one.size() << std::endl;

	one.push_back(1);
	one.push_back(10);
	one.push_back(10);
	one.push_back(20);
	one.push_back(20);
	one.push_back(2);
	one.push_back(20);
	one.push_back(10);
	one.remove_if(ft_is_digit2<typename T::value_type>);
	std::cout << one.size() << std::endl;
	ft_print_it_range(one.begin(), one.end());
	// one.unique();
	one.unique(ft_is_smaller<typename T::value_type>);
	std::cout << one.size() << std::endl;
	ft_print_it_range(one.begin(), one.end());

	two.assign(20, 20);
	ft_print_it_range(two.begin(), two.end());
	two.unique();
	ft_print_it_range(two.begin(), two.end());

	T a;

	a.sort();

	a.push_back(10);
	
	a.unique();

	std::cout << a.size() << std::endl;
	
	a.merge(a);

	std::cout << "a:" << a.size() << std::endl;

	std::cout << "a" << std::endl;

	one.merge(two);
	// std::cout << "b" << std::endl;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	// std::cout << "c" << std::endl;

	two.assign(2, 10);
	ft_print_it_range(two.begin(), two.end());
	// std::cout << "d" << std::endl;
	two.merge(one);
	// std::cout << "e" << std::endl;
	ft_print_it_range(one.begin(), one.end());
	ft_print_it_range(two.begin(), two.end());
	std::cout << "f" << std::endl;

	one.assign(10, 10);
	one.push_back(100);
	ft_print_it_range(one.begin(), one.end());

	// two.merge(one, ft_is_smaller<int>);
	two.merge(one, ft_is_bigger<int>);
	ft_print_it_range(two.begin(), two.end());

	two.reverse();
	std::cout << "g" << std::endl;
	ft_print_it_range(two.begin(), two.end());

	two.sort();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	std::cout << "a" << std::endl;
	two.sort(ft_is_bigger<int>);
	std::cout << "b" << std::endl;
	ft_print_it_range(two.begin(), two.end());
	two.sort(ft_is_smaller<int>);
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());

	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());
	
	two.reverse();
	ft_print_it_range(two.begin(), two.end());
	ft_print_it_range(two.rbegin(), two.rend());

	ft_check_all_comp(one, two);
	ft_check_all_comp(two, one);
	ft_check_all_comp(one, three);
	ft_check_all_comp(three, one);
	ft_check_all_comp(two, three);
	ft_check_all_comp(three, two);
}

#endif
