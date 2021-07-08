/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 05:43:01 by dait-atm         ###   ########.fr       */
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
	//ft::vector<int>::iterator iv;
	ft::vector<int>::iterator iw;

	v.push_back(4);
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(0x0a);
	v.push_back(0x0b);
	v.push_back(0x0c);
	v.push_back(0x0d);

	for (auto & iv : v)
		std::cout << iv << std::endl;

	ft::vector<int> w;

	w = v;
	for (auto & iw : w)
		std::cout << iw << std::endl;

	ft_print_memory(reinterpret_cast<void *>(w._value_data), w._value_count * w._value_size);
	std::cout << std::endl;

	std::cout << w._value_count * w._value_size << std::endl;

}

int	main(void)
{
	test_vector();
	return (0);
}
