/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:11:19 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 15:40:45 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITER_HPP__
# define __ITER_HPP__

template <typename T, typename F>
void	iter(T *a, int size, F f)
{
	for (int i = 0; i < size; i++)
	{
		(f)(a[i]);
	}
}

template <typename T>
void    doubleIt(T &a)
{
        a *= T (2);
}

/*
 *	still good options, but distinguish functions from member functions
 *
template <typename T>
void	iter(T *a, int size, void (f)(T &))
{
	for (int i = 0; i < size; i++)
	{
		(f)(a[i]);
	}
}

template <typename T>
void	iter(T *a, int size, void (T::*f)())
{
	for (int i = 0; i < size; i++)
	{
		(a[i].*f)();
	}
}
*/

#endif /* __ITER_HPP__ */
