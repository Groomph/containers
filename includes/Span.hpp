/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/06 12:03:42 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               Span Class                                 //
// ************************************************************************** //

#define DEFAULT_SIZE 10

template <typename T>
class Span {
	private:
		unsigned int		_capacity;
		unsigned int		_size;
		T			*_array;

		void	copyArray(T *array, unsigned int size);
		ostream	&display(ostream &os) const;
		voidœ	resize(void);

	public:

		Span();
		Span(unsigned int nb);
		Span(float nb);
		Span(Span const &span);
		~Span(void);

		Span	&operator=(Span const &fixed);

		void		addNumber(T const &tocopy);

	class NotEnoughIndexException : public exception
	{
		public:
			char const	*what(void);
	}
};

ostream	&operator<<(ostream &os, Span const &fixed);

#endif /* __SPAN_HPP__ */
