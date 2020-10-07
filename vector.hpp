/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 09:33:34 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/07 17:32:23 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <limits>
# include "reverse_iterator.hpp"
# include <exception>
# include <stdexcept>

# include <iostream>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T										value_type;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type* 						const_pointer;
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
					typedef ft::random_access_iterator_tag iterator_category;
					
					iterator()
					{
						this->p = NULL;
						this->crement = 0;
						// this->before_end = NULL;
					}
					iterator(pointer p, int crement = 0)
					{
						this->p = p;
						this->crement = crement;
						// int i = 0;
						
						// while (i < crement)
						// {
						// 	if (this->p->next == NULL)
						// 		this->before_end = this->p;
						// 	this->p = this->p->next;
						// 	i++;
						// }
					}
					iterator(const iterator& it)
					{
						*this = it;
					}
					iterator &operator=(const iterator& it)
					{
						this->p = it.p;
						this->crement = it.crement;
						// this->before_end = it.before_end;
						return (*this);
					}
					~iterator()
					{
						
					}
					bool operator==(const iterator& it2) const
					{
						return (this->operator->() == it2.operator->());
					}
					bool operator!=(const iterator& it2) const
					{
						return (!(*this == it2));
					}
					value_type& operator*() const
					{
						return (this->p[this->crement]);
					}
					value_type* operator->() const
					{
						return (&(this->operator*()));
					}
					iterator &operator++()
					{
						this->crement++;
						return (*this);
					}
					iterator operator++(int)
					{
						iterator tmp = *this;

						this->crement++;
						return (tmp);
					}
					iterator &operator--()
					{
						this->crement--;
						return (*this);
					}
					iterator operator--(int)
					{
						iterator tmp = *this;

						this->crement--;
						return (tmp);
					}
					iterator operator+(const difference_type& b) const
					{
						iterator tmp = *this;
						difference_type i = 0;

						while (i < b)
						{
							tmp++;
							i++;
						}
						while (i > b)
						{
							tmp--;
							i--;
						}
						return (tmp);
					}
					friend iterator operator+(const difference_type &a, const iterator &b)
					{
						iterator tmp = b;
						return (tmp + a);
					}
					iterator operator-(const difference_type& b) const
					{
						return (*this + -b);
					}
					difference_type operator-(const iterator& b) const
					{
						return (this->operator->() - b.operator->());
					}
					bool operator<(const iterator& it2) const
					{
						return (this->operator->() < it2.operator->());
					}
					bool operator>(const iterator& it2) const
					{
						return (this->operator->() > it2.operator->());
					}
					bool operator<=(const iterator& it2) const
					{
						return (!(*this > it2));
					}
					bool operator>=(const iterator& it2) const
					{
						return (!(*this < it2));
					}
					iterator &operator+=(const difference_type& b)
					{
						difference_type i = 0;

						while (i < b)
						{
							(*this)++;
							i++;
						}
						while (i > b)
						{
							(*this)--;
							i--;
						}
						return (*this);
					}
					iterator &operator-=(const difference_type& b)
					{
						return (*this += -b);
					}
					value_type &operator[](size_type idx) const
					{
						return (this->p[this->crement + idx]);
					}
				private:
					pointer p;
					int crement;
					// pointer before_end;
			};
			class const_iterator
			{
				public:
					typedef const value_type value_type;
					typedef difference_type difference_type;
					typedef value_type& reference;
					typedef value_type* pointer;
					typedef ft::random_access_iterator_tag iterator_category;

					const_iterator()
					{
						this->it = NULL;
					}
					const_iterator(const iterator& it)
					{
						// std::cout << "HERE" << std::endl;
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
					{
						
					}
					bool operator==(const const_iterator& it2) const
					{
						return (this->it == it2.it);
					}
					bool operator!=(const const_iterator& it2) const
					{
						return (!(*this == it2));
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
					const_iterator operator+(const difference_type& b) const
					{
						const_iterator tmp = this->it + b;
						return (tmp);
					}
					friend const_iterator operator+(const difference_type& a, const const_iterator& b)
					{
						const_iterator tmp = b;
						return (tmp + a);
					}
					const_iterator operator-(const difference_type& b) const
					{
						const_iterator tmp = this->it - b;
						return (tmp);
					}
					difference_type operator-(const const_iterator& it2) const
					{
						return (this->it - it2.it);
					}
					bool operator<(const const_iterator& it2) const
					{
						return (this->it < it2.it);
					}
					bool operator>(const const_iterator& it2) const
					{
						return (this->it > it2.it);
					}
					bool operator<=(const const_iterator& it2) const
					{
						return (this->it <= it2.it);
					}
					bool operator>=(const const_iterator& it2) const
					{
						return (this->it >= it2.it);
					}
					const_iterator &operator+=(const difference_type& b)
					{
						// iterator tmp = this->it;
						// tmp += b;
						// this->it = tmp;
						this->it += b;
						return (*this);
					}
					const_iterator &operator-=(const difference_type& b)
					{
						return (*this += -b);
					}
					value_type &operator[](size_type idx) const
					{
						return (this->it[idx]);
					}
				private:
					iterator it;

			};
			
		public:
			typedef class iterator							iterator;
			typedef class const_iterator					const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			
			explicit vector(const allocator_type& alloc = allocator_type())
			{
				// std::cout << "1" << std::endl;
				this->p = NULL;
				this->vec_size = 0;
				// (void)alloc;
				this->alloc = alloc;
				this->vec_capacity = 0;
			}
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				// std::cout << "HERE" << std::endl;
				(void)val;
				(void)alloc;
				this->p = NULL;
				this->vec_size = 0;
				this->alloc = alloc;
				this->vec_capacity = 0;
				this->reserve(n);
				size_type i = 0;

				while (i < n)
				{
					this->push_back(val);
					i++;
				}
			}
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				(void)first;
				(void)last;
				(void)alloc;
				this->p = NULL;
				this->vec_size = 0;
				this->alloc = alloc;
				this->vec_capacity = 0;
				F<InputIterator, std::numeric_limits<InputIterator>::is_integer>()(first, last, this);
			}
			vector(const vector& x)
			{
				this->p = NULL;
				this->vec_size = 0;
				this->alloc = alloc;
				this->vec_capacity = 0;
				*this = x;
			}
			~vector()
			{
				this->clear();
				this->alloc.deallocate(this->p, this->vec_capacity);
				// this->alloc.destroy(this->p);
			}
			vector &operator=(const vector& x)
			{
				// std::cout << this->vec_capacity << std::endl;
				this->clear();
				this->alloc.deallocate(this->p, this->vec_capacity);
				this->p = NULL;
				this->vec_size = 0;
				// this->alloc = x.alloc;
				this->vec_capacity = 0;
				this->reserve(x.size());
				size_type i = 0;
				
				while (i < x.size())
				{
					// std::cout << "hey" << std::endl;
					// this->p[i] = x[i];
					this->push_back(x[i]);
					i++;
				}
				return (*this);
				// this->alloc = x.alloc;
			}
			iterator begin()
			{
				return (ft::vector<T, Alloc>::iterator(this->p));
			}
			const_iterator begin() const
			{
				return (ft::vector<T, Alloc>::const_iterator(ft::vector<T, Alloc>::iterator(this->p)));
			}
			iterator end()
			{
				return (ft::vector<T, Alloc>::iterator(this->p, this->vec_size));
			}
			const_iterator end() const
			{
				return (ft::vector<T, Alloc>::const_iterator(ft::vector<T, Alloc>::iterator(this->p, this->vec_size)));
			}
			reverse_iterator rbegin()
			{
				return (ft::vector<T, Alloc>::reverse_iterator(this->end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (ft::vector<T, Alloc>::const_reverse_iterator(ft::vector<T, Alloc>::const_iterator(this->end())));
			}
			reverse_iterator rend()
			{
				return (ft::vector<T, Alloc>::reverse_iterator(this->begin()));
			}
			const_reverse_iterator rend() const
			{
				return (ft::vector<T, Alloc>::const_reverse_iterator(ft::vector<T, Alloc>::const_iterator(this->begin())));
			}
			size_type size() const
			{
				return (this->vec_size);
			}
			size_type max_size() const
			{
				return (alloc.max_size());
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n < this->vec_size)
				{
					// std::cout << n << "|||" << this->size() << std::endl;
					size_type i = 0;
					size_type size = this->size();

					while (i + n < size)
					{
						this->pop_back();
						i++;
					}
					// std::cout << this->size() << std::endl;
				}
				else if (n > this->vec_size)
				{
					if (n > this->vec_capacity)
					{
						if (this->vec_size * 2 >= n)
							this->reserve(this->vec_size * 2);
						else
							this->reserve(n);
					}
					// size_type i = 0;

					while (this->vec_size < n)
					{
						this->push_back(val);
						// i++;
					}
				}
			}
			size_type capacity() const
			{
				return (this->vec_capacity);
			}
			bool empty() const
			{
				return (this->vec_size == 0);
			}
			void reserve(size_type n)
			{
				if (n > this->vec_capacity)
				{
					pointer tmp = this->alloc.allocate(n);
					size_type i = 0;

					while (i < this->vec_size)
					{
						tmp[i] = this->p[i];
						i++;
					}
					this->alloc.destroy(this->p);
					this->alloc.deallocate(this->p, this->vec_capacity);
					// this->alloc.destroy(this->p);
					this->p = tmp;
					this->vec_capacity = n;
				}
			}
			reference operator[](size_type n)
			{
				return (this->p[n]);
			}
			const_reference operator[](size_type n) const
			{
				return (this->p[n]);
			}
			reference at(size_type n)
			{
				if (n >= this->vec_size)
					throw std::out_of_range("at() tries to access out of range data");
				return (this->p[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= this->vec_size)
					throw std::out_of_range("const at() tries to access out of range data");
				return (this->p[n]);
			}
			reference front()
			{
				return (this->p[0]);
			}
			const_reference front() const
			{
				return (this->p[0]);
			}
			reference back()
			{
				return (this->p[this->vec_size - 1]);
			}
			const_reference back() const
			{
				return (this->p[this->vec_size - 1]);
			}
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				// this->clear();
				F<InputIterator, std::numeric_limits<InputIterator>::is_integer> f;
				f.assign(first, last, this);
			}
			void assign(size_type n, const value_type &val)
			{
				// std::cout << "cap:" << this->capacity() << std::endl;
				// this->clear();
				this->resize(n);
				iterator it_begin = this->begin();
				iterator it_end = this->end();
				size_type i = 0;
				// this->resize(n);

				while (it_begin != it_end)//&& i < n ?// peut etre pas besoin grace au resize, par contre resize au debut sert pour les capacity
				{
					*it_begin = val;
					it_begin++;
					i++;
				}
				while (i < n)
				{
					this->push_back(val);
					i++;
				}
				// this->resize(n);
			}
			void push_back(const value_type& val)
			{
				(void)val;
				if (this->vec_size >= this->vec_capacity)
				{
					ft_reallocate();
				}
				this->p[this->vec_size] = val;
				this->vec_size = this->vec_size + 1;
			}
			void pop_back()
			{
				if (this->vec_size > 0)
					this->p[this->vec_size - 1].~value_type();
					// this->p[this->vec_size - 1] = value_type();//destroy if not primitive ?
				this->vec_size = this->vec_size - 1;
			}
			iterator insert(iterator position, const value_type& val)
			{
				iterator it_begin = position;
				iterator it_end = this->end();
				value_type value = val;
				value_type next_value;

				while (it_begin != it_end)
				{
					next_value = *it_begin;
					*it_begin = value;
					value = next_value;
					it_begin++;
				}
				this->push_back(value);
				return (position);
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				(void)n;
				(void)val;
				iterator it_begin = position;//meilleur insert possible si on est a end pos ?
				size_type i = 0;
				while (i < n)
				{
					this->push_back(val);//reserve ?
					i++;
				}
				iterator it_end = this->end();
				value_type value;
				value_type next_value;
				i = 0;
				while (i < n)
				{
					value = val;
					while (it_begin != it_end)
					{
						next_value = *it_begin;
						*it_begin = value;
						value = next_value;
						it_begin++;
					}
					it_begin = position + i;
					i++;
				}
			}
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last)
			{
				F<InputIterator, std::numeric_limits<InputIterator>::is_integer> f;
				f.insert(position, first, last, this);
			}
			iterator erase(iterator position)
			{
				iterator it_begin = position;
				iterator it_begin_plus = position;
				iterator it_end = this->end();
				// value_type value;
				value_type next_value;
				// std::cout << "pos:" << *position << std::endl;

				if (it_begin_plus != it_end)
				{
					// std::cout << "a" << std::endl;
					it_begin_plus++;
				}
				// else
					// std::cout << "b" << std::endl;
				// std::cout << "size:" << this->size() << std::endl;
				while (it_begin_plus != it_end)
				{
					// std::cout << "here" << std::endl;
					// value = *it_begin;
					next_value = *it_begin_plus;
					*it_begin = next_value;
					it_begin++;
					it_begin_plus++;
				}
				this->pop_back();
				return (position);
			}
			iterator erase(iterator first, iterator last)//a tester
			{
				iterator tmp_first = first;
				iterator tmp;
				difference_type d = last - first;
				// std::cout << "diff:" << d << std::endl;
				difference_type i = 0;
				
				while (i < d)
				{
					// std::cout << "e:" << *first << std::endl;
					// tmp = first;
					// first++;
					// this->erase(tmp);
					// std::cout << "f" << std::endl;
					// tmp++;
					first = this->erase(first);
					i++;
				}
				return (tmp_first);
			}
			void swap(vector& x)
			{
				// std::cout << "a" << std::endl;
				// std::cout << &(x[0]) << "|" << &((*this)[0]) << std::endl;
				// vector tmp = x;
				pointer tmp_p = x.p;
				size_type tmp_vec_size = x.vec_size;
				size_type tmp_vec_capacity = x.vec_capacity;
				Alloc tmp_alloc = x.alloc;
				x.p = this->p;
				x.vec_size = this->vec_size;
				x.vec_capacity = this->vec_capacity;
				x.alloc = this->alloc;
				this->p = tmp_p;
				this->vec_size = tmp_vec_size;
				this->vec_capacity = tmp_vec_capacity;
				this->alloc = tmp_alloc;
				// std::cout << "b" << std::endl;
			}
			void clear()
			{
				// this->vec_size = 0;
				size_type size = this->vec_size;
				size_type i = 0;

				// std::cout << "size:" << size << std::endl;
				
				while (i < size)
				{
					// std::cout << "clear" << std::endl;
					// std::cout << this->vec_size << std::endl;
					this->pop_back();
					i++;
				}
			}
		private:
			pointer p;
			size_type vec_size;
			size_type vec_capacity;
			allocator_type alloc;

			void ft_reallocate()
			{
				if (this->empty())
				{
					this->p = this->alloc.allocate(1);
					this->vec_capacity = 1;
					return;
				}
				this->reserve(this->vec_capacity * 2);
				// pointer tmp = this->alloc.allocate(vec_capacity * 2);
				// vec_capacity = vec_capacity * 2;
				// size_type i = 0;

				// while (i < this->vec_size)
				// {
				// 	tmp[i] = this->p[i];
				// 	i++;
				// }
				// this->alloc.deallocate(this->p, this->vec_size);
				// this->alloc.destroy(this->p);
				// this->p = tmp;
			}
			template <class InputIterator, bool>
			class F
			{};
			template <class InputIterator>
			class F<InputIterator, true>
			{
				public:
					F()
					{}
					~F()
					{}
					void operator()(InputIterator first, InputIterator last, ft::vector<T, Alloc> *ctnr)
					{
						int i = 0;

						ctnr->reserve(first);
						while (i < first)
						{
							ctnr->push_back(last);
							i++;
						}
					}
					void assign(InputIterator first, InputIterator last, ft::vector<T, Alloc> *ctnr)
					{
						ctnr->assign((size_type)first, last);
						// int i = 0;

						// while (i < first)
						// {
						// 	ctnr->push_back(last);
						// 	i++;
						// }
					}
					void insert(iterator position, InputIterator first, InputIterator last, ft::vector<T, Alloc> *ctnr)
					{
						int i = 0;
						while (i < first)
						{
							position = ctnr->insert(position, last);
							i++;
						}
						// iterator it_begin = position;
						// int i = 0;
						// while (i < first)
						// {
						// 	ctnr->push_back(last);
						// 	i++;
						// }
						// iterator it_end = ctnr->end();
						// value_type value;
						// value_type next_value;
						// i = 0;
						// while (i < first)
						// {
						// 	value = last;
						// 	while (it_begin != it_end)
						// 	{
						// 		next_value = *it_begin;
						// 		*it_begin = value;
						// 		value = next_value;
						// 		it_begin++;
						// 	}
						// 	it_begin = position + i;
						// 	i++;
						// }
					}
			};
			template <class InputIterator>
			class F<InputIterator, false>
			{
				public:
					F()
					{}
					~F()
					{}
					void operator()(InputIterator first, InputIterator last, ft::vector<T, Alloc> *ctnr)
					{
						ctnr->reserve(last - first);
						while (first != last)
						{
							ctnr->push_back(*first);
							first++;
						}
					}
					void assign(InputIterator first, InputIterator last, ft::vector<T,Alloc> *ctnr)
					{
						ctnr->resize(last - first);
						iterator it_begin = ctnr->begin();
						iterator it_end = ctnr->end();
						size_type i = 0;
						// while (it_begin != it_end)
						// {
						// 	*it_begin = *first;
						// 	it_begin++;
						// 	i++;
						// }
						while (first != last)
						{
							// std::cout << "here" << *first << std::endl;
							if (it_begin != it_end)
							{
								// std::cout << "hey" << std::endl;
								*it_begin = *first;
								it_begin++;
							}
							else
								ctnr->push_back(*first);
							first++;
							// it_begin++;
							i++;
						}
						// ctnr->resize(i);
						// std::cout << "size" << i << "|" << ctnr->size()<< std::endl;
					}
					void insert(iterator position, InputIterator first, InputIterator last, ft::vector<T, Alloc> *ctnr)
					{
						while (first != last)
						{
							// std::cout << "here:" << *first << std::endl;
							position = ctnr->insert(position, *first);
							position++;
							first++;
						}
						// iterator it_begin = position;
						// InputIterator tmp_first = first;
						// while (tmp_first != last)
						// {
						// 	ctnr->push_back(*tmp_first);
						// 	tmp_first++;
						// }
						// iterator it_end = ctnr->end();
						// value_type value;
						// value_type next_value;
						// while (first != last)
						// {
						// 	value = *first;
						// 	while (it_begin != it_end)
						// 	{
						// 		next_value = *it_begin;
						// 		*it_begin = value;
						// 		value = next_value;
						// 		it_begin++;
						// 	}
						// 	position++;
						// 	it_begin = position;
						// 	first++;
						// }
					}
			};
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename vector<T, Alloc>::const_iterator lhs_begin = lhs.begin();
			typename vector<T, Alloc>::const_iterator lhs_end = lhs.end();
			typename vector<T, Alloc>::const_iterator rhs_begin = rhs.begin();
			typename vector<T, Alloc>::const_iterator rhs_end = rhs.end();
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
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		typename vector<T, Alloc>::const_iterator lhs_begin = lhs.begin();
		typename vector<T, Alloc>::const_iterator lhs_end = lhs.end();
		typename vector<T, Alloc>::const_iterator rhs_begin = rhs.begin();
		typename vector<T, Alloc>::const_iterator rhs_end = rhs.end();

		while (lhs_begin != lhs_end && rhs_begin != rhs_end)
		{
			if (*lhs_begin < *rhs_begin)
				return (true);
			else if (*rhs_begin < *lhs_begin)
				return (false);
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
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
	// template <class T, class Alloc>
	// typename ft::vector<T, Alloc>::iterator operator+(const ptrdiff_t &a, const typename ft::vector<T, Alloc>::iterator &b)
	// {
	// 	return (b + a);
	// }
}

#endif
