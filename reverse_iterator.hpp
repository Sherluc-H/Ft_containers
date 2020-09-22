/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhuang <lhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 10:12:49 by lhuang            #+#    #+#             */
/*   Updated: 2020/09/22 11:49:45 by lhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
    typedef struct {} bidirectional_iterator_tag;
    typedef struct {} random_access_iterator_tag;
    template <class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_type::iterator_category iterator_category;
            typedef typename iterator_type::value_type value_type;
            typedef typename iterator_type::difference_type difference_type;
            typedef typename iterator_type::pointer pointer;
            typedef typename iterator_type::reference reference;

            reverse_iterator()
            {
                this->base_it = iterator_type();
            }
            explicit reverse_iterator(iterator_type it)
            {
                this->base_it = it;
            }
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& rev_it)
            {
                *this = reverse_iterator(rev_it.base());
            }
            iterator_type base() const
            {
                return (this->base_it);
            }
            bool operator==(const reverse_iterator& it2)
            {
                if (this->base_it == it2.base_it)
                    return (true);
                return (false);
            }
            bool operator!=(const reverse_iterator& it2)
            {
                return (!(*this == it2));
            }
            reference& operator*() const
            {
                iterator_type tmp = this->base_it;
                tmp--;
                return (*tmp);
            }
            reverse_iterator operator+(difference_type n) const
            {
                return (reverse_iterator(this->base_it - n));
            }
            reverse_iterator &operator++()
            {
                this->base_it--;
                return (*this);
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;

                this->base_it--;
                return (tmp);
            }
            reverse_iterator& operator+=(difference_type n)//ici ref a checker
            {
                this->base_it += n;
                return (*this);
            }
            reverse_iterator operator-(difference_type n) const//a check avec vector
            {
                return (reverse_iterator(this->base_it + n));
            }
            reverse_iterator &operator--()
            {
                this->base_it++;
                return (*this);
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;

                this->base_it++;
                return (this);
            }
            reverse_iterator& operator-=(difference_type n)
            {
                this->base_it -= n;
                return (*this);
            }
            pointer operator->() const
            {
                return (&(this->operator*()));
            }
            reference operator[](difference_type n) const
            {
                return (this->base()[-n-1]);
            }

        private:
            iterator_type base_it;
    };
    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs == rhs);
    }
    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs != rhs);
    }
    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs < rhs);
    }
    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs <= rhs);
    }
    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs > rhs);
    }
    template <class Iterator>
    bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs >= rhs);
    }
    template <class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
    {
        return (rev_it + n);
    }
    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (rhs.base() - lhs.base());
    }
}

#endif
