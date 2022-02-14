/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/14 19:41:23 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

# include <cstddef>

// ************************************************************************** //
//                               iterator Class                               //
// ************************************************************************** //

namespace	ft
{

template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::value_type		value_type;
	typedef typename Iterator::distance		difference_type;
	typedef typename Iterator::pointer		pointer;
	typedef typename Iterator::reference		reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <class Category, class T, class Distance = ptrdiff_t,
	 			class Pointer = T*, class Reference = T &>
struct Iterator
{
	typedef Category	iterator_category;
	typedef	T		value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;

	~Iterator(void) = 0;
};

};

#endif /* __ITERATOR_HPP__ */
