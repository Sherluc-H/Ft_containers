/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:51:24 by lhuang            #+#    #+#             */
/*   Updated: 2020/05/30 00:15:06 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

namespace ft
{
	template <class T>
	class list
	{
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef size_t size_type;
		typedef struct	s_list_el
		{
			struct s_list_el *previous;
			value_type value;
			struct s_list_el *next;
		}				t_list_el;
		public:
			class iterator
			{
				public:
					iterator()
					{
					//	std::cout << "it default constructor" << std::endl;
					}
					iterator(t_list_el* l, bool is_start): l(l), is_start(is_start), crement(0)
					{
					//	std::cout << "it param constructor" << std::endl;
					}
					~iterator()
					{
					//	std::cout << "it destructor" << std::endl;
					}
					iterator(const iterator& it)
					{
					//	std::cout << "it copy constructor" << std::endl;
						*this = it;
					}
					iterator &operator=(const iterator& it)
					{
					//	std::cout << "it op=" << std::endl;
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
					value_type &operator*()
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

						el = it.l;
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
					t_list_el* l;
					bool is_start;
					int crement;
			};
			class const_iterator
			{
				public:
					const_iterator(const t_list_el* l, bool is_start): l(l), is_start(is_start), crement(0)
					{
					//	std::cout << "it const param constructor" << std::endl;
					}
					~const_iterator()
					{
					//	std::cout << "it destructor" << std::endl;
					}
					const_iterator(const const_iterator& it)
					{
					//	std::cout << "it copy constructor" << std::endl;
						*this = it;
					}
					const_iterator &operator=(const const_iterator& it)
					{
					//	std::cout << "it op=" << std::endl;
						this->l = it.l;
						this->is_start = it.is_start;
						this->crement = it.crement;
						return (*this);
					}

				private:
					const_iterator()
					{
					//	std::cout << "it default constructor" << std::endl;
					}
					const t_list_el* l;
					bool is_start;
					int crement;
			};
			//add reverse_iterator && const_reverse_iterator
			explicit list()
			{
			//	std::cout << "list default constructor" << std::endl;
				this->first_el = NULL;
				this->l_size = 0;
			}
			explicit list(size_type n, const value_type& val = value_type())
			{
				size_type i;

			//	std::cout << "list fill constructor" << std::endl;
				i = 0;
				this->first_el = NULL;
				this->l_size = 0;
				while (i < n)
				{
					this->push_back(val);
					i++;
				}
			}
			template <class InputIterator>
			list(InputIterator start, InputIterator end)
			{
				this->first_el = NULL;
				this->l_size = 0;
				Construct<InputIterator, std::numeric_limits<InputIterator>::is_integer>()(start, end, this);
			}
			~list()
			{
			//	std::cout << "list destructor" << std::endl;
				this->clear();
			}
			list(const list& l)
			{
			//	std::cout << "list copy constructor" << std::endl;
				this->first_el = NULL;
				this->l_size = 0;
				*this = l;
			}
			list &operator=(const list& l)
			{
				t_list_el *el;

			//	std::cout << "list op=" << std::endl;
				this->clear();
				this->first_el = NULL;
				this->l_size = 0;
				if (l.l_size > 0)
				{
					el = l.first_el;
					while (el && el->next)
					{
						this->push_back(el->value);
						el = el->next;
					}
					this->push_back(el->value);
				}
				return (*this);
			}
			iterator begin()
			{
				return (ft::list<T>::iterator(this->first_el, true));
			}
			const_iterator begin() const
			{
				return (ft::list<T>::const_iterator(this->first_el, true));
			}
			iterator end()
			{
				return (ft::list<T>::iterator(this->first_el, false));
			}
			const_iterator end() const
			{
				return (ft::list<T>::const_iterator(this->first_el, false));
			}
			bool empty() const
			{
				if (this->l_size == 0)
					return (true);
				return (false);
			}
			size_type size() const
			{
				return (this->l_size);
			}
			size_type max_size() const
			{
				return (std::numeric_limits<size_t>::max());
			}
			reference front()
			{
				return (this->first_el->value);
			}
			const_reference front() const
			{
				return (this->first_el->value);
			}
			reference back()
			{
				t_list_el *end_el;

				end_el = this->first_el;
				while (end_el && end_el->next)
					end_el = end_el->next;
				return (end_el->value);
			}
			const_reference back() const
			{
				t_list_el *end_el;

				end_el = first_el;
				while (end_el && end_el->next)
					end_el = end_el->next;
				return(end_el->value);
			}
			void push_front(const value_type& val)
			{
				t_list_el *new_el = new t_list_el;

			//	std::cout << "push_front" << std::endl;
				new_el->previous = NULL;
				new_el->value = val;
				new_el->next = this->first_el;
				if (this->l_size)
					this->first_el->previous = new_el;
				this->first_el = new_el;
				this->l_size = this->l_size + 1;
			}
			void pop_front()
			{
				t_list_el *tmp;

				tmp = this->first_el;
				this->first_el = this->first_el->next;
				delete tmp;
				this->l_size = this->l_size - 1;
			}
			void push_back(const value_type& val)
			{
				t_list_el *end_el;
				t_list_el *new_el;

			//	std::cout << "push_back" << std::endl;
				if (this->l_size == 0)
				{
					this->push_front(val);
					return ;
				}
				new_el = new t_list_el;
				end_el = this->first_el;
				while (end_el && end_el->next)
					end_el = end_el->next;
				new_el->previous = end_el;
				new_el->value = val;
				new_el->next = NULL;
				end_el->next = new_el;
				this->l_size = this->l_size + 1;
			}
			void pop_back()
			{
				t_list_el *new_end_el;
				t_list_el *tmp;

				tmp = this->first_el;
				while(tmp && tmp->next)
					tmp = tmp->next;
				if (tmp && tmp->previous)
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
			void clear()
			{
				while (this->l_size)
					this->pop_front();
			}

			void show_all();
		private:
			t_list_el *first_el;
			size_t l_size;
			template <class U, bool>
			class Construct
			{
				public:
					Construct(){}
					~Construct(){}
				private:
					Construct(const Construct& c);
					Construct &operator=(const Construct& c);
			};
			template <class U>
			class Construct<U, true>
			{
				public:
					Construct(){}
					~Construct(){}
					void operator()(U n, U val, ft::list<T> *ctnr)
					{
						U i;

						i = 0;
						while (i < n)
						{
							ctnr->push_back(val);
							i++;
						}
					}
				private:
					Construct(const Construct& c);
					Construct &operator=(const Construct& c);
			};
			template <class U>
			class Construct<U, false>
			{
				public:
					Construct(){}
					~Construct(){}
					void operator()(U start, U end, ft::list<T> *ctnr)
					{
						while (start != end)
						{
							ctnr->push_back(*start);
							start++;
						}
					}
				private:
					Construct(const Construct& c);
					Construct &operator=(const Construct& c);
			};
	};
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
		el = el->next;
		std::cout << el->value << std::endl;
	}
}
