/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:43:37 by lhuang            #+#    #+#             */
/*   Updated: 2020/10/02 17:15:19 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

namespace ft
{

    template <class T, class Container = ft::list<T>>
    class stack
    {
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;

            explicit stack(const container_type& ctnr = container_type())
            {
                this->ctnr = ctnr;
            }
            bool empty() const
            {
                return (this->ctnr.empty());
            }
            size_type size() const
            {
                return (this->ctnr.size());
            }
            value_type& top()
            {
                return (this->ctnr.back());
            }
            const value_type& top() const
            {
                return (this->ctnr.back());
            }
            void push(const value_type& val)
            {
                this->ctnr.push_back(val);
            }
            void pop()
            {
                this->ctnr.pop_back();
            }
            friend bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
            {
                return (lhs.ctnr == rhs.ctnr);
            }
            friend bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
            {
                return (lhs.ctnr < rhs.ctnr);
            }

        private:
            container_type ctnr;
    };
    template <class T, class Container>
    bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T, class Container>
    bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T, class Container>
    bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T, class Container>
    bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    {
        return (!(lhs < rhs));
    }

}

#endif
