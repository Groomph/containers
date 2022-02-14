/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/14 19:53:25 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __RANDOM_ACCESS_ITERATOR_HPP__
#define __RANDOM_ACCESS_ITERATOR_HPP__

# include "Iterator.hpp"
# include <iterator>

// ************************************************************************** //
//                         random_access_iterator Class                       //
// ************************************************************************** //

namespace	ft
{

template <typename T>
class Random_access_iterator :
			public ft::Iterator<std::random_access_iterator_tag, T>
{
	typedef Random_access_iterator	RaIt;
	public:
	typedef ft::Iterator<std::random_access_iterator_tag, T> Iterator;
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type		value_type;
	typedef typename Iterator::difference_type	difference_type;
	typedef typename Iterator::pointer		pointer;
	typedef typename Iterator::reference		reference;

		explicit Random_access_iterator(T const &pt = NULL) :
			Iterator(),
			_p(pt)
		{
		}

		Random_access_iterator(RaIt const &pt) :
			Iterator(),
			_p(pt._p)
		{
		}

		~Random_access_iterator(void)
		{
		}

		RaIt	&operator=(RaIt const &it)
		{
			if (this != &it)
			{
				_p = it._p;
			}
			return (*this);
		}

		bool	operator==(RaIt const &it) const {return (_p == it._p);}
		bool	operator!=(RaIt const &it) const {return (_p != it._p);}
		bool	operator<(RaIt const &it) const {return (_p < it._p);}
		bool	operator<=(RaIt const &it) const {return (_p <= it._p);}
		bool	operator>(RaIt const &it) const {return (_p > it._p);}
		bool	operator>=(RaIt const &it) const {return (_p >= it._p);}
		T	&operator*(void) const {	return (*_p);	}
		T	&operator[](int i) {	return (_p[i]);	}
		T	*operator->(void) {	return (_p);	}

		RaIt	&operator++(void)
		{
			++_p;
			return (*this);
		}

		RaIt	&operator--(void)
		{
			--_p;
			return (*this);
		}

		T	operator++(int)
		{
			RaIt	tmp(*this);
			operator++();
			return (tmp);
		}

		T	&operator--(int)
		{
			RaIt	tmp(*this);
			operator--();
			return (tmp);
		}

		RaIt	operator+(difference_type nb) const
		{
			return (RaIt(_p + nb));
		}

		friend RaIt	operator+(difference_type nb, RaIt const &it)
		{
			return (RaIt(it._p + nb));
		}

		RaIt	&operator+=(difference_type nb) const
		{
			_p += nb;
			return (*this);
		}

		RaIt	operator-(difference_type nb) const
		{
			return (RaIt(_p - nb));
		}

		RaIt	operator-(RaIt const &it) const
		{
			return (RaIt(_p - it._p));
		}

		RaIt	&operator-=(difference_type nb) const
		{
			_p -= nb;
			return (*this);
		}

	private:
		T	*_p;
};

};

#endif /* __RANDOM_ACCESS_ITERATOR_HPP__ */
