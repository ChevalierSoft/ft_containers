/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:19:28 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 01:31:18 by dait-atm         ###   ########.fr       */
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

	v.push_back(4);

	// ft_print_memory(reinterpret_cast<void *>(*iv), 4);

}

int	main(void)
{
	test_vector();
	return (0);
}
