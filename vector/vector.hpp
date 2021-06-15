/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/15 14:59:20 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "../iterator/iterator.h"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		class list_iterator : public ft::iterator<T>
		{
		public:
			list_iterator()	{}
			~list_iterator(){}
		};
		typedef list_iterator iterator;

		// Constructors & Destructors
		vector(void) {};
		// vector(/* args */);
		virtual	~vector(void) {};

		// Copy constructor
		vector(const vector<T> & copy);

		// Operation overload =
		vector<T> &	operator=(const vector<T> &	copy);

	private:
		typedef T			value_type;
		typedef Allocator	allocator_type;
	};
} // namespace ft

#endif
