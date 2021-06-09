/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 02:23:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/09 06:38:31 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template <typename T>
	class VectorIterator
	{
	public:
		typedef	T						value_type;
		typedef	value_type*				pointer;
		typedef	const value_type		const_pointer;
		typedef	value_type&				reference;
		typedef	const value_type&		const_reference;
		typedef typename std::ptrdiff_t	difference_type;

		/// Member functions
		VectorIterator() {}
		VectorIterator(pointer x_t) : _ptr(x_t) {}
		~VectorIterator() {}
		VectorIterator(VectorIterator & x_ptr) : _ptr(x_ptr._x_ptr) {}

		/// Member Operators
		VectorIterator &		operator= (const VectorIterator & rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		/// Non Member Operators
		///  Dereference
		reference			operator* ()		{	return (*_ptr);	}
		const_reference		operator* () const	{	return (*_ptr);	}
		pointer				operator->() 		{	return (_ptr);	}
		const_pointer		operator->() const	{	return (_ptr);	}
		reference			operator[](difference_type rhs) 		{	return (*(_ptr + rhs));	}
		const_reference		operator[](difference_type rhs) const	{	return (*(_ptr + rhs));	}

		/// Equality Operators
		bool				operator==(const VectorIterator & rhs) const {	return (_ptr == rhs._ptr);	}
		bool				operator!=(const VectorIterator & rhs) const {	return (_ptr != rhs._ptr);	}
		bool				operator<=(const VectorIterator & rhs) const {	return (_ptr <= rhs._ptr);	}
		bool				operator>=(const VectorIterator & rhs) const {	return (_ptr >= rhs._ptr);	}
		bool				operator< (const VectorIterator & rhs) const {	return (_ptr <  rhs._ptr);	}
		bool				operator> (const VectorIterator & rhs) const {	return (_ptr >  rhs._ptr);	}

		///  Arithmetic Operators
		VectorIterator		operator+ (difference_type rhs) {	return VectorIterator(_ptr + rhs);	}
		VectorIterator		operator- (difference_type rhs) {	return VectorIterator(_ptr - rhs);	}

		///   Pre
		VectorIterator &	operator++() {	++(this->_ptr); return (*this);	}
		VectorIterator &	operator--() {	--(this->_ptr); return (*this);	}
		///   Post
		VectorIterator		operator++(int) {	VectorIterator tmp = *this; ++(this->_ptr); return (tmp); }
		VectorIterator		operator--(int) {	VectorIterator tmp = *this; --(this->_ptr); return (tmp); }
		///   Assignation
		void				operator+=(difference_type rhs) {	_ptr += rhs;	}
		void				operator-=(difference_type rhs) {	_ptr -= rhs;	}

	private:
		pointer	_ptr;

	};

	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		/* data */
	public:
		typedef	T					value_type;
		typedef	Allocator			allocator_type;
		typedef	VectorIterator<T>	iterator;
	
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
