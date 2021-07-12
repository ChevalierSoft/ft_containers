/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/12 07:12:48 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

#include "./vector/vector.hpp"

#include "./utils/color.h"
#include "./utils/ft_print_memory.h"

void	test_vector()
{
	ft::vector<int>				v;
	ft::vector<int>				w;
	ft::vector<char>			e;

	std::cout <<std::endl<<CYN<< "__________________ft::vector__________________" <<RST<< std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "push_back()" <<RST<< std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);
	for (auto & iv : v)
		std::cout << iv << " ";
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "pop_back()" <<RST<< std::endl;

	v.pop_back();
	v.pop_back();
	v.pop_back();
	
	v.pop_back();
	v.pop_back();
	for (auto & iv : v)
		std::cout << iv << " ";
	std::cout << "(nothing should be printed)" << std::endl;

	v.push_back(0x4C);
	v.push_back(0x55);
	v.push_back(0x4C);
	v.push_back(0x5A);

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "copy constructor" <<RST<< std::endl;
	ft::vector<int>				c(w);
	ft_print_memory(reinterpret_cast<void *>(c._value_data), c._value_count * c._value_size);
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "operator =" <<RST<< std::endl;

	w = v;
	w.push_back('M');
	w.push_back('D');
	w.push_back('R');
	for (auto & iw : w)
		std::cout << iw << " ";
	std::cout << std::endl;
	ft_print_memory(reinterpret_cast<void *>(w._value_data), w._value_count * w._value_size);
	std::cout << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "size()" <<RST<< std::endl;

	std::cout << "v count : " << v.size() << std::endl;
	std::cout << "w count : " << w.size() << std::endl;

	//__________________________________________________________________________
	std::cout <<std::endl<<CYN<< "empty()" <<RST<< std::endl;

	std::cout << "e : " << e.empty() << std::endl;
	e.push_back('v');
	std::cout << "e : " << e.empty() << std::endl;
	e.pop_back();
	std::cout << "e : " << e.empty() << std::endl;

	//__________________________________________________________________________


}

int	main(void)
{
	test_vector();

	return (0);
}
