/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/14 21:17:31 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __REVERSE_ITERATOR_HPP__
#define __REVERSE_ITERATOR_HPP__

# include "Iterator.hpp"
# include <iterator>

// ************************************************************************** //
//                          Reverse_iterator Class                      //
// ************************************************************************** //

namespace	ft
{

template <typename Iterator>
class Reverse_iterator
{
	typedef Reverse_iterator	RevIt;
	public:
	typedef Iterator				iterator_type;
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type		value_type;
	typedef typename Iterator::difference_type	difference_type;
	typedef typename Iterator::pointer		pointer;
	typedef typename Iterator::reference		reference;

		Reverse_iterator() :
			_it()
		{
		}

		explicit Reverse_iterator(iterator_type const &it) :
			_it(it)
		{
		}

		template <class Iter>
		Reverse_iterator(Reverse_iterator<Iter> const &rev_it) :
			_it(rev_it._it)
		{
		}

		~Reverse_iterator(void)
		{
		}

		RevIt	&operator=(Reverse_iterator const &revit)
		{
			if (this != &revit)
			{
				_it = revit._it;
			}
			return (*this);
		}

		Reverse_iterator	base(void) const { return (_it); }

		value_type	&operator*(void) const { return *(_it - 1); }
		value_type	&operator[](int i) { return *(_it - i - 1); }
		value_type	*operator->(void) { return (_it - 1); }

		Reverse_iterator	&operator++(void)
		{
			--_it;
			return (*this);
		}

		Reverse_iterator	&operator--(void)
		{
			++_it;
			return (*this);
		}

		Reverse_iterator	operator++(int)
		{
			Reverse_iterator	tmp(*this);
			operator--();
			return (tmp);
		}

		Reverse_iterator	&operator--(int)
		{
			Reverse_iterator	tmp(*this);
			operator++();
			return (tmp);
		}

		Reverse_iterator	operator+(difference_type nb) const
		{
			return (Reverse_iterator(_it - nb));
		}

		Reverse_iterator	&operator+=(difference_type nb) const
		{
			_it -= nb;
			return (*this);
		}

		Reverse_iterator	operator-(difference_type nb) const
		{
			return (Reverse_iterator(_it + nb));
		}

		Reverse_iterator	&operator-=(difference_type nb) const
		{
			_it += nb;
			return (*this);
		}

	private:
		iterator_type	_it;
};


template <class It1, class It2>
bool	operator==(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() == rhs.base());
}

template <class It1, class It2>
bool	operator!=(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() != rhs.base());
}

template <class It1, class It2>
bool	operator<(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() < rhs.base());
}

template <class It1, class It2>
bool	operator<=(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() <= rhs.base());
}

template <class It1, class It2>
bool	operator>(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() > rhs.base());
}

template <class It1, class It2>
bool	operator>=(Reverse_iterator<It1> const lhs,
		Reverse_iterator<It2> const rhs)
{
	return (lhs.base() >= rhs.base());
}

template <class It>
Reverse_iterator<It>
operator+(typename Reverse_iterator<It>::difference_type nb,
					Reverse_iterator<It> const &rev_it)
{
	return (RevIt(rev_it.base() - nb));
}

template <class It>
typename Reverse_iterator<It>::difference_type
operator-(Reverse_iterator<It> const &lhs, Reverse_iterator<It> const &rhs)
{
	return (lhs.base() + rhs.base());
}

};

#endif /* __REVERSE_ITERATOR_HPP__ */
