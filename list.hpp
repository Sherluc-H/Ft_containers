/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:51:24 by lhuang            #+#    #+#             */
/*   Updated: 2020/05/04 01:16:14 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

namespace ft
{
	template <class T>
	class list
	{
		typedef struct	s_list_el
		{
			struct s_list_el *previous;
			T value;
			struct s_list_el *next;
		}				t_list_el;
		public:
			class iterator
			{
				public:
					iterator()
					{
						std::cout << "it default constructor" << std::endl;
					}
					iterator(list* l, bool is_start): l(l), is_start(is_start), crement(0)
					{
						std::cout << "it param constructor" << std::endl;
					}
					~iterator()
					{
						std::cout << "it destructor" << std::endl;
					}
					iterator(const iterator& it)
					{
						std::cout << "it copy constructor" << std::endl;
						*this = it;
					}
					iterator &operator=(const iterator& it)
					{
						std::cout << "it op=" << std::endl;
						this->l = it.l;
						this->is_start = it.is_start;
						this->crement = it.crement;
						return (*this);
					}
					bool operator==(const iterator& it2)
					{
						if (get_it_ptr_el(*this) == get_it_ptr_el(it2))
							return (true);
						return (false);
					}
					bool operator!=(const iterator& it2)
					{
						if (get_it_ptr_el(*this) == get_it_ptr_el(it2))
							return (false);
						return (true);
					}
					T &operator*()
					{
						return ((get_it_ptr_el(*this))->value);
					}
					iterator &operator++()
					{
						this->crement = this->crement + 1;
						return (*this);
					}
					iterator operator++(int i)
					{
						iterator tmp;
						(void)i;

						tmp = *this;
						this->crement = this->crement + 1;
						return (tmp);
					}
					iterator &operator--()
					{
						this->crement = this->crement - 1;
						return (*this);
					}
					iterator operator--(int i)
					{
						iterator tmp;
						(void)i;

						tmp = *this;
						this->crement = this->crement - 1;
						return (tmp);
					}

				private:
					t_list_el *get_it_ptr_el(const iterator& it)
					{
						t_list_el *el;
						int el_crement;
						int i;

						el = it.l->first_el;
						el_crement = it.crement;
						if (!(it.is_start))
						{
							while(el->next)
								el = el->next;
							el_crement++;
						}
						if (el_crement > 0)
						{
							i = 0;
							while (i < el_crement)
							{
								el = el->next;
								i++;
							}
						}
						else
						{
							i = 0;
							while (i > el_crement)
							{
								el = el->previous;
								i--;
							}
						}
						return (el);
					}
					list* l;
					bool is_start;
					int crement;
			};
			class const_iterator
			{
				public:
					const_iterator(const list* l, bool is_start): l(l), is_start(is_start), crement(0)
					{
						std::cout << "it const param constructor" << std::endl;
					}
					~const_iterator()
					{
						std::cout << "it destructor" << std::endl;
					}
					const_iterator(const const_iterator& it)
					{
						std::cout << "it copy constructor" << std::endl;
						*this = it;
					}
					const_iterator &operator=(const const_iterator& it)
					{
						std::cout << "it op=" << std::endl;
						this->l = it.l;
						this->is_start = it.is_start;
						this->crement = it.crement;
						return (*this);
					}

				private:
					const_iterator()
					{
						std::cout << "it default constructor" << std::endl;
					}
					const list* l;
					bool is_start;
					int crement;
			};
			//add reverse_iterator && const_reverse_iterator
			explicit list();
			explicit list(int n, const T& val);
			template <class InputIterator>
			list(InputIterator start, InputIterator end);
			~list();
			list(const list& l);
			list &operator=(const list& l);
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			bool empty() const;
			size_t size() const;
			size_t max_size() const;
			T &front();
			const T &front() const;
			T &back();
			const T &back() const;
			void push_front(const T& val);
			void pop_front();
			void push_back(const T& val);
			void pop_back();

			void show_all();
		private:
			t_list_el *first_el;
			size_t l_size;
	};
}

template <class T>
ft::list<T>::list()
{
	std::cout << "list default constructor" << std::endl;
	this->first_el = NULL;
	this->l_size = 0;
}

template <class T>
ft::list<T>::list(int n, const T& val)
{
	int i;

	std::cout << "list fill constructor" << std::endl;
	i = 0;
	this->first_el = NULL;
	this->l_size = 0;
	while (i < n)
	{
		this->push_back(val);
		i++;
	}
}

template <class T>
template <class InputIterator>
ft::list<T>::list(InputIterator first, InputIterator last)
{
	this->first_el = NULL;
	this->l_size = 0;
	this->push_back(*first);
	while(first != last)
	{
		std::cout << "a" << std::endl;
		this->push_back(*first);
		first++;
	}
}

template <class T>
ft::list<T>::~list()
{
	t_list_el *el;
	t_list_el *tmp;

	std::cout << "list destructor" << std::endl;
	el = this->first_el;
	if (this->l_size > 0)
	{
		while (el->next)
		{
			tmp = el;
			el = el->next;
			delete tmp;
		}
		delete el;
	}
}

template <class T>
ft::list<T>::list(const list& l)
{
	std::cout << "list copy constructor" << std::endl;
	this = l;
}

template <class T>
ft::list<T> &ft::list<T>::operator=(const list& l)
{
	std::cout << "list op=" << std::endl;
	this->l = l.l;
	this->l_size = l.l_size;
}

template <class T>
typename ft::list<T>::iterator ft::list<T>::begin()
{
	std::cout << "begin" << std::endl;
	return (ft::list<T>::iterator(this, true));
}

template <class T>
typename ft::list<T>::const_iterator ft::list<T>::begin() const
{
	std::cout << "const begin" << std::endl;
	return (ft::list<T>::const_iterator(this, true));
}

template <class T>
typename ft::list<T>::iterator ft::list<T>::end()
{
	return (ft::list<T>::iterator(this, false));
}

template <class T>
typename ft::list<T>::const_iterator ft::list<T>::end() const
{
	return (ft::list<T>::const_iterator(this, false));
}

template <class T>
bool ft::list<T>::empty() const
{
	if (this->l_size == 0)
		return (true);
	return (false);
}

template <class T>
size_t ft::list<T>::size() const
{
	return (this->l_size);
}

template <class T>
size_t ft::list<T>::max_size() const
{
	return (std::numeric_limits<size_t>::max());
}

template <class T>
T &ft::list<T>::front()
{
	return (this->first_el->value);
}

template <class T>
const T &ft::list<T>::front() const
{
	return (this->first_el->value);
}

template <class T>
T &ft::list<T>::back()
{
	t_list_el *end_el;

	end_el = this->first_el;
	while (end_el->next)
		end_el = end_el->next;
	return (end_el->value);
}

template <class T>
const T &ft::list<T>::back() const
{
	t_list_el *end_el;

	end_el = first_el;
	while (end_el->next)
		end_el = end_el->next;
	return(end_el->value);
}

template <class T>
void ft::list<T>::push_front(const T& val)
{
	t_list_el *new_el = new t_list_el;

	std::cout << "push_front" << std::endl;
	new_el->previous = NULL;
	new_el->value = val;
	new_el->next = this->first_el;
	this->first_el = new_el;
	this->l_size = this->l_size + 1;
}

template <class T>
void ft::list<T>::pop_front()
{
	t_list_el *tmp;

	tmp = this->first_el;
	this->first_el = this->first_el->next;
	delete tmp;
	this->l_size = this->l_size - 1;
}

template <class T>
void ft::list<T>::push_back(const T& val)
{
	t_list_el *end_el;
	t_list_el *new_el = new t_list_el;

	std::cout << "push_back" << std::endl;
	if (this->l_size == 0)
	{
		new_el->previous = NULL;
		new_el->value = val;
		new_el->next = NULL;
		this->first_el = new_el;
		this->l_size = this->l_size + 1;
		return ;
	}
	end_el = this->first_el;
	while (end_el->next)
		end_el = end_el->next;
	new_el->previous = end_el;
	new_el->value = val;
	new_el->next = NULL;
	end_el->next = new_el;
	this->l_size = this->l_size + 1;
}

template <class T>
void ft::list<T>::pop_back()
{
	t_list_el *new_end_el;
	t_list_el *tmp;

	tmp = this->first_el;
	while(tmp->next)
		tmp = tmp->next;
	if (tmp->previous)
	{
		new_end_el = tmp->previous;
		new_end_el->next = NULL;
		delete tmp;
	}
	else
	{
		delete this->first_el;
		this->first_el = NULL;
	}
	this->l_size = this->l_size - 1;
}

template <class T>
void ft::list<T>::show_all()
{
	t_list_el *el;

	el = first_el;
	std::cout << "start show all, size = " << this->l_size << std::endl;
	if (el)
	{
		std::cout << el->value << std::endl;
	}
	while (el && el->next)
	{
		std::cout << el->value << el->next << std::endl;
		el = el->next;
	}
}
