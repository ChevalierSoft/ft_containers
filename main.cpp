/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/09 08:09:39 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

#include "./list/list.hpp"
#include "./vector/vector.hpp"

#include "./utils/color.h"

int	main(void)
{
	ft::vector<int>				v;
	ft::vector<int>::iterator	iv;

	std::vector<int>	rv;
	std::vector<int>	rb;
	
	for (int i = 0; i < 20; ++i)
	{
		rv.push_back(i);
		rb.push_back(i);
	}

	std::vector<int>::iterator it = rv.begin();
	it++;



	std::cout << it - (rv.begin() + 1) << std::endl;

	return (0);
}
