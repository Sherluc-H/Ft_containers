/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:06:30 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/08 22:38:46 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		typedef struct		s_map_el
		{
			struct s_map_el*		previous;
			int					pos;//0 == root, 1 == left, 2 == right
			std::pair<const Key, T>	val;
			// int						pos;
			struct s_map_el*		next_left;
			struct s_map_el*		next_right;
		}					t_map_el;
		class Value_comp: public std::binary_function<std::pair<const Key, T>, std::pair<const Key, T>, bool>
		{
			friend class map;
			protected:
				Value_comp(const Compare& comp)
				{
					this->comp = comp;
				}
			public:
				bool operator()(const std::pair<const Key, T>& x, const std::pair<const Key, T>& y)
				{
					return (this->comp(x.first, y.first));
				}
			private:
				Compare comp;
		};
		public:
			typedef Key 									key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Value_comp								value_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
		private:
			class iterator
			{
				public:
					typedef value_type value_type;
					typedef difference_type difference_type;
					typedef value_type& reference;
					typedef value_type* pointer;
					typedef ft::bidirectional_iterator_tag iterator_category;
					iterator()
					{
						this->el = NULL;
						this->crement = 0;
						this->before_end = NULL;
					}
					iterator(t_map_el* el, int crement = 0)
					{
						this->el = el;
						this->crement = crement;
						this->before_end = NULL;
						// std::cout << "start" << std::endl;
						this->el = ft_get_cremented(*this, &this->before_end);
						// std::cout << "end" << std::endl;
						// if (this->el == NULL)
						// {
						// 	std::cout << "h" << std::endl;
						// 	this->before_end = ft_get_first_right(el);
						// }
						// if (this->before_end)
						// 	std::cout << "this->before" << this->before_end->val.first << std::endl;
					}
					iterator(const iterator& it)
					{
						*this = it;
					}
					iterator &operator=(const iterator& it)
					{
						this->el = it.el;
						this->crement = it.crement;
						this->before_end = it.before_end;
						return (*this);
					}
					~iterator()
					{}
					bool operator==(const iterator& it) const
					{
						// return (this->el == it.el && this->crement == it.crement);
						// std::cout << "comp2" << std::endl;
						// std::cout << this->el->val.first << "|" << it.el->val.first << std::endl;
						// std::cout << this->crement << "|" << it.crement << std::endl;
						// ft_get_cremented(*this);
						// std::cout << "a" << &(this->el->val) << "|" << &(it.el->val) << std::endl;
						// ft_get_cremented(it);
						// std::cout << "b" << &(it.el) << std::endl;
						// return (ft_get_cremented(*this) == ft_get_cremented(it));
						return (this->el == it.el);
					}
					bool operator!=(const iterator& it) const
					{
						return (!(*this == it));
					}
					value_type &operator*() const
					{
						// std::cout << "a:" << &(*this->el) << std::endl;
						return (this->el->val);
						// return ((ft_get_cremented(*this)->val));
					}
					value_type *operator->() const
					{
						return (&(this->operator*()));
					}
					iterator &operator++()
					{
						// this->crement = this->crement + 1;
						this->el = ft_get_next_el(this->el, &this->before_end);
						return (*this);
					}
					iterator operator++(int)
					{
						iterator tmp = *this;

						// this->crement = this->crement + 1;
						this->el = ft_get_next_el(this->el, &this->before_end);
						return (tmp);
					}
					iterator &operator--()
					{
						// this->crement = this->crement - 1;
						if (this->el == NULL)
						{
							// std::cout << "aaaa" << this->before_end->val.first << std::endl;
							this->el = this->before_end;
						}
						else
							this->el = ft_get_previous_el(this->el);
						return (*this);
					}
					iterator operator--(int)
					{
						// std::cout << "here1" << std::endl;
						iterator tmp = *this;

						// this->crement = this->crement - 1;
						if (this->el == NULL)
						{
							// std::cout << "in" << std::endl;
							// std::cout << this->before_end->val.first << std::endl;
							this->el = this->before_end;
						}
						else
							this->el = ft_get_previous_el(this->el);
						// std::cout << "here2" << std::endl;
						return (tmp);
					}
				private:
					t_map_el* el;
					int crement;
					t_map_el* before_end;
					t_map_el* ft_get_first_left(t_map_el* el) const
					{
						while (el)
						{
							if (!(el->next_left))
								break;
							el = el->next_left;
						}
						return (el);
					}
					t_map_el* ft_get_first_right(t_map_el* el) const
					{
						while (el)
						{
							if (!(el->next_right))
								break;
							el = el->next_right;
						}
						return (el);
					}
					t_map_el* ft_get_next_el(t_map_el* el, t_map_el** before_end) const
					{
						// t_map_el* el = it.el;
						if (el->next_right)
							return (ft_get_first_left(el->next_right));
						else if (el->pos == 1)
							return (el->previous);
						else if (el->pos == 2)
						{
							while (el->pos == 2)
								el = el->previous;
							if (el->pos == 1)
								return (el->previous);
							else if (el->pos == 0)
							{
								el = ft_get_first_right(el);
								// std::cout << "HERE" << el->val.first << std::endl;
								// if (before_end)
								// 	std::cout << "y" << std::endl;
								*before_end = el;
								// if (before_end)
								// 	std::cout << "z" << std::endl;
								return (el->next_right);
							}
							return (ft_get_first_left(el->next_right));
						}
						else
						{
							if (el->pos == 0)
								*before_end = el;
							return (ft_get_first_left(el->next_right));
						}
					}
					t_map_el* ft_get_previous_el(t_map_el* el) const
					{
						if (el->next_left)
							return (ft_get_first_right(el->next_left));
						else if (el->pos == 2)
							return (el->previous);
						else if (el->pos == 1)
						{
							while (el->pos == 1)
								el = el->previous;
							if (el->pos == 2)
								return (el->previous);
							else if (el->pos == 0)
							{
								el = ft_get_first_left(el);
								return (el->next_left);
							}
							return (ft_get_first_right(el->next_left));
						}
						else
							return (ft_get_first_right(el->next_left));
					}
					t_map_el* ft_get_cremented(const iterator& it, t_map_el** before_end) const
					{
						t_map_el* first = it.el;
						int crement = it.crement;
						int i = 0;
						// bool from_right = false;

						while (first)
						{
							if (!(first->next_left))
								break;
							first = first->next_left;
						}
						// i++;
						while (i < crement)
						{
							first = ft_get_next_el(first, before_end);
							i++;
							// // std::cout << "a" << std::endl;
							// if (first->next_right && !from_right)
							// {
							// // std::cout << "b" << std::endl;
							// 	first = first->next_right;
							// 	while (first)
							// 	{
							// 		if (!(first->next_left))
							// 			break;
							// 		first = first->next_left;
							// 	}
							// 	if (first)
							// 		i++;
							// }
							// else
							// {
							// // std::cout << "c" << std::endl;
							// 	if (first->pos == 1)
							// 		from_right = false;
							// 	else if (first->pos == 2)
							// 		from_right = true;
							// 	if (!(first->previous))
							// 	{
							// // std::cout << "c1" << std::endl;
							// 		if (first->next_right)
							// 			first = first->next_right;
							// 		while (first)
							// 		{
							// // std::cout << "c2" << std::endl;
							// 			if (!(first->next_right))
							// 				break;
							// 			first = first->next_right;
							// 		}
							// // std::cout << "c3" << std::endl;
							// 		first = first->next_right;
							// 		i++;
							// 		break;
							// 	}
							// 	else
							// 		first = first->previous;
							// 	if (first && !from_right)
							// 		i++;
							// }
						}
							// std::cout << "d" << std::endl;
						return (first);
					}
			};
			class const_iterator
			{
				public:
					typedef value_type value_type;
					typedef difference_type difference_type;
					typedef value_type& reference;
					typedef value_type* pointer;
					typedef ft::bidirectional_iterator_tag iterator_category;
					const_iterator()
					{}
					const_iterator(const iterator& it)
					{
						this->it = it;
					}
					const_iterator(const const_iterator& cit)
					{
						*this = cit;
					}
					const_iterator &operator=(const const_iterator& cit)
					{
						this->it = cit.it;
						return (*this);
					}
					~const_iterator()
					{}
					bool operator==(const const_iterator& cit) const
					{
						// std::cout << "commp" << std::endl;
						return (this->it == cit.it);
					}
					bool operator!=(const const_iterator& cit) const
					{
						return (this->it != cit.it);
					}
					value_type &operator*() const
					{
						return (*(this->it));
					}
					value_type *operator->() const
					{
						return ((this->it).operator->());
					}
					const_iterator &operator++()
					{
						this->it++;
						return (*this);
					}
					const_iterator operator++(int)
					{
						const_iterator tmp = *this;
						this->it++;
						return (tmp);
					}
					const_iterator &operator--()
					{
						this->it--;
						return (*this);
					}
					const_iterator operator--(int)
					{
						const_iterator tmp = *this;
						this->it--;
						return (tmp);
					}
				private:
					iterator it;
			};
			
		public:
			typedef class iterator iterator;
			typedef class const_iterator const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				this->el = NULL;
				this->map_size = 0;
				this->comp = comp;
				this->alloc = alloc;
			}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				(void)first;
				(void)last;
				this->el = NULL;
				this->map_size = 0;
				this->comp = comp;
				this->alloc = alloc;
				this->insert(first, last);
			}
			map(const map& x)
			{
				this->el = NULL;
				this->map_size = 0;
				*this = x;
			}
			~map()
			{
				this->clear();
			}
			map& operator=(const map& x)
			{
				if (this->map_size > 0)
				{
					// std::cout << this->map_size << std::endl;
					this->clear();
				}
				// this->alloc = x.alloc;
				this->comp = x.comp;
				const_iterator it_begin = x.begin();
				const_iterator it_end = x.end();
				while (it_begin != it_end)
				{
					this->insert(*it_begin);
					it_begin++;
				}
				return (*this);
			}
			iterator begin()
			{
				return (typename ft::map<key_type, mapped_type>::iterator(this->el));
			}
			const_iterator begin() const
			{
				return (typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el)));
			}
			iterator end()
			{
				return (typename ft::map<key_type, mapped_type>::iterator(this->el, this->map_size));
			}
			const_iterator end() const
			{
				return (typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, this->map_size)));
			}
			reverse_iterator rbegin()
			{
				// std::cout << "msize:" << this->map_size << std::endl;
				return (typename ft::map<key_type, mapped_type>::reverse_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, this->map_size)));
			}
			const_reverse_iterator rbegin() const
			{
				return (typename ft::map<key_type, mapped_type>::const_reverse_iterator(typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, this->map_size))));
			}
			reverse_iterator rend()
			{
				return (typename ft::map<key_type, mapped_type>::reverse_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el)));
			}
			const_reverse_iterator rend() const
			{
				return (typename ft::map<key_type, mapped_type>::const_reverse_iterator(typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el))));
			}
			bool empty() const
			{
				return (this->map_size == 0);
			}
			size_type size() const
			{
				return (this->map_size);
			}
			size_type max_size() const
			{
				typename allocator_type::template rebind<t_map_el>::other r;
				return (r.max_size());
			}
			mapped_type& operator[](const key_type& k)
			{
				// std::cout << "a" << std::endl;
				if (this->count(k) == 0)
				{
					// std::cout << "aa" << std::endl;
					this->insert(std::pair<int, int>(k, mapped_type()));
				}
				// std::cout << "b" << std::endl;
				iterator it = this->find(k);
				// std::cout << "c" << std::endl;
				return ((*it).second);
			}
			std::pair<iterator, bool> insert(const value_type& val)
			{
				(void)val;
				std::pair<iterator, bool> p;
				typename allocator_type::template rebind<t_map_el>::other r;
				key_compare comp;

				if (this->map_size == 0)
				{
					t_map_el *new_el = ft_new_el(val);
					this->el = new_el;
					this->map_size = this->map_size + 1;
					p = std::make_pair(this->find(val.first), true);
					// p = value_type(true, true);
					return (p);
				}
				t_map_el* next = this->el;
				while (next)
				{
					// if (next->val.first > val.first)
					if (comp(val.first, next->val.first))
					{
						if (!(next->next_left))
							break;
						next = next->next_left;
					}
					else if (comp(next->val.first, val.first))
					{
						if (!(next->next_right))
							break;
						next = next->next_right;
					}
					else
					{
						t_map_el* new_el = ft_new_el(val);
						// new_el->previous = next->previous;
						// new_el->next_left = next->next_left;
						// new_el->next_right = next->next_right;
						// new_el->pos = next->pos;
						// if (next->pos == 1)
						// 	next->previous->next_left = new_el;
						// else if (next->pos == 2)
						// 	next->previous->next_right = new_el;
						// else if (next->pos == 0)
						// 	this->el = new_el;
						// if (next->next_right)
						// 	next->next_right->previous = new_el;
						// if (next->next_left)
						// 	next->next_left->previous = new_el;
						// next->val.second = val.second;
						ft_deallocate_n_destroy(new_el);
						// p = value_type(false, false);
						p = std::make_pair(this->find(val.first), false);
						return (p);
					}
				}
				t_map_el* new_el = ft_new_el(val);
				if (next->val.first > val.first)
				{
					next->next_left = new_el;
					new_el->pos = 1;
				}
				else
				{
					next->next_right = new_el;
					new_el->pos = 2;
				}
				this->map_size = this->map_size + 1;
				new_el->previous = next;
				// p = value_type(true, false);
				p = std::make_pair(this->find(val.first), true);
				return (p);
			}
			iterator insert(iterator position, const value_type& val)
			{
				(void)position;//a changer ?
				// iterator tmp = position;
				std::pair<iterator, bool> p;
				if (position != this->end())
				{
					iterator tmp = position;
					tmp++;
					if (*position < val && (tmp == this->end() || *tmp > val))
					{
						// std::cout << "ok" << std::endl;
						// t_map_el* prev = *position;
						// value_type *val2 = position.operator->();
						reference val2 = *position;
						t_map_el *prev = (t_map_el*)((&((char*)(&val2))[-12]));
						// std::cout << "size:" << sizeof(int) << "|" << sizeof(std::pair<int, int>) << "|" << sizeof(t_map_el*) << "|" << sizeof(char*) << std::endl;
						// std::cout << "b:" << &(*prev) << std::endl;
						// std::cout << &(val2) << std::endl;
						// std::cout << "hey:" << prev->val.first << std::endl;
						if (!(prev->next_right))
						{
							// std::cout << "here!" << std::endl;
							t_map_el* new_el = ft_new_el(val);
							new_el->previous = prev;
							new_el->pos = 2;
							prev->next_right = new_el;
							p = std::make_pair(iterator(new_el), true);
							this->map_size = this->map_size + 1;
						}
						else
						{
							p = this->insert(val);
						}
						// p = std::make_pair(tmp, true);
					}
					else
					{
						// std::cout << "pas ok" << std::endl;
						p = this->insert(val);
					}
				}
				else
				{
					p = this->insert(val);
				}
				return (p.first);
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					if (!(this->count((*first).first)))
						this->insert(*first);
					first++;
				}
			}
			void erase(iterator position)
			{
				// std::cout << "a" << std::endl;
				// std::cout << (*position).first << std::endl;
				int crement = ft_search_specific((*position).first, ft_comp_for_eq);
				// std::cout << "a1" << std::endl;
				if ((size_type)crement < this->map_size)
					this->map_size = this->map_size - 1;
				// std::cout << "a2" << std::endl;
				t_map_el* tmp = ft_get_crement_el(this->el, crement);
				// std::cout << "a3" << std::endl;
				t_map_el* tmp_prev = tmp->previous;
				// std::cout << "b" << std::endl;
				if (tmp->next_left && tmp->next_right)
				{
				// std::cout << "c" << std::endl;
					t_map_el* tmp_next_right = tmp->next_right;
					t_map_el* tmp_next_right_left = ft_get_first_left_from(tmp_next_right);
					tmp->next_left->previous = tmp_next_right_left;
					tmp_next_right_left->next_left = tmp->next_left;
					tmp_next_right->previous = tmp_prev;
					if (tmp->pos == 0)
					{
						tmp_next_right->pos = 0;
						this->el = tmp_next_right;
					}
					else if (tmp->pos == 1)
					{
						tmp_prev->next_left = tmp_next_right;
						tmp_next_right->pos = 1;
					}
					else if (tmp->pos == 2)
					{
						tmp_prev->next_right = tmp_next_right;
						tmp_next_right->pos = 2;
					}
					ft_deallocate_n_destroy(tmp);
				}
				else if (!tmp->next_left && !tmp->next_right)
				{
				// std::cout << "d" << std::endl;
					if (tmp->pos == 0)
						this->el = NULL;
					else if (tmp->pos == 1)
						tmp_prev->next_left = NULL;
					else if (tmp->pos == 2)
						tmp_prev->next_right = NULL;
					ft_deallocate_n_destroy(tmp);
				}
				else if (tmp->next_left)
				{
				// std::cout << "e" << std::endl;
					tmp->next_left->previous = tmp_prev;
					if (tmp->pos == 0)
					{
						this->el = tmp->next_left;
						tmp->next_left = 0;
					}
					else if (tmp->pos == 1)
					{
						tmp_prev->next_left = tmp->next_left;
						tmp->next_left->pos = 1;
					}
					else if (tmp->pos == 2)
					{
						tmp_prev->next_right = tmp->next_left;
						tmp->next_left->pos = 2;
					}
					ft_deallocate_n_destroy(tmp);
				}
				else if (tmp->next_right)
				{
				// std::cout << "f" << std::endl;
					tmp->next_right->previous = tmp_prev;
					if (tmp->pos == 0)
					{
						this->el = tmp->next_right;
						tmp->next_right->pos = 0;
					}
					else if (tmp->pos == 1)
					{
						tmp_prev->next_left = tmp->next_right;
						tmp->next_right->pos = 1;
					}
					else if (tmp->pos == 2)
					{
						tmp_prev->next_right = tmp->next_right;
						tmp->next_right->pos = 2;
					}
					ft_deallocate_n_destroy(tmp);
				}
				// std::cout << "g" << std::endl;
			}
			size_type erase(const key_type& k)
			{
				// int ret = 0;
				int crement = ft_search_specific(k, ft_comp_for_eq);
				if ((size_type)crement < this->map_size)
				{
					// ret = 1;
					this->erase(this->find(k));
					return (1);
				}
				return (0);
			}
			void erase(iterator first, iterator last)
			{
				iterator tmp;
				while (first != last)
				{
					tmp = first;
					first++;
					// std::cout << (*tmp).first << std::endl;
					this->erase((*tmp).first);
					// std::cout << "here" << std::endl;
				}
				// std::cout << "first" << this->el->val.first << std::endl;
				// int crement = ft_search_specific((*first).first, ft_comp_for_eq);
				// iterator it = iterator(this->el, crement);
				// (void)last;
				// while (it != last)
				// {
				// 	std::cout << "here" << std::endl;
				// 	std::cout << "it:" << (*it).first << "|" << crement << std::endl;
				// 	std::cout << "here1" << std::endl;
				// 	this->erase((*it).first);
				// 	std::cout << "here2" << std::endl;
				// 	// first++;
				// 	it = iterator(this->el, crement);
				// 	std::cout << "here3" << std::endl;
				// }
				// std::cout << "here" << std::endl;
			}
			void swap(map& x)
			{
				t_map_el* tmp_el = x.el;
				size_type tmp_map_size = x.map_size;
				x.el = this->el;
				x.map_size = this->map_size;
				this->el = tmp_el;
				this->map_size = tmp_map_size;
			}
			void clear()
			{
				// iterator it_begin = this->begin();
				// iterator it_end = this->end();
				// iterator tmp;
				int i = 0;
				int size = this->size();
				// while (it_begin != it_end)
				while (i < size)
				{
					// std::cout << "i:" << i << "|" << (*this->begin()).first << std::endl;
					// tmp = it_begin;
					// it_begin++;
					this->erase((*this->begin()).first);
					i++;
				}
				// t_map_el* el_tab[this->map_size];
				// int new_old = 0;
				// if (this->map_size == 0)
				// 	return;
				// t_map_el* first = this->el;
				// first = ft_get_first_left_from(first);
				// el_tab[new_old] = first;
				// new_old++;
				// bool from_right = false;
				// typename allocator_type::template rebind<t_map_el>::other r;
				// while (1)
				// {
				// 	if (first->next_right && !from_right)
				// 	{
				// 		first = first->next_right;
				// 		first = ft_get_first_left_from(first);
				// 		el_tab[new_old] = first;
				// 		new_old++;
				// 	}
				// 	else
				// 	{
				// 		if (first->pos == 1)
				// 			from_right = false;
				// 		else if (first->pos == 2)
				// 			from_right = true;
				// 		if (!(first->previous))
				// 			break;
				// 		first = first->previous;
				// 		if (!from_right)
				// 		{
				// 			el_tab[new_old] = first;
				// 			new_old++;
				// 		}
				// 	}
				// }
				// int i = 0;
				// while (i < new_old)
				// {
				// 	r.destroy(el_tab[1]);
				// 	r.deallocate(el_tab[i], 1);
				// 	// r.destroy(el_tab[i]);
				// 	i++;
				// }
				// this->map_size = 0;
			}
			value_compare value_comp() const
			{
				value_compare valcmp(this->comp);
				return (valcmp);
			}
			key_compare key_comp() const
			{
				return (this->comp);
			}
			iterator find(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_eq);
				// std::cout << "here30" << std::endl;
				return (typename ft::map<key_type, mapped_type>::iterator(this->el, crement));
			}
			const_iterator find(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_eq);
				// std::cout << "here35" << std::endl;
				// const_iterator ct =  const_iterator(iterator(this->el, crement));
				// std::cout << "herect" << std::endl;
				return (typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, crement)));
			}
			size_type count(const key_type& k) const
			{
				if (this->find(k) == this->end())
				{
					// std::cout << "not found" << std::endl;
					return (0);
				}
				// std::cout << "found" << std::endl;
				return (1);
			}
			iterator lower_bound(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_lower);
				return (typename ft::map<key_type, mapped_type>::iterator(this->el, crement));
			}
			const_iterator lower_bound(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_lower);
				return (typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, crement)));
			}
			iterator upper_bound(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_upper);
				return (typename ft::map<key_type, mapped_type>::iterator(this->el, crement));
			}
			const_iterator upper_bound(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_upper);
				return (typename ft::map<key_type, mapped_type>::const_iterator(typename ft::map<key_type, mapped_type>::iterator(this->el, crement)));
			}
			std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const
			{
				const_iterator one = this->find(k);
				if (one != this->end())
					return (std::pair<const_iterator, const_iterator>(one, this->upper_bound(k)));
				const_iterator cit_one = this->upper_bound(k);
				return (std::pair<const_iterator, const_iterator>(cit_one, cit_one));
			}
			std::pair<iterator, iterator> equal_range(const key_type& k)
			{
				iterator one = this->find(k);
				if (one != this->end())
					return (std::pair<iterator, iterator>(one, this->upper_bound(k)));
				iterator it_one = this->upper_bound(k);
				return (std::pair<iterator, iterator>(it_one, it_one));
			}
			// void ft_show_all()//a enlever
			// {
			// 	t_map_el* first = this->el;
				// std::cout << "show start" << std::endl;
			// 	if (first == NULL)
			// 	{
					// std::cout << "none" << std::endl;
			// 		return;
			// 	}
			// 	first = ft_get_first_left_from(first);
				// std::cout << first->val.first << "|" << first->val.second << std::endl;
			// 	bool from_right = false;
			// 	while (1)
			// 	{
			// 		if (first->next_right && !from_right)
			// 		{
			// 			first = first->next_right;
			// 			first = ft_get_first_left_from(first);
			// 			std::cout << "a" << first->val.first << "|" << first->pos << std::endl;
			// 		}
			// 		else
			// 		{
			// 			if (first->pos == 1)
			// 				from_right = false;
			// 			else if (first->pos == 2)
			// 				from_right = true;
			// 			if (!(first->previous))
			// 				break;
			// 			first = first->previous;
			// 			if (!from_right)
			// 				std::cout << "c" << first->val.first << "|" << first->pos << std::endl;
			// 		}
			// 	}
			// 	std::cout << "show end" << std::endl;
			// }
		private:
			t_map_el *el;
			size_type map_size;
			allocator_type alloc;
			key_compare comp;

			t_map_el* ft_new_el(const value_type& val)
			{
				typename allocator_type::template rebind<t_map_el>::other r;
				t_map_el el;
				this->alloc.construct(&(el.val), val);
				t_map_el* new_el = r.allocate(1);

				r.construct(new_el, el);
				new_el->previous = NULL;
				new_el->pos = 0;
				new_el->next_left = NULL;
				new_el->next_right = NULL;
				return (new_el);
			}
			static bool ft_comp_for_lower(key_type a, key_type b)
			{
				key_compare comp;
				return (!(comp(a, b)));
			}
			static bool ft_comp_for_upper(key_type a, key_type b)
			{
				key_compare comp;
				return (comp(b, a));
			}
			static bool ft_comp_for_eq(key_type a, key_type b)
			{
				key_compare comp;
				return (comp(a, b) == false && comp(b, a) == false);
			}
			int ft_search_specific(const key_type& k, bool(*f)(key_type, key_type)) const
			{
				// std::cout << "here" << std::endl;
				t_map_el* first = this->el;
				bool from_right = false;
				int crement = 0;

				// std::cout << "here1" << std::endl;
				first = ft_get_first_left_from(first);
				// std::cout << "here11" << std::endl;
				if (!first || f(first->val.first, k))
					return (crement);
				// std::cout << "here2" << std::endl;
				crement++;
				// std::cout << "here3" << std::endl;
				while (1)
				{
					// std::cout << "val:" << first->val.first << std::endl;
					if (first->next_right && !from_right)
					{
						first = first->next_right;
						first = ft_get_first_left_from(first);
						if (f(first->val.first, k))
							return (crement);
						crement++;
					}
					else
					{
						// std::cout << "hhhhh" << std::endl;
						if (first->pos == 1)
							from_right = false;
						else if (first->pos == 2)
							from_right = true;
						if (!(first->previous))
							break;
						// std::cout << "p" << std::endl;
						first = first->previous;
						if (!from_right)
						{
							if (f(first->val.first, k))
								return (crement);
							crement++;
						}
					}
				}
				// std::cout << "aaaaa" << std::endl;
				// std::cout << "crement:" << crement << std::endl;
				return (crement);
			}
			t_map_el* ft_get_crement_el(t_map_el* el, const int& crement) const
			{
				t_map_el* first = el;
				int i = 0;
				bool from_right = false;

				first = ft_get_first_left_from(first);
				while (i < crement)
				{
					if (first->next_right && !from_right)
					{
						first = first->next_right;
						first = ft_get_first_left_from(first);
						i++;
					}
					else
					{
						if (first->pos == 1)
							from_right = false;
						else if (first->pos == 2)
							from_right = true;
						if (!(first->previous))
						{
							first = first->next_right;
							if (first == NULL)
								break;
							while (first)
							{
								if (!(first->next_right))
									break;
								first = first->next_right;
							}
							first = first->next_right;
							i++;
							break;
						}
						else
							first = first->previous;
						if (!from_right)
							i++;
					}
				}
				return (first);
			}
			t_map_el* ft_get_first_left_from(t_map_el* el) const
			{
				t_map_el* first = el;

				while (first)
				{
					if (!(first->next_left))
						break;
					first = first->next_left;
				}
				return (first);
			}
			void ft_deallocate_n_destroy(t_map_el* el)
			{
				typename allocator_type::template rebind<t_map_el>::other r;

				r.destroy(el);
				r.deallocate(el, 1);
				// r.destroy(el);
			}
	};
}

#endif
