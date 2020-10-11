/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:55:37 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/11 22:35:52 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

# include <memory>
# include <limits>
# include "reverse_iterator.hpp"
# include <exception>
# include <stdexcept>

# include <iostream>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class deque
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
					}
					~iterator()
					{

					}
					iterator(pointer p, int crement = 0)
					{
						this->p = p;
						this->crement = crement;
					}
					iterator(const iterator& it)
					{
						*this = it;
					}
					iterator &operator=(const iterator& it)
					{
						this->p = it.p;
						this->crement = it.crement;
						return (*this);
					}
					bool operator==(const iterator& it) const
					{
						return (this->operator->() == it.operator->());
					}
					bool operator!=(const iterator& it) const
					{
						return (!(*this == it));
					}
					value_type &operator*() const
					{
						return (this->p[this->crement]);
					}
					value_type *operator->() const
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
			
			explicit deque(const allocator_type& alloc = allocator_type())
			{
				this->p = NULL;
				this->d_size = 0;
				this->alloc = alloc;
				this->d_capacity = 0;
			}
			explicit deque(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->p = NULL;
				this->d_size = 0;
				this->alloc = alloc;
				this->d_capacity = 0;
				this->reserve(n);
				size_type i = 0;

				while (i < n)
				{
					this->push_back(val);
					i++;
				}
			}
			template <class InputIterator>
			deque(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				this->p = NULL;
				this->d_size = 0;
				this->alloc = alloc;
				this->d_capacity = 0;
				F<InputIterator, std::numeric_limits<InputIterator>::is_integer>()(first, last, this);
			}
			deque(const deque& x)
			{
				this->p = NULL;
				this->d_size = 0;
				this->alloc = x.alloc;
				this->d_capacity = 0;
				*this = x;
			}
			~deque()
			{
				this->clear();
				this->alloc.deallocate(this->p, this->d_capacity);
			}
			deque& operator=(const deque& x)
			{
				this->assign(x.begin(), x.end());
				return (*this);
			}
			iterator begin()
			{
				return (iterator(this->p));
			}
			const_iterator begin() const
			{
				return (const_iterator(iterator(this->p)));
			}
			iterator end()
			{
				return (iterator(this->p, this->d_size));
			}
			const_iterator end() const
			{
				return (const_iterator(iterator(this->p, this->d_size)));
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
			size_type size() const
			{
				return (this->d_size);
			}
			size_type max_size() const
			{
				return (alloc.max_size());
			}
			void resize(size_type n, value_type val = value_type())
			{
				if (n < this->d_size)
				{
					size_type i = 0;
					size_type size = this->size();

					while (i + n < size)
					{
						this->pop_back();
						i++;
					}
				}
				else if (n > this->d_size)
				{
					if (n > this->d_capacity)
					{
						if (this->d_size * 2 >= n)
							this->reserve(this->d_size * 2);
						else
							this->reserve(n);
					}

					while (this->d_size < n)
						this->push_back(val);
				}
			}
			bool empty() const
			{
				return (this->d_size == 0);
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
				if (n >= this->d_size)
					throw std::out_of_range("at() tries to access out of range data");
				return (this->p[n]);
			}
			const_reference at(size_type n) const
			{
				if (n >= this->d_size)
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
				return (this->p[this->d_size - 1]);
			}
			const_reference back() const
			{
				return (this->p[this->d_size - 1]);
			}
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				F<InputIterator, std::numeric_limits<InputIterator>::is_integer> f;
				f.assign(first, last, this);
			}
			void assign(size_type n, const value_type& val)
			{
				this->resize(n);
				iterator it_begin = this->begin();
				iterator it_end = this->end();
				size_type i = 0;

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
			}
			void push_back(const value_type& val)
			{
				(void)val;
				if (this->d_size >= this->d_capacity)
					ft_reallocate();
				this->p[this->d_size] = val;
				this->d_size = this->d_size + 1;
			}
            void push_front(const value_type& val)
            {
                deque tmp;

                tmp.push_back(val);
                tmp.insert(tmp.end(), this->begin(), this->end());
                this->swap(tmp);
                tmp.clear();
            }
			void pop_back()
			{
				if (this->d_size > 0)
					this->alloc.destroy(&(this->p[this->d_size - 1]));
				this->d_size = this->d_size - 1;
			}
            void pop_front()
            {
                this->erase(this->begin());
            }
			iterator insert(iterator position, const value_type& val)
			{
				iterator it_begin = position;
				iterator it_end = this->end();
				value_type value = val;
				value_type next_value;

				iterator it = position;
				size_t i = 0;
				while (i < this->size() && &(*it) != &(this->p[i]))
					i++;

				while (it_begin != it_end)
				{
					next_value = *it_begin;
					*it_begin = value;
					value = next_value;
					it_begin++;
				}
				this->push_back(value);
				return (iterator(this->p, i));
			}
			void insert(iterator position, size_type n, const value_type& val)
			{
				size_type i = 0;
				while (i < this->size() && &(*position) != &(this->p[i]))
					i++;
				if (this->d_capacity < this->size() + n)
				{
					if (this->size() * 2 >= this->size() + n)
						this->reserve(this->size() * 2);
					else
						this->reserve(this->size() + n);
				}
				position = iterator(this->p, i);
				i = 0;
				while (i < n)
				{
					position = this->insert(position, val);
					position++;
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
				value_type next_value;

				if (it_begin_plus != it_end)
					it_begin_plus++;
				while (it_begin_plus != it_end)
				{
					next_value = *it_begin_plus;
					*it_begin = next_value;
					it_begin++;
					it_begin_plus++;
				}
				this->pop_back();
				return (position);
			}
			iterator erase(iterator first, iterator last)//a tester encore
			{
				iterator tmp_first = first;
				iterator tmp;
				difference_type d = last - first;
				difference_type i = 0;
				
				while (i < d)
				{
					first = this->erase(first);
					i++;
				}
				return (tmp_first);
			}
			void swap(deque& x)
			{
				pointer tmp_p = x.p;
				size_type tmp_d_size = x.d_size;
				size_type tmp_d_capacity = x.d_capacity;
				x.p = this->p;
				x.d_size = this->d_size;
				x.d_capacity = this->d_capacity;
				this->p = tmp_p;
				this->d_size = tmp_d_size;
				this->d_capacity = tmp_d_capacity;
			}
			void clear()
			{
				this->erase(this->begin(), this->end());
			}
		
		private:
			pointer p;
			size_type d_size;
			size_type d_capacity;
			allocator_type alloc;

            void reserve(size_type n)
			{
				if (n > this->max_size())
					throw std::length_error("trying to reserve with n > max_size");
				if (n > this->d_capacity)
				{
					pointer tmp = this->alloc.allocate(n);
					size_type i = 0;

					while (i < this->d_size)
					{
						tmp[i] = this->p[i];
						i++;
					}
					this->alloc.destroy(this->p);
					this->alloc.deallocate(this->p, this->d_capacity);
					this->p = tmp;
					this->d_capacity = n;
				}
			}

			void ft_reallocate()
			{
				if (this->empty())
				{
					this->p = this->alloc.allocate(1);
					this->d_capacity = 1;
					return;
				}
				this->reserve(this->d_capacity * 2);
			}
			
			template <class U, bool>
			class F
			{
				public:
					F()
					{}
					~F()
					{}
					F(const F& f)
					{
						*this = f;
					}
					F &operator=(const F& f)
					{
						(void)f;
					}
			};
			
			template <class U>
			class F<U, true>
			{
				public:
					F()
					{}
					~F()
					{}
					F(const F& f)
					{
						*this = f;
					}
					F &operator=(const F& f)
					{
						(void)f;
					}
					void operator()(U n, U val, ft::deque<T, Alloc> *ctnr)
					{
						int i = 0;

						ctnr->reserve(n);
						while (i < n)
						{
							ctnr->push_back(val);
							i++;
						}
					}
					void assign(U n, U val, ft::deque<T, Alloc> *ctnr)
					{
						ctnr->assign((size_type)n, val);
					}
					void insert(iterator position, U n, U val, ft::deque<T, Alloc> *ctnr)
					{
						ctnr->insert(position, (size_type)n, val);
					}
			};
			
			template <class U>
			class F<U, false>
			{
				public:
					F()
					{}
					~F()
					{}
					F(const F& f)
					{
						*this = f;
					}
					F &operator=(const F& f)
					{
						(void)f;
					}
					void operator()(U first, U last, ft::deque<T, Alloc> *ctnr)
					{
						ctnr->reserve(last - first);
						while (first != last)
						{
							ctnr->push_back(*first);
							first++;
						}
					}
					void assign(U first, U last, ft::deque<T,Alloc> *ctnr)
					{
						ctnr->resize(last - first);
						iterator it_begin = ctnr->begin();
						iterator it_end = ctnr->end();
						size_type i = 0;
						while (first != last)
						{
							if (it_begin != it_end)
							{
								*it_begin = *first;
								it_begin++;
							}
							else
								ctnr->push_back(*first);
							first++;
							i++;
						}
					}
					void insert(iterator position, U first, U last, ft::deque<T, Alloc> *ctnr)
					{
						size_type i = 0;
						while (i < ctnr->size() && &(*position) != &(ctnr->p[i]))
							i++;
						if (ctnr->d_capacity < ctnr->size() + (last - first))
						{
							if (ctnr->size() * 2 >= ctnr->size() + (last - first))
								ctnr->reserve(ctnr->size() * 2);
							else
								ctnr->reserve(ctnr->size() + (last - first));
						}
						position = iterator(ctnr->p, i);
						while (first != last)
						{
							position = ctnr->insert(position, *first);
							position++;
							first++;
						}
					}
			};
    };
	
	template <class T, class Alloc>
	bool operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		if (lhs.size() == rhs.size())
		{
			typename deque<T, Alloc>::const_iterator lhs_begin = lhs.begin();
			typename deque<T, Alloc>::const_iterator lhs_end = lhs.end();
			typename deque<T, Alloc>::const_iterator rhs_begin = rhs.begin();
			typename deque<T, Alloc>::const_iterator rhs_end = rhs.end();
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
	bool operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Alloc>
	bool operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		typename deque<T, Alloc>::const_iterator lhs_begin = lhs.begin();
		typename deque<T, Alloc>::const_iterator lhs_end = lhs.end();
		typename deque<T, Alloc>::const_iterator rhs_begin = rhs.begin();
		typename deque<T, Alloc>::const_iterator rhs_end = rhs.end();

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
	bool operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Alloc>
	bool operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Alloc>
	bool operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}
	template <class T, class Alloc>
	void swap(deque<T, Alloc>& x, deque<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
