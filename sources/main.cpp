/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:24:18 by rsanchez          #+#    #+#             */
/*   Updated: 2022/02/14 19:57:38 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using	std::cin;
using	std::cout;
using	std::endl;
using	std::vector;

template <typename T>
void	test_capa_size(vector<T> const &vec, ft::vector<T> const &ftvec)
{
	static int	color = 1;
	cout << "\033[3" << color << ";01mft size: " << ftvec.size() << endl;
	cout << "   size: " << vec.size() << endl;
	cout << "ft capa: " << ftvec.capacity() << endl;
	cout << "   capa: " << vec.capacity() << "\033[00m" << endl;
	color++;
	if (color == 7)
		color = 1;
}

template <typename T>
void	test_capa_size(ft::vector<T> const &vec, ft::vector<T> const &ftvec)
{
	static int	color = 1;
	cout << "\033[3" << color << ";01mft size: " << ftvec.size() << endl;
	cout << "   size: " << vec.size() << endl;
	cout << "ft capa: " << ftvec.capacity() << endl;
	cout << "   capa: " << vec.capacity() << "\033[00m" << endl;
	color++;
	if (color == 7)
		color = 1;
}

void	test_constructor()
{
	cout << "TEST DEFAULT CONSTRUCTOR" << endl;
	vector<int>	vec;
	ft::vector<int>	ft_vec;
	int		i = 666;
	
	test_capa_size(vec, ft_vec);
	cout << "Adding a new variable" << endl;
	vec.push_back(i);
	ft_vec.push_back(i);
	test_capa_size(vec, ft_vec);
	cout << "index 0: " << vec[0] << "   adress: " << &(vec[0]) << endl;
	cout << "index 0: " << ft_vec[0] << "   adress: " << &(ft_vec[0])
									<< endl;
	cout << "adress int: " << &i << endl;
	
	cout << "\n\nTEST 1 PARAM CONSTRUCTOR" << endl;
	int	i2 = -42;
	vector<int>	vec2(6);
	ft::vector<int>	ft_vec2(6);
	test_capa_size(vec2, ft_vec2);
	cout << "Adding a new variable" << endl;
	vec2.push_back(i2);
	ft_vec2.push_back(i2);
	test_capa_size(vec2, ft_vec2);
	cout << "index 0: " << vec2[0] << "   adress: " << &(vec2[0]) << endl;
	cout << "index 6: " << vec2[6] << "   adress: " << &(vec2[6]) << endl;
	cout << "index 0: " << ft_vec2[0] << "   adress: " << &(ft_vec2[0])
									<< endl;
	cout << "index 6: " << ft_vec2[6] << "   adress: " << &(ft_vec2[6])
									<< endl;
	cout << "adress int: " << &i2 << endl;

	cout << "\n\nTEST 2 PARAM CONSTRUCTOR" << endl;
	vector<int>	vec3(6, i2);
	ft::vector<int>	ft_vec3(6, i2);
	test_capa_size(vec3, ft_vec3);
	cout << "Adding a new variable" << endl;
	vec3.push_back(i2);
	ft_vec3.push_back(i2);
	test_capa_size(vec3, ft_vec3);
	cout << "index 0: " << vec3[0] << "   adress: " << &(vec3[0]) << endl;
	cout << "index 6: " << vec3[6] << "   adress: " << &(vec3[6]) << endl;
	cout << "index 0: " << ft_vec3[0] << "   adress: " << &(ft_vec3[0])
									<< endl;
	cout << "index 6: " << ft_vec3[6] << "   adress: " << &(ft_vec3[6])
									<< endl;
	cout << "adress int: " << &i2 << endl;
	cout << "\n\nTEST COPY CONSTRUCTOR" << endl;
	vector<float>	vec4(6, -65.611f);
	vector<float>	vec5(vec4);
	ft::vector<float>	ft_vec4(6, -65.611f);
	ft::vector<float>	ft_vec5(ft_vec4);
	test_capa_size(vec5, ft_vec5);
	cout << "Adding a new variable" << endl;
	vec5.push_back(i2);
	ft_vec5.push_back(i2);
	test_capa_size(vec5, ft_vec5);
	cout << "index 0: " << vec5[0] << "   adress: " << &(vec5[0]) << endl;
	cout << "index 5: " << vec5[5] << "   adress: " << &(vec5[5]) << endl;
	cout << "index 6: " << vec5[6] << "   adress: " << &(vec5[6]) << endl;
	cout << "index 7: " << vec5[7] << "   adress: " << &(vec5[7]) << endl;
	cout << "index 0: " << ft_vec5[0] << "   adress: " << &(ft_vec5[0])
									<< endl;
	cout << "index 5: " << ft_vec5[5] << "   adress: " << &(ft_vec5[5])
									<< endl;
	cout << "index 6: " << ft_vec5[6] << "   adress: " << &(ft_vec5[6])
									<< endl;
	cout << "index 7: " << ft_vec5[7] << "   adress: " << &(ft_vec5[7])
									<< endl;
	cout << "\n\nTEST OPERATOR=" << endl;
	vector<float>	vec6(100);
	ft::vector<float>	ft_vec6(100);
	test_capa_size(vec6, ft_vec6);
	vec6 = vec5;
	ft_vec6 = ft_vec5;
	test_capa_size(vec6, ft_vec6);
	cout << "index 0: " << ft_vec5[0] << "   adress: " << &(ft_vec5[0])
									<< endl;
	cout << "index 5: " << ft_vec5[5] << "   adress: " << &(ft_vec5[5])
									<< endl;
	cout << "index 6: " << ft_vec5[6] << "   adress: " << &(ft_vec5[6])
									<< endl;
	cout << "index 0: " << ft_vec6[0] << "   adress: " << &(ft_vec6[0])
									<< endl;
	cout << "index 5: " << ft_vec6[5] << "   adress: " << &(ft_vec6[5])
									<< endl;
	cout << "index 6: " << ft_vec6[6] << "   adress: " << &(ft_vec6[6])
									<< endl;
	cout << "\n\nTEST 2 OPERATOR=" << endl;
	vector<float>	vec7;
	ft::vector<float>	ft_vec7;
	test_capa_size(vec7, ft_vec7);
	vec7 = vec5;
	ft_vec7 = ft_vec5;
	test_capa_size(vec7, ft_vec7);
	cout << "index 0: " << ft_vec7[0] << "   adress: " << &(ft_vec7[0])
									<< endl;
	cout << "index 5: " << ft_vec7[5] << "   adress: " << &(ft_vec7[5])
									<< endl;
	cout << "index 6: " << ft_vec7[6] << "   adress: " << &(ft_vec7[6])
									<< endl;
	cout << "index 0: " << ft_vec7[0] << "   adress: " << &(ft_vec7[0])
									<< endl;
	cout << "index 5: " << ft_vec7[5] << "   adress: " << &(ft_vec7[5])
									<< endl;
	cout << "index 6: " << ft_vec7[6] << "   adress: " << &(ft_vec7[6])
									<< endl;
	cout << "\n\nTEST 3 OPERATOR=" << endl;
	vector<float>	vec8(3);
	ft::vector<float>	ft_vec8(3);
	test_capa_size(vec8, ft_vec8);
	vec8 = vec5;
	ft_vec8 = ft_vec5;
	test_capa_size(vec8, ft_vec8);
}

int	main()
{
	test_constructor();
	return (0);
}
