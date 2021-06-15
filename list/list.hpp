/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:24:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/15 15:03:44 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>
#include "../iterator/iterator.h"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class list
	{
	public:
		class list_iterator : public ft::iterator<T>
		{
		typedef T				value_type;
		typedef Allocator		allocator_type;
		
		public:
			list_iterator()	{}
			~list_iterator(){}
		};
		typedef list_iterator	iterator;

		// Constructors & Destructors
		list(void){};
		// list(/* args */);
		virtual ~list(void){};

		// Copy constructor
		list(const list<T> &copy);

		// Operation overload =
		list<T>	&operator=(const list<T> &copy);

	private:
		
	};
} // namespace ft

#endif
