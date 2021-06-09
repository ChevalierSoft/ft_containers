/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/09 04:39:24 by dait-atm         ###   ########.fr       */
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
	ft::vector<int>		v;
	std::vector<int>	rv;
	std::vector<int>	rb;
	
	rv.push_back(22);
	rb.push_back(22);

	std::vector<int>::iterator it = rv.begin();
	std::vector<int>::iterator ij = rb.begin();

	if (rv == rb)
		std::cout << "oui" << std::endl;
	else
		std::cout << "non" << std::endl;

	return (0);
}
