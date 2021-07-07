/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:36:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/08 01:52:57 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ITERATOR_H
# define ITERATOR_H

# include <iostream>
# include <type_traits>

namespace ft
{

	// template <bool IsConst>
	// class MyIterator
	// {
	// 	int *d_;

	// public:
	// 	MyIterator(const MyIterator &) = default;				// c++11
	// 	MyIterator &operator=(const MyIterator &) = default;	// c++11

	// 	template <bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
	// 	MyIterator(const MyIterator<WasConst> &rhs) : d_(rhs.d_) {}

	// 	template <bool WasConst, class = std::enable_if_t<IsConst && !WasConst>>
	// 	MyIterator &operator=(const MyIterator<WasConst> &rhs)
	// 	{
	// 		d_ = rhs.d_;
	// 		return *this;
	// 	}
	// };

	// template <bool B, class T = void>
	// struct enable_if
	// {
	// };

	// template <class T>
	// struct enable_if<true, T>
	// {
	// 	typedef T type;
	// };

	// template <typename T, bool IsConst>
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

		typedef iterator<const T>		const_iterator;

		/// Member functions
		iterator()
		{
		}
		iterator(const_reference x_ptr) : _ptr(x_ptr._ptr) {}	// cpp11 : = default;
		// iterator(pointer x_t) : _ptr(x_t) {}

		// template <bool WasConst, class = std::enable_if<IsConst && !WasConst>>
		// iterator(const iterator<T, WasConst> &rhs) : _ptr(rhs._ptr) {}

		virtual	~iterator() {}

		/// Member Operators
		// iterator &operator=(const iterator &rhs) { _ptr = rhs._ptr; return (*this);	}

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
