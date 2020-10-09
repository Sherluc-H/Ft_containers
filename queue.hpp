/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:50:08 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/09 13:40:13 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			explicit queue(const container_type& ctnr = container_type())
			{
				this->ctnr = ctnr;
			}
			~queue()
			{}
			queue(const queue& q)
			{
				*this = q;
			}
			queue &operator=(const queue& q)
			{
				this->ctnr = q.ctnr;
				return (*this);
			}
			bool empty() const
			{
				return (this->ctnr.empty());
			}
			size_type size() const
			{
				return (this->ctnr.size());
			}
			value_type& front()
			{
				return (this->ctnr.front());
			}
			const value_type& front() const
			{
				return (this->ctnr.front());
			}
			value_type& back()
			{
				return (this->ctnr.back());
			}
			const value_type& back() const
			{
				return (this->ctnr.back());
			}
			void push(const value_type& val)
			{
				this->ctnr.push_back(val);
			}
			void pop()
			{
				this->ctnr.pop_front();
			}
			friend bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
			{
				return (lhs.ctnr == rhs.ctnr);
			}
			friend bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
			{
				return (lhs.ctnr < rhs.ctnr);
			}

		private:
			container_type ctnr;
	};
	
	template <class T, class Container>
	bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T, class Container>
	bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T, class Container>
	bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T, class Container>
	bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
