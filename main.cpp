/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 03:38:41 by dait-atm         ###   ########.fr       */
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

	std::cout << YEL;
	std::cout << iv._ptr			<< std::endl;
	std::cout << *iv				<< std::endl;
	std::cout << v._value_data[0]	<< std::endl;
	std::cout << RST;

	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

}

int	main(void)
{
	test_vector();
	return (0);
}
