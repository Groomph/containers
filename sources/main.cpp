/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/04 16:58:23 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include "Fixed.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

using	std::cin;
using	std::cout;
using	std::endl;

/*
void	doubleIt(Fixed &a)
{
	a.doubleIt();
}

void	doubleIt(int &a)
{
	a *= 2;
}
*/

int	main()
{
	Fixed	fixed[3];
	int	integer[3];
	string	buff;

	srand(time(NULL));
	while (!cin.eof())
	{
		fixed[0] = Fixed(rand()/static_cast<float>(rand()));
		fixed[1] = Fixed(rand()/static_cast<float>(rand()));
		fixed[2] = Fixed(rand()/static_cast<float>(rand()));

		cout << "INIT: Fixed point number 0: " << fixed[0] << endl;
		cout << "INIT: Fixed point number 1: " << fixed[1] << endl;
		cout << "INIT: Fixed point number 2: " << fixed[2] << endl;
		iter(fixed, 3, doubleIt<Fixed>);
		cout << "Iter result:\n";
		cout << "Fixed point number 0: " << fixed[0] << endl;
		cout << "Fixed point number 1: " << fixed[1] << endl;
		cout << "Fixed point number 2: " << fixed[2] << endl;
		integer[0] = rand() % 500;
		integer[1] = rand() % 500;
		integer[2] = rand() % 500;
		cout << "INIT: Integer 0: " << integer[0] << endl;
		cout << "INIT: Integer 1: " << integer[1] << endl;
		cout << "INIT: Integer 2: " << integer[2] << endl;
		iter(integer, 3, doubleIt<int>);
		cout << "Iter result:\n";
		cout << "INIT: Integer 0: " << integer[0] << endl;
		cout << "INIT: Integer 1: " << integer[1] << endl;
		cout << "INIT: Integer 2: " << integer[2] << endl;
		cout << "\n\nPress enter for another test" << endl;
		getline(cin, buff);
	}
	return (0);
}
