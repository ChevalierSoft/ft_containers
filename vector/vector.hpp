/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/16 12:18:32 by dait-atm         ###   ########.fr       */
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
		class vector_iterator : public ft::iterator<T>
		{
		public:
			typedef T						value_type;
			typedef value_type				*pointer;
			// typedef const value_type 		const_pointer;
			typedef value_type &			reference;
			// typedef const value_type &		const_reference;
			typedef typename std::ptrdiff_t	difference_type;

			vector_iterator() : ft::iterator<T>()	{}
			vector_iterator(pointer x_t) : _ptr(x_t) {}
			// vector_iterator(const difference_type rhs) : ft::iterator<T>(rhs) {}
			~vector_iterator()	{}
			/// Member Operators
			vector_iterator	&operator=(const vector_iterator &rhs)	{	_ptr = rhs._ptr; return (*this);	}

			///   Random access vvv
			vector_iterator operator+(difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}
			vector_iterator	operator-(difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}
			difference_type operator-(vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}

		// private:
			pointer _ptr;

		};
		typedef vector_iterator iterator;

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
