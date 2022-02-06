/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 15:12:50 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FIXED_HPP__
#define __FIXED_HPP__

# include <iostream>

using	std::string;
using	std::ostream;

// ************************************************************************** //
//                               Fixed Class                                 //
// ************************************************************************** //

class Fixed {
	private:
		int			_rawValue;
		int const static	_fraction_bits = 8;
		int const static	_coef = 1 << _fraction_bits;

		bool		_isInteger() const;
		void		_setFromInt(int nb);
		void		_setFromFloat(float nb);

	public:

		Fixed();
		Fixed(int nb);
		Fixed(float nb);
		Fixed(Fixed const &fixed);

		Fixed	&operator=(Fixed const &fixed);
		bool	operator>(Fixed const &fixedr) const;
		bool	operator<(Fixed const &fixedr) const;
		bool	operator>=(Fixed const &fixedr) const;
		bool	operator<=(Fixed const &fixedr) const;
		bool	operator==(Fixed const &fixedr) const;
		bool	operator!=(Fixed const &fixedr) const;
		Fixed	operator++(int);
		Fixed	&operator++();
		Fixed	operator--(int);
		Fixed	&operator--();
		Fixed	operator+(Fixed const &fixedr) const;
		Fixed	operator-(Fixed const &fixedr) const;
		Fixed	operator*(Fixed const &fixr) const;
		Fixed	&operator*=(Fixed const &fixr);
		Fixed	operator/(Fixed const &fixr) const;
		ostream	&display(ostream &os) const;

		bool		isGreaterThan(Fixed const &fixedr) const;
		bool		isLesserThan(Fixed const &fixedr) const;
		bool		isEqualOf(Fixed const &fixedr) const;
		static Fixed	&min(Fixed &fixedl, Fixed &fixedr);
		static const Fixed	&min(Fixed const &fixedl, Fixed const &fixedr);
		static Fixed	&max(Fixed &fixedl, Fixed &fixedr);
		static const Fixed	&max(Fixed const &fixedl, Fixed const &fixedr);

		float		toFloat(void) const;
		int		toInt(void) const;
		void		doubleIt(void);

		int		getRawBits(void) const;
		void		setRawBits(int const raw);

		~Fixed(void);
};

ostream	&operator<<(ostream &os, Fixed const &fixed);

#endif /* __FIXED_HPP__ */
