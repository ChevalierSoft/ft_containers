/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 01:58:56 by dait-atm         ###   ########.fr       */
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
	ft::vector<int> v;
	ft::vector<int>::iterator iv;
	ft::vector<int>::iterator iw;

	iv = v.begin();

	std::cout <<YEL<< iv._ptr << std::endl;
	std::cout <<YEL<< std::hex<< *iv <<std::dec<<RST<< std::endl;
	std::cout <<YEL<< v._value_data[0] << RST <<std::endl;

	// v.push_back(4);
	// ft_print_memory(reinterpret_cast<void *>(s), 32);
	// std::cout << std::endl;

	std::vector<int> w;
	std::vector<int>::iterator ij;
	w.push_back(77);
	ij = w.begin();
	std::cout <<RED<< *ij <<RST<<std::endl;
}

int	main(void)
{
	test_vector();
	return (0);
}
