/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 15:12:34 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/ 

bool	Fixed::_isInteger() const
{
	if (_rawValue & 0xff)
		return (false);
	return (true);
}

void	Fixed::_setFromInt(int nb)
{
	_rawValue = nb << _fraction_bits;
}

void	Fixed::_setFromFloat(float nb)
{
	_rawValue = roundf(nb * _coef);
}

/*************   PUBLIC   *************/ 

Fixed::Fixed() : _rawValue(0)
{
}

Fixed::Fixed(int nb)
{
	_setFromInt(nb);
}

Fixed::Fixed(float nb)
{
	_setFromFloat(nb);
}

Fixed::Fixed(Fixed const &fixed) : _rawValue(fixed._rawValue)
{
}

float	Fixed::toFloat() const
{
	return (roundf(_rawValue) / _coef);
}

int	Fixed::toInt() const
{
	return (_rawValue >> _fraction_bits);
}

int	Fixed::getRawBits() const
{
	cout << "getRawBits member function called" << endl;
	return (_rawValue);
}

void	Fixed::setRawBits(int const raw)
{
	_rawValue = raw;
}

Fixed	&Fixed::min(Fixed &fixedl, Fixed &fixedr)
{
	if (fixedl < fixedr)
		return (fixedl);
	return (fixedr);
}

Fixed const	&Fixed::min(Fixed const &fixedl, Fixed const &fixedr)
{
	if (fixedl < fixedr)
		return (fixedl);
	return (fixedr);
}

Fixed	&Fixed::max(Fixed &fixedl, Fixed &fixedr)
{
	if (fixedl > fixedr)
		return (fixedl);
	return (fixedr);
}

Fixed const	&Fixed::max(Fixed const &fixedl, Fixed const &fixedr)
{
	if (fixedl > fixedr)
		return (fixedl);
	return (fixedr);
}

void		Fixed::doubleIt(void)
{
	operator*=(Fixed(2));
}

Fixed::~Fixed()
{
}

Fixed	&Fixed::operator=(Fixed const &fixed)
{
	if (this != &fixed)
		_rawValue = fixed._rawValue;
	return (*this);
}

bool	Fixed::operator>(Fixed const &fixedr) const
{
	return (_rawValue > fixedr._rawValue);
}

bool	Fixed::operator<(Fixed const &fixedr) const
{
	return (_rawValue < fixedr._rawValue);
}

bool	Fixed::operator==(Fixed const &fixedr) const
{
	return (_rawValue == fixedr._rawValue);
}

bool	Fixed::operator!=(Fixed const &fixedr) const
{
	return (_rawValue != fixedr._rawValue);
}

bool	Fixed::operator>=(Fixed const &fixedr) const
{
	return (_rawValue >= fixedr._rawValue);
}

bool	Fixed::operator<=(Fixed const &fixedr) const
{
	return (_rawValue <= fixedr._rawValue);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_rawValue++;
	return (tmp);
}

Fixed	&Fixed::operator++()
{
	_rawValue++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_rawValue--;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	_rawValue--;
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &fixedr) const
{
	Fixed	tmp(*this);

	tmp._rawValue += fixedr._rawValue;
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &fixedr) const
{
	Fixed	tmp(*this);

	tmp._rawValue -= fixedr._rawValue;
	return (tmp);
}

Fixed	&Fixed::operator*=(Fixed const &fixr)
{
	_rawValue = ((int64_t)_rawValue * (int64_t)fixr._rawValue) / _coef;
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &fixr) const
{
	Fixed	tmp(*this);
	return (tmp.operator*=(fixr));
}

Fixed	Fixed::operator/(Fixed const &fixr) const
{
	Fixed	tmp(*this);

	tmp._rawValue = ((int64_t)_rawValue * _coef) / fixr._rawValue;
	return (tmp);
}

ostream	&Fixed::display(ostream &os) const
{
	if (_isInteger())
		os << toInt();
	else
		os << toFloat();
	return (os);
}

ostream	&operator<<(ostream &os, Fixed const &fixed)
{
	fixed.display(os);
	return (os);
}
