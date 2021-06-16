/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/16 12:20:09 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

#include "./list/list.hpp"
#include "./vector/vector.hpp"

#include "./utils/color.h"

void	test_vector()
{
	ft::vector<int> v;
	ft::vector<int>::iterator iv;
	ft::vector<int>::iterator iw;

	iv._ptr = reinterpret_cast<int *>(40); // 10
	iw._ptr = reinterpret_cast<int *>(20); // 5

	std::cout << iw - iv << std::endl;

	iv = iv - 1;
	std::cout << iv._ptr << std::endl;
}

int	main(void)
{
	test_vector();
	return (0);
}
