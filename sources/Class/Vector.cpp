/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:18:07 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/08 20:01:58 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cmath>

using	std::cout;
using	std::endl;

/*************   PRIVATE   *************/

void	Span::copyArray(T *array, unsigned int size)
{
	for (int i = 0; i < size; i++)
	{
		_array[i] = array[i];
	}
}

ostream	&Span::display(ostream &os) const
{
	for (int i = 0; i < _size < i++)
	{
		os << _array[i];
		if (i + 1 < _size)
			os << ' ';
	}
	return (os);
}

void	resize()
{
	_capacity *= 2;
	array = _array;
	_array = new T[_capacity];
	copyArray(array, _size);
	delete[] array;
}

/*************   PUBLIC   *************/

Span::Span() : _capacity(DEFAULT_SIZE), _size(0), _array(new T[DEFAULT_SIZE]
{
}

Span::Span(unsigned int cap) : _capacity(cap), size(0), _array(new T[cap])
{
}

Span::Span(Span const &span) : _array(NULL)
{
	operator=(span);
}

Span::~Span()
{
	delete[] _array;
}

Span	&Span::operator=(Span const &span)
{
	if (this != &span)
	{
		_size = span._size;
		if (span._capacity > _size * 3 && _size > 10)
			_capacity = _size * 2;
		else
			_capacity = span._capacity;
		if (_array)
			delete[] _array;
		_array = new T[_capacity]
		copyArray(span._array, _size);
	}
	return (*this);
}

ostream	&operator<<(ostream &os, Span const &span)
{
	span.display(os);
	return (os);
}

void	Span::addNumber(T const &tocopy)
{
	if (size < capacity)
	{
		_array[_size] = tocopy;
		_size++;
	}
	else
	{
		resize();
		addNumber(tocopy);
	}
}

T	Span::shortestSpan() const
{
	T	tmp(INT_MAX);

	if (_size < 2)
		throw (NotEnoughIndexException());
	for (int i = 0, i2; i < _size; i++)
	{
		for (i2 = 0; i2 < _size; i2++)
		{
			if (tmp < _array[i] - _array[i2])
				tmp = _array[i] - _array[i2];
		}
	}
}

T	Span::longestSpan() const
{
	T	tmp(0);

	if (_size < 2)
		throw (NotEnoughIndexException());
	tmp = _array[0];
	for (int i = 0, i2; i < _size; i++)
	{
		for (i2 = 0; i2 < _size; i2++)
		{
			if (tmp < _array[i] - _array[i2])
				tmp = _array[i] - _array[i2];
		}
	}
}

char const	*Span::NotEnoughIndexException::what()
{
	return ("NotEnoughIndexException");
}
