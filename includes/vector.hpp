/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/14 21:07:59 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

# include "Random_access_iterator.hpp"
# include "Reverse_iterator.hpp"
# include <iostream>

using	std::ostream;
using	std::allocator;

// ************************************************************************** //
//                               vector Class                                 //
// ************************************************************************** //

namespace	ft
{


template <typename T, typename Alloc = allocator<T> >
class vector
{
# define DEFAULT_CAPA 0
	public:
		typedef T	value_type;
		typedef size_t	size_type;

		typedef ft::Random_access_iterator<T>	iterator;
		typedef ft::Random_access_iterator<T const>	const_iterator;
		typedef ft::Reverse_iterator<iterator>	reverse_iterator;
		typedef ft::Reverse_iterator<const_iterator> const_reverse_iterator;
		typedef	std::ptrdiff_t			difference_type;

		typedef Alloc				allocator_type;
		typedef typename Alloc::reference	reference;
		typedef typename Alloc::const_reference	const_reference;
		typedef typename Alloc::pointer		pointer;
		typedef typename Alloc::const_pointer	const_pointer;

	private:
		size_type		_capacity;
		size_type		_size;
		value_type		*_array;
		Alloc			_allocator;

		void	importArray(value_type *arr)
		{
			for (size_t i = 0; i < _size; i++)
				_allocator.construct(&(_array[i]), arr[i]);
		}

		void	appendTo(size_type nb, value_type const &val)
		{
			while (_size < nb)
				_allocator.construct(&(_array[_size++]), val);
		}

		void	truncTo(size_type nb)
		{
			while (nb < _size)
				_allocator.destroy(&(_array[--_size]));
		}

		void	autoReserve()
		{
			if (_capacity == 0)
				reserve(1);
			else
				reserve(_capacity * 2);
		}

		void	purgeArray(void)
		{
			while (_size > 0)
				_allocator.destroy(&(_array[--_size]));
		}

		void	clearArray(void)
		{
			if (_array)
			{
				purgeArray();
				_allocator.deallocate(_array, _capacity);
				_array = NULL;
				_capacity = 0;
			}
		}

		ostream	&display(ostream &os) const
		{
			for (size_t i = 0; i < _size ; i++)
			{
				os << _array[i];
				if (i + 1 < _size)
					os << '\n';
			}
			return (os);
		}

	public:

//******************************************************************************
//Basic form:

		explicit vector(Alloc alloc = Alloc()) :
			_capacity(DEFAULT_CAPA),
			_size(0),
			_allocator(alloc)
		{
			_array = _allocator.allocate(DEFAULT_CAPA);
		}

		explicit vector(size_type nb, value_type const &val = T()) :
			_capacity(nb),
			_size(nb),
			_allocator()
		{
			_array = _allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
			{
				_allocator.construct(&_array[i], val);
			}
		}

		vector(vector const &vector) :
			_capacity(0),
			_size(0),
			_array(NULL),
			_allocator()
		{
			operator=(vector);
		}

		~vector(void)
		{
			clearArray();
		}

		vector	&operator=(vector const &vector)
		{
			if (this != &vector)
			{
				purgeArray();
//				_allocator = vector._allocator;
				if (_capacity < vector._size)
				{
					_allocator.deallocate(_array,_capacity);
					_capacity = vector._size;
					_array = _allocator.allocate(_capacity);
				}
				_size = vector._size;
				importArray(vector._array);
			}
			return (*this);
		}


//******************************************************************************
//Accesser methods:

		value_type	&operator[](size_type nb)
		{ return (_array[nb]);	}

		value_type const	&operator[](size_type nb) const
		{ return (_array[nb]);	}

		value_type		&at(size_type nb)
		{
			if (nb < _size)
				return (_array[nb]);
			throw(std::out_of_range("ft::vector::at"));
		}

		value_type const	&at(size_type nb) const
		{
			if (nb < _size)
				return (_array[nb]);
			throw(std::out_of_range("ft::vector::at"));
		}

		value_type		&front(void)
		{
			return (_array[0]);
		}

		value_type const	&front(void) const
		{
			return (_array[0]);
		}

		value_type		&back(void)
		{
			return (_array[_size - 1]);
		}

		value_type const	&back(void) const
		{
			return (_array[_size - 1]);
		}


//******************************************************************************
//Capacity methods:

		void	resize(size_type nb, value_type const &val = T())
		{
			if (nb > _capacity)
			{
				reserve(nb);
			}
			if (nb > _size)
			{
				appendTo(nb, val);
			}
			else if (nb < _size)
			{
				truncTo(nb);
			}
		}

		void	reserve(size_type nb)
		{
			if (nb > _capacity)
			{
				value_type	*tmp = _array;
				_array = _allocator.allocate(nb);
				importArray(tmp);
				for (size_t i = 0; i < _size; i++)
				{
					_allocator.destroy(&(tmp[i]));
				}
				_allocator.deallocate(tmp, _capacity);
				_capacity = nb;
			}
		}

/*C11		void	shrink_to_fit(void)
		{
			if (_size < _capacity && _capacity > DEFAULT_CAPA)
			{
				value_type	*tmp = _array;
				int	new_capa = _size;
				if (new_capa < DEFAULT_CAPA)
					new_capa = DEFAULT_CAPA;
				_array = _allocator.allocate(new_capa);
				importArray(tmp);
				for (size_t i = 0; i < _size; i++)
				{
					_allocator.destroy(&(tmp[i]));
				}
				_allocator.deallocate(tmp, _capacity);
				_capacity = new_capa;
			}
		}
*/

		size_type	size(void) const {	return(_size);	}
		size_type	capacity(void) const {	return(_capacity); }
		bool		empty(void) const {	return(_size == 0); }

//******************************************************************************
//Modifiers methods:

		void	assign(size_type nb, value_type const &val)
		{
			if (nb < _capacity)
			{
				clearArray();
				_capacity = nb;
				_allocator.allocate(_capacity);
			}
			else
				purgeArray();
			appendTo(nb, val);
		}

		void	push_back(value_type const &val)
		{
			if (_size == _capacity)
				autoReserve();
			_allocator.construct(&(_array[_size++]), val);
		}

		void	pop_back(void)
		{
			if (_size > 0)
				truncTo(_size - 1);
		}

		void	swap(vector &vector)
		{
			value_type	*tmp_pt(_array);
			size_type	*tmp_capa(_capacity);
			size_type	*tmp_size(_size);

			_array = vector._array;
			_capacity = vector._capacity;
			_size = vector._size;

			vector._array = tmp_pt;
			vector._capacity = tmp_capa;
			vector._size = tmp_size;
		}

		void	clear(void)
		{
			purgeArray();
		}

		friend ostream	&operator<<(ostream &os,
						vector<T> const &vector)
		{
			return (vector.display(os));
		}
};

};

#endif /* __VECTOR_HPP__ */
