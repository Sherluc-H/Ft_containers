/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 21:06:30 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/12 01:03:00 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
		class Value_comp: public std::binary_function<std::pair<const Key, T>, std::pair<const Key, T>, bool>
		{
			friend class map;
			protected:
				Value_comp(const Compare& comp)
				{
					this->comp = comp;
				}
			public:
				~Value_comp()
				{}
				Value_comp(const Value_comp& v)
				{
					*this = v;
				}
				Value_comp& operator=(const Value_comp& v)
				{
					this->comp = v.comp;
					return (*this);
				}
				bool operator()(const std::pair<const Key, T>& x, const std::pair<const Key, T>& y)
				{
					return (this->comp(x.first, y.first));
				}
			private:
				Value_comp()
				{}
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
			typedef struct				s_map_el
			{
				struct s_map_el*		previous;
				int						pos;//0 == root, 1 == left, 2 == right
				std::pair<const Key, T>	val;
				struct s_map_el*		next_left;
				struct s_map_el*		next_right;
			}							t_map_el;
			
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
					~iterator()
					{

					}
					iterator(t_map_el* el, int crement = 0)
					{
						this->el = el;
						this->crement = crement;
						this->before_end = NULL;
						this->el = ft_get_cremented(*this, &this->before_end);
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
					bool operator==(const iterator& it) const
					{
						return (this->el == it.el);
					}
					bool operator!=(const iterator& it) const
					{
						return (!(*this == it));
					}
					value_type &operator*() const
					{
						return (this->el->val);
					}
					value_type *operator->() const
					{
						return (&(this->operator*()));
					}
					iterator &operator++()
					{
						this->el = ft_get_next_el(this->el, &this->before_end);
						return (*this);
					}
					iterator operator++(int)
					{
						iterator tmp = *this;

						this->el = ft_get_next_el(this->el, &this->before_end);
						return (tmp);
					}
					iterator &operator--()
					{
						if (this->el == NULL)
							this->el = this->before_end;
						else
							this->el = ft_get_previous_el(this->el);
						return (*this);
					}
					iterator operator--(int)
					{
						iterator tmp = *this;

						if (this->el == NULL)
							this->el = this->before_end;
						else
							this->el = ft_get_previous_el(this->el);
						return (tmp);
					}
				
				private:
					t_map_el* el;
					t_map_el* before_end;
					int crement;
					
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
								*before_end = el;
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

						while (first)
						{
							if (!(first->next_left))
								break;
							first = first->next_left;
						}
						while (i < crement)
						{
							first = ft_get_next_el(first, before_end);
							i++;
						}
						return (first);
					}
			};
			
			class const_iterator
			{
				public:
					typedef const value_type value_type;
					typedef difference_type difference_type;
					typedef value_type& reference;
					typedef value_type* pointer;
					typedef ft::bidirectional_iterator_tag iterator_category;
					
					const_iterator()
					{
						this->it = iterator();
					}
					~const_iterator()
					{

					}
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
					bool operator==(const const_iterator& cit) const
					{
						return (this->it == cit.it);
					}
					bool operator!=(const const_iterator& cit) const
					{
						return (!(*this == cit));
					}
					value_type &operator*() const
					{
						return (*(this->it));
					}
					value_type *operator->() const
					{
						return (&(this->operator*()));
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
			typedef class iterator							iterator;
			typedef class const_iterator					const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			
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
				this->comp = x.comp;
				this->alloc = x.alloc;
				*this = x;
			}
			~map()
			{
				this->clear();
			}
			map& operator=(const map& x)
			{
				this->comp = x.comp;
				iterator it_begin = this->begin();
				iterator it_end = this->end();
				const_iterator first = x.begin();
				const_iterator last = x.end();
				while (first != last)
				{
					if (it_begin != it_end)
					{
						this->alloc.construct(&(*it_begin), *first);
						it_begin++;
					}
					else
						this->insert(*first);
					first++;
				}
				this->erase(it_begin, it_end);
				return (*this);
			}
			iterator begin()
			{
				return (iterator(this->el));
			}
			const_iterator begin() const
			{
				return (const_iterator(iterator(this->el)));
			}
			iterator end()
			{
				return (iterator(this->el, this->map_size));
			}
			const_iterator end() const
			{
				return (const_iterator(iterator(this->el, this->map_size)));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
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
				if (this->count(k) == 0)
					this->insert(std::pair<int, int>(k, mapped_type()));
				iterator it = this->find(k);
				return ((*it).second);
			}
			std::pair<iterator, bool> insert(const value_type& val)
			{
				(void)val;
				std::pair<iterator, bool> p;
				typename allocator_type::template rebind<t_map_el>::other r;

				if (this->map_size == 0)
				{
					t_map_el *new_el = ft_new_el(val);
					this->el = new_el;
					this->map_size = this->map_size + 1;
					p = std::make_pair(this->find(val.first), true);
					return (p);
				}
				t_map_el* next = this->el;
				while (next)
				{
					if (this->comp(val.first, next->val.first))
					{
						if (!(next->next_left))
							break;
						next = next->next_left;
					}
					else if (this->comp(next->val.first, val.first))
					{
						if (!(next->next_right))
							break;
						next = next->next_right;
					}
					else
					{
						t_map_el* new_el = ft_new_el(val);
						ft_deallocate_n_destroy(new_el);
						p = std::make_pair(this->find(val.first), false);
						return (p);
					}
				}
				t_map_el* new_el = ft_new_el(val);
				if (this->comp(val.first, next->val.first))
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
				p = std::make_pair(this->find(val.first), true);
				return (p);
			}
			iterator insert(iterator position, const value_type& val)
			{
				std::pair<iterator, bool> p;
				if (position != this->end())
				{
					iterator tmp = position;
					tmp++;
					if (this->value_comp()(*position, val) && (tmp == this->end() || this->value_comp()(val, *tmp)))
					{
						reference val2 = *position;
						t_map_el *prev = (t_map_el*)((&((char*)(&val2))[-12]));
						if (!(prev->next_right))
						{
							t_map_el* new_el = ft_new_el(val);
							new_el->previous = prev;
							new_el->pos = 2;
							prev->next_right = new_el;
							p = std::make_pair(iterator(new_el), true);
							this->map_size = this->map_size + 1;
						}
						else
							p = this->insert(val);
					}
					else
						p = this->insert(val);
				}
				else
					p = this->insert(val);
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
				int crement = ft_search_specific((*position).first, ft_comp_for_eq);
				if ((size_type)crement < this->map_size)
					this->map_size = this->map_size - 1;
				t_map_el* tmp = ft_get_crement_el(this->el, crement);
				t_map_el* tmp_prev = tmp->previous;
				if (tmp->next_left && tmp->next_right)
				{
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
			}
			size_type erase(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_eq);
				if ((size_type)crement < this->map_size)
				{
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
					this->erase((*tmp).first);
				}
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
				this->erase(this->begin(), this->end());
			}
			key_compare key_comp() const
			{
				return (this->comp);
			}
			value_compare value_comp() const
			{
				value_compare valcmp(this->comp);
				return (valcmp);
			}
			iterator find(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_eq);
				return (iterator(this->el, crement));
			}
			const_iterator find(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_eq);
				return (const_iterator(iterator(this->el, crement)));
			}
			size_type count(const key_type& k) const
			{
				if (this->find(k) == this->end())
					return (0);
				return (1);
			}
			iterator lower_bound(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_lower);
				return (iterator(this->el, crement));
			}
			const_iterator lower_bound(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_lower);
				return (const_iterator(iterator(this->el, crement)));
			}
			iterator upper_bound(const key_type& k)
			{
				int crement = ft_search_specific(k, ft_comp_for_upper);
				return (iterator(this->el, crement));
			}
			const_iterator upper_bound(const key_type& k) const
			{
				int crement = ft_search_specific(k, ft_comp_for_upper);
				return (const_iterator(iterator(this->el, crement)));
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
			static bool ft_comp_for_lower(key_type a, key_type b, key_compare comp)
			{
				return (!(comp(a, b)));
			}
			static bool ft_comp_for_upper(key_type a, key_type b, key_compare comp)
			{
				return (comp(b, a));
			}
			static bool ft_comp_for_eq(key_type a, key_type b, key_compare comp)
			{
				return (comp(a, b) == false && comp(b, a) == false);
			}
			int ft_search_specific(const key_type& k, bool(*f)(key_type, key_type, key_compare)) const
			{
				t_map_el* first = this->el;
				bool from_right = false;
				int crement = 0;

				first = ft_get_first_left_from(first);
				if (!first || f(first->val.first, k, this->comp))
					return (crement);
				crement++;
				while (1)
				{
					if (first->next_right && !from_right)
					{
						first = first->next_right;
						first = ft_get_first_left_from(first);
						if (f(first->val.first, k, this->comp))
							return (crement);
						crement++;
					}
					else
					{
						if (first->pos == 1)
							from_right = false;
						else if (first->pos == 2)
							from_right = true;
						if (!(first->previous))
							break;
						first = first->previous;
						if (!from_right)
						{
							if (f(first->val.first, k, this->comp))
								return (crement);
							crement++;
						}
					}
				}
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
			}
	};
}

#endif
