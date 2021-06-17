/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:36:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/17 09:27:54 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITERATOR_H
# define ITERATOR_H

#include <iostream>

namespace ft
{
	template <typename T>
	class iterator
	{
	public:
		typedef T						value_type;
		typedef value_type *			pointer;
		typedef const value_type		const_pointer;
		typedef value_type &			reference;
		typedef const value_type &		const_reference;
		typedef typename std::ptrdiff_t	difference_type;

		/// Member functions
				iterator() {}
				iterator(pointer x_t) : _ptr(x_t) {}
		virtual ~iterator() {}
				iterator(reference x_ptr) : _ptr(x_ptr._ptr) {}

		/// Member Operators
		iterator &operator=(const iterator &rhs)
		{
			_ptr = rhs._ptr;
			return (*this);
		}

		/// Non Member Operators

		///   Random access vvv
		// vector_iterator operator+(difference_type rhs)	{ vector_iterator	it(_ptr + rhs); return (it);		}	// optional
		// vector_iterator	operator-(difference_type rhs)	{ vector_iterator	it(_ptr - rhs); return (it);		}	// optional
		// difference_type operator-(vector_iterator rhs)	{ difference_type	df(_ptr - rhs._ptr); return (df);	}	// optional

		///  Dereference
		reference		operator* () { return (*_ptr); }
		// const_reference	operator* () const { return (*_ptr); }	// const_iterator
		pointer			operator->() { return (_ptr); }
		// const_pointer	operator->() const { return (_ptr); }	// const_iterator
		// reference		operator[](difference_type rhs) { return (*(_ptr + rhs)); }			// optional
		// const_reference	operator[](difference_type rhs) const { return (*(_ptr + rhs)); }	// const_iterator // optional

		/// Equality Operators
		bool	operator==(const iterator &rhs) const	{ return (_ptr == rhs._ptr); }
		bool	operator!=(const iterator &rhs) const	{ return (_ptr != rhs._ptr); }
		// bool	operator<=(const iterator &rhs) const	{ return (_ptr <= rhs._ptr); }	// optional
		// bool	operator>=(const iterator &rhs) const	{ return (_ptr >= rhs._ptr); }	// optional
		// bool	operator< (const iterator &rhs)	const	{ return (_ptr < rhs._ptr);  }	// optional
		// bool	operator> (const iterator &rhs)	const	{ return (_ptr > rhs._ptr);  }	// optional

		///  Arithmetic Operators

		///   Pre
		iterator	&operator++() { ++(this->_ptr); return (*this);	}
		// iterator	&operator--() { --(this->_ptr); return (*this);	}	// optional
		///   Post
		// iterator	operator++(int){ iterator tmp = *this; ++(this->_ptr); return (tmp);	}	// optional
		// iterator	operator--(int){ iterator tmp = *this; --(this->_ptr); return (tmp);	}	// optional
		///   Assignation
		// void		operator+=(difference_type rhs) { _ptr += rhs; }	// optional
		// void		operator-=(difference_type rhs) { _ptr -= rhs; }	// optional

	private:
		pointer _ptr;
	};

};


#endif
