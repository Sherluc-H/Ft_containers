/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:51:24 by lhuang            #+#    #+#             */
/*   Updated: 2020/09/19 20:47:43 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <limits>
#include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
			
		private:
			typedef struct	s_list_el
			{
				struct s_list_el *previous;
				value_type value;
				struct s_list_el *next;
			}				t_list_el;
			class iterator
			{
				public:
					typedef value_type value_type;
					typedef difference_type difference_type;
					typedef pointer pointer;
					typedef reference reference;
					typedef ft::bidirectional_iterator_tag iterator_category;
				// public:
					iterator()
					{
						this->el = NULL;
						this->crement = 0;
					//	std::cout << "it default constructor" << std::endl;
					}
					iterator(t_list_el* el, int crement = 0)
					{
						this->el = el;
						this->crement = crement;
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
						this->el = it.el;
						this->crement = it.crement;
						return (*this);
					}
					bool operator==(const iterator& it2)
					{
						// std::cout << "a" << std::endl;
						t_list_el *one = this->el;
						t_list_el *two = it2.el;
						// std::cout << this->crement << "|" << it2.crement << std::endl;
						int i = 0;
						while (i < this->crement)
						{
							// if (one)
								one = one->next;
							i++;
						}
						i = 0;
						while (i < it2.crement)
						{
							// if (two)
								two = two->next;
							i++;
						}
						// std::cout << "hereb" << one << "|" << two << std::endl;
						if (one == two)
							return (true);
						return (false);
						// if ((this->el) == it2.el)
						// 	return (true);
						// return (false);
					}
					bool operator!=(const iterator& it2)
					{
						// std::cout << "in" << std::endl;
						return (!(*this == it2));
					}
					value_type &operator*()
					{
						int i = 0;
						t_list_el *tmp = this->el;
						
						while (i < this->crement)
						{
							tmp = tmp->next;
							i++;
						}
						i = 0;
						while (this->crement + i < 0)
						{
							tmp = tmp->previous;
							i++;
						}
						// std::cout << "c" << std::endl;
						return (tmp->value);
						// return (this->el->value);
					}
					value_type *operator->()
					{
						int i = 0;
						t_list_el *tmp = this->el;

						while (i < this->crement)
						{
							tmp = tmp->next;
						}
						return (&this->el->value);
						// return (&this->el->value);
					}
					iterator &operator++()
					{
						// this->el = this->el->next;
						this->crement++;
						// std::cout << "aa" << std::endl;
						return (*this);
					}
					iterator operator++(int i)
					{
						iterator tmp;
						(void)i;

						tmp = *this;
						// this->el = this->el->next;
						this->crement++;
						// std::cout << "bb" << std::endl;
						return (tmp);
					}
					iterator &operator--()
					{
						// this->el = this->el->previous;
						this->crement--;
						return (*this);
					}
					iterator operator--(int i)
					{
						iterator tmp;
						(void)i;

						tmp = *this;
						// this->el = this->el->previous;
						this->crement--;
						return (tmp);
					}

				private:
					t_list_el* el;
					int crement;
			};
			class const_iterator
			{
				public:
					const_iterator()
					{
					//	std::cout << "it default constructor" << std::endl;
					}
					const_iterator(const t_list_el* el)
					{
						this->el = el;
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
						this->el = it.el;
						return (*this);
					}
					bool operator==(const const_iterator& it)
					{
						if (this->el == it.el)
							return (true);
						return (false);
					}
					bool operator!=(const const_iterator& it)
					{
						return (!(*this == it));
					}
					value_type operator*()
					{
						return (this->el->value);
					}
					const_iterator &operator++()
					{
						this->el = this->el->next;
						return (*this);
					}
					const_iterator operator++(int i)
					{
						(void)i;
						const_iterator tmp = *this;

						this->el = this->el->next;
						return (tmp);
					}

				private:
					const t_list_el* el;
			};
		public:
			typedef class iterator iterator;
			typedef class const_iterator const_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
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
				std::cout << "list destructor" << std::endl;
				this->clear();
				std::cout << "end" << std::endl;
			}
			list(const list& x)
			{
				// t_list_el *el;
				std::cout << "list copy constructor" << std::endl;
				this->first_el = NULL;
				this->l_size = 0;
				*this = x;
				// if (x.l_size > 0)
				// {
				// 	el = x.first_el;
				// 	while (el && el->next)
				// 	{
				// 		this->push_back(el->value);
				// 		el = el->next;
				// 	}
				// 	this->push_back(el->value);
				// }
			}
			list &operator=(const list& x)
			{
				t_list_el *el;

				std::cout << "list op=" << std::endl;
				this->clear();
				this->first_el = NULL;
				this->l_size = 0;
				if (x.l_size > 0)
				{
					el = x.first_el;
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
				return (ft::list<T, Alloc>::iterator(this->first_el));
			}
			const_iterator begin() const
			{
				return (ft::list<T, Alloc>::const_iterator(this->first_el));
			}
			iterator end()
			{
				// t_list_el *tmp = this->first_el;
				// while (tmp->next)
				// 	tmp = tmp->next;
				// tmp = tmp->next;
				return (ft::list<T, Alloc>::iterator(this->first_el, this->l_size));
			}
			const_iterator end() const
			{
				// t_list_el *tmp = this->first_el;
				// while (tmp->next)
				// 	tmp = tmp->next;
				// tmp = tmp->next;
				return (ft::list<T, Alloc>::const_iterator(this->first_el, this->l_size));
			}
			reverse_iterator rbegin()
			{
				// std::cout << "test" << std::endl;
				// iterator a = this->end();
				// // --a;
				// // a--;
				// // std::cout << "aa" << *a << std::endl;
				// iterator b = this->begin();
				// iterator c = this->begin();
				// b++;
				// while (b != a)
				// {
				// 	c++;
				// 	b++;
				// }
				// std::cout << *c << std::endl;
				return (ft::reverse_iterator<iterator>(this->end()));
			}
			reverse_iterator rend()
			{
				return (ft::reverse_iterator<iterator>(this->begin()));
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
				// allocator_type a;
				// std::cout << a.max_size() << std::endl;

				//return (std::numeric_limits<size_t>::max());
				typename Alloc::template rebind<t_list_el>::other r;

				return (r.max_size());
			}
			reference front()
			{
				T a = T();
				T *t = &a;
				// if (!this->first_el)
				// 	return (0);
				if (!this->first_el)
				{
					// std::cout << "here" << std::endl;
					return (*t);
				}
				return (this->first_el->value);
			}
			const_reference front() const
			{
				T *t = NULL;
				// if (!this->first_el)
				// 	return (0);
				if (!this->first_el)
					return (*t);
				return (this->first_el->value);
			}
			reference back()
			{
				if (this->l_size == 0)
				{
					T a = T();//ne marche plus si c est str par exemple ? T a la place de int == 0 ca semble marcher
					T *t = &a;
					return (*t);
				}
				t_list_el *end_el;

				end_el = this->first_el;
				// if (!this->first_el)
				// 	return (0);
				while (end_el && end_el->next)
					end_el = end_el->next;
				return (end_el->value);
			}
			const_reference back() const
			{
				t_list_el *end_el;

				end_el = first_el;
				// if (!this->first_el)
				// 	return (0);
				while (end_el && end_el->next)
					end_el = end_el->next;
				return(end_el->value);
			}
			//assign
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				this->clear();
				ft_push_elements(first, last, *this, std::numeric_limits<InputIterator>::is_integer);
			}
			void assign(size_type n, const value_type& val)
			{
				this->clear();
				ft_push_elements(n, val, *this);
			}
			void push_front(const value_type& val)
			{
			//	t_list_el *new_el = new t_list_el;
				typename Alloc::template rebind<t_list_el>::other r;

				t_list_el *new_el = r.allocate(1);
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
				// std::cout << "here1" << std::endl;
				t_list_el *tmp;
				typename Alloc::template rebind<t_list_el>::other r;

				tmp = this->first_el->next;
				// this->first_el = this->first_el->next;
				//delete tmp;
				r.deallocate(this->first_el, 1);
				r.destroy(this->first_el);
				this->first_el = tmp;
				// r.destroy(tmp);
				this->l_size = this->l_size - 1;
			}
			void push_back(const value_type& val)
			{
				t_list_el *end_el;
				t_list_el *new_el;
				typename Alloc::template rebind<t_list_el>::other r;

			//	std::cout << "push_back" << std::endl;
				if (this->l_size == 0)
				{
					this->push_front(val);
					return ;
				}
				//new_el = new t_list_el;
				new_el = r.allocate(1);
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
				typename Alloc::template rebind<t_list_el>::other r;

				tmp = this->first_el;
				while(tmp && tmp->next)
					tmp = tmp->next;
				if (tmp && tmp->previous)
				{
					new_end_el = tmp->previous;
					new_end_el->next = NULL;
					//delete tmp;
					r.deallocate(tmp, 1);
					r.destroy(tmp);
				}
				else
				{
					//delete this->first_el;
					r.deallocate(this->first_el, 1);
					r.destroy(this->first_el);
					this->first_el = NULL;
				}
				this->l_size = this->l_size - 1;
			}
			// void clear()
			// {
			// 	while (this->l_size)
			// 		this->pop_front();//pop front problem ?
			// }
			//insert
			iterator insert(iterator position, const value_type& val)
			{
				std::cout << "insert" << std::endl;
				t_list_el *el = this->first_el;
				while (el && &(el->value) != &(*position) && el->next)
				{
				// std::cout << &(el->next->value)<< "|" << el->value << &(el->value) << "||" <<  *position << std::endl;
					el = el->next;
				}
				t_list_el *prev_el = el->previous;
				typename Alloc::template rebind<t_list_el>::other r;
				t_list_el *new_el = r.allocate(1);
				new_el->previous = el->previous;
				new_el->value = val;
				new_el->next = el;
				el->previous = new_el;
				if (el == this->first_el)
					this->first_el = new_el;
				else if (prev_el)//a verifier
					prev_el->next = new_el;
				this->l_size = this->l_size + 1;
				// t_list_el *to_show = this->first_el;
				// std::cout << "start" << std::endl;
				// while (to_show)
				// {
				// 	std::cout << to_show->value << std::endl;
				// 	// std::cout << this->l_size << std::endl;
				// 	to_show = to_show->next;
				// }
				// std::cout << "end" << std::endl;
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type i = 0;
				while (i < n)
				{
					this->insert(position, val);//postion a deplacer ?
					i++;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)//rajouter protection cas n == int
			{
				// if (std::numeric_limits<InputIterator>::is_integer)
				// {
				// 	// this->insert(position, (size_type)first, (value_type)last);
				// 	F<InputIterator, true>()(position, first, last, this);
				// 	return;
				// }
				// else
				// {
					F<InputIterator, std::numeric_limits<InputIterator>::is_integer>()(position, first, last, this);
					// ft_insert_from_iterator<U, false>(position, first, last);
					// ft_insert_from_iterator(position, first, last, std::numeric_limits<InputIterator>::is_integer);
					// while (first != last)
					// {
					// 	if (std::numeric_limits<InputIterator>::is_integer)
					// 		this->insert(position, *first);
					// 	position++;
					// 	first++;
					// }
				// }
			}
			iterator erase(iterator position)
			{
				iterator position_next = position++;
				t_list_el *tmp = this->first_el;
				typename Alloc::template rebind<t_list_el>::other r;

				while (tmp && &(tmp->value) != &(*position) && tmp->value)
					tmp = tmp->next;
				if (this->first_el == tmp)
					this->first_el = tmp->next;
				else
				{
					t_list_el *prev_el = tmp->previous;
					t_list_el *next_el = tmp->next;
					prev_el->next = next_el;
					next_el->previous = prev_el;
				}
				r.deallocate(tmp, 1);
				r.destroy(tmp);
				return (position_next);
			}
			iterator erase(iterator first, iterator last)
			{
				while (first != last)
				{
					this->erase(first);
					first++;
				}
				return (last);
			}
			void swap(list& x)
			{
				(void)x;
				// list tmp = *this;
				t_list_el *tmp = this->first_el;
				size_type tmp_size = this->l_size;
				(void)tmp;
				// this->clear();
				// this->insert(x.begin(), x.begin(), x.end());
				// x.clear();
				// x.insert(tmp->begin(), tmp->begin(), tmp->end());
				// this->first_el = (t_list_el*)&(((char*)(&x.front()))[-sizeof(char*)]);
				this->first_el = x.first_el;
				this->l_size = x.l_size;
				// std::cout << "a" << std::endl;
				x.first_el = tmp;
				x.l_size = tmp_size;
				// std::cout << "b" << std::endl;
				// t_list_el *x_first_el = (t_list_el*)&(((char*)&x.front())[-sizeof(char*)]);
				// x_first_el->previous = (t_list_el*)&(((char*)&(tmp.front()))[-sizeof(char*)]);
				// x_first_el->value = tmp.front();
				// (t_list_el*)&(((char*)&(x.front()))[sizeof(char*)]) = tmp.front();
				// x.insert(x.begin(), tmp->begin(), tmp->end());
				// x = NULL;
				// x = list(tmp);
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (this->l_size > n)
				{
					while (this->l_size > n)
						this->pop_back();
				}
				else if (this->l_size < n)
				{
					while (this->l_size < n)
						this->push_back(val);
				}
			}
			void clear()
			{
				while (this->l_size)
					this->pop_front();
			}
			void splice(iterator position, list& x)
			{
				t_list_el *tmp = this->first_el;
				t_list_el *tmp_next;
				while (tmp && &tmp->value != &(*position))//1 pos de trop loin ?
				{
					tmp = tmp->next;
				}
				tmp_next = tmp->next;
				x.first_el->previous = tmp;
				tmp->next = x.first_el;
				tmp->l_size = tmp->l_size + x.l_size;
				while(tmp->next)
					tmp = tmp->next;
				tmp->next = tmp_next;
				x.first_el = NULL;
				x.l_size = 0;
			}
			void splice(iterator position, list& x, iterator i)
			{
				t_list_el *tmp = this->first_el;
				t_list_el *tmp_next;
				while (tmp && &tmp->value != &(*position))
					tmp = tmp->next;
				t_list_el *to_add_tmp = x.first_el;
				t_list_el *to_add;
				while (to_add_tmp && &to_add_tmp->value != &(*i))
					to_add_tmp = to_add_tmp->next;
				//retire de x
				t_list_el *before = to_add_tmp->previous;
				t_list_el *after = to_add_tmp->next;
				before->next = after;
				after->previous = before;
				x.l_size = x.l_size - 1;
				//
				to_add = to_add_tmp->previous;
				to_add->previous = tmp;
				tmp_next = tmp->next;
				tmp->next = to_add;
				this->l_size = this->l_size + 1;
			}
			void splice(iterator position, list& x, iterator first, iterator last)
			{
				while (first != last)
				{
					this->splice(position, x, first);//peut etre probleme ici
					first++;
				}
			}
			void remove(const value_type& val)
			{
				// size_type i = 0;
				// t_list_el *tmp = this->first_el;
				// while (i < this->l_size)
				// {
				// 	if (tmp->value == val)
				// 	{
						
				// 	}
				// 	i++;
				// }
				iterator begin = this->begin();
				iterator end = this->end();
				while (begin != end)
				{
					if (*begin == val)
						this->erase(begin);
					begin++;
				}
			}
			template <class Predicate>
			void remove_if(Predicate pred)
			{
				iterator begin = this->begin();
				iterator end = this->end();
				while (begin != end)
				{
					if (pred(*begin))
						this->erase(begin);
					begin++;
				}
			}
			void unique()
			{
				iterator begin = this->begin();
				iterator end = this->end();
				value_type prev = *begin;
				if (begin != end)
					begin++;
				while (begin != end)
				{
					if (prev == *begin)
						this->erase(begin);
					else
						prev = *begin;
					begin++;
				}
			}
			template <class Predicate>
			void unique(Predicate pred)
			{
				iterator begin = this->begin();
				iterator end = this->end();
				iterator prev_it = begin;
				if (begin != end)
					begin++;
				while (begin != end)
				{
					if (pred(*begin, *prev_it))
						this->erase(begin);
					else
						prev_it = begin;
					begin++;
				}
			}
			void merge(list& x)
			{
				// iterator begin = this->begin();
				// iterator end = this->end();
				// iterator x_begin = x.begin();
				// iterator x_end = x.end();
				t_list_el *tmp = this->first_el;
				size_type tmp_size = this->l_size;
				size_type i = 0;
				t_list_el *x_tmp = x.first_el;
				size_type x_tmp_size = x.l_size;
				size_type j = 0;
				// while (tmp)
				// {
					// tmp = tmp->next;
				// }
				t_list_el *prev;
				if (x_tmp->value <= tmp->value)
				{
					this->first_el = x_tmp;
					x_tmp = x_tmp->next;
					j++;
				}
				else
				{
					tmp = tmp->next;
					i++;
				}
				prev = this->first_el;
				while (i < tmp_size && j < x_tmp_size)
				{
					if (tmp->value <= x_tmp->value)
					{
						tmp->previous = prev;
						prev->next = tmp;
						prev = tmp;
						tmp = tmp->next;
						i++;
					}
					else
					{
						x_tmp->previous = prev;
						prev->next = x_tmp;
						prev = x_tmp;
						x_tmp = x_tmp->next;
						j++;
					}
				}
				if (i < tmp_size)
				{
					tmp->previous = prev;
					prev->next = tmp;
				}
				else
				{
					x_tmp->previous = prev;
					prev->next = x_tmp;
				}
				this->l_size = i + j;
				x.first_el = NULL;
				x.l_size = 0;
			}
			template <class Compare>
			void merge(list& x, Compare comp)
			{
				// iterator begin = this->begin();
				// iterator end = this->end();
				// iterator x_begin = x.begin();
				// iterator x_end = x.end();
				t_list_el *tmp = this->first_el;
				size_type tmp_size = this->l_size;
				size_type i = 0;
				t_list_el *x_tmp = x.first_el;
				size_type x_tmp_size = x.l_size;
				size_type j = 0;
				// while (tmp)
				// {
					// tmp = tmp->next;
				// }
				t_list_el *prev;
				// if (x_tmp->value < tmp->value)
				if (comp(x_tmp->value, tmp->value))
				{
					this->first_el = x_tmp;
					x_tmp = x_tmp->next;
					j++;
				}
				else
				{
					tmp = tmp->next;
					i++;
				}
				prev = this->first_el;
				while (i < tmp_size && j < x_tmp_size)
				{
					// if (tmp->value <= x_tmp->value)
					if (comp(x_tmp->value, tmp->value))
					{
						x_tmp->previous = prev;
						prev->next = x_tmp;
						prev = x_tmp;
						x_tmp = x_tmp->next;
						i++;
					}
					else
					{
						tmp->previous = prev;
						prev->next = tmp;
						prev = tmp;
						tmp = tmp->next;
						j++;
					}
				}
				if (i < tmp_size)
				{
					tmp->previous = prev;
					prev->next = tmp;
				}
				else
				{
					x_tmp->previous = prev;
					prev->next = x_tmp;
				}
				this->l_size = i + j;
				x.first_el = NULL;
				x.l_size = 0;
			}
			void sort()
			{
				t_list_el *tmp = this->first_el;
				t_list_el *tmp_next;
				size_type i = 0;
				size_type j = 0;
				// value_type* tmp_value_ptr;
				t_list_el *new_el;
				while (i < this->l_size)
				{
					j = 0;
					while (j < this->l_size && tmp)
					{
						tmp_next = tmp->next;
						if (tmp && tmp_next && tmp->value > tmp_next->value)//checker les next et previous
						{
							tmp_next->previous = tmp->previous;
							tmp->previous = tmp_next;
							tmp->next = tmp_next->next;
							tmp_next->next = tmp;
							// tmp->next = tmp_next;
							// tmp_value_ptr = &tmp->value;
							new_el->next = tmp_next;
						}
						else
							new_el->next = tmp;
						new_el = new_el->next;
						tmp = tmp->next;
						j++;
					}
					tmp = new_el;
					i++;
				}
				this->first_el = new_el;
				this->first_el->previous = NULL;
				tmp = this->first_el;
				while (i < this->l_size)
				{
					tmp = tmp->next;
					i++;
				}
				tmp->next = NULL;
			}
			template <class Compare>
			void sort(Compare comp)
			{
				t_list_el *tmp = this->first_el;
				t_list_el *tmp_next;
				size_type i = 0;
				size_type j = 0;
				value_type* tmp_value_ptr;
				t_list_el *new_el;
				while (i < this->l_size)
				{
					j = 0;
					while (j < this->l_size && tmp)
					{
						tmp_next = tmp->next;
						if (tmp && tmp_next && comp(tmp_next->value, tmp->value))//checker les next et previous
						{
							tmp_next->previous = tmp->previous;
							tmp->previous = tmp_next;
							tmp->next = tmp_next->next;
							tmp_next->next = tmp;
							// tmp->next = tmp_next;
							// tmp_value_ptr = &tmp->value;
							new_el->next = tmp_next;
						}
						else
							new_el->next = tmp;
						new_el = new_el->next;
						tmp = tmp->next;
						j++;
					}
					tmp = new_el;
					i++;
				}
				this->first_el = new_el;
				this->first_el.previous = NULL;
				tmp = this->first_el;
				while (i < this->l_size)
				{
					tmp = tmp->next;
					i++;
				}
				tmp->next = NULL;
			}
			void reverse()
			{
				t_list_el *tmp = this->first_el;
				size_type i = 0;
				while (i < this->l_size)
				{
					tmp = tmp->next;
					i++;
				}
				t_list_el *new_el = tmp;
				i = 0;
				while (i < this->l_size)
				{
					t_list_el *tmp_next = tmp->next;
					tmp->next = tmp->previous;
					tmp->previous = tmp_next;
					tmp = tmp->next;
					i++;
				}
				this->first_el = new_el;
			}
			// allocator_type get_allocator() const
			// {
			// 	std::cout << "in" << std::endl;
			// 	allocator_type a;
			// 	int *b = a.allocate(5);
			// 	a.deallocate(b, 5);
			// 	return (a);
			// }

//			void show_all();
		private:
			t_list_el	*first_el;
			size_t		l_size;
			template <class U>
			void ft_push_elements(U n, U val, ft::list<T> ctnr)
			{
				*this = ctnr;
				U i = 0;
				while (i < n)
				{
					ctnr.push_back(val);
					i++;
				}
			}
			template <class U>
			void ft_push_elements(U first, U last, ft::list<T> ctnr, bool is_integer)
			{
				*this = ctnr;
				if (!is_integer)
				{
					while (first != last)
					{
						ctnr.push_back(*first);
						first++;
					}
					return;
				}
				U n = first;
				U val = last;
				U i = 0;
				
				while (i < n)
				{
					ctnr.push_back(val);
					i++;
				}
			}
			// template <bool, class U>
			// void ft_insert_from_iterator(iterator position, U first, U last)
			// {
			// 	U i = 0;
			// 	while (i < last)
			// 	{
			// 		this->insert(position, first);
			// 		i++;
			// 	}
			// }
			// template <class U, bool>
			// struct f
			// {
				
			// };
			template <class U, bool>
			class F
			{
				public:
					F();
					~F();
			};
			template <class U>
			class F<U, true>
			{
				public:
					void operator()(iterator position, U first, U last, list *ctnr)
					{
						U i = 0;
						while (i < first)
						{
							ctnr->insert(position, last);
							i++;
						}
					}
			};
			template <class U>
			class F<U, false>
			{
				public:
					void operator()(iterator position, U first, U last, list *ctnr)
					{
						while (first != last)
						{
							ctnr->insert(position, *first);
							first++;
						}
					}
			};
			template <class U, bool>
			class Construct
			{
				public:
					Construct(){
						std::cout << "HERE" << std::endl;
					}
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
						// ft_push_elements(n, val, ctnr);
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
	template <class T, class Alloc>
	bool operator==(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename list<T, Alloc>::const_iterator lhs_begin = lhs.begin();
			typename list<T, Alloc>::const_iterator lhs_end = lhs.end();
			typename list<T, Alloc>::const_iterator rhs_begin = rhs.begin();
			typename list<T, Alloc>::const_iterator rhs_end = rhs.end();
			while (lhs_begin != lhs_end && rhs_begin != rhs_end)
			{
				if (*lhs_begin != *rhs_begin)
					return (false);
				lhs_begin++;
				rhs_begin++;
			}
			if (lhs_begin == lhs_end && rhs_begin == rhs_end)
				return (true);
			return (false);
		}
		return (false);
	}
	template <class T, class Alloc>
	bool operator!=(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{
		(void)lhs;
		(void)rhs;
		typename list<T, Alloc>::iterator lhs_begin = lhs.begin();
		typename list<T, Alloc>::iterator lhs_end = lhs.end();
		typename list<T, Alloc>::iterator rhs_begin = rhs.begin();
		typename list<T, Alloc>::iterator rhs_end = rhs.end();
		while (lhs_begin != lhs_end && rhs_begin != rhs_end)
		{
			if (*lhs_begin < *rhs_begin)
				return (true);
			lhs_begin++;
			rhs_begin++;
		}
		if (lhs_begin == lhs_end && rhs_begin == rhs_end)
			return (false);
		else if (lhs_begin == lhs_end)
			return (true);
		return (false);
	}
	template <class T, class Alloc>
	bool operator<=(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap(list<T, Alloc>& x, list<T, Alloc>& y)
	{
		x.swap(y);
	}
}
/*
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
}*/
