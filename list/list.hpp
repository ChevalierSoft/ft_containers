/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 01:24:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/08 02:12:02 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class list
	{
	private:
		/* data */
	public:
		// Constructors & Destructors
		list(void) {};
		// list(/* args */);
		~list(void) {};

		// Copy constructor
		list(const list<T> & copy) {};

		// Operation overload =
		list<T> &	operator=(const list<T> &	copy);
	};
}
#endif
