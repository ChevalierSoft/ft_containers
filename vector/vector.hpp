/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/09 05:33:18 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class Iterator
	{
	public:
		typedef	T						value_type;
		typedef	value_type*				pointer;
		typedef	const value_type		const_pointer;
		typedef	value_type&				reference;
		typedef	const value_type&		cont_reference;
		typedef typename std::ptrdiff_t	difference_type;

		/// Member functions
		Iterator() {}
		Iterator(pointer x_t) : _ptr(x_t) {}
		~Iterator() {}
		Iterator(Iterator & x_ptr) : _ptr(x_ptr._x_ptr) {}

		/// Member Operators
		Iterator &		operator= (const Iterator & rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		/// Non Member Operators
		// Dereference
		reference		operator* () const	{	return (*_ptr);	}
		const_reference	operator* () const	{	return (*_ptr);	}
		pointer			operator->() const	{	return (_ptr);	}
		const_pointer	operator->() const	{	return (_ptr);	}
		reference		operator[](difference_type rhs) const	{	return (*(_ptr + rhs));		}
		const_reference	operator[](difference_type rhs) const	{	return ((*(_ptr + rhs));	}


	private:
		pointer	_ptr;

	};

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
