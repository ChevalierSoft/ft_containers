/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/09 04:34:09 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		/* data */
	public:
		typedef	T				value_type;
		typedef	Allocator		allocator_type;
	
		// Constructors & Destructors
		vector(void) {};
		// vector(/* args */);
		~vector(void) {};

		// Copy constructor
		vector(const vector<T> & copy);

		// Operation overload =
		vector<T> &	operator=(const vector<T> &	copy);
	};
}

#endif
